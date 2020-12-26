#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void Mountain(QPainter& painter);
    void Sea(QPainter& painter);
    void Moon(QPainter& painter,QPoint p);
    void Brid(QPainter& painter);
    //------//Hàm cơ sở
    QPoint quay(QPoint p,QPoint c,int deta);
    QPoint tinhtien(QPoint p,int tx,int ty);
    QPoint trungdiem(QPoint a, QPoint b);
    int random(int n);
    int randomNM(int n,int m);
    //------//
    QPointF BD;
    void backGround(QPainter & painter);
    int boatPosition;
    int cloudFlyPosition1;
    int cloudFlyPosition2;
    int luminosity;
    int sunAngle;
    double positionXBrid;
    double positionYBrid;
    double timerId;
    int moonAngle;
    //update
   void thaiCuc(QPainter &painter, QPoint p, int x, int y);
   void sun(QPainter &painter, QPoint p, int size);
   void boat(QPainter &painter, QPoint p, int size);
   void cloud(QPainter &painter, QPoint p, int size);
   void star(QPainter &painter, QPoint p, int size);
signals:

public slots:

};

#endif // GRAPHICS_H
