#ifndef CHERCHERD_H
#define CHERCHERD_H
using namespace std;
#include <string>
#include <QWidget>

/**
* @class Chercherd
* @brief est un widget qui permet de chercher contact par date
*/

    namespace Ui {
    class ChercherD;
    }

class ChercherD : public QWidget
{
    Q_OBJECT

    public:
        explicit ChercherD(QWidget *parent = nullptr);
        ~ChercherD();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::ChercherD *ui;

    signals:
        void chercherDate(string *);
        /**
       * @fn chercherDate
       * @brief signal qui envoie  une chaine de caractère
       * @param la chaine représente la date de création du contact.
       */
};

#endif // CHERCHERD_H
