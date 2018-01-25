#include <main.h>
void Thread::runstop()
    {
        flag = 1;
    }
void Thread::run()
    {
        while(1)
        {
            qDebug()<<"From worker thread: "<<currentThreadId();
            this->sleep(1);
            if(flag)
            {
                flag = 0;
                qDebug()<<"break: "<<currentThreadId();
                break;
            }
        }

    }


int main(int argc, char *argv[])
{
    //int counter= 0;
    QApplication a(argc, argv);
    qDebug()<<"From main thread: "<<QThread::currentThreadId();

    QWidget *widget;
    widget = new QWidget(0,0);
    QHBoxLayout *layout;
    layout = new QHBoxLayout(widget);
    QPushButton *btn_stop = new QPushButton( "stop Thread" );
    QPushButton *btn_start = new QPushButton( "btn_start" );
    layout->addWidget(btn_start,0,0);
    layout->addWidget(btn_stop,0,0);

    widget->show();

    Thread t;

    QObject::connect(btn_stop, SIGNAL(clicked()), &t, SLOT(runstop()));
    QObject::connect(btn_start, SIGNAL(clicked()), &t, SLOT(start()));

    t.start();
    //return a.exec();
}
