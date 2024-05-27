#include "../../header/ui_mainwindow.h"
#include <QWidget>
#include <QMainWindow>


class MyMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

public slots:
    void func_send(); 
    void func_train(); 
    void func_script(); 
};
