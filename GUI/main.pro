QT += core gui widgets serialport

TARGET = GUI_demo
TEMPLATE = app
CONFIG += sdk_no_version_check 

# 链接lua的库
# !!!自行编译时需修改路径!!!
INCLUDEPATH += /opt/homebrew/Cellar/lua/5.4.6/include/lua5.4
LIBS += -L/opt/homebrew/Cellar/lua/5.4.6/lib -llua

# 设计中间文件的目录
OBJECTS_DIR = construct/
MOC_DIR = moc/
UI_DIR = header/

# 源文件
SOURCES += \
    ./source/main_gui.cpp \
    ./source/handle_send.cpp \
    ./source/GUI_demo.cpp

HEADERS += \
    ./source/include/handle_send.h \
    ./source/include/main_gui.h 

# UI 文件
FORMS += \
    ./ui_files/mainwindow.ui