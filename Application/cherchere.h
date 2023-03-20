#ifndef CHERCHERE_H
#define CHERCHERE_H
using namespace std;
#include <string>
#include <QWidget>
/**
* @class Cherchere
* @brief est un widget qui permet de chercher contact par son entreprise
*/

namespace Ui {
class chercherE;
}

class chercherE : public QWidget
{
    Q_OBJECT

    public:
        explicit chercherE(QWidget *parent = nullptr);
        ~chercherE();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::chercherE *ui;

    signals:
        void chercherEntr(string *);
        /**
       * @fn chercherEntr
       * @brief signal qui envoie  une chaine de caractère
       * @param la chaine représente l'entreprise du contact
       */
};

#endif // CHERCHERE_H
