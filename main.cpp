#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickView>

#include "SimpleListModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    QQuickView *view = new QQuickView();
    SimpleListModel *model = new SimpleListModel(view);
    view->engine()->rootContext()->setContextProperty("myModel", model);
    view->setSource(QUrl::fromLocalFile("myuiscript.qml"));
    view->show();

    return a.exec();
}
