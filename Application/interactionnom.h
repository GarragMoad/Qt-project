#ifndef INTERACTIONNOM_H
#define INTERACTIONNOM_H
using namespace std;

#include <QWidget>
/**
* @class interactionnom
* @brief est un widget qui permet de rechercher un interaction dans un intervalle de date
*/

namespace Ui {
class InteractionNom;
}

class InteractionNom : public QWidget
{
    Q_OBJECT

    public:
        explicit InteractionNom(QWidget *parent = nullptr);
        ~InteractionNom();

    private slots:
        void on_pushButton_clicked();
        /**
       * @fn on_pushButton_clicked
       * @brief slot  qui recupère le contenue de chaque champ du widget
       */


    signals:
        void Intera(string *,string *);
        /**
       * @fn Intera
       * @brief signal qui envoie le nom et prénom du contact concerné par l'interaction
       */

    private:
        Ui::InteractionNom *ui;
};

#endif // INTERACTIONNOM_H
