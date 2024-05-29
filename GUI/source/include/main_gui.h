#include "../../header/ui_mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include "lua_include.h"


class MyMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    lua_State *L;

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

public slots:
    void func_send(); 
    void func_train(); 
    void func_script(); 
};
