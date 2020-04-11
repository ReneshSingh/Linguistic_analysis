QT += widgets

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

SOURCES += \
    Main.cpp \
    export.cpp \
    mainwindow.cpp \
    LinguisticAnalysis.cpp

HEADERS += \
    export.h \
    mainwindow.h \
    LinguisticAnalysis.h \

FORMS += \
    mainwindow.ui
