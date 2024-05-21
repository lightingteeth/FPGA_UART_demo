QT += core gui widgets

TARGET = GUI_demo
TEMPLATE = app
CONFIG+=sdk_no_version_check

# 设计中间文件的目录
OBJECTS_DIR = construct/
MOC_DIR = moc/
UI_DIR = header/

# 源文件
SOURCES += \
    ./source/main_gui.cpp

# UI 文件
FORMS += \
    ./ui_files/mainwindow.ui