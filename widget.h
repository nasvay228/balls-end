#ifndef WIDGET_H
#define WIDGET_H
#include "ball.h"
#include "player.h"
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

const int NUM = 15;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    ball * balls[NUM];
    bool started = false;
    int lifes = 5;
    player pudge;

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
protected slots:
    void moveAll();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
