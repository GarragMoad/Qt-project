#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "affichercontact.h"
#include"form.h"
#include <QMainWindow>
#include <QPushButton>
#include<QWidget.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *i;
    QHBoxLayout *Central;
    QPushButton * Ajouter;
    QPushButton * Afficher;
    Form *f; //pour Ajouter un contact
    AfficherContact *A;


public slots:
    void AjouterContact();
    void AfficherContact();

};
#endif // MAINWINDOW_H
