#ifndef GAMEWIDGET1_H
#define GAMEWIDGET1_H

#include <QWidget>//基础部件
#include <QPalette>//控件颜色，用来添加背景
#include <QIcon>//添加图片组合
#include <QPushButton>//按钮
#include <QPainter>//绘图
#include <QDebug>
#include <QTime>//时钟
#include <QTimer>//定时器
#include <QMessageBox>//消息框
#include <QKeyEvent>
#include <QLabel>//标签文字
#include <QFont>//字体
#include <QSound>//声音
class GameWidget1 : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget1(QWidget *parent = 0);//不能隐式调用
    ~GameWidget1();
    void paintEvent(QPaintEvent *);//画方格画蛇
    void keyPressEvent(QKeyEvent *);//方向按键
private:
    QPushButton *upbtn;//定义上下左右开始结束按键
    QPushButton *leftbtn;
    QPushButton *downbtn;
    QPushButton *rightbtn;
    QPushButton *startbtn;
    QPushButton *returnbtn;
    int direction;//定义方向
    int direction_two;
    int snake[100][2];
    int snake1[100][2];
    int snake_two[100][2];
    int snake1_two[100][2];
    int foodcount;
    int foodcount_two;
    QTimer *timer;
    QTimer *timer_two;
    int foodx,foody;
    int foodx1,foody1;
    int foodx2,foody2;
    int foodx3,foody3;
    int foodx4,foody4;
    int foodx5,foody5;
    int foodx6,foody6;
    int foodx7,foody7;
    int foodx8,foody8;
    int foodx9,foody9;
    int foodx10,foody10;
    int foodx11,foody11;
    int score;
    int score_two;
    int level;
    QLabel *scorelabel;
    QLabel *scorelabel_two;
    QLabel *levellabel;
    QLabel *scoreshow;
    QLabel *scoreshow_two;
    QLabel *levelshow;
    QString str1,str2,str3;
    QSound *sound;
    QSound *sound1;
signals:
    void UpSignal();
    void DownSignal();
    void LeftSignal();
    void RightSignal();
public slots:
    void upbtnSlot();
    void leftbtnSlot();
    void rightbtnSlot();
    void downbtnSlot();
    void startbtnSlot();
    void returnbtnSlot();
    void timeoutSlot();
};

#endif // GAMEWIDGET1_H
