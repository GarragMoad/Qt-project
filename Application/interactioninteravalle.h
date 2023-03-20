#ifndef INTERACTIONINTERAVALLE_H
#define INTERACTIONINTERAVALLE_H
using namespace std;
#include <QWidget>
/**
* @class interactionintervalle
* @brief est un widget qui permet de rechercher un interaction dans un intervalle de date
*/


    namespace Ui {
    class InteractionInteravalle;
    }

class InteractionInteravalle : public QWidget
{
    Q_OBJECT

    public:
        explicit InteractionInteravalle(QWidget *parent = nullptr);
        ~InteractionInteravalle();

    private slots:
        void on_pushButton_clicked();
        /**
       * @fn on_pushButton_clicked
       * @brief slot  qui recupère le contenue de chaque champ du widget
       */

    private:
        Ui::InteractionInteravalle *ui;

    signals:
        void InteraDate(string *,string *);
        /**
       * @fn InteraDate
       * @brief signal qui envoie l'intervalle d'interaction
       */
};

#endif // INTERACTIONINTERAVALLE_H
