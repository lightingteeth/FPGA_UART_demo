#include <QFileDialog>
#include <QString>
#include "./include/main_gui.h"
#include "./include/handle_send.h"

MyMainWindow::MyMainWindow(QWidget *parent) 
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Button_send, &QPushButton::clicked, this, &MyMainWindow::func_send);
    connect(ui->Button_train, &QPushButton::clicked, this, &MyMainWindow::func_train);
    connect(ui->Button_script, &QPushButton::clicked, this, &MyMainWindow::func_script);
}

MyMainWindow::~MyMainWindow() {
    delete ui;
}

void MyMainWindow::func_send() {
    //处理发送的槽
    QString path = QFileDialog::getOpenFileName(this, "选择发送数据", "$HOME", "*.txt");

    send_UART();
}

void MyMainWindow::func_train() {
    //点击训练模式的槽

}

void MyMainWindow::func_script() {
    //点击脚本按钮的槽
    QString path = QFileDialog::getOpenFileName(this, "选择脚本文件", "../script/", "*.lua");

}
