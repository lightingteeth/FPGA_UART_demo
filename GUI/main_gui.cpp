#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QObject>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    MyMainWindow(QWidget *parent = nullptr) 
        : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        connect(ui->pushButton_send, &QPushButton::clicked, this, &MyMainWindow::UART_send);
    }
    ~MyMainWindow() {
        delete ui;
    }

public slots:
    void UART_send() {
        //处理发送的函数
        std::cout << "这是一个发送的按钮" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建主窗口
    MyMainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

#include "main_gui.moc"
