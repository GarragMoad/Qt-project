#include "form.h"


Form::Form(QWidget *parent) :
    QWidget(parent)

{
    /**
    * ...  l'instanciation des différentes élements du widget (formulaire,bouton,layout)  ...
    */
    valider=new QPushButton("Valider", this);
    formulaire=new QFormLayout();
    nameEdit=new QLineEdit();
    PrenomEdit=new QLineEdit();
    phoneEdit=new QLineEdit();
    emailEdit=new QLineEdit();
    entrepriseEdit=new QLineEdit();
    PhotoEdit=new QLineEdit();

    formulaire->addRow(tr("&Name"),nameEdit);
    formulaire->addRow(tr("&Prénom"),PrenomEdit);
    formulaire->addRow(tr("&Email"),emailEdit);
    formulaire->addRow(tr("&Entreprise"),entrepriseEdit);
    formulaire->addRow(tr("&Telephone"),phoneEdit);
    formulaire->addRow(tr("&Photo"),PhotoEdit);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formulaire);
    mainLayout->addWidget(valider);
    setLayout(mainLayout);
    setWindowTitle(tr("Saisie Contact"));

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(RecupInfos())); // connection du bouton avec le slot RecupInfos par le signal du bouton

}

Form::~Form()
{

}
void Form:: RecupInfos()
{
    /**
    * ...  Création d'un objet contact en affectant à ses attributs le contenu des champs et l'émission du signal   ...
    */
    QString Nom=nameEdit->text();
    std::string NomC = Nom.toStdString();
    QString Prenom=PrenomEdit->text();
    std::string PC = Prenom.toStdString();
    QString Email=emailEdit->text();
    std::string EC = Email.toStdString();
    QString Entreprise=entrepriseEdit->text();
    std::string EnC = Entreprise.toStdString();
    QString Telephone=phoneEdit->text();
    std::string TC = Telephone.toStdString();
    QString photo=PhotoEdit->text();
    std::string PhC = photo.toStdString();

    Contact *c=new Contact(NomC,PC,EnC,EC,TC,PhC);
    emit rajoutC(c);
    close();
}

