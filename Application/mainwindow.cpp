#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    i=new QWidget();
    Ajouter = new QPushButton("Ajouter Contact", this);
    Afficher = new QPushButton("Afficher", this);
    f=new Form();
    A=new class AfficherContact(f->gestion);
    QObject::connect(Ajouter, SIGNAL(clicked()), this, SLOT(AjouterContact()));
    QObject::connect(Afficher, SIGNAL(clicked()), this, SLOT(AfficherContact()));

    Central = new QHBoxLayout;
    Central->addWidget(Ajouter);
    Central->addWidget(Afficher);
    setLayout(Central);
    i->setLayout(Central);
    setCentralWidget(i);
}

MainWindow::~MainWindow()
{

}
void MainWindow::AjouterContact()
{
     f->show();
}
void MainWindow::AfficherContact()
{
    A->show();
}


