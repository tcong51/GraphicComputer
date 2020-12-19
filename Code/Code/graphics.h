#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void Mountain(QPainter& painter);
    void Boat(QPainter& painter);
    void Sea(QPainter& painter);
    void timerEvent(QTimerEvent *);
    void Moon(QPainter& painter);
    void Sun(QPainter& paineter);
    void cloudBig(QPainter& painter,double x, double y,double sx,double sy);
    void cloudSmall(QPainter& painter,double x, double y,double sx,double sy);
    void Brid(QPainter& painter);
    QPoint quay(QPoint p,QPoint c,int deta);
    QPoint tinhtien(QPoint p,int tx,int ty);
    QPoint doixungy(QPoint p);
    QPoint doixungx(QPoint p);

    int mode=0;
    double position;
    double positionBoat;
    double positionXMoon;
    double positionYMoon;
    double positionXSun;
    double positionYSun;
    double positionXBrid;
    double positionYBrid;
    double timerId;
signals:

public slots:

};

#endif // GRAPHICS_H
