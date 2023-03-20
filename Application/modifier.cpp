#include "modifier.h"
#include "ui_modifier.h"

Modifier::Modifier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
}

Modifier::~Modifier()
{
    delete ui;
}


void Modifier::on_Valider_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString nom=ui->Nom->text();
    std::string NomC = nom.toStdString();
    QString Prenom=ui->Prenom->text();
    std::string PrenomC = Prenom.toStdString();
    //la partie au-dessus recupère le nom et prénom du contact à modifier
    // la partie au-dessous recupère le contenu des champs à modifier
    QString Entreprise=ui->Entreprise->text();
    std::string EntrepriseC = Entreprise.toStdString();
    QString Email=ui->Mail->text();
    std::string EmailC = Email.toStdString();
    QString Phone=ui->Telephone->text();
    std::string PhoneC = Phone.toStdString();
    QString Image=ui->Image->text();
    std::string ImageC = Image.toStdString();
    /**
    * ...  la modification d'un attribut du contact se fait après la vérification de son champs s'il contient une chaine non vide  ...
    */
    if(!EntrepriseC.empty())
        {
          emit modifEntreprise(&NomC,&PrenomC,&EntrepriseC);
        }
    if(!EmailC.empty())
        {
           emit modifMail(&NomC,&PrenomC,&EmailC);
        }
    if(!PhoneC.empty())
        {
           emit modifPhone(&NomC,&PrenomC,&PhoneC);
        }
    if(!ImageC.empty())
        {
           emit modifImage(&NomC,&PrenomC,&ImageC);
        }
    close();
}



