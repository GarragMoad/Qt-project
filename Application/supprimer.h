#ifndef SUPPRIMER_H
#define SUPPRIMER_H

#include <QWidget>
#include<modifier.h>
using namespace std;
#include <string>
/**
* @class supprimer
* @brief widget pour supprimer un client par son nom
*/
    namespace Ui {
    class supprimer;
    }

class supprimer : public QWidget
{
    Q_OBJECT

    public:
        explicit supprimer(QWidget *parent = nullptr);
        ~supprimer();


    private slots:
        void on_BoutonSupprimer_clicked();


    signals:
        void supprimerC(string *);
        /**
        * @fn supprimerC
        * @brief signal qui envoie le nom du contact à supprimer
        */


    private:
        Ui::supprimer *ui;
};

#endif // SUPPRIMER_H
