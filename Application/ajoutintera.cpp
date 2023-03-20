#include "ajoutintera.h"
#include "ui_ajoutintera.h"

AjoutIntera::AjoutIntera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutIntera)
{
    ui->setupUi(this);
}

AjoutIntera::~AjoutIntera()
{
    delete ui;
}

void AjoutIntera::on_pushButton_clicked()
{
    /**
    * ... Création d'un objet interaction en affectant à ses attributs le contenue des champs et l'émission du signal ...
    */
    QString Contenu=ui->ContenuI->text();
    std::string C = Contenu.toStdString();
    QString Nom=ui->NomC->text();
    std::string N = Nom.toStdString();
    QString Prenom=ui->lineEditP->text();
    std::string Pr = Prenom.toStdString();
    Interaction *i=new Interaction();
    i->setContenuI(C);
     emit rajoutI(&N,&Pr,i);
    this->close();
}

