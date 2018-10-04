#ifndef CAMERAINQUIRY_H
#define CAMERAINQUIRY_H
#include <QObject>
#include <QVariant>

class CameraInquiry: public QObject
{
    Q_OBJECT

public:
    bool *ok;
    CameraInquiry();
    QByteArray powerCameraInquiry(); //depends on how do we wanna use these functions, here as only functions in private slots as signal&slots

private slots:

    void zoomPositionInquiry();
    int receiveZoomSendToQML(QByteArray valueRead);
    void digitalZoomModeInquiry();
    void digitalZoomCombSepModeInq();
    void digitalZoomPositionInqiry();
    void focusModeInquiry();
    void focusPositionInquiry();
    void focusNearLimitInquiry();
    void afSensitivityInquiry();
    void afModeInquiry();
    void afTimeSettingInquiry();
    void irCorrectionInquiry();
    void wbModeInquiry();
    void rGainInquiry();
    void bGainInquiry();
    void aeModeInquiry();
    void autoSlowShutterInquiry();
    void irisPosInquiry();
    void gainPosInquiry();
    void gainLimitInquiry();
    void brightPosInquiry();
    void expCompModeInquiry();
    void expCompPosInquiry();
    void backLightModeInquiry();
    void spotAeModeInquiry();
    void spotAePosInquiry();
    void veModeInquiry();
    void veParameterInquiry();
    void aeResponseInquiry();
    void defogInquiry();
    void apertureInquiry();
    void hrModeInquiry();
    void nrInquiry();
    void gammaInquiry();
    void highSensitivityInquiry();
    void lrReverseModeInquiry();
    void freezeModeInquiry();
    void pictureEffectModeInquiry();
    void pictureFlipModeInquiry();
    void icrModeInquiry();
    void autoIcrModeInquiry();
    void autoIcrThresholdInquiry();
    void autoIcrAlarmReplyInquiry();
    void memoryInquiry();
    void memorySaveInquiry();
    void displayModeInquiry();
    void stabilizerModeInquiry();
    void muteModeInquiry();
    void privacyDisplayInquiry();
    void privacyPanTiltInquiry();
    void privacyMonitorInquiry();
    void idInquiry();
    void versionInquiry();
    void mdModeInquiry();
    void mdFunctionInquiry();
    void mdWindowInquiry(int);
    void continuousZoomPosReplyModeInquiry();
    void zoomPosReplyIntervalTimeInquiry();
    void continuousFocusPosReplyModeInquiry();
    void focusRepIntervalTimeInquiry();
    void registerValueInquiry(int);
    void colorEnhanceOnOffInquiry();
    void colorEnhanceInquiry();
    void chromaSuppressInquiry();
    void colorGainInquiry();
    void colorHueInquiry();
    void lensTemperatureInquiry();
    void gammaOffsetInquiry();
    void contrastAdjLevelInquiry();
    void exExpCompPosInquiry();
    void exApertureInquiry();
    void exColorGainInquiry();
    void exColorHueInquiry();
    void exAutoIcrThresholdInq();
    void exAutoIcrOnLevelInquiry();
    void minShutterInquiry();
    void minShutterLimitInquiry();
    void hlcInquiry();

signals:
    void sendInquiryToSerialPort(QByteArray);
    void dataChanged();
    void inquiryReplySignalToController(QString);

private:
    QString zoomInquiryValue;

};

#endif // CAMERAINQUIRY_H
