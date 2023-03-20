#ifndef MODIFIER_H
#define MODIFIER_H

#include <QWidget>
using namespace std;
#include<string>
/**
* @class modifier
* @brief widget pour modifier le client
*/


    namespace Ui {
    class Modifier;
    }

class Modifier : public QWidget
{
    Q_OBJECT

    public:
        explicit Modifier(QWidget *parent = nullptr);
        ~Modifier();

    private slots:
        void on_Valider_clicked();
        /**
       * @fn on_Valider_clicked();
       * @brief slot pour récuperer le contenue des champs
       */


    signals:
        void modifEntreprise(string *,string*,string*);
        /**
       * @fn modifEntreprise
       * @brief slot qui modifie l'entreprise du contact
       * @param les paramètres sont le nom , prénom et la nouvelle entreprise du contact
       */
        void modifMail(string *,string*,string*);
        /**
       * @fn modifMail
       * @brief slot qui modifie le mail du contact
       * @param les paramètres sont le nom , prénom et le nouveau mail du contact
       */
        void modifPhone(string *,string*,string*);
        /**
       * @fn modifPhone
       * @brief slot qui modifie le téléphone du contact
       * @param les paramètres sont le nom , prénom et le nouveau télephone  du contact
       */
        void modifImage(string *,string*,string*);
        /**
       * @fn modifImage
       * @brief slot qui modifie l'image du contact
       * @param les paramètres sont le nom , prénom et la nouvelle image du contact
       */

    private:
        Ui::Modifier *ui;
};

#endif // MODIFIER_H
