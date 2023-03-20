#include "cherchere.h"
#include "ui_cherchere.h"

chercherE::chercherE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chercherE)
{
    ui->setupUi(this);
}

chercherE::~chercherE()
{
    delete ui;
}

void chercherE::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Entreprise=ui->lineEdit->text();
    std::string EntrepriseC = Entreprise.toStdString();
    emit chercherEntr(&EntrepriseC);
    close();
}

