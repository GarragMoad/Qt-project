#include "supprimer.h"
#include "ui_supprimer.h"

supprimer::supprimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::supprimer)
{
    ui->setupUi(this);


}

supprimer::~supprimer()
{
    delete ui;
}

void supprimer::on_BoutonSupprimer_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString nom=ui->lineEditNom->text();
    std::string NomC = nom.toStdString();
    emit supprimerC(&NomC);
  close();
}

