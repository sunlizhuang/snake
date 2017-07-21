#include "GameWidget1.h"
#define ROW 50
#define COL 70
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_TWO 0
#define DOWN_TWO 1
#define LEFT_TWO 2
#define RIGHT_TWO 3
GameWidget1::GameWidget1(QWidget *parent) : QWidget(parent)//游戏部件，右部分
{
    this->setAutoFillBackground(true);//将游戏界面全屏显示
    this->setWindowTitle("游戏开始");
    this->setWindowIcon(QIcon(":/new/prefix1/img/1.png"));
    this->resize(1800,1000);
    this->setMaximumSize(1800,1000);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/img/diyu.png").scaled(this->size())));
    this->setPalette(palette);
    //声音区
    sound=new QSound(":/listen/img/5611.wav");
    sound1=new QSound(":/listen/img/5611.wav");
    //按钮区
    upbtn=new QPushButton("↑",this);
    upbtn->setGeometry(QRect(1480,90,0,0));//设置大小，前两个为距离左边框距离和上边框距离，后两个为x长度和y长度

    leftbtn=new QPushButton("←",this);
    leftbtn->setGeometry(QRect(1440,13,0,0));

    rightbtn=new QPushButton("→",this);
    rightbtn->setGeometry(QRect(1520,130,0,0));

    downbtn=new QPushButton("↓",this);
    downbtn->setGeometry(QRect(1480,170,0,0));

    startbtn=new QPushButton("",this);
    startbtn->setGeometry(QRect(1470,870,80,30));
    startbtn->setFlat(true);

    returnbtn=new QPushButton("",this);
    returnbtn->setGeometry(QRect(1670,870,80,30));
    returnbtn->setFlat(true);

    //设置分数等级为0
    score=0;
    score_two=0;
    level=0;
    //显示分数等级标签区
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(19);

    scorelabel=new QLabel("玩家1分数:",this);
    scorelabel->setFont(font);
    scorelabel->setGeometry(QRect(1425,1,120,30));

    scorelabel_two=new QLabel("玩家2分数:",this);
    scorelabel_two->setFont(font);
    scorelabel_two->setGeometry(QRect(1425,20,120,30));

    levellabel=new QLabel("等级:",this);
    levellabel->setFont(font);
    levellabel->setGeometry(QRect(1425,30,0,0));

    str1=QString::number(score);
    str2=QString::number(level);

    str3=QString::number(score_two);

    scoreshow=new QLabel(this);
    scoreshow->setFont(font);
    scoreshow->setGeometry(QRect(1700,1,60,30));
    scoreshow->setText(str1);

    scoreshow_two=new QLabel(this);
    scoreshow_two->setFont(font);
    scoreshow_two->setGeometry(QRect(1700,20,60,30));
    scoreshow_two->setText(str3);

    levelshow=new QLabel(this);
    levelshow->setFont(font);
    levelshow->setGeometry(QRect(1485,30,0,0));
    levelshow->setText(str2);
    //设置按钮操作
    connect(leftbtn,SIGNAL(clicked()),this,SLOT(leftbtnSlot()));
    connect(rightbtn,SIGNAL(clicked()),this,SLOT(rightbtnSlot()));
    connect(upbtn,SIGNAL(clicked()),this,SLOT(upbtnSlot()));
    connect(downbtn,SIGNAL(clicked()),this,SLOT(downbtnSlot()));
    connect(startbtn,SIGNAL(clicked()),this,SLOT(startbtnSlot()));
    connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    //设置键盘操作
    connect(this,SIGNAL(UpSignal()),upbtn,SLOT(click()));
    connect(this,SIGNAL(DownSignal()),downbtn,SLOT(click()));
    connect(this,SIGNAL(LeftSignal()),leftbtn,SLOT(click()));
    connect(this,SIGNAL(RightSignal()),rightbtn,SLOT(click()));
    foodcount=0;
    foodcount_two=0;
     //设置随机数
    int i=1;
    QTime t;
    t= QTime::currentTime();
    qsrand(t.msec()+t.second()*100);
    snake[0][0]=qrand()%COL;//蛇头x
    snake[0][1]=qrand()%ROW;//蛇头y
    foodx=qrand()%COL;//食物x
    foody=qrand()%ROW;//食物y
    foodx1=qrand()%COL;
    foody1=qrand()%ROW;
    foodx2=qrand()%COL;
    foody2=qrand()%ROW;
    foodx3=qrand()%COL;
    foody3=qrand()%ROW;
    foodx4=qrand()%COL;
    foody4=qrand()%ROW;
    foodx5=qrand()%COL;
    foody5=qrand()%ROW;
    foodx6=qrand()%COL;
    foody6=qrand()%ROW;
    foodx7=qrand()%COL;
    foody7=qrand()%ROW;
    foodx8=qrand()%COL;
    foody8=qrand()%ROW;
    foodx9=qrand()%COL;
    foody9=qrand()%ROW;
    foodx10=qrand()%COL;
    foody10=qrand()%ROW;
    foodx11=qrand()%COL;
    foody11=qrand()%ROW;
    direction=qrand()%4;//方向

    timer=new QTimer(this);
    timer->setInterval(130);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));
    int i_two=1;
    snake_two[0][0]=qrand()%COL;
    snake_two[0][1]=qrand()%ROW;
    direction_two=qrand()%4;

}

GameWidget1::~GameWidget1()
{
    delete startbtn;
    delete returnbtn;
    delete leftbtn;
    delete rightbtn;
    delete upbtn;
    delete downbtn;
    delete timer;
    delete sound;
    delete sound1;
}
void GameWidget1::upbtnSlot()
{
    if(direction==DOWN)
        return;
    else
    {
    direction=UP;
    }
}

void GameWidget1::downbtnSlot()
{
    if(direction==UP)
        return;
    else
    {
   direction=DOWN;
    }
}

void GameWidget1::leftbtnSlot()
{
    if(direction==RIGHT)
        return;
    else
    {
    direction=LEFT;
    }
}

void GameWidget1::rightbtnSlot()
{
    if(direction==LEFT)
        return;
    else
    {
    direction=RIGHT;
    }
}

void GameWidget1::startbtnSlot()
{
    timer->start();
}

void GameWidget1::returnbtnSlot()
{
    delete this;
}

void GameWidget1::timeoutSlot()
{
    //判断是否吃到食物
   if(snake[0][0]==foodx&&snake[0][1]==foody)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx=qrand()%COL;
        foody=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx&&snake[i][1]==foody)
            {
                foodx=qrand()%COL;
                foody=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }


   if(snake[0][0]==foodx1&&snake[0][1]==foody1)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx1=qrand()%COL;
        foody1=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx1&&snake[i][1]==foody1)
            {
                foodx1=qrand()%COL;
                foody1=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx2&&snake[0][1]==foody2)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx2=qrand()%COL;
        foody2=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx2&&snake[i][1]==foody2)
            {
                foodx2=qrand()%COL;
                foody2=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx3&&snake[0][1]==foody3)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx3=qrand()%COL;
        foody3=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx3&&snake[i][1]==foody)
            {
                foodx3=qrand()%COL;
                foody3=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx4&&snake[0][1]==foody4)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx4=qrand()%COL;
        foody4=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx4&&snake[i][1]==foody4)
            {

                foodx1=qrand()%COL;
                foody1=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx5&&snake[0][1]==foody5)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx5=qrand()%COL;
        foody5=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx5&&snake[i][1]==foody5)
            {

                foodx1=qrand()%COL;
                foody1=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx6&&snake[0][1]==foody6)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx6=qrand()%COL;
        foody6=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx6&&snake[i][1]==foody6)
            {

                foodx1=qrand()%COL;
                foody1=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx7&&snake[0][1]==foody7)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx7=qrand()%COL;
        foody7=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx7&&snake[i][1]==foody7)
            {

                foodx1=qrand()%COL;
                foody1=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx8&&snake[0][1]==foody8)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx8=qrand()%COL;
        foody8=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx8&&snake[i][1]==foody8)
            {

                foodx8=qrand()%COL;
                foody8=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx9&&snake[0][1]==foody9)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx9=qrand()%COL;
        foody9=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx9&&snake[i][1]==foody9)
            {

                foodx1=qrand()%COL;
                foody1=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx10&&snake[0][1]==foody10)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx10=qrand()%COL;
        foody10=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx10&&snake[i][1]==foody10)
            {

                foodx10=qrand()%COL;
                foody10=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
   if(snake[0][0]==foodx11&&snake[0][1]==foody11)
    {
       //吃到食物发出声音
       sound->play();
        //如果吃到食物，食物坐标更新
       int i=0;
        foodcount++;
        score++;
        str1=QString::number(score);
        scoreshow->setText(str1);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx11=qrand()%COL;
        foody11=qrand()%ROW;
        while(i<=foodcount)
        {
            i++;
            //判断食物是否出现在蛇身上，如果出现在蛇身上重新产生食物
            if(snake[i][0]==foodx11&&snake[i][1]==foody11)
            {

                foodx11=qrand()%COL;
                foody11=qrand()%ROW;
                i=0;
            }
        }
        switch(score)
        {
        case 1:timer->setInterval(130);level++;break;
        case 10:timer->setInterval(130);level++;break;
        case 20:timer->setInterval(130);level++;break;
        case 30:timer->setInterval(130);level++;break;
        }
    }
    //memcpy(snake1,snake,sizeof(snake));
    ///////////////////////////
    //判断蛇2是否吃到食物
    if(snake_two[0][0]==foodx&&snake_two[0][1]==foody)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx=qrand()%COL;
        foody=qrand()%ROW;
    }

    if(snake_two[0][0]==foodx1&&snake_two[0][1]==foody1)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx1=qrand()%COL;
        foody1=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx2&&snake_two[0][1]==foody2)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx2=qrand()%COL;
        foody2=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx3&&snake_two[0][1]==foody3)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx3=qrand()%COL;
        foody3=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx4&&snake_two[0][1]==foody4)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx4=qrand()%COL;
        foody4=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx5&&snake_two[0][1]==foody5)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx5=qrand()%COL;
        foody5=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx6&&snake_two[0][1]==foody6)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx6=qrand()%COL;
        foody6=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx7&&snake_two[0][1]==foody7)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx7=qrand()%COL;
        foody7=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx8&&snake_two[0][1]==foody8)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx8=qrand()%COL;
        foody8=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx9&&snake_two[0][1]==foody9)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx9=qrand()%COL;
        foody9=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx10&&snake_two[0][1]==foody10)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx10=qrand()%COL;
        foody10=qrand()%ROW;
    }
    if(snake_two[0][0]==foodx11&&snake_two[0][1]==foody11)
    {
        sound->play();
        int i_two=0;
        foodcount_two++;
        score_two++;
        str3=QString::number(score_two);
        scoreshow_two->setText(str3);
        QTime t;
        t= QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        foodx11=qrand()%COL;
        foody11=qrand()%ROW;
    }


    /////////////////////
    //实现蛇1的游动
    for(int i=foodcount;i>=1;i--)
    {
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }

    switch(direction)
    {
    case UP:snake[0][1]--;break;
    case DOWN:snake[0][1]++;break;
    case LEFT:snake[0][0]--;break;
    case RIGHT:snake[0][0]++;break;
    }
    //蛇2的游动
    for (int i_two=foodcount_two;i_two>=1;i_two--)
    {
        snake_two[i_two][0]=snake_two[i_two-1][0];
        snake_two[i_two][1]=snake_two[i_two-1][1];
    }
    switch(direction_two)
    {
    case UP_TWO:snake_two[0][1]--;break;
    case DOWN_TWO:snake_two[0][1]++;break;
    case LEFT_TWO:snake_two[0][0]--;break;
    case RIGHT_TWO:snake_two[0][0]++;break;
    }
//判断蛇头是否对撞

for (int i =1;i<=foodcount;i++){
    if(snake_two[0][0]==snake[i][0]&&snake_two[0][1]==snake[i][1]){
        sound1->play();
        if(QMessageBox::question(this,"提示","玩家2被击杀",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
                      {
                      delete this;
                       return ;
                      }
    }
}


for (int i =1;i<=foodcount_two;i++){
    if(snake[0][0]==snake_two[i][0]&&snake[0][1]==snake_two[i][1]){
        sound1->play();
        if(QMessageBox::question(this,"提示","玩家1被击杀",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
                      {
                      delete this;
                       return ;
                      }
    }
}





    //判断蛇是否撞到墙体
    if(snake[0][0]<0||snake[0][0]>=COL||snake[0][1]<0||snake[0][1]>=ROW)
    {
        sound1->play();
      //  memcpy(snake,snake1,sizeof(snake));
       timer->stop();
       if(QMessageBox::question(this,"提示","玩家1撞墙，玩家2胜利！",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
      {delete this;
       return ;}

    }
   if(snake_two[0][0]<0||snake_two[0][0]>=COL||snake_two[0][1]<0||snake_two[0][1]>=ROW){
       sound1->play();
     //  memcpy(snake,snake1,sizeof(snake));
      timer->stop();
      if(QMessageBox::question(this,"提示","玩家2撞墙，玩家1胜利！",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
     {delete this;
      return ;}
       }
    this->update();
}
void GameWidget1::paintEvent(QPaintEvent *)
{
    //画方格
    QPainter painter(this);
    painter.setPen(Qt::red);
    QPainter painter_two(this);
// for(int i=0;i<ROW*20;i+=20)
//        for(int j=0;j<COL*20;j+=20){
//         painter.setPen(Qt::red);
//        painter.drawRect(j,i,20,20);
//        }
//    painter.setPen(Qt::red);
//painter.drawRect(0,0,COL*20,ROW*20);

    //画食物
    painter.drawImage(foodx*20,foody*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx1*20,foody1*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx2*20,foody2*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx3*20,foody3*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx4*20,foody4*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx5*20,foody5*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx6*20,foody6*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx7*20,foody7*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    painter.drawImage(foodx8*20,foody8*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
     painter.drawImage(foodx9*20,foody9*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
      painter.drawImage(foodx10*20,foody10*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
       painter.drawImage(foodx11*20,foody11*20,QImage(":/new/prefix1/img/apple.png").scaled(QSize(20,20)));
    //画蛇头1

    switch(direction)
    {
    case UP:painter.drawImage(snake[0][0]*20,snake[0][1]*20,QImage(":/new/prefix1/img/headup.png").scaled(QSize(20,20)));break;//蛇头向上
    case DOWN:painter.drawImage(snake[0][0]*20,snake[0][1]*20,QImage(":/new/prefix1/img/headdown.png").scaled(QSize(20,20)));break;//蛇头向下
    case LEFT:painter.drawImage(snake[0][0]*20,snake[0][1]*20,QImage(":/new/prefix1/img/headleft.png").scaled(QSize(20,20)));break;//蛇头向下
    case RIGHT:painter.drawImage(snake[0][0]*20,snake[0][1]*20,QImage(":/new/prefix1/img/headright.png").scaled(QSize(20,20)));break;//蛇头向下
    }
    //画蛇头2
    switch (direction_two) {
    case UP_TWO:painter_two.drawImage(snake_two[0][0]*20,snake_two[0][1]*20,QImage(":/new/prefix1/img/headup2.png").scaled(QSize(25,25)));break;//蛇头向上
    case DOWN_TWO:painter_two.drawImage(snake_two[0][0]*20,snake_two[0][1]*20,QImage(":/new/prefix1/img/headdown2.png").scaled(QSize(25,25)));break;//蛇头向下
    case LEFT_TWO:painter_two.drawImage(snake_two[0][0]*20,snake_two[0][1]*20,QImage(":/new/prefix1/img/headleft2.png").scaled(QSize(25,25)));break;//蛇头向下
    case RIGHT_TWO:painter_two.drawImage(snake_two[0][0]*20,snake_two[0][1]*20,QImage(":/new/prefix1/img/headright2.png").scaled(QSize(25,25)));break;//蛇头向下
    }

    //画蛇身1
    for(int i=1;i<=foodcount;i++)
    {
        if(i!=foodcount)
        {
        if((snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]-1&&
           snake[i][0]==snake[i+1][0]-1&&snake[i][1]==snake[i+1][1])||
           (snake[i][0]==snake[i-1][0]-1&&snake[i][1]==snake[i-1][1]&&
            snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]-1))
            painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/tl_corner.png").scaled(QSize(20,20)));
           else if((snake[i][0]==snake[i-1][0]-1&&snake[i][1]==snake[i-1][1]&&
                    snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]+1)||
                    (snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]+1&&
                     snake[i][0]==snake[i+1][0]-1&&snake[i][1]==snake[i+1][1]))
            painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/bl_corner.png").scaled(QSize(20,20)));
           else if((snake[i][0]==snake[i-1][0]+1&&snake[i][1]==snake[i-1][1]&&
                    snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]-1)||
                    (snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]-1&&
                     snake[i][0]==snake[i+1][0]+1&&snake[i][1]==snake[i+1][1]))
            painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/tr_corner.png").scaled(QSize(20,20)));
           else if((snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]+1&&
                    snake[i][0]==snake[i+1][0]+1&&snake[i][1]==snake[i+1][1])||
                    (snake[i][0]==snake[i-1][0]+1&&snake[i][1]==snake[i-1][1]&&
                     snake[i][0]==snake[i+1][0]&&snake[i][1]==snake[i+1][1]+1))
            painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/br_corner.png").scaled(QSize(20,20)));
           else if(snake[i][1]==snake[i-1][1]&&snake[i][0]!=snake[i-1][0])
          painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/h_body.png").scaled(QSize(20,20)));
           else if(snake[i][0]==snake[i-1][0]&&snake[i][1]!=snake[i-1][1])
            painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/v_body.png").scaled(QSize(20,20)));
        }
        else
        {
            //画蛇尾
            if(snake[i][0]==snake[i-1][0]+1&&snake[i][1]==snake[i-1][1])
                painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/tailleft.png").scaled(QSize(20,20)));
            else if(snake[i][0]==snake[i-1][0]-1&&snake[i][1]==snake[i-1][1])
                painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/tailright.png").scaled(QSize(20,20)));
            else if(snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]-1)
                painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/taildown.png").scaled(QSize(20,20)));
             else if(snake[i][0]==snake[i-1][0]&&snake[i][1]==snake[i-1][1]+1)
                painter.drawImage(snake[i][0]*20,snake[i][1]*20,QImage(":/new/prefix1/img/tail.png").scaled(QSize(20,20)));
        }
    }

    //画蛇身2////////////////////////////////////
    for(int i_two=1;i_two<=foodcount_two;i_two++)
    {
        if(i_two!=foodcount_two)
        {
        if((snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]==snake_two[i_two-1][1]-1&&
           snake_two[i_two][0]==snake_two[i_two+1][0]-1&&snake_two[i_two][1]==snake_two[i_two+1][1])||
           (snake_two[i_two][0]==snake_two[i_two-1][0]-1&&snake_two[i_two][1]==snake_two[i_two-1][1]&&
            snake_two[i_two][0]==snake_two[i_two+1][0]&&snake_two[i_two][1]==snake_two[i_two+1][1]-1))
         painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/body2.png").scaled(QSize(25,25)));
        else if((snake_two[i_two][0]==snake_two[i_two-1][0]-1&&snake_two[i_two][1]==snake_two[i_two-1][1]&&
                 snake_two[i_two][0]==snake_two[i_two+1][0]&&snake_two[i_two][1]==snake_two[i_two+1][1]+1)||
                 (snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]==snake_two[i_two-1][1]+1&&
                  snake_two[i_two][0]==snake_two[i_two+1][0]-1&&snake_two[i_two][1]==snake_two[i_two+1][1]))
         painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/body2.png").scaled(QSize(25,25)));
        else if((snake_two[i_two][0]==snake_two[i_two-1][0]+1&&snake_two[i_two][1]==snake_two[i_two-1][1]&&
                 snake_two[i_two][0]==snake_two[i_two+1][0]&&snake_two[i_two][1]==snake_two[i_two+1][1]-1)||
                 (snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]==snake_two[i_two-1][1]-1&&
                  snake_two[i_two][0]==snake_two[i_two+1][0]+1&&snake_two[i_two][1]==snake_two[i_two+1][1]))
         painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/body2.png").scaled(QSize(25,25)));
        else if((snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]==snake_two[i_two-1][1]+1&&
                 snake_two[i_two][0]==snake_two[i_two+1][0]+1&&snake_two[i_two][1]==snake_two[i_two+1][1])||
                 (snake_two[i_two][0]==snake_two[i_two-1][0]+1&&snake_two[i_two][1]==snake_two[i_two-1][1]&&
                  snake_two[i_two][0]==snake_two[i_two+1][0]&&snake_two[i_two][1]==snake_two[i_two+1][1]+1))
         painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/body2.png").scaled(QSize(25,25)));
        else if(snake_two[i_two][1]==snake_two[i_two-1][1]&&snake_two[i_two][0]!=snake_two[i_two-1][0])
       painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/body2.png").scaled(QSize(25,25)));
        else if(snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]!=snake_two[i_two-1][1])
         painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/body2.png").scaled(QSize(25,25)));
        }
        else
        {
            //画蛇尾
            if(snake_two[i_two][0]==snake_two[i_two-1][0]+1&&snake_two[i_two][1]==snake_two[i_two-1][1])
                painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/tailleft2.png").scaled(QSize(25,25)));
            else if(snake_two[i_two][0]==snake_two[i_two-1][0]-1&&snake_two[i_two][1]==snake_two[i_two-1][1])
                painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/tailright2.png").scaled(QSize(25,25)));
            else if(snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]==snake_two[i_two-1][1]-1)
                painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/taildown2.png").scaled(QSize(25,25)));
             else if(snake_two[i_two][0]==snake_two[i_two-1][0]&&snake_two[i_two][1]==snake_two[i_two-1][1]+1)
                painter_two.drawImage(snake_two[i_two][0]*20,snake_two[i_two][1]*20,QImage(":/new/prefix1/img/tailup2.png").scaled(QSize(25,25)));
        }
    }
}
void GameWidget1::keyPressEvent(QKeyEvent *k)//以下为键盘操作
{
if(k->key()==Qt::Key_W){
    if(direction==DOWN)
        return;
    else
    {
    direction=UP;
    }
}else if(k->key()==Qt::Key_S){
    if(direction==UP)
        return;
    else
    {
    direction=DOWN;
    }
}else if(k->key()==Qt::Key_A){
    if(direction==RIGHT)
        return;
    else
    {
    direction=LEFT;
    }
}else if(k->key()==Qt::Key_D){
    if(direction==LEFT)
        return;
    else
    {
    direction=RIGHT;
    }
}
if(k->key()==Qt::Key_I){
    if(direction_two==DOWN_TWO)
        return;
    else
    {
    direction_two=UP_TWO;
    }
}else if(k->key()==Qt::Key_K){
    if(direction_two==UP_TWO)
        return;
    else
    {
    direction_two=DOWN_TWO;
    }
}else if(k->key()==Qt::Key_J){
    if(direction_two==RIGHT_TWO)
        return;
    else
    {
    direction_two=LEFT_TWO;
    }
}else if(k->key()==Qt::Key_L){
    if(direction_two==LEFT_TWO)
        return;
    else
    {
    direction_two=RIGHT_TWO;
    }
}
}


