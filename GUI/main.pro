QT += core gui widgets serialport

TARGET = GUI_demo
TEMPLATE = app
CONFIG+=sdk_no_version_check 

# 设计中间文件的目录
OBJECTS_DIR = construct/
MOC_DIR = moc/
UI_DIR = header/

# MOC文件
QMAKE_MOC += include/main_gui.h

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