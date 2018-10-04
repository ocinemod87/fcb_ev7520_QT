#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QWidget>

class Controller: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getZoomInquiryValue READ getZoomInquiryValue WRITE setZoomVarToBeRead NOTIFY dataChanged)

public:
    Controller();
    //they receive the signal from QML
    Q_INVOKABLE void zoomSignalReceiver(int message);//opt
    Q_INVOKABLE void zoomPositionSignalReceiver(int message);//opt
    Q_INVOKABLE void digitalzoomswitchSignalReceiver(int message);
    Q_INVOKABLE void zoommodeSignalReceiver(int message);//opt
    Q_INVOKABLE void zoomDigitalValueSignalReceiver(int message); //enabled in separate mode
    Q_INVOKABLE void zoomDigitalPositionSignalReceiver(int message);
    Q_INVOKABLE void maxSwitchReceiver(void); //enabled in separate mode
    Q_INVOKABLE void focusSignalReceiver(int message);
    Q_INVOKABLE void focusFixedPositionSignalReceiver(int message);
    Q_INVOKABLE void focusNearLimitSignalReceiver(int message);
    Q_INVOKABLE void autofocusSignalReceiver(QString message);
    Q_INVOKABLE void autofocusmodeSignalReceiver(QString message);
    Q_INVOKABLE void onepushafSignalReceiver(QString message);
    Q_INVOKABLE void afsensSignalReceiver(QString message);
    Q_INVOKABLE void exposureSignalReceiver(int message);
    Q_INVOKABLE void infraRedSignalReceiver(QString message);
    Q_INVOKABLE void irCorrectionSignalReceiver(QString message);
    Q_INVOKABLE void cameraInitSignalReceiver(QString message);
    Q_INVOKABLE void cameraPowerSignalReceiver(QString message);
    Q_INVOKABLE void cameraModeSignalReceiver(QString message);
    Q_INVOKABLE void rGainSignalReceiver(QString message);
    Q_INVOKABLE void bGainSignalReceiver(QString message);
    Q_INVOKABLE void exposureModeSignalReceiver(QString message);
    Q_INVOKABLE void autoSlowShutterReceiver(QString message);
    Q_INVOKABLE void shutterSignalReceiver(QString message);
    Q_INVOKABLE void irisSignalReceiver(QString message);
    Q_INVOKABLE void gainSignalReceiver(QString message);
    Q_INVOKABLE void brightSignalReceiver(QString message);
    Q_INVOKABLE void backLightSignalReceiver(QString message);
    Q_INVOKABLE void aeSpotModeSignalReceiver(QString message);
    Q_INVOKABLE void baudRateSignalReceiver(QString message);
    Q_INVOKABLE void newScreenshotReceiver();
    Q_INVOKABLE void saveScreenshotReceiver();

    //getters to allow QML to access the variables containing the inquiry replies
    QString getZoomInquiryValue();

public slots:
    //receive inquiry values from CameraInquiry class and set the value of a variable which can be returned to QML
    void setZoomVarToBeRead(QString message);

signals:
    void signalZoomToSend(int); //called by SignalReceivers they send the signal to trigger SIGNAL AND SLOT
    void signalZoomPositionToSend(int);
    void signalDigitalZoomSwitchToSend(int);
    void signalZoomModeToSend(int);
    void signalDigitalZoomValueToSend(int); //enabled in separate mode
    void signalDigitalZoomPositionToSend(int);
    void signalMaxSwitch(void); //enabled in separate mode
    void signalFocusToSend(int);
    void signalFocusFixedPositionToSend(int);
    void signalFocusNearLimitToSend(int);
    void signalExposureToSend(int);
    void signalAutoFocusToSend(QString);
    void signalAutoFocusModeToSend(QString);
    void signalOnePushAFToSend(QString);
    void signalAfSensToSend(QString);
    void signalInfraRedToSend(QString);
    void signalIRCorrectionToSend(QString);
    void signalCameraInitToSend(QString);
    void signalCameraPowerToSend(QString);
    void signalCameraModeToSend(QString);
    void signalRGainToSend(QString);
    void signalBGainToSend(QString);
    void signalExposureModeToSend(QString);
    void signalAutoSlowShutter(QString);
    void signalShutterToSend(QString);
    void signalIrisToSend(QString);
    void signalGainToSend(QString);
    void signalBrightToSend(QString);
    void signalBackLightToSend(QString);
    void signalAeSpotModeToSend(QString);
    void signalBaudRateToSend(QString);
    void signalSaveScreenshot();
    void signalNewScreenshot();

    void dataChanged();

private:
    QString zoomInquiryValue;               //variable to be read from qml after inquiry reply
};

#endif // CONTROLLER_H
