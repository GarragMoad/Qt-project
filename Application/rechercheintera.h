#ifndef RECHERCHEINTERA_H
#define RECHERCHEINTERA_H

#include <QWidget>
using namespace std;
#include <string>

namespace Ui {
class rechercheIntera;
}

class rechercheIntera : public QWidget
{
    Q_OBJECT

public:
    explicit rechercheIntera(QWidget *parent = nullptr);
    ~rechercheIntera();
signals:
    void rechercherrIntera(string *,string *,string *,string *);
private slots:
    void on_rechercheI_clicked();

private:
    Ui::rechercheIntera *ui;
};

#endif // RECHERCHEINTERA_H
