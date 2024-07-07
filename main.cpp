#include <QCoreApplication>
#include "ImplConfig.h"
#include "ProxyOriginatorConfig.h"
#include "Caretaker.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto implConf = std::make_shared<ImplConfig>();
    ProxyOriginatorConfig proxyConf(implConf);
    Caretaker caretaker;

    qDebug() << "first set params";
    proxyConf.setFirstParam(1);
    proxyConf.setSecondParam(2);

    qDebug() << proxyConf.getFirstParam() << proxyConf.getSecondParam();

    caretaker.addMemento(proxyConf.saveStateToMemento());

    qDebug() << "second set params";
    proxyConf.setFirstParam(11);
    proxyConf.setSecondParam(22);

    qDebug() << proxyConf.getFirstParam() << proxyConf.getSecondParam();

    qDebug() << "upload memento in proxyConf";
    proxyConf.getStateFromMemento(caretaker.getMemento(0));

    qDebug() << proxyConf.getFirstParam() << proxyConf.getSecondParam();

    return a.exec();
}
