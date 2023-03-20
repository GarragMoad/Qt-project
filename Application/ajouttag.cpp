#include "ajouttag.h"
#include "ui_ajouttag.h"
#include<QDebug>
AjoutTag::AjoutTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutTag)
{
    ui->setupUi(this);
}

AjoutTag::~AjoutTag()
{
    delete ui;
}

void AjoutTag::on_pushButton_clicked()

{
    /**
    * ... Création d'un objet todo en affectant à ses attributs le contenue des champs et l'émission du signal ...
    */
    Todo* t;
    QString Id=ui->lineEditNom->text();
    std::string IdC = Id.toStdString();
    QString Contenu=ui->lineEditContenu->text();
    std::string ContenuC = Contenu.toStdString();
    QString date=ui->lineEditDate->text();
    std::string DateC = date.toStdString();
    if(!DateC.empty()) // si le champ de la date n'est pas vide on affecte cette date au todo
    {
        t=new Todo(ContenuC,DateC);
    }
    else // sinon on passe une chaine vide à l'attribut date comme ça il affecte la date courante à ce todo(ce traitement est fait dans la classe todo)
    {
        t=new Todo(ContenuC,"");
    }

     emit ajoutTag(&IdC,t);
     close();
}

