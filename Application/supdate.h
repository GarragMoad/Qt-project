#ifndef SUPDATE_H
#define SUPDATE_H
using namespace std;
#include <string>
#include <QWidget>
/**
* @class supdate
* @brief widget pour supprimer un client par sa date de création
*/

    namespace Ui {
    class supDate;
    }

class supDate : public QWidget
{
    Q_OBJECT

    public:
        explicit supDate(QWidget *parent = nullptr);
        ~supDate();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::supDate *ui;
    signals:
        void supprimerD(string *);
        /**
       * @fn supprimerD
       * @brief signal qui envoie la date de création du contact à supprimer
       */
};

#endif // SUPDATE_H
