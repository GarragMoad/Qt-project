#include "interactionnom.h"
#include "ui_interactionnom.h"

InteractionNom::InteractionNom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InteractionNom)
{
    ui->setupUi(this);
}

InteractionNom::~InteractionNom()
{
    delete ui;
}

void InteractionNom::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Nom=ui->lineEdit->text();
    std::string NomC = Nom.toStdString();
    QString Prenom=ui->lineEdit_2->text();
    std::string PrenomC = Prenom.toStdString();
    emit Intera(&NomC,&PrenomC);
  close();
}

