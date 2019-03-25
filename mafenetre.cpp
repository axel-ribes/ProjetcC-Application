#include "mafenetre.h"
#include "vector"


void MaFenetre::setQuitter()
{
    this->close();
}

void MaFenetre::setCouleur()
{
    couleur = m_com->currentText();
    m_tra->setText(">> " + couleur + " <<");
}

void MaFenetre::ChargerColonne(int colonne)
{
    m_vecteur->clear();
    m_vecteur->push_back(nullptr); //null au debut de liste

    read_csv(m_mat,m_vet,"data.csv");
    for(int i = 0;i<m_vet.size();i++){
    m_vettstring = (m_mat[colonne][i].c_str());
    m_vecteur->push_back(m_vettstring);
    }

}
MaFenetre::MaFenetre(QWidget *parent)
{
    setFixedSize(800,600);
    m_bou = new QPushButton("quitter",this);
    m_bou->setGeometry(600,400,80,40);

    m_lab = new QLabel("Couleur", this);
    m_lab->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_lab->move(320, 125);

    m_com = new QComboBox(this);
    m_com->setGeometry(300,150,100,30);
    m_com->addItem("Rouge");
    m_com->addItem("Vert");
    m_com->addItem("Bleu");
    m_com->addItem("Jaune");
    m_com->addItem("Orange");
    m_com->addItem("Violet");

    m_tra = new QLabel(this);
    m_tra->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_tra->move(320, 300);

    //read_csv(m_mat,m_vet,"data.csv"); //lecture du fichier
    ChargerColonne(0);
    CVString* fievre = m_vecteur;
//    vector<string> douleur = ChargerColonne(1);
//    vector<string> toux = ChargerColonne(2);   //vecteurs colonne
//    vector<string> maladie = ChargerColonne(3);

    m_table = new QTableWidget(m_mat.size()+1,m_mat[0].size()+1,this);
    m_table->setGeometry(0,250,550,350);

    for(int i =0;i<m_vet.size();i++){
        m_table->setItem(0,i+1,new QTableWidgetItem(QString::fromUtf8(fievre[i])));
    }

    m_vett = new QLabel(m_vettstring,this); //label affichant vettstring
    m_vett->setFont(QFont("Helvetica",10,QFont::Bold,true));
    m_vett->move(400,420);


    connect(m_bou, SIGNAL(clicked()),this,SLOT(setQuitter()));
    connect(m_com, SIGNAL(currentIndexChanged(const QString &)),
    this, SLOT(setCouleur()));
}
