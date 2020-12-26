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
    timerId=startTimer(250);
    luminosity=0;
    sunAngle =0;
    moonAngle =180;
    positionXBrid=100;
    positionYBrid=100;
    boatPosition=0;

}
void graphics::timerEvent(QTimerEvent *){
//moveBoat
    boatPosition+=5;
    cloudFlyPosition1 +=10;
    cloudFlyPosition2 +=8;
    if(luminosity==30*45){
        luminosity = 0;
    }
    else{
        luminosity +=30;
    }
    sunAngle +=4;
    moonAngle-=4;
  //moveBrid
    positionXBrid+=20;
    if(positionXBrid ==200)positionXBrid+=50,positionYBrid+=50;
    if(positionXBrid ==300)positionXBrid+=25,positionYBrid+=25;
    if(positionXBrid ==350)positionXBrid-=25,positionYBrid+=-25;
    if(positionXBrid ==325)positionXBrid+=40,positionYBrid+=0;
    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    backGround(painter);
    for(int i=1;i<=1000;i++){
        int w =370;
        QPoint p(i+1,random(w));
        star(painter,p,2);
        i+=10;
    }
    painter.setBrush(QBrush("#8787ff"));
    QPoint sunP(0,height());
    QPoint O(width()/2,height());
    sunP = quay(sunP,O,sunAngle);
    sun(painter,sunP,50);
    Sea(painter);
    QPoint cloud1(300,130);
    cloud1.setX(cloud1.x()+ cloudFlyPosition1);
    QPoint cloud2(650,200);
    QPoint cloud3(450,50);
    QPoint cloud4(280,130);
    QPoint cloud5(50,50);
    QPoint cloud6(60,70);
    cloud6.setX(cloud6.x()+ cloudFlyPosition2);
    cloud(painter,cloud1,40);
    cloud(painter,cloud2,40);
    cloud(painter,cloud3,60);
    cloud(painter,cloud4,35);
    cloud(painter,cloud5,40);
    cloud(painter,cloud6,50);
    Mountain(painter);
    painter.setRenderHint(QPainter::Antialiasing);
    QPoint boatP(0,370);
    boatP.setX(boatP.x()+ boatPosition);
    boat(painter,boatP,150);
    Brid(painter);
}

QPoint graphics::quay(QPoint p,QPoint c,int deta){
    QPoint pnew;
    double goc=deta*3.14/180;
    pnew.setX(c.x()+(p.x()-c.x())*cos(goc)-(p.y()-c.y())*sin(goc));
    pnew.setY(c.y()+(p.x()-c.x())*sin(goc)-(p.y()-c.y())*cos(goc));
    return pnew;
}

QPoint graphics::trungdiem(QPoint a, QPoint b){
    QPoint pnew((a.x()+b.x())/2, (a.y()+b.y())/2);
    return pnew;
}

void graphics::Mountain(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));
    QString filename= "C:/xampp/htdocs/GitHub/DHMT/mountain.png";
    painter.drawPixmap(10,175,w-20,h/2,QPixmap(filename));
}

void graphics::Moon(QPainter &painter , QPoint p){
    painter.setPen(Qt::yellow);
    painter.setBrush(QBrush("#b40000"));
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/moon.png";
    painter.drawPixmap(p.x(),p.y(),30*1.85,40,QPixmap(filename));

}
void graphics::Sea(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#8787ff"));
    painter.drawRect(0,h-30,w,100);
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
void graphics::backGround(QPainter & painter){
    int h =height();
    int w = width();
    painter.setBrush(QBrush("#8787af"));
    painter.drawRect(0,0,w,h);
}
//Random số
int graphics::random(int n)
   {
       return rand() % n;
   }
int graphics::randomNM(int n,int m){
    return rand()% m+n;
}
void graphics::cloud(QPainter &painter, QPoint p, int size){
    painter.setBrush(Qt::white);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(p.x(), p.y(), size, size);
    painter.drawEllipse(p.x()+size/2, p.y(), size, size);
    painter.drawEllipse(p.x()+size/2, p.y()+size/2, size, size);
    painter.drawEllipse(p.x()+size, p.y()+size/2, size, size);
    painter.drawEllipse(p.x()+size, p.y(), size, size);
    painter.drawEllipse(p.x()+2/3*size, p.y()+size/2, size, size);
    painter.drawEllipse(p.x()+1.8*size, p.y()+size/3, size, size);
    painter.drawEllipse(p.x()-size/3, p.y()+size/3, size, size);
}
void graphics::star(QPainter &painter, QPoint p, int size){
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(random(255), random(255), random(255)));
    QPolygon starWing1_1;
    QPoint a(p.x()-size*sqrt(3)/2, p.y()-size/2);
    QPoint b(p.x()-size*sqrt(3)/2, p.y()+size/2);
    QPoint c(p.x()-size*sqrt(3)/2-2*size, p.y());
    starWing1_1.push_back(p);
    starWing1_1.push_back(a);
    starWing1_1.push_back(b);
    painter.drawPolygon(starWing1_1);
    QPolygon starWing1_2;
    starWing1_2.push_back(a);
    starWing1_2.push_back(b);
    starWing1_2.push_back(c);
    painter.drawPolygon(starWing1_2);

    for(int i=0; i<3; i++){
        QPolygon points1, points2;
        a=quay(a, p, 90);
        b=quay(b, p, 90);
        c=quay(c, p, 90);
        points1.push_back(p);
        points1.push_back(a);
        points1.push_back(b);
        points2.push_back(a);
        points2.push_back(b);
        points2.push_back(c);
        painter.drawPolygon(points1);
        painter.drawPolygon(points2);
    }
}

void graphics::boat(QPainter &painter, QPoint p, int size){
    QPolygon points;
    points.push_back(p);
    QPoint a(p.x()+size, p.y());
    QPoint b(p.x()+size*4/5, p.y()+size/7);
    QPoint c(p.x()+size*1/5, p.y()+size/7);
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    painter.setBrush(QBrush('#715842'));
    painter.drawPolygon(points);

    //Cot buom
    QPoint dinhCotBuom=trungdiem(p,a);
    dinhCotBuom.setY(dinhCotBuom.y()-size*3/5);
    painter.setBrush(QBrush('#353847'));
    painter.drawRect(dinhCotBuom.x(), dinhCotBuom.y(), size/30, size/1.75);

    //Canh buom
    QPolygon canhBuom1;
    canhBuom1.push_back(QPoint(dinhCotBuom.x()-size/70, dinhCotBuom.y()+size/23));
    canhBuom1.push_back(QPoint(dinhCotBuom.x()-size/70, dinhCotBuom.y()+size*2/5));
    canhBuom1.push_back(QPoint(dinhCotBuom.x()-size/5, dinhCotBuom.y()+size*2/5));
    painter.setBrush(QBrush('##24b4ec'));
    painter.drawPolygon(canhBuom1);

    QPolygon canhBuom2;
    canhBuom2.push_back(QPoint(dinhCotBuom.x()+size/23, dinhCotBuom.y()+50));
    canhBuom2.push_back(QPoint(dinhCotBuom.x()+size/23, dinhCotBuom.y()+size*0.5));
    canhBuom2.push_back(QPoint(dinhCotBuom.x()+size/4, dinhCotBuom.y()+size*0.5));
    painter.drawPolygon(canhBuom2);

    //Co
    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(dinhCotBuom.x()+size/25, dinhCotBuom.y(), size/7, size/9);
    QPoint hinhCo(dinhCotBuom.x()+size/25+size/27, dinhCotBuom.y()+size/27);
    thaiCuc(painter, hinhCo, size/17, size/17);
    //Di chuyen

}
void graphics::sun(QPainter &painter, QPoint p, int size){
//    painter.setPen(QPen('#ffffff'));
    if(p.y()>height()){
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::NoBrush);
        luminosity=0;
        QPoint C(width()/2,0);
        QPoint moon(width()/2-200,0);
        moon=quay(moon,C,moonAngle);
        Moon(painter,moon);

    }
    else{
        painter.drawEllipse(p, size+ luminosity, size+luminosity);
        painter.drawEllipse(p, size+luminosity/2, size+luminosity/2);
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(p, size-20, size-20);
    }
}
void graphics::thaiCuc(QPainter &painter, QPoint p, int x, int y){
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::black));
    painter.drawChord(p.x(),p.y(), x, y, 16*0, 16*180);
    painter.setBrush(QBrush(Qt::white));
    painter.drawChord(p.x(),p.y(), x, y, 16*180, 16*180);
    QPoint a,b;
    a.setX(p.x()+x/4);
    a.setY(p.y()+y/2);
    b.setX(p.x()+3*x/4);
    b.setY(p.y()+y/2);
    painter.setBrush(QBrush(Qt::white));
    painter.drawChord(p.x(), p.y()+y/4, x/2, y/2, 16*0, 16*180);
    painter.setBrush(QBrush(Qt::black));
    painter.drawChord(p.x()+x/2, p.y()+y/4, x/2, y/2, 16*180, 16*180);
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(a, x/20, x/20);
    painter.setBrush(QBrush(Qt::white));
    painter.drawEllipse(b, x/20, x/20);
}
