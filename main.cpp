#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <libbw.h>
#include <libmrplotter.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    BW* bw = BW::instance();
    bw->connectAgent("localhost", 28589);

    initLibMrPlotter();

    QQmlApplicationEngine engine;
    bw->setEntityFromEnviron([&](QString s)
    {
        qDebug("Got callback from sete: %s", qPrintable(s));
        qDebug("VK is %s", qPrintable(bw->getVK()));
        qDebug("loading");
        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    });

    return app.exec();
}
