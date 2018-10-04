#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include "cameracommand.h"
#include "serial.h"
#include "controller.h"
#include "videomanager.h"

// ............................. what it is for?
class CameraCommand;

class MainWindow: public QObject
{
    Q_OBJECT
public:
    MainWindow();
    CameraInquiry* cameraInquiry;
    Serial* seialCommunication;
    Controller* generalController;
    VideoManager* runningThread;

private:
    CameraCommand* cameraCommand;

public slots:
    void simpleFunction();

};

#endif // MAINWINDOW_H
