#include "graphics.h"
#include <QPainter>
#include <QPoint>
#include <math.h>
graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position=0;
    timerId=startTimer(500);
    positionBoat=0;
    positionXMoon=100;
    positionYMoon=500;
    positionXSun=100;
    positionYSun=300;
}
void graphics::timerEvent(QTimerEvent *){
    int h= height();
    int w= width();

    positionBoat+=50;
    positionYMoon+=50;
    positionXMoon-=20;
    if(positionXMoon==-20)positionXMoon=100;
    if(positionYMoon==800)positionYMoon=500;
    positionXSun+=10;
    positionYSun-=20;
    if(positionYSun==200)positionYSun=200;
    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    Mountain(painter);
    Sea(painter);
    painter.setRenderHint(QPainter::Antialiasing);
    Boat(painter);
    Moon(painter);
    Sun(painter);
}

QPoint graphics::quay(QPoint p,QPoint c,int deta){
    QPoint pnew;
    double goc=deta*3.14/180;
    pnew.setX(c.x()+(p.x()-c.x())*cos(goc)-(p.y()-c.y())*sin(goc));
    pnew.setY(c.y()+(p.x()-c.x())*sin(goc)-(p.y()-c.y())*cos(goc));
    return pnew;
}
void graphics::Mountain(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));

    QString filename= "C:/xampp/htdocs/GitHub/DHMT/mountain.png";
    painter.drawPixmap(position,100,w,h/2,QPixmap(filename));
}
void graphics::Boat(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));
//Chạy tới vị trí 300 là kiểm tra điều kiện
//    if(positionBoat!=300)positionBoat+=50; else positionBoat-=50;
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/boat.png";
    painter.drawPixmap(positionBoat,300,100*1.7,100,QPixmap(filename));


 }

void graphics::Sea(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("blue"));
    painter.drawRect(0,325,w,100);
}

void graphics::Moon(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/moon.png";
    painter.drawPixmap(positionYMoon,positionXMoon,30*1.85,40,QPixmap(filename));

}
void graphics::Sun(QPainter& painter){
    int r= 100;
    int h= height();
    int w= width();
    QPoint pcenter;
    pcenter.setX(positionXSun);
    pcenter.setY(positionYSun);
    painter.drawEllipse(pcenter,20,20);
}
