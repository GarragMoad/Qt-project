#ifndef SUPENTREPRISE_H
#define SUPENTREPRISE_H
using namespace std;
#include <string>
#include <QWidget>
/**
* @class supentreprise
* @brief widget pour supprimer un client par son entreprise
*/

namespace Ui {
class SupEntreprise;
}

class SupEntreprise : public QWidget
{
    Q_OBJECT

    public:
        explicit SupEntreprise(QWidget *parent = nullptr);
        ~SupEntreprise();

    private slots:
        void on_pushButton_clicked();

    signals:
        void supprimerE(string *);
        /**
       * @fn supprimerE
       * @brief signal qui envoie l'entreprise du contact à supprimer
       */


    private:
        Ui::SupEntreprise *ui;
};

#endif // SUPENTREPRISE_H
