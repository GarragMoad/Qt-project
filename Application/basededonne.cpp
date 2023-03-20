#include "basededonne.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include<QDebug>

basededonne::basededonne(QWidget *parent) :
    QWidget(parent)

{
    /**
    * ...  Ouvrir de la BDD via le chemin d'accès   ...
    */
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString localeUri="C:/Users/Amokrane Ahmed Mehdi/Documents/ProjetFinal/Application/version.sqlite";
    db.setDatabaseName( localeUri );
    db.open();

}

basededonne::~basededonne()
{
   db.close();
}

void basededonne::bddCreate(Contact *c)
{
    /**
    * ... On récupère le contact à ajouter à la BDD et on ajoute ses attributs aux colonnes de la table contact  ...
    */
    QSqlQuery query;

    //avec une préparation de la requête et des champs pré−conçus
    query.prepare("INSERT INTO Contact (nom, entreprise,mail,Telephone,photo,prenom,dateC) VALUES (:n, :e, :m, :t, :p, :pr,:date)");
    //affectation de chaque élements mis dans la requête par sa valeur
    query.bindValue(":n", QString::fromStdString(c->getNom()));
    query.bindValue(":e", QString::fromStdString(c->getEntreprise()));
    query.bindValue(":m", QString::fromStdString(c->getEmail()));
    query.bindValue(":p", QString::fromStdString(c->getPhoto()));
    query.bindValue(":t", QString::fromStdString(c->getTelephone()));
    query.bindValue(":pr", QString::fromStdString(c->getPrenom()));
     query.bindValue(":date", QString::fromStdString(c->getDateCreation()));
    query.exec(); //
}


void basededonne::ajoutIntera(string *N,string* Pr,Interaction *i)//ajouter Interaction
{
    /**
    * ... l'ajout de l'interaction à BDD par le même principe de l'affichage d'un interaction fait dans mainw  ...
    */
    QString b="SELECT idContact from Contact WHERE nom='";
    QString s=QString::fromStdString(*N);
    QString s1=QString::fromStdString(*Pr);
    b=b+s;
    b=b+"' AND prenom='"+s1+"'"; // on a complété la requête par
    qDebug()<<b;
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();

         }
     }
     QSqlQuery query1;
     query1.prepare("INSERT INTO Interaction (idContact,contenu,dateInteraction) VALUES (:n,:e,:m)");
     query1.bindValue(":n",ID);
     query1.bindValue(":e", QString::fromStdString(i->getContI()));
     query1.bindValue(":m", QString::fromStdString(i->getDateI()));
     query1.exec();
     qDebug() << ID;
}

void basededonne::supprContact(string *NomC)//supprimer Contact
{
    /**
    * ... au Début on cherche l'Id du contact à supprimer ...
    */
    QString b="SELECT idContact from Contact WHERE nom='";
    QString s=QString::fromStdString(*NomC);
    b=b+s;
    b=b+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();

         }
     }
     /**
     * ... On supprime le contact de la table contact par son nom et ses interactions par la table interaction par son Id  ...
     */
     QSqlQuery query1;
     query1.prepare("delete from Interaction WHERE idContact=:n");
        query1.bindValue(":n",ID);
        query1.exec();

        QSqlQuery query2;
        query2.prepare("DELETE from Contact WHERE  nom=:n");
        query2.bindValue(":n", s);

        query2.exec();
}
void basededonne::supprContactE(string *EntrepriseC)//supprimer Contact
{
    /**
    * ... Idem que supprContac sauf cette fois par Entreprise  ...
    */
    QString b="SELECT idContact from Contact WHERE entreprie='";
    QString s=QString::fromStdString(*EntrepriseC);
    b=b+s;
    b=b+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();

         }
     }
     QSqlQuery query1;
     query1.prepare("delete from Interaction WHERE idContact=:n");
        query1.bindValue(":n",ID);
        query1.exec();

        QSqlQuery query2;
        query2.prepare("DELETE from Contact WHERE  entreprise=:n");
        query2.bindValue(":n", s);

        query2.exec();
}
void basededonne::supprContactD(string *dateC)//supprimer Contact
{
    /**
    * ... Idem que supprContac sauf cette fois par Date de création  ...
    */
    QString b="SELECT idContact from Contact WHERE dateC='";
    QString s=QString::fromStdString(*dateC);
    b=b+s;
    b=b+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();

         }
     }
     QSqlQuery query1;
     query1.prepare("delete from Interaction WHERE idContact=:n");
        query1.bindValue(":n",ID);
        query1.exec();

        QSqlQuery query2;
        query2.prepare("DELETE from Contact WHERE  dateC=:n");
        query2.bindValue(":n", s);

        query2.exec();
}
void basededonne::modifierE(string *NomC,string* PrenomC,string *EntrepriseC)//modifier entreprise
{
    /**
    * ... On modifie le champ Entreprise pour le contact de nomC et prenomC   ...
    */
    /**
    * ... au début on récupère l'id du contact   ...
    */
    c1=new Contact();
    QString b="SELECT idContact from Contact WHERE nom='";
    QString s=QString::fromStdString(*NomC);
    QString s1=QString::fromStdString(*PrenomC);
    b=b+s;
    b=b+"' AND prenom='";
    b=b+s1+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();
         }
     }
     qDebug()<<ID;
     qDebug()<<EntrepriseC;
     /**
     * ... on met à jour le champ entreprise et la date de modif du contact par la requête ci-dessous   ...
     */
     QString s2=QString::fromStdString(*EntrepriseC);
     QSqlQuery query1;
     query1.prepare("UPDATE Contact SET entreprise=:e,dateM=:md WHERE idContact="+ID+";");
     query1.bindValue(":e",s2);
     query1.bindValue(":md",QString::fromStdString(c1->getDateCreation()));
     query1.exec();
}
void basededonne::modifierM(string *NomC,string* PrenomC,string *EmailC)//modifier mail
{
    /**
    * ... Idem que MoodifierE sauf cette fois on modifie le mail  ...
    */
    c1=new Contact();
    QString b="SELECT idContact from Contact WHERE nom='";
    QString s=QString::fromStdString(*NomC);
    QString s1=QString::fromStdString(*PrenomC);
    b=b+s;
    b=b+"' AND prenom='";
    b=b+s1+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();
         }
     }
     qDebug()<<ID;
     qDebug()<<EmailC;

     QString s2=QString::fromStdString(*EmailC);
      QSqlQuery query1;
     query1.prepare("UPDATE Contact SET mail=:m,dateM=:md WHERE idContact="+ID+";");
     query1.bindValue(":m",s2);
     query1.bindValue(":md",QString::fromStdString(c1->getDateCreation()));
     query1.exec();
}
void basededonne::modifierI(string *NomC,string* PrenomC,string *ImageC)//modifier photo
{
    /**
    * ... Idem que MoodifierE sauf cette fois on modifie Image  ...
    */
    c1=new Contact();
    QString b="SELECT idContact from Contact WHERE nom='";
    QString s=QString::fromStdString(*NomC);
    QString s1=QString::fromStdString(*PrenomC);
    b=b+s;
    b=b+"' AND prenom='";
    b=b+s1+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();
         }
     }

     QString s2=QString::fromStdString(*ImageC);
     //qDebug()<<s2;
      QSqlQuery query1;
     query1.prepare("UPDATE Contact SET photo=:m,dateM=:md WHERE idContact="+ID+";");
     query1.bindValue(":m",s2);
     query1.bindValue(":md",QString::fromStdString(c1->getDateCreation()));
     query1.exec();
}

void basededonne::modifierP(string *NomC,string* PrenomC,string *PhoneC)//modifier Telephone
{
    /**
    * ... Idem que MoodifierE sauf cette fois on modifie téléphone  ...
    */
    c1=new Contact();
    QString b="SELECT idContact from Contact WHERE nom='";
    QString s=QString::fromStdString(*NomC);
    QString s1=QString::fromStdString(*PrenomC);
    b=b+s;
    b=b+"' AND prenom='";
    b=b+s1+"'";
     QSqlQuery query(b);
     QString ID;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();
         }
     }
     qDebug()<<ID;
     qDebug()<<PhoneC;

     QString s2=QString::fromStdString(*PhoneC);
      QSqlQuery query1;
    query1.prepare("UPDATE Contact SET telephone=:t,dateM=:md WHERE idContact="+ID+";");
    query1.bindValue(":t",s2);
    query1.bindValue(":md",QString::fromStdString(c1->getDateCreation()));
    query1.exec();
}
void basededonne::AjouterTag(string*IdC,Todo* t)
{
    /**
    * ... Insertion du todo dans la BDD avec l'id du contact concerné  ...
    */
     QString Id=QString::fromStdString(*IdC);
    qDebug()<<QString::fromStdString(t->getContenu());
    QSqlQuery query1;
    query1.prepare("INSERT INTO Todo (contenu,dateTodo,idInteraction) VALUES (:n,:e,:m)");
    query1.bindValue(":n", QString::fromStdString(t->getContenu()));
    query1.bindValue(":e", QString::fromStdString(t->getDate()));
    query1.bindValue(":m",Id);
    query1.exec();

}
QJsonArray basededonne::faireJson()
{
    QJsonArray T1;
    QSqlQuery query;
    query.prepare("SELECT * from Contact");
    if(!query.exec())
    {
        qDebug()<<"erreur";
    }
    else
    {
        while(query.next())
        {
            QVariantMap map;

            map.insert("Nom:",query.value(1));
            map.insert("Prenom:",query.value(2));
            map.insert("Entreprise:",query.value(3));
            map.insert("Mail:",query.value(4));
            map.insert("Telephone:",query.value(5));
            map.insert("Date de creation:",query.value(7));
            T1.push_back(QJsonObject::fromVariantMap(map));
        }
    }
    return T1;

}
