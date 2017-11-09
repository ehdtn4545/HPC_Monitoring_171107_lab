#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T13:46:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

#QT += widgets printsupport
#QT += widgets
#QT += printsupport

TARGET = HPC_Monitoring_171107_lab
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# CUDA with Windows
#CUDA_DIR = "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v7.5"
#CUDA_DIR = "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0"
CUDA_DIR = "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.0"
SYSTEM_NAME = x64         # Depending on your system either 'Win32', 'x64', or 'Win64'
SYSTEM_TYPE = 64            # '32' or '64', depending on your system
CUDA_ARCH = sm_61           # Type of CUDA architecture, for example 'compute_10', 'compute_11', 'sm_10'
NVCC_OPTIONS = --use_fast_math # default setting

#include paths
#INCLUDEPATH += $$CUDA_DIR\include
#INCLUDEPATH += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v7.5\include"
#INCLUDEPATH += "C:\ProgramData\NVIDIA Corporation\CUDA Samples\v8.0\common\inc"
#INCLUDEPATH += "C:\Qt\5.9.1\msvc2015_64\include"
#INCLUDEPATH += "D:\QT_Projects\HPC_Monitoring_170911_03_lab"
#INCLUDEPATH += "D:\QT_Projects\build-HPC_Monitoring_170911_03_lab-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug"
#INCLUDEPATH += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0\include"
INCLUDEPATH += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.0\include"


#library directories
#QMAKE_LIBDIR += $$join(CUDA_DIR,'" -I"','-I"','"')\lib\$$SYSTEM_NAME
#QMAKE_LIBDIR += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v7.5\lib\x64"
#QMAKE_LIBDIR += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v8.0\lib\x64"
QMAKE_LIBDIR += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.0\lib\x64"

CUDA_LIBS = -lcuda -lcudart -lnvml

CUDA_INC += $$join(INCLUDEPATH,'" -I"','-I"','"')

LIBS += $$CUDA_LIBS

# MSVCRT link option (static or dynamic, it must be the same with your Qt SDK link option)
MSVCRT_LINK_FLAG_DEBUG = "/MDd"
MSVCRT_LINK_FLAG_RELEASE = "/MD"


SOURCES += \
        main.cpp \
        qcustomplot.cpp \
        mainwindow.cpp \
        init_gpuinfo.cpp \
        init_combobox.cpp \
    init_hostoverview.cpp \
    init_deviceoverview.cpp \
    init_devprocusage.cpp \
    init_devmemusage.cpp \
    init_devproperties.cpp \
    reset_devprocusage.cpp \
    del_devprocusage.cpp \
    reset_devmemusage.cpp \
    reset_devproperties.cpp \
    del_devproperties.cpp \
    del_devmemusage.cpp \
    update_window.cpp \
    update_hostoverview.cpp \
    update_deviceoverview.cpp \
    update_devprocusage.cpp \
    update_devmemusage.cpp \
    reset_ltchkptdsp.cpp
        #initialize_window.cpp \
        #update_window.cpp \
        #gpu_getstatus.cpp \
        #initialize_overview.cpp \
        #initialize_smusage.cpp \
        #initialize_combobox.cpp \
        #initialize_gpuinfo.cpp

CUSOURCES += \
        gpu_testperformance.cu \
        gpu_testmemcpy.cu \
        testdouble.cu \
        testsingle.cu \
        testint.cu \
        testlong.cu \
        testdevicememcpy.cu

HEADERS += \
        mainwindow.h \
        qcustomplot.h

FORMS += \
        mainwindow.ui

include(cuda.pri)
