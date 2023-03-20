#include "supentreprise.h"
#include "ui_supentreprise.h"

SupEntreprise::SupEntreprise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupEntreprise)
{
    ui->setupUi(this);
}

SupEntreprise::~SupEntreprise()
{
    delete ui;
}

void SupEntreprise::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString entreprise=ui->lineEdit->text();
    std::string EntrepriseC = entreprise.toStdString();
    emit supprimerE(&EntrepriseC);
  close();
}

