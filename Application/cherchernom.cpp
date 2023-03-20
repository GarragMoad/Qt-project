#include "cherchernom.h"
#include "ui_cherchernom.h"

chercherNom::chercherNom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chercherNom)
{
    ui->setupUi(this);
}

chercherNom::~chercherNom()
{
    delete ui;
}

void chercherNom::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Nom=ui->lineEdit->text();
    std::string NomC = Nom.toStdString();
    emit chercherN(&NomC);
  close();
}

