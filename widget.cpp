#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPainter>
#include <ctime>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->hide();
    setGeometry(50,50, 600, 600);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_W){
        pudge.peoples_move(0, -5);
    }
    if (e->key() == Qt::Key_A){
        pudge.peoples_move(-5, 0);
    }
    if (e->key() == Qt::Key_D){
        pudge.peoples_move(5, 0);
    }
    if (e->key() == Qt::Key_S){
        pudge.peoples_move(0, 5);
    }
}

void Widget::paintEvent(QPaintEvent *e){
    if (started){
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        for (int i = 0; i<NUM; i++){
            balls[i]->draw(painter);
        }
        pudge.draw(painter);
    }
}

void Widget::moveAll(){
    if(started){
        for (int i = 0; i<NUM; i++){
            balls[i]->move(width(),height());
            for (int j = 0; j<NUM; j++){
                if (i == j){
                    continue;
                }
                if (balls[j]->intersects(balls[i])){
                        balls[j]->revers();
                }
            }
            if (pudge.intersects(balls[i])){
                balls[i]->revers();
                lifes--;
            }
            ui->lcdNumber->display(lifes);
            if (lifes == 0){
                this->close();
            }
        }
    }
    this->repaint();
}

void Widget::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->lcdNumber->show();
    lifes = 15;
    for(int i=0; i<NUM; i++) {
        balls[i] = new ball(width(),height());
        ui->lcdNumber->display(lifes);
        started = true;



    }


    timer.setInterval(1000/60);
    timer.start();
    connect(&timer,SIGNAL(timeout()), this, SLOT(moveAll()));
}

void Widget::on_pushButton_2_clicked()
{
    this->close();
}
