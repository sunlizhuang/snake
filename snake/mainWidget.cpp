#include "mainWidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)//刚进入的主界面类
{
    this->resize(1800,1000);//设置大小
    this->setMaximumSize(1800,1000);
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));//程序的图标图
    this->setWindowTitle("贪吃蛇");//标题
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/img/baxk2.png").scaled(this->size())));//画刷，将背景用图片填充
    this->setPalette(palette);

    startbtn=new QPushButton(this);//新建按钮
    //startbtn->setIcon(QIcon(":/new/prefix1/img/start.png"));//按钮图片
    startbtn->setIconSize(QSize(75,75));//按钮尺寸
    startbtn->setGeometry(QRect(500,680,130,75));//按钮位置
    startbtn->setFlat(true);


    startbtn1  =new QPushButton(this);//新建按钮
    //startbtn1->setIcon(QIcon(":/new/prefix1/img/start.png"));//按钮图片
    startbtn1->setIconSize(QSize(75,75));//按钮尺寸
    startbtn1->setGeometry(QRect(830,680,130,75));//按钮位置
    startbtn1->setFlat(true);


    exitbtn=new QPushButton(this);
   // exitbtn->setIcon(QIcon(":/new/prefix1/img/quit.png"));
    exitbtn->setIconSize(QSize(70,70));
    exitbtn->setGeometry(QRect(1180,680,130,70));
    exitbtn->setFlat(true);
    //设置说明标签
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(13);
    label=new QLabel(this);
    label->setText("游戏说明：贪吃蛇游戏可使用按钮或者w a s d控制蛇的走动");
    label->setFont(font);
    label->setGeometry(QRect(10,10,400,50));

    connect(exitbtn,SIGNAL(clicked()),this,SLOT(exitSlot()));
    connect(startbtn,SIGNAL(clicked()),this,SLOT(startSlot()));//将按钮和事件函数关联
    connect(startbtn1,SIGNAL(clicked()),this,SLOT(startSlot1()));//将按钮和事件函数关联

}

mainWidget::~mainWidget()
{
    delete startbtn;//删除按钮
    delete startbtn1;
    delete exitbtn;
}
void mainWidget::exitSlot()
{
    if(QMessageBox::question(this,"退出游戏","是否退出当前游戏",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        delete this;
        exit(0);
    }
}
void mainWidget::startSlot()
{

    g=new GameWidget(this);//新建游戏界面
    g->show();//显示游戏界面
}
void mainWidget::startSlot1()
{
    g1 =new GameWidget1(this);
    g1->show();
}
