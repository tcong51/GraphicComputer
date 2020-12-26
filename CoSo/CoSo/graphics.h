#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void thaiCuc(QPainter &painter, QPoint p, int x, int y);

    //Chỉ cần truyền vị trí và kích thước cần vẽ là được
    void moon(QPainter &painter, QPoint p, int size);
    void cloud(QPainter &painter, QPoint p, int size);
    void boat(QPainter &painter, QPoint p, int size);
    void star(QPainter &painter, QPoint p, int size);
    QPoint tinhtien(QPoint p, int tx, int ty);
    QPoint quay(QPoint p, QPoint c, int deta);
    QPoint trungdiem(QPoint a, QPoint b);
    QPoint dichuyen(QPoint p, int kc, int huong);
    void timerEvent(QTimerEvent *);
    int timerId, position;
    int random(int n);
signals:

public slots:

};

#endif // GRAPHICS_H
