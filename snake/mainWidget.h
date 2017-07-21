#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "GameWidget.h"
#include "GameWidget1.h"
#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();
    //void resizeEvent(QResizeEvent *);
private:
    QPushButton *startbtn;//开始与结束按钮
    QPushButton *startbtn1;
    QPushButton *exitbtn;
    GameWidget *g;//游戏
    GameWidget1 *g1;
    QLabel *label;//文字标签
signals:
public slots:
    void exitSlot();//退出与开始的事件函数
    void startSlot();
    void startSlot1();
};

#endif // MAINWIDGET_H
