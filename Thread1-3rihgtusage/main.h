#ifndef MAIN_H
#define MAIN_H
#include <QtCore>
#include <QDebug>
#include <QtWidgets>
#include <QboxLayout>
#include <QApplication>
#include <QThread>
class Thread : public QThread
{
    Q_OBJECT
public:
    int flag = 0;
public slots:
    void runstop();
private:
    void run();
};
#endif // MAIN_H
