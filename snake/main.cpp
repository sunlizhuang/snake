#include "mainWidget.h"
#include <QApplication>//基础头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;//刚进入的主界面
    w.show();
    return a.exec();//返回窗口
}
