#include <QCoreApplication>

/*
 What
 Templates

 Description
 QObject and templates do not mix well

 Why
 Copy is disabled by design

 Example
 Pass a pointer of a QObject to a template function

 */

#include <QDebug>
#include "myclass.h"

template <class T>
void testPointer(T x)
{
    QObject *obj = qobject_cast<QObject*>(x);
    if(!obj) return;

    obj->setObjectName(QString("Hello Templates"));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass myclass;

    testPointer(&myclass);

    qInfo() << myclass.objectName();

    return a.exec();
}
