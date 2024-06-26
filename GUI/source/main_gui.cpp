#include <QFileDialog>
#include <QString>
#include "./include/main_gui.h"
#include "./include/handle_send.h"

//include lua
#include "./include/lua_include.h"

MyMainWindow::MyMainWindow(QWidget *parent) 
    : QMainWindow(parent), ui(new Ui::MainWindow), L(luaL_newstate()) //原来为lua_newstate()，改前报错
{
    ui->setupUi(this);
    luaL_openlibs(L);

    connect(ui->Button_send, &QPushButton::clicked, \
        this, &MyMainWindow::func_send);
    connect(ui->Button_train, &QPushButton::clicked, \
        this, &MyMainWindow::func_train);
    connect(ui->Button_script, &QPushButton::clicked, \
        this, &MyMainWindow::func_script);
}

MyMainWindow::~MyMainWindow() {
    delete ui;
    lua_close(L);
}

void MyMainWindow::func_send() {
    //处理发送的槽
    QString path = QFileDialog::getOpenFileName(this, "选择发送数据", "$HOME", "*.txt");
    if (!path.isEmpty()) {
        send_UART(path);
    }
}

void MyMainWindow::func_train() {
    //点击训练模式的槽

}

void MyMainWindow::func_script() {
    //点击脚本按钮的槽
    QString path = QFileDialog::getOpenFileName(this, "选择脚本文件", "../script/", "*.lua");

}
