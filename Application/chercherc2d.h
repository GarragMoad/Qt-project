#ifndef CHERCHERC2D_H
#define CHERCHERC2D_H
using namespace std;

#include <QWidget>
/**
* @class Chercherc2d
* @brief est un widget qui permet de chercher contact entre deux dates
*/

    namespace Ui {
    class ChercherC2D;
    }

class ChercherC2D : public QWidget
{
    Q_OBJECT

    public:
        explicit ChercherC2D(QWidget *parent = nullptr);
        ~ChercherC2D();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::ChercherC2D *ui;

    signals:
        void chercherDate2(string *,string*);
        /**
       * @fn chercherDate2
       * @brief signal qui envoie  deux chaines de caractère
       * @param les deux chaines représentent les dates.
       */
};

#endif // CHERCHERC2D_H
