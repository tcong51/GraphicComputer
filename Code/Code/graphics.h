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
    void mountain(QPainter& painter);
    void sea(QPainter& painter);
    void moon(QPainter& painter,QPoint p);
    void bird(QPainter& painter, QPoint p);
    QPoint quay(QPoint p,QPoint c,int deta);
    QPoint trungdiem(QPoint a, QPoint b);
    int random(int n);
    int randomNM(int n,int m);
    void backGround(QPainter & painter);
    void thaiCuc(QPainter &painter, QPoint p, int x, int y);
    void sun(QPainter &painter, QPoint p, int size);
    void boat(QPainter &painter, QPoint p, int size);
    void cloud(QPainter &painter, QPoint p, int size);
    void star(QPainter &painter, QPoint p, int size);
    int speedOfBoat;
    int speedOfBird;
    int speedOfCloud1;
    int speedOfCloud2;
    int luminosity;
    int sunAngle;
    double timerId;
    int moonAngle;
signals:

public slots:

};

#endif // GRAPHICS_H
