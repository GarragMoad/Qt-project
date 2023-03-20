#ifndef CHERCHERNOM_H
#define CHERCHERNOM_H
using namespace std;
#include <string>
#include <QWidget>
/**
* @class Cherchernom
* @brief est un widget qui permet de chercher contact par son nom
*/


namespace Ui {
class chercherNom;
}

class chercherNom : public QWidget
{
    Q_OBJECT

    public:
        explicit chercherNom(QWidget *parent = nullptr);
        ~chercherNom();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::chercherNom *ui;

    signals:
        void chercherN(string *);
        /**
       * @fn chercherN
       * @brief signal qui envoie  une chaine de caractère
       * @param la chaine représente le nom du contact
       */
};

#endif // CHERCHERNOM_H
