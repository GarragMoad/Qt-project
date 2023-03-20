#ifndef BASEDEDONNE_H
#define BASEDEDONNE_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include<Contact.h>
#include<QJsonObject>
#include<QJsonArray>
#include"qfile.h"
/**
* @class basededonne
* @brief est la classe qui gère la base de donnée
*/


class basededonne : public QWidget
{
    Q_OBJECT

public:
    explicit basededonne(QWidget *parent = nullptr);
    Contact *c1;
    ~basededonne();
     QJsonArray faireJson();//pour inserer des donnée qu'on affichera dans le qjson

private:

     QSqlDatabase db;

public slots:
     /**
     * ... les différents slots qui permettent les modification dans la base de données ...
     */
     void bddCreate(Contact*);  //slot pour creer un contact
     void ajoutIntera(string*,string*,Interaction*);    //slot pour ajouter une interaction
     void supprContact(string*);    //slot pour supprimer des contact selon le nom
     void supprContactE(string*);   //slot pour supprimer selon l'entreprise
     void supprContactD(string*);   //slot pour supprimer selon la date
     void modifierE(string*,string*,string*);   //slot pour modifier l'entreprise
     void modifierM(string*,string*,string*);   //slot pour modifier le mail
     void modifierP(string*,string*,string*);   //slot pour modifier le numero de telephone
     void modifierI(string*,string*,string*);   //slot pour modifier un interaction
     void AjouterTag(string*,Todo*);    //slot pour ajouter des todos

};

#endif // BASEDEDONNE_H
