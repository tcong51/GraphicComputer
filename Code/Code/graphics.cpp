#include "graphics.h"
#include <QPainter>
#include <QPoint>
#include <math.h>
#include <QTableWidgetItem>
#include <QPen>
#include <QString>
#include <QLineEdit>
#include <QStyleOption>
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
    positionXBrid=100;
    positionYBrid=100;
}
void graphics::timerEvent(QTimerEvent *){
    int h= height();
    int w= width();
    int r= 100;
//moveBoat
    positionBoat+=50;
//moveMoon
    positionYMoon+=50;
    positionXMoon-=20;
    if(positionXMoon==-20)positionXMoon=100;
    if(positionYMoon==800)positionYMoon=500;
//moveSun
    positionXSun+=10;
    positionYSun-=20;
    if(positionYSun==200)positionYSun=200;
  //moveBrid
    positionXBrid+=25;
    if(positionXBrid ==200)positionXBrid+=50,positionYBrid+=50;
    if(positionXBrid ==300)positionXBrid+=25,positionYBrid+=25;
    if(positionXBrid ==350)positionXBrid-=25,positionYBrid+=-25;
    if(positionXBrid ==325)positionXBrid+=40,positionYBrid+=0;
    if(positionXBrid ==390)positionXBrid-=30,positionYBrid-=30;
    if(positionXBrid ==360)positionXBrid+=50,positionYBrid+=0;
    if(positionXBrid ==435)positionXBrid-=60,positionYBrid-=60;

    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
//     painter.setPen(Qt::white);

    cloudBig(painter,300,130,70,50);
    cloudSmall(painter,650,200,20*1.4,20);
    Mountain(painter);
    cloudBig(painter,50,50,70,50);
    Sea(painter);
    painter.setRenderHint(QPainter::Antialiasing);
    Boat(painter);
    Moon(painter);
    Sun(painter);
    Brid(painter);


    ngansao(painter);
}

QPoint graphics::quay(QPoint p,QPoint c,int deta){
    QPoint pnew;
    double goc=deta*3.14/180;
    pnew.setX(c.x()+(p.x()-c.x())*cos(goc)-(p.y()-c.y())*sin(goc));
    pnew.setY(c.y()+(p.x()-c.x())*sin(goc)-(p.y()-c.y())*cos(goc));
    return pnew;
}
QPoint graphics::tinhtien(QPoint p,int tx,int ty){
    QPoint pnew;
    pnew.setX(p.x()+tx);
    pnew.setY(p.y()+ty);
    return pnew;
}
QPoint graphics::doixungy(QPoint p){
    QPoint pnew;
    pnew.setX(-p.x());
    pnew.setY(p.y());
    return pnew;
}
QPoint graphics::doixungx(QPoint p){
    QPoint pnew;
    pnew.setX(p.x());
    pnew.setY(-p.y());
    return pnew;
}

void graphics::Mountain(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));

    QString filename= "C:/xampp/htdocs/GitHub/DHMT/mountain.png";
    painter.drawPixmap(position,130,w,h/2,QPixmap(filename));
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
    painter.setPen(Qt::blue);
    painter.drawRect(0,325,w,100);
}

void graphics::Moon(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setPen(Qt::yellow);
    painter.setBrush(QBrush("#b40000"));
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/moon.png";
    painter.drawPixmap(positionYMoon,positionXMoon,30*1.85,40,QPixmap(filename));

}
void graphics::cloudBig(QPainter &painter,double x, double y,double sx,double sy){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("white"));
    painter.setPen(Qt::white);
    //vị trí mặc định là 100,100
    QPoint pointCloud(x,y);
    //sx =70,sy=50
    //vẽ bằng ellipse
    painter.drawEllipse(pointCloud.x(),pointCloud.y(),sx,sy);
    //sx1=100.,sy1=50
    painter.drawEllipse(pointCloud.x()+35,pointCloud.y()-25,100,sy);
    painter.drawEllipse(pointCloud.x()+100,pointCloud.y(),sx,sy);
    painter.drawEllipse(pointCloud.x()+35,pointCloud.y()+25,100,sy);
    //vẽ bằng drawChord nữa cung tròn
     //    painter.drawChord(pointCould.x(),pointCould.y(),sx,sy,(90*16),(180*16));//nữa hình tròn
     //    painter.drawChord(pointCould.x(),pointCould.y(),sx,sy,(90*16),-(180*16));//nữa hình tròn
     //    painter.drawChord(pointCloud.x()+35,pointCloud.y()-25,100,sy,0,(180*16));
     //     painter.drawChord(pointCloud.x()+35,pointCloud.y()-25,100,sy,0,-(180*16));
     //    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),-(180*16));
     //    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),+(180*16));
     //    painter.drawChord(pointCloud.x()+35,pointCloud.y()+25,100,sy,0,-(180*16));
     //    painter.drawChord(pointCloud.x()+35,pointCloud.y()+25,100,sy,0,+(180*16));
}
void graphics::cloudSmall(QPainter &painter,double x, double y,double sx,double sy){

    //vị trí mặc định là 100,100
    QPoint pointCloud(x,y);
    //sx =70,sy=50
    painter.drawEllipse(pointCloud.x(),pointCloud.y(),sx,sy);
//    painter.drawChord(pointCloud.x(),pointCloud.y(),sx,sy,(90*16),(180*16));//nữa hình tròn
//    painter.drawChord(pointCloud.x(),pointCloud.y(),sx,sy,(90*16),-(180*16));
    painter.drawEllipse(pointCloud.x()+15,pointCloud.y()-10,80,sy);
//    painter.drawChord(pointCloud.x()+15,pointCloud.y()-10,100,sy,0,(180*16));
//    painter.drawChord(pointCloud.x()+15,pointCloud.y()-10,100,sy,0,-(180*16));
    painter.drawEllipse(pointCloud.x()+80,pointCloud.y(),sx,sy);
//    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),-(180*16));
//    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),(180*16));
    painter.drawEllipse(pointCloud.x()+15,pointCloud.y()+10,80,sy);
//    painter.drawChord(pointCloud.x()+15,pointCloud.y()+10,100,sy,0,-(180*16));
//     painter.drawChord(pointCloud.x()+15,pointCloud.y()+10,100,sy,0,(180*16));

}
void graphics::Sun(QPainter& painter){
    int r= 100;
    int h= height();
    int w= width();
    QPoint pcenter;
    painter.setBrush(QBrush("yellow"));
    pcenter.setX(positionXSun);
    pcenter.setY(positionYSun);
    painter.drawEllipse(pcenter,20,20);
}
void graphics::Brid(QPainter& painter){
    QPoint P(positionXBrid,positionYBrid);
    //bridFirst
    QString bridFirst = "C:/xampp/htdocs/GitHub/DHMT/wing.png";
    painter.drawPixmap(P.x(),P.y(),20*(258/183),20,QPixmap(bridFirst));
    QString bridFirstContinue = "C:/xampp/htdocs/GitHub/DHMT/wing.png";
    painter.drawPixmap(P.x()+18*(258/183),P.y(),20*(258/183),20,QPixmap(bridFirstContinue));
    //bridSecond
    QPoint PSecond(positionXBrid+25,positionYBrid+25);
    QString bridSecond =  "C:/xampp/htdocs/GitHub/DHMT/wing.png";
    painter.drawPixmap(PSecond.x(),PSecond.y(),20*(258/153),20,QPixmap(bridSecond));
    QString bridSecondContinue =  "C:/xampp/htdocs/GitHub/DHMT/wing.png";
    painter.drawPixmap(PSecond.x()+18*(253/183),PSecond.y(),20*(258/153),20,QPixmap(bridSecondContinue));
}

//Random số
int graphics::random(int n)
   {
       return rand() % n;
   }

//Bầu trời sao, chưa viết đc sao 4 cánh chớp.
void graphics::ngansao(QPainter& painter){
    int h= height();
    int w= width();
    for(int i=1;i<=1000;i++){
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(random(255),random(255),random(255)));
        painter.drawEllipse(random(1000),random(300),3,3);
    }

}



