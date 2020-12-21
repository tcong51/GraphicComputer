#include "graphics.h"
#include <QPainter>
#include <QBrush>
#include "math.h"
#include <QPointF>
graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position=0;
    timerId=startTimer(100);
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPoint p(300, 300);
//    moon(painter, p, 70);
//    boat(painter, p, 350);
    star(painter, p, 70);
}
void graphics::timerEvent(QTimerEvent *){
    position+=15;
    repaint();
}

int graphics::random(int n){
    return rand()%n;
}

QPoint graphics::tinhtien(QPoint p, int tx, int ty){
    QPoint pnew;
    pnew.setX(p.x()+tx);
    pnew.setY(p.y()+ty);
    return pnew;
}

QPoint graphics:: quay(QPoint p, QPoint c, int deta){
    double goc=deta*3.14/180;
    QPoint pnew;
    pnew.setX(c.x()+(p.x()-c.x())*cos(goc)-(p.y()-c.y())*sin(goc));
    pnew.setY(c.y()+(p.x()-c.x())*sin(goc)+(p.y()-c.y())*cos(goc));
    return pnew;
}

QPoint graphics::trungdiem(QPoint a, QPoint b){
    QPoint pnew((a.x()+b.x())/2, (a.y()+b.y())/2);
    return pnew;
}

QPoint graphics::dichuyen(QPoint p, int kc, int huong){
    QPoint pnew;
    double goc=huong*M_PI/180;
    pnew.setX(p.x()+kc*cos(goc));
    pnew.setY(p.y()+kc*sin(goc));
    return pnew;
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

void graphics::moon(QPainter &painter, QPoint p, int size){
//    painter.setPen(QPen('#ffffff'));
    painter.setPen(Qt::DashDotDotLine);
    painter.drawEllipse(p, size+position, size+position);
    painter.drawEllipse(p, size+position/2, size+position/2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(p, size-20, size-20);
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
