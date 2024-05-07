QT += core gui widgets 

TARGET = GUI_demo
TEMPLATE = app
CONFIG+=sdk_no_version_check

# 源文件
SOURCES += \
    main_gui.cpp \

# 头文件
HEADERS += \
    mainwindow.h

# UI 文件
FORMS += \
    mainwindow.ui
