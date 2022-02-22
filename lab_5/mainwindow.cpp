#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);

    h_limit=1000;                   //Asigna el tamaño de la interfaz
    v_limit=500;

    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
    ui->centralWidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);



    srand (time(NULL)); //para el timer
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));







}

MainWindow::~MainWindow()//destructor
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()//actualiza la posicion dependiendo del timer para la colision
{
    for(int i=0;i<bars.size();i++){

        bars.at(i)->actualizar(v_limit);//actualiza en esferagraf
        bordercollision(bars.at(i)->getEsf());//actualiza el choque con el borde
    }
}

void MainWindow::bordercollision(cuerpo *b)//son los choques con los bordes
{
    if(b->get_posX()<= b->get_Radio()){
        b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), b->get_Radio(), b->get_posY()) ;//con el borde izquierdo

    }
    if(b->get_posX()>h_limit-b->get_Radio()){//posicion con el borde derecho.
        b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());
    }
    if(b->get_posY()<b->get_Radio()){//choque con el borde superior.
        b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
    }
    if(b->get_posY()>v_limit-b->get_Radio()){//choque con el borde inferior.
        b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), v_limit-b->get_Radio());
    }
}



void MainWindow::on_pushButton_clicked()//cuando se pulsa el boton
{
     timer->start(20);
     bars.push_back(new cuerpograf); //se devuelve al principio de la lista
     bars.back()->actualizar(v_limit); //la actualiza
     scene->addItem(bars.back()); //agrega el nuevo elemento .

}
