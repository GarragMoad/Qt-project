#ifndef AFFICHERCONTACT_H
#define AFFICHERCONTACT_H

#include <QWidget>
#include <QFormLayout>
#include<QLineEdit>
#include<QPushButton>
//#include <QLabel>
//#include <QPixmap>
#include "qstring.h"
#include"Gestioncontact.h"
#include"Contact.h"




class AfficherContact : public QWidget
{
    Q_OBJECT

public:
    explicit AfficherContact(QWidget *parent = nullptr);
    AfficherContact(Gestioncontact *gestion);
    ~AfficherContact();



public slots:
    void ChercherContact();
signals:
    void declencher(string *);
    void declencherE(string *);
    void declencherD(string *);
    void declencherIntervalle(string *,string*);


private:

    QFormLayout *formulaire; // formulaire pour les les infos d'un contact
    QLineEdit *Nom;

    list<Contact> List;
};

#endif // AFFICHERCONTACT_H
