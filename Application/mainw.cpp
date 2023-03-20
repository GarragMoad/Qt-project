#include "mainw.h"
#include "qjsondocument.h"
#include "ui_mainw.h"
#include "supprimer.h"
#include<QDebug>
#include <QtSql/QSqlQuery>

MainW::MainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainW)
{
    /**
    * ...  Instanciation des différantes classes utilisées par la fenêtre principale  ...
    */
    ui->setupUi(this);
    n=new basededonne();
    f=new Form();
    B=new supprimer();
    A=new chercherNom();
    I=new AjoutIntera();
    R=new InteractionNom;
    C=new Modifier();
    Z=new AjoutTag();
    T=new AfficherTag();
    E=new SupEntreprise();
    D=new supDate();
    Ch=new chercherE();
    date=new ChercherD();
    inter=new ChercherC2D();
    II=new InteractionInteravalle();

    Remplir();
}

MainW::~MainW()
{
    delete ui;
}



void MainW::AfficherText(string *S){
    /**
    * ...  Récuperation du contact par son nom dans la BDD et l'afficher dans une TextEdit dans la fenêtre principale  ...
    */

    QString s=QString::fromStdString(*S); // Convertir le nom du string à Qstring pour composer la requête

    QString b="SELECT * from Contact WHERE nom='";
    b=b+s; //Concaténer le nom du contact à notre requête préparée à l'avance
    b=b+"'";
    QSqlQuery query(b);
    ui->Affichage->clear(); //Supprimer le contenu précedent de la TextEdit
    if(!query.exec())
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << b;

    }
    else
    {
        qDebug() << "Requête exécutée";

        while(query.next())
        {
            QString list=QString(query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString()+" "+query.value(4).toString()+" "+query.value(5).toString()+" "+query.value(7).toString());
            ui->Affichage->append(list);
            ui->AffichImage->setPixmap(QPixmap(query.value(6).toString()));
            ui->AffichImage->show(); // on affiche l'image du contact


        }
    }
    update();
}
void MainW::AfficherTextE(string *S){
    /**
    * ...  Récuperation du contact par son entreprise dans la BDD et l'afficher dans une TextEdit dans la fenêtre principale  ...
    */


    QString s=QString::fromStdString(*S);

    QString b="SELECT * from Contact WHERE entreprise='";
    b=b+s;
    b=b+"'";
     qDebug() << b;
    QSqlQuery query(b);
    ui->Affichage->clear();
    if(!query.exec())
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << b;

    }
    else
    {
        qDebug() << "Requête exécutée";

        while(query.next())
        {

            QString list=QString(query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString()+" "+query.value(4).toString()+" "+query.value(5).toString()+""+query.value(7).toString());
            ui->Affichage->append(list);
            ui->AffichImage->setPixmap(QPixmap(query.value(6).toString()));
            ui->AffichImage->show();


        }
    }
    update();
}
void MainW::AfficherTextD(string *S){

    /**
    * ...  Récuperation du contact par sa date de création dans la BDD et l'afficher dans une TextEdit dans la fenêtre principale  ...
    */

    QString s=QString::fromStdString(*S);

    QString b="SELECT * from Contact WHERE dateC='";
    b=b+s;
    b=b+"'";
     qDebug() << b;
    QSqlQuery query(b);
    ui->Affichage->clear();
    if(!query.exec())
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << b;

    }
    else
    {
        qDebug() << "Requête exécutée";

        while(query.next())
        {
            //le value(0) est l'idPersonne
            //qDebug() << "nom : " << ;

            QString list=QString(query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString()+" "+query.value(4).toString()+" "+query.value(5).toString()+" "+query.value(7).toString());
            ui->Affichage->append(list);
            ui->AffichImage->setPixmap(QPixmap(query.value(6).toString()));
            ui->AffichImage->show();


        }
    }
    update();
}

void MainW::AfficherTextIntervalle(string *date1,string *date2)
{
    /**
    * ...  Récuperation des contact dans un intervalle de date dans la BDD et les afficher dans une TextEdit dans la fenêtre principale  ...
    */

    QString Date1=QString::fromStdString(*date1);
    QString Date2=QString::fromStdString(*date2);
    QString b="SELECT * from Contact WHERE dateC>='";
    b=b+Date1+"' AND dateC<='";
    b=b+Date2+"'";
    qDebug() << b;
    QSqlQuery query(b);
    ui->Affichage->clear();
    if(!query.exec())
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << b;

    }
    else
    {
        qDebug() << "Requête exécutée";

        while(query.next())
        {

            QString list=QString(query.value(1).toString()+" "+query.value(2).toString()+" "+query.value(3).toString()+" "+query.value(4).toString()+" "+query.value(5).toString()+" "+query.value(7).toString()+" ");
            ui->Affichage->append(list);
            //ui->AffichImage->setPixmap(QPixmap(query.value(6).toString()));
            //ui->AffichImage->show();


        }
    }
    update();


}



void MainW::on_afficherall_clicked()
{
    /**
    * ...  En cliquant sur le bouton d'afficher tous les contacts on les affiche tous et on les compte   ...
    */

    ui->AffichImage->clear();
    ui->Affichage->clear();
    QSqlQuery q;
     q.prepare(QString("SELECT COUNT (*) from Contact")); //Pour calculer le nombre des contacts
     q.exec();
     int nb= 0;
     if (q.next()) {
            nb= q.value(0).toInt();
            }
    QString N = QString("Nombre de Contact:"+QString::number(nb)); //Affichage du nombre de contacts
    ui->Affichage->append(N);
    QString s="SELECT * from Contact"; // Récupération de l'ensembles des contacts
    QSqlQuery query(s);

    if(!query.exec())
    {
        qDebug() << "Impossible d'exécuter la requête !";
    }
    else
    {
        qDebug() << "Requête exécutée";

        while(query.next())
        {

            QString list=QString(query.value(1).toString()+" "+query.value(2).toString());
            ui->Affichage->append(list); //Affichages des contacts


        }
    }
    update();
}
void MainW::bddafficheIDate(string *date1,string *date2)
{
    /**
    * ...  Récuperation des interaction dans un intervalle de date dans la BDD et les afficher dans une TextEdit dans la fenêtre principale  ...
    */
    ui->Affichage->clear();
    QString Date1=QString::fromStdString(*date1);
    QString Date2=QString::fromStdString(*date2);


     QString a="SELECT * from Interaction WHERE dateInteraction>='";
     a=a+Date1;
     a=a+"' And dateInteraction<='"+Date2+"'";

     QSqlQuery query1(a);
      if(query1.exec())
      {
        while(query1.next())
        {

           QString list=QString(" "+query1.value(0).toString()+" "+query1.value(2).toString()+" "+query1.value(3).toString());
           ui->Affichage->append(list);


         }
      }
}
void MainW::bddafficheINom(string *NomC,string *PrenomC)
{
    /**
    * ...  Récuperation des interactions d'un contact dans la BDD et les afficher dans une TextEdit dans la fenêtre principale  ...
    */
    ui->Affichage->clear();
    QString s=QString::fromStdString(*NomC);
    QString s1=QString::fromStdString(*PrenomC);

    QString b="SELECT * from Contact WHERE nom='"; //On récupère le id du contact après ajouter le nom et prénom du contact à cette requête
    b=b+s;
    b=b+"'And prenom='"+s1+"'";
    qDebug()<<b;
     QSqlQuery query(b);
     QString ID,IDi;
     if(query.exec())
     {
         while(query.next())
         {
              ID=query.value(0).toString();
              QString list0=QString("Nom du Contact:"+query.value(1).toString());
              ui->Affichage->append(list0);
         }
     }
     QString a="SELECT * from Interaction WHERE idContact='"; // on Récupère l'ensemble des interactions associé au contact d'id trouvé par la requête au-dessus
     a=a+ID+"'";
     QSqlQuery query1(a);
      if(query1.exec())
      {
        while(query1.next())
        {
           IDi=query1.value(0).toString();
           QString list=QString(" "+query1.value(0).toString()+" "+query1.value(2).toString()+" "+query1.value(3).toString());
           ui->Affichage->append(list);
           QString c="SELECT * from Todo WHERE idInteraction='";
            c=c+IDi+"'";
            QSqlQuery query2(c);
            query2.exec();
            while(query2.next())
            {
                QString list1=QString("@todo "+query2.value(1).toString()+" @date "+query2.value(2).toString());
                ui->Affichage->append(list1);
            }


         }
      }
}



void MainW::bddafficheT(string* DateC)
{
    /**
    * ...  Récuperation du todo par sa date  ...
    */
    ui->Affichage->clear();
    QString Date=QString::fromStdString(*DateC);
     QString a="SELECT * from Todo WHERE dateTodo='";
     a=a+Date+"'";
     QSqlQuery query1(a);
      if(query1.exec())
      {
        while(query1.next())
        {

           QString list=QString("@todo "+query1.value(1).toString()+" @date  "+query1.value(2).toString());
           ui->Affichage->append(list);


         }
      }
}

/**
* ...  La patie dessous est dédié à afficher les widgets pour effectuer les différentes actions  demandés et à établir les connexion entre
* les signaux et les slots   ...
*/

void MainW::on_pushButton_clicked()
{
    C->show();
    connect(C, SIGNAL(modifEntreprise(string *,string*,string*)),n, SLOT(modifierE(string*,string*,string*)));
    connect(C, SIGNAL(modifMail(string *,string*,string*)),n, SLOT(modifierM(string*,string*,string*)));
    connect(C, SIGNAL(modifPhone(string *,string*,string*)),n, SLOT(modifierP(string*,string*,string*)));
    connect(C, SIGNAL(modifImage(string *,string*,string*)),n, SLOT(modifierI(string*,string*,string*)));
}

void MainW::on_actionContact_triggered()
{
    f->show();
    connect(f, SIGNAL(rajoutC(Contact*)),n, SLOT(bddCreate(Contact*))); // connexion du signal qui envoie un contact au slot qui l'ajoute à la base de donnée

}


void MainW::on_actionInteraction_triggered()
{
    I->show();
    connect(I, SIGNAL(rajoutI(string *,string*,Interaction*)),n, SLOT(ajoutIntera(string*,string*,Interaction*)));//connexion du qignal qui envoie l'interaction ave les cordonées du contact concerné au slot qui l'ajoute à BDD

}


void MainW::on_actionPar_Nom_triggered()
{
    B->show();
    connect(B, SIGNAL(supprimerC(string*)),n, SLOT(supprContact(string*)));
}


void MainW::on_actionPar_Entreprise_triggered()
{
    E->show();
    connect(E, SIGNAL(supprimerE(string*)),n, SLOT(supprContactE(string*)));
}


void MainW::on_actionPar_Date_de_Cr_ation_triggered()
{
   D->show();
   connect(D, SIGNAL(supprimerD(string*)),n, SLOT(supprContactD(string*)));
}


void MainW::on_actionNom_triggered()
{
    A->show();
    connect(A, SIGNAL(chercherN(string *)), this, SLOT(AfficherText(string *)));//conexion pour afficher selon le nom
}


void MainW::on_actionEntreprise_triggered()
{
    Ch->show();
   connect(Ch, SIGNAL(chercherEntr(string *)), this, SLOT(AfficherTextE(string *)));//conexion pour afficher selon l'entreprise
}


void MainW::on_actionDate_triggered()
{
   date->show();
   connect(date, SIGNAL(chercherDate(string *)), this, SLOT(AfficherTextD(string *)));//conexion pour afficher selon la date
}


void MainW::on_actionIntervalle_triggered()
{
    inter->show();
    connect(inter, SIGNAL(chercherDate2(string *,string *)), this, SLOT(AfficherTextIntervalle(string *,string *)));//conexion pour afficher selon un intervalle de date

}


void MainW::on_actionInteraction_par_Nom_Contact_triggered()
{
    R->show();
    connect(R, SIGNAL(Intera(string *,string *)),this, SLOT(bddafficheINom(string*,string*)));
}


void MainW::on_actionInteraction_entre_deux_dates_triggered()
{
    II->show();
     connect(II, SIGNAL(InteraDate(string *,string *)),this, SLOT(bddafficheIDate(string*,string*)));
}


void MainW::on_actionTodo_triggered()
{
    Z->show();
    connect(Z, SIGNAL(ajoutTag(string *,Todo*)),n, SLOT(AjouterTag(string*,Todo*)));
}


void MainW::on_actionTodo_par_date_triggered()
{
    QObject::connect(T, SIGNAL(afficherT(string *)),this, SLOT(bddafficheT(string*)));
    T->show();
}
void MainW::Remplir()
{
   QJsonDocument doc;
   doc.setArray(n->faireJson());
   QFile fichierJSON("C:/Users/Amokrane Ahmed Mehdi/Documents/ProjetFinal/Application/texte.json");
   if (fichierJSON.open(QFile::WriteOnly | QIODevice::Text))
   {
      fichierJSON.write(doc.toJson());
      qDebug()<<"marche";
      //fichierJSON.close();

   }

}

