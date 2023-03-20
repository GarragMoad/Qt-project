QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Contact.cpp \
    Date.cpp \
    Gestioncontact.cpp \
    Todo.cpp \
    affichertag.cpp \
    ajoutintera.cpp \
    ajouttag.cpp \
    basededonne.cpp \
    chercherc2d.cpp \
    chercherd.cpp \
    cherchere.cpp \
    cherchernom.cpp \
    form.cpp \
    gestiontodo.cpp \
    interaction.cpp \
    interactioninteravalle.cpp \
    interactionnom.cpp \
    main.cpp \
    mainw.cpp \
    modifier.cpp \
    supdate.cpp \
    supentreprise.cpp \
    supprimer.cpp

HEADERS += \
    Contact.h \
    Date.h \
    Gestioncontact.h \
    Interaction.h \
    Todo.h \
    affichertag.h \
    ajoutintera.h \
    ajouttag.h \
    basededonne.h \
    chercherc2d.h \
    chercherd.h \
    cherchere.h \
    cherchernom.h \
    form.h \
    gestiontodo.h \
    interactioninteravalle.h \
    interactionnom.h \
    mainw.h \
    modifier.h \
    supdate.h \
    supentreprise.h \
    supprimer.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    affichertag.ui \
    ajoutintera.ui \
    ajouttag.ui \
    chercherc2d.ui \
    chercherd.ui \
    cherchere.ui \
    cherchernom.ui \
    interactioninteravalle.ui \
    interactionnom.ui \
    mainw.ui \
    modifier.ui \
    supdate.ui \
    supentreprise.ui \
    supprimer.ui


