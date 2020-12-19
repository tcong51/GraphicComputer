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
    QPoint quay(QPoint p,QPoint c,int deta);
    int mode=0;
    double position;
    double positionBoat;
    double positionXMoon;
    double positionYMoon;
    double positionXSun;
    double positionYSun;
    double timerId;
signals:

public slots:

};

#endif // GRAPHICS_H
