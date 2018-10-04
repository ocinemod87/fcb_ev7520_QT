#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H
#include <QSerialPort>
#include <QObject>
#include <QMetaEnum>
#include <camerainquiry.h>

class CameraCommand: public QObject
{
    Q_OBJECT
public:
    CameraCommand();
    bool *ok;           //check if really needs to be public

private:

public slots:
    void cameraSetup();
    void valueInQML(QString);
    void sendZoomSpeed(int mes); //sendZoomSpeed
    void sendZoomPosition(int mes);
    void sendDigitalZoomSwitch(int mes);
    void sendZoomMode(int mes);
    void sendDigitalZoomValue(int mes);               //enabled in separate mode
    void sendDigitalZoomPosition(int mes);
    void sendMaxSwitch(void);                         //enabled in separate mode
    void sendFocusSpeed(int mes);
    void sendFocusFixedPosition(int mes);
    void sendFocusNearLimit(int);
    void sendAutoManualFocus(QString mes);
    void sendAutoFocusMode(QString mes);
    void sendOnePushAFTrigger(void);
    void sendAfSens(QString mes);
    void sendExposureCompensation(int mes);
    void sendInfraRed(QString mes);
    void sendIrCorrection(QString mes);
    void sendCameraCommandInit(QString mes);
    void sendCameraCommandPower(QString mes);
    void sendCameraCommandMode(QString mes);
    void sendRGain(QString mes);
    void sendBGain(QString mes);
    void sendExposureMode(QString mes);
    void sendAutoSlowShutter(QString mes);
    void sendShutter(QString mes);
    void sendIrisValue(QString mes);
    void sendGainValue(QString mes);
    void sendBrightValue(QString mes);
    void sendBackLightValue(QString mes);
    void sendAeSpotModeValue(QString mes);
    void sendAePositionSpotValue(QString x, QString y);
    void sendAeResponseValue(QString mes);
    void sendCamVeMode(QString mes);                      //in part valid for WD
    void sendCamVeParameter(QString bright, QString compSel, QString compLevel); //this is the same for WD
    void sendCamWdMode(QString mes);                      // valid for VE
    void sendDefogMode(QString state, QString level);
    void sendCamAperture(QString aperture);
    void sendCamAperturePosition(QString aperturePos);
    void sendCamHrMode(QString hrMode);
    void sendCamNoiseReduction(QString nrValue);
    void sendNoiseReductionIntipendent(QString nrInd);
    void sendCamGammaValue(QString gamma);
    void sendHighSensitivityMode(QString mode);
    void sendLrReverse(QString mode);
    void sendCamFreeze(QString mode);
    void sendPictureEffect(QString mode);
    void sendMinimumShutterMode (QString mode);
    void sendMinimumShutterLimitPos(QString pos);
    void sendPictureFlipMode(QString mode);
    void sendIcrMode(QString mode);
    void sendAutoIcrMode(QString mode);
    void sendAutoIcrThresholdLevel(QString level);
    void sendAutoIcrAlarmMode(QString mode);
    void sendCamStabilizerMode(QString mode);
    void sendCamMemory(QString mode, QString memNum);
    void sendCamCustomMode(QString mode);
    void sendMemorySave(QString address, QString dataValue);
    void sendCamDisplay();
    void sendMuteMode();
    void sendCamIDWriteOn();
    void sendContinuousZoomPosReply(QString mode);
    void sendZoomReplyIntervalTime(QString interTime);
    void sendContinuousFocusPosReply(QString mode);
    void sendFocusReplyIntervalTime(QString interTime);
    void sendRegisterValue(QString regNum, QString regValue);
    void sendColorEnhanceMode(QString mode);
    void sendColorEnhanceValue(QString thresholdLev, QString yHigh, QString crHigh, QString cbHigh,QString yLow, QString crLow, QString cbLow);
    void sendChromaSuppressLevel(QString chromaLevel);
    void sendColorGainLevel(int gainLevel);
    void sendColorHueLevel(int hueLevel);
    void sendGammaOffset(int polarityOffset, int offset);
    void sendContrastAdjLevel(int contrast);
    void sendExExpComp(int value,int upDownReset);
    void sendExAperture(int value, int upDownReset);
    void sendExAutoICR(int value, int switchOnOff);
    void sendExColorGain(int value);
    void sendExColorHue(int value);
    void sendHclLevel(int level, int maskLevel);
    void sendBaudRate(QString mes);

signals:
    void sendInQML(QVariant text1);
    void sendToSerialPort(QByteArray);
    void sendedBaudRate(QByteArray, int);

};

#endif // CAMERACOMMAND_H
