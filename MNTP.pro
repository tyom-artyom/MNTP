QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainmenubar.cpp \
    maintoolbar.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    managerwidget.cpp \
    markstablewidget.cpp \
    markswidget.cpp \
    noteswidget.cpp \
    plannercalendardockwidget.cpp \
    plannereventwidget.cpp \
    plannertablewidget.cpp \
    plannerwidget.cpp \
    preferencesdialog.cpp \
    progresswidget.cpp \
    trackerwidget.cpp

HEADERS += \
    mainmenubar.h \
    maintoolbar.h \
    mainwidget.h \
    mainwindow.h \
    managerwidget.h \
    markstablewidget.h \
    markswidget.h \
    noteswidget.h \
    plannercalendardockwidget.h \
    plannereventwidget.h \
    plannertablewidget.h \
    plannerwidget.h \
    preferencesdialog.h \
    progresswidget.h \
    trackerwidget.h

TRANSLATIONS += \
    MNTP_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/calendar.png

RESOURCES += \
    MNTP.qrc
