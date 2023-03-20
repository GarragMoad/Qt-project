#ifndef MAINW_H
#define MAINW_H


#include <QMainWindow>
#include<form.h>
#include<cherchernom.h>
#include<supprimer.h>
#include"basededonne.h"
#include"ajoutintera.h"
#include"ajouttag.h"
#include"affichertag.h"
#include"supentreprise.h"
#include"supdate.h"
#include"cherchere.h"
#include"chercherd.h"
#include"chercherc2d.h"
#include"interactionnom.h"
#include"interactioninteravalle.h"

/**
* @class mainw
* @brief est le widget principal c'est l'interface de l'application
*/



namespace Ui {
class MainW;
}

class MainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainW(QWidget *parent = nullptr);
    ~MainW();
    Form *f;    // Widget pour Ajouter un contact
    chercherNom *A;     //Widget pour chercher le nom
    supprimer *B;   //Widget pour supprimer un contact
    basededonne *n;     // classe qui gère la base de donnée
    AjoutIntera *I;     //Widget pour ajouter un interaction
     Modifier *C;   //Widget pour modifier un contact
     AjoutTag *Z;   //Widget pour ajouter un todo
     AfficherTag *T;    //Widget pour afficher les todos
     SupEntreprise *E;  //Widget pour supprimer le contact par son entreprise
     supDate *D;    /*Widget pour supprimer le contact par la date de création*/
     chercherE *Ch; /*Widget pour chercher un contact par son Entreprise*/
     ChercherD *date;   /*Widget pour chercher le contact par la date de création*/
     ChercherC2D *inter; /*Widget pour chercher un contact entre deux dates */
     InteractionNom *R; /*Widget pour chercher un interaction par le nom du contact*/
     InteractionInteravalle *II;  /*Widget pour chercher un interaction par un intervalle de date*/
     void Remplir();//pour creer le Qjson
public slots:
    void AfficherText(string *);
    /**
   * @fn AfficherText
   * @brief slot qui affiche un contact en récupérant son nom en paramètre
   */
    void AfficherTextE(string *);
    /**
   * @fn AfficherTextE
   * @brief slot qui affiche un contact en récupérant son entreprise en paramètre
   */
    void AfficherTextD(string *);
    /**
   * @fn AfficherTextD
   * @brief slot qui affiche un contact en récupérant sa date de création en paramètre
   */
    void AfficherTextIntervalle(string *,string *);
    /**
   * @fn AfficherTextIntervalle
   * @brief slot qui affiche des contact en récupérant l'intervalle de date nom en paramètre
   */
    void bddafficheINom(string*,string *);
    /**
   * @fn bddafficheInom
   * @brief slot qui affiche un interaction en récupérant le nom et prénom du contact en paramètre
   */
    void bddafficheIDate(string*,string *);
    /**
   * @fn bddafficheIdate
   * @brief slot qui affiche un intération entre deux dates
   */
    void bddafficheT(string*);
    /**
   * @fn bddafficheT
   * @brief slot qui affiche un todo par sa date
   */

private slots:
    /*les slots définis par défaut par UI pour gérer les options du menus bar*/

    void on_afficherall_clicked();

    void on_pushButton_clicked();

    void on_actionContact_triggered();

    void on_actionInteraction_triggered();

    void on_actionPar_Nom_triggered();

    void on_actionPar_Entreprise_triggered();

    void on_actionPar_Date_de_Cr_ation_triggered();

    void on_actionNom_triggered();

    void on_actionEntreprise_triggered();

    void on_actionDate_triggered();

    void on_actionIntervalle_triggered();

    void on_actionInteraction_par_Nom_Contact_triggered();

    void on_actionInteraction_entre_deux_dates_triggered();

    void on_actionTodo_triggered();

    void on_actionTodo_par_date_triggered();

private:
    Ui::MainW *ui;
};

#endif // MAINW_H
