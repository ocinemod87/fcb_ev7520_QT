#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickStyle>
#include <QQuickWindow>
#include <QQuickView>
#include <QVariant>
#include <QApplication>
#include <QQuickImageProvider>
#include "mainwindow.h"
#include "cameracommand.h"
#include "controller.h"
#include "serial.h"
#include "camerainquiry.h"


int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);
    MainWindow windowInstance;

    // ..................................................
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;

    qmlRegisterType<VideoManager>("com.amin.classes", 1, 0, "CvDetectFilter");
    qRegisterMetaType<QList<QRect>>("QList<QRect>");

    // set the communication between Controller class and QML
    engine.rootContext()->setContextProperty("inquirySignal", windowInstance.generalController);
    engine.rootContext()->setContextProperty("commandSignal", windowInstance.generalController);

    engine.rootContext()->setContextProperty("videoProvider", windowInstance.runningThread);
    engine.addImageProvider(QLatin1String ("videoCapture"), windowInstance.runningThread);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        qDebug()<<"engine problem";
        return -1;
    }

    return app.exec();
}
