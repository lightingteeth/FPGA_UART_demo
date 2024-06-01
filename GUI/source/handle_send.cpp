#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QDebug>
#include "./include/handle_send.h"

QSerialPort serial;
extern QSerialPort serial; // 声明一个全局的串口对象

void send_UART(const QString &path) {
    // 打开文件
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件";
        return;
    }

    // 初始化串口，可根据实际更改
    serial.setPortName("/dev/ttyUSB0"); // 根据实际情况设置串口名称
    serial.setBaudRate(QSerialPort::Baud9600); // 设置波特率为9600
    serial.setDataBits(QSerialPort::Data8); // 设置数据位为8位
    serial.setParity(QSerialPort::NoParity); // 设置无校验位
    serial.setStopBits(QSerialPort::OneStop); // 设置停止位为1位
    serial.setFlowControl(QSerialPort::NoFlowControl); // 设置无流控制

    if (!serial.open(QIODevice::ReadWrite)) {
        qDebug() << "无法打开串口";
        return;
    }

    // 逐行读取文件并通过串口发送
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QByteArray data = line.toUtf8();
        serial.write(data);

        // 等待写入完成
        if (!serial.waitForBytesWritten(1000)) {
            qDebug() << "写入超时";
            break;
        }

        // 等待FPGA的响应
        if (!serial.waitForReadyRead(5000)) { // 等待FPGA响应5秒
            qDebug() << "等待FPGA响应超时";
            break;
        }

        QByteArray responseData = serial.readAll();
        while (serial.waitForReadyRead(10))
            responseData += serial.readAll();

        qDebug() << "收到FPGA响应:" << responseData;

        // 等待5秒再发送下一行数据
        QThread::sleep(5);
    }
    qDebug() << "所有数据发送完成";
    // 关闭文件和串口
    file.close();
    serial.close();
}
