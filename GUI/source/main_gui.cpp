#include "header/ui_mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QObject>
#include <QFileDialog>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    void send_UART() {

    }

public:
    MyMainWindow(QWidget *parent = nullptr) 
        : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        
        connect(ui->Button_send, &QPushButton::clicked,\
         this, &MyMainWindow::func_send);
        connect(ui->Button_train, &QPushButton::clicked,\
         this, &MyMainWindow::func_train);
        connect(ui->Button_script, &QPushButton::clicked,\
         this, &MyMainWindow::func_script);
    }

    ~MyMainWindow() {
        delete ui;
    }

public slots:
    void func_send() {
        //处理发送的槽

        this->send_UART();
    }

    void func_train() {
        //点击训练模式的槽

    }

    void func_script() {
        //点击脚本按钮的槽
        QString path = QFileDialog::getOpenFileName(this, "选择脚本文件", "../script/", "*.lua");
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

#include "moc/main_gui.moc"
