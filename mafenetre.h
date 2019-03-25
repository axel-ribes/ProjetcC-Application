#include<QWidget>
#include<QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QComboBox>
#include<QString>
#include <string>
#include "charger_csv.h"
#include <vector>
#include <QTableWidget>

class MaFenetre : public QMainWindow
{
    Q_OBJECT

public slots:
    void setQuitter();
    void setCouleur();

public :
    void ChargerColonne(int colonne);
    MaFenetre(QWidget *parent = 0);
private :
    QLabel *m_lab, *m_tra;
    QPushButton *m_bou;
    QComboBox *m_com;
    QString couleur;
    CVString m_vet;
    CMatString m_mat;
    QLabel *m_vett;
    const char *m_vettstring;
    QTableWidget *m_table;
    CVString *m_vecteur;
};
