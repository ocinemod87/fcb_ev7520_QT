#include "mainwindow.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "cameracommand.h"
#include "controller.h"
#include "serial.h"
#include "camerainquiry.h"
#include <QQuickView>

MainWindow::MainWindow()
{  
    seialCommunication = new Serial;
    cameraCommand = new CameraCommand;
    cameraInquiry = new CameraInquiry;
    generalController = new Controller;

    runningThread = new VideoManager();
    connect(runningThread, SIGNAL(finished()), runningThread, SLOT(deleteLater()));
    runningThread->start();


    //inquiries connections from CameraInquiry to Controller
    //zoom inquiry
    QObject::connect(cameraInquiry, SIGNAL(inquiryReplySignalToController(QString)), generalController, SLOT(setZoomVarToBeRead(QString)));

    //connection from inquiry to serial send class
    QObject::connect(cameraInquiry, SIGNAL(sendInquiryToSerialPort(QByteArray)), seialCommunication, SLOT(sendReadInquiry(QByteArray)));
    QObject::connect(seialCommunication, SIGNAL(sendByteToInquiry(QByteArray)), cameraInquiry, SLOT(receiveZoomSendToQML(QByteArray)));

//    QObject::connect(generalController,SIGNAL(signalNewScreenshot()), screenshotInstance,SLOT(newScreenshot()));
//    QObject::connect(generalController,SIGNAL(signalSaveScreenshot()), screenshotInstance,SLOT(saveScreenshot()));

    //connection from camera class to Serial class, cameraSetup called after the connection
    QObject::connect(cameraCommand, SIGNAL(sendToSerialPort(QByteArray)), seialCommunication, SLOT(sendCommand(QByteArray)));
    cameraCommand->cameraSetup();

    //Zoom slider
    QObject::connect(generalController, SIGNAL(signalZoomToSend(int)),cameraCommand, SLOT(sendZoomSpeed(int)));

    //Zoom fixed position
    QObject::connect(generalController, SIGNAL(signalZoomPositionToSend(int)),cameraCommand, SLOT(sendZoomPosition(int)));

    //DigitalZoomSwitch Signal and Slot connection with QML
    QObject::connect(generalController, SIGNAL(signalDigitalZoomSwitchToSend(int)),cameraCommand, SLOT(sendDigitalZoomSwitch(int)));

    //Zoom mode Controller Signal and Slot connection with QML
    QObject::connect(generalController, SIGNAL(signalZoomModeToSend(int)),cameraCommand, SLOT(sendZoomMode(int)));

    //Indipendent zoom digital when in separated mode, enabled in separate mode
    QObject::connect(generalController, SIGNAL(signalDigitalZoomValueToSend(int)),cameraCommand, SLOT(sendDigitalZoomValue(int)));

    //ZoomSlider digital fixed position Signal and Slot connection with QML, enabled in separate mode
    QObject::connect(generalController, SIGNAL(signalDigitalZoomPositionToSend(int)),cameraCommand, SLOT(sendDigitalZoomPosition(int)));

    //Magnigication switchover enabled in separate mode
    QObject::connect(generalController, SIGNAL(signalMaxSwitch()),cameraCommand, SLOT(sendMaxSwitch()));

    //Camera exposure
    QObject::connect(generalController,SIGNAL(signalExposureToSend(int)),cameraCommand,SLOT(sendExposureCompensation(int)));

    //FocusSlider Signal and Slot connection with QML
    QObject::connect(generalController,SIGNAL(signalFocusToSend(int)),cameraCommand,SLOT(sendFocusSpeed(int)));

    //Auto Focus
    QObject::connect(generalController,SIGNAL(signalAutoFocusToSend(QString)),cameraCommand,SLOT(sendAutoManualFocus(QString)));

    //Focus Fixed Position Slider Signal and Slot connection with QML
    QObject::connect(generalController,SIGNAL(signalFocusFixedPositionToSend(int)),cameraCommand,SLOT(sendFocusFixedPosition(int)));

    //Focus Near Limit Slider Signal and Slot connection with QML
    QObject::connect(generalController,SIGNAL(signalFocusNearLimitToSend(int)),cameraCommand,SLOT(sendFocusNearLimit(int)));

    //Auto Focus mode Controller Signal and Slot connection with QML
    QObject::connect(generalController, SIGNAL(signalAutoFocusModeToSend(QString)),cameraCommand, SLOT(sendAutoFocusMode(QString)));

    //OnePushAuto Focus;
    QObject::connect(generalController,SIGNAL(signalOnePushAFToSend(QString)),cameraCommand,SLOT(sendOnePushAFTrigger()));

    //Auto Focus Sensitivity
    QObject::connect(generalController, SIGNAL(signalAfSensToSend(QString)),cameraCommand, SLOT(sendAfSens(QString)));

    //Infra Red connection
    QObject::connect(generalController, SIGNAL(signalInfraRedToSend(QString)),cameraCommand, SLOT(sendInfraRed(QString)));

    //Infra Red connection
    QObject::connect(generalController, SIGNAL(signalIRCorrectionToSend(QString)),cameraCommand, SLOT(sendIrCorrection(QString)));

    //Camera init native functions for Lens initialization and Camera reset
    QObject::connect(generalController, SIGNAL(signalCameraInitToSend(QString)),cameraCommand, SLOT(sendCameraCommandInit(QString)));

    //Camera power on/off
    QObject::connect(generalController, SIGNAL(signalCameraPowerToSend(QString)),cameraCommand, SLOT(sendCameraCommandPower(QString)));

    //Camera mode
    QObject::connect(generalController, SIGNAL(signalCameraModeToSend(QString)),cameraCommand, SLOT(sendCameraCommandMode(QString)));

    //R Gain
    QObject::connect(generalController, SIGNAL(signalRGainToSend(QString)),cameraCommand, SLOT(sendRGain(QString)));

    //B Gain
    QObject::connect(generalController, SIGNAL(signalBGainToSend(QString)),cameraCommand, SLOT(sendBGain(QString)));

    //Exposure Mode
    QObject::connect(generalController, SIGNAL(signalExposureModeToSend(QString)),cameraCommand, SLOT(sendExposureMode(QString)));

    //Auto Slow Shutter
    QObject::connect(generalController, SIGNAL(signalAutoSlowShutter(QString)),cameraCommand, SLOT(sendAutoSlowShutter(QString)));

    //Shutter Control
    QObject::connect(generalController, SIGNAL(signalShutterToSend(QString)),cameraCommand, SLOT(sendShutter(QString)));

    //Iris
    QObject::connect(generalController, SIGNAL(signalIrisToSend(QString)),cameraCommand, SLOT(sendIrisValue(QString)));

    //Gain
    QObject::connect(generalController, SIGNAL(signalGainToSend(QString)),cameraCommand, SLOT(sendGainValue(QString)));

    //Bright
    QObject::connect(generalController, SIGNAL(signalBrightToSend(QString)),cameraCommand, SLOT(sendBrightValue(QString)));

    //Back Light Compensation
    QObject::connect(generalController, SIGNAL(signalBackLightToSend(QString)),cameraCommand, SLOT(sendBackLightValue(QString)));

    //Auto Exposure spot Mode
    QObject::connect(generalController, SIGNAL(signalAeSpotModeToSend(QString)),cameraCommand, SLOT(sendAeSpotModeValue(QString)));

    //Baud Rate
    QObject::connect(generalController, SIGNAL(signalBaudRateToSend(QString)),cameraCommand, SLOT(sendBaudRate(QString)));
//    QObject::connect(cameraCommand, SIGNAL(sendToSerialPort(QByteArray, int)), seialCommunication, SLOT(sendBaudRateValue(QByteArray, int)));

}

// debugging function
void MainWindow::simpleFunction(){
    qDebug()<<"invoked In Simple Function";
}
