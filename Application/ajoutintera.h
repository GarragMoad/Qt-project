#ifndef AJOUTINTERA_H
#define AJOUTINTERA_H

#include <QWidget>
using namespace std;
#include<string>
#include"Interaction.h"
/**
* @class Affichertag
* @brief est un widget qui permet d'ajouter une interaction
*/
    namespace Ui {
    class AjoutIntera;
    }

class AjoutIntera : public QWidget
{
    Q_OBJECT

    public:
        explicit AjoutIntera(QWidget *parent = nullptr);
        ~AjoutIntera();

    signals:
        void rajoutI(string *,string*,Interaction*);
        /**
       * @fn rajoutI
       * @brief signal qui envoie une interaction et deux chaines de caractère
       * @param les deux premièrs caractères sont le nom et prénom du contact et le troixième est l'interaction qui sera ajouté au contact
       */

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::AjoutIntera *ui;
};

#endif // AJOUTINTERA_H
