#include "camerainquiry.h"
#include "cameracommand.h"
#include <QDebug>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QObject>
#include <QQmlProperty>
#include <QTimer>


CameraInquiry::CameraInquiry()
{
    ok = new bool;
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()),this, SLOT(zoomPositionInquiry()));
//    timer->start(500);

}

QByteArray CameraInquiry::powerCameraInquiry()
{
    QByteArray powerInq("\x81\x09\x04\x00\xFF", 5);

//    emit sendInquiryToSerialPort(powerInq);
    return powerInq;
}

void CameraInquiry::zoomPositionInquiry()
{
    QByteArray zoomPosInq("\x81\x09\x04\x47\xFF", 5);
    qDebug()<<"inside inquiry";

    emit sendInquiryToSerialPort(zoomPosInq);
}

int CameraInquiry::receiveZoomSendToQML(QByteArray valueRead)
{
    if(valueRead == NULL || valueRead.length() < 7){
        return 0;
    }
    //IF THE CAMERA IS NOT CONNECTED YOU HAVE TO COMMENT THE REST OF THIS FUNCTION OTHERWISE THE SOFTWARE WILL CRASH
    int a = valueRead.at(2);
    int b = valueRead.at(3);
    int c = valueRead.at(4);
    int d = valueRead.at(5);

    QString byteToString;
    byteToString.sprintf("%X%X%X%X", a, b, c, d);
    int decimalValue = byteToString.toInt(ok,16);

    byteToString.sprintf("%d", decimalValue);
    qDebug()<<byteToString;

    //receives the value from the Serial class and manipulates it to send it to the Controller class
    float percentagefloat = byteToString.toFloat(ok);
    percentagefloat = (percentagefloat/31424) * 100;
    byteToString.sprintf("%.0f", percentagefloat);
    byteToString.append("%");

    qDebug()<<percentagefloat<<" in receiveZoomSendToQML";

    emit inquiryReplySignalToController(byteToString);
    return 1;
}

void CameraInquiry::digitalZoomModeInquiry()
{
    QByteArray digitalZoomMode("\x81\x09\x04\x06\xFF", 5);

    emit sendInquiryToSerialPort(digitalZoomMode);
}

void CameraInquiry::digitalZoomCombSepModeInq()
{
    QByteArray zoomCombSepMode("\x81\x09\x04\x36\xFF", 5);

    emit sendInquiryToSerialPort(zoomCombSepMode);
}

void CameraInquiry::digitalZoomPositionInqiry()
{
    QByteArray digitalZoomPos("\x81\x09\x04\x46\xFF", 5);

    emit sendInquiryToSerialPort(digitalZoomPos);
}

void CameraInquiry::focusModeInquiry()
{
    QByteArray focusMode("\x81\x09\x04\x38\xFF", 5);

    emit sendInquiryToSerialPort(focusMode);
}

void CameraInquiry::focusPositionInquiry()
{
    QByteArray focusPos("\x81\x09\x04\x48\xFF", 5);

    emit sendInquiryToSerialPort(focusPos);
}

void CameraInquiry::focusNearLimitInquiry()
{
    QByteArray focusNearLimit("\x81\x09\x04\x28\xFF", 5);

    emit sendInquiryToSerialPort(focusNearLimit);
}

void CameraInquiry::afSensitivityInquiry()
{
    QByteArray afSensitivity("\x81\x09\x04\x58\xFF", 5);

    emit sendInquiryToSerialPort(afSensitivity);
}

void CameraInquiry::afModeInquiry()
{
    QByteArray afMode("\x81\x09\x04\x57\xFF", 5);

    emit sendInquiryToSerialPort(afMode);
}

void CameraInquiry::afTimeSettingInquiry()
{
    QByteArray afTimeSetting("\x81\x09\x04\x27\xFF", 5);

    emit sendInquiryToSerialPort(afTimeSetting);
}

void CameraInquiry::irCorrectionInquiry()
{
    QByteArray irCorrection("\x81\x09\x04\x11\xFF", 5);

    emit sendInquiryToSerialPort(irCorrection);
}

void CameraInquiry::wbModeInquiry()
{
    QByteArray wbMode("\x81\x09\x04\x35\xFF", 5);

    emit sendInquiryToSerialPort(wbMode);
}

void CameraInquiry::rGainInquiry()
{
    QByteArray rGain("\x81\x09\x04\x43\xFF", 5);

    emit sendInquiryToSerialPort(rGain);
}

void CameraInquiry::bGainInquiry()
{
    QByteArray bGain("\x81\x09\x04\x44\xFF", 5);

    emit sendInquiryToSerialPort(bGain);
}

void CameraInquiry::aeModeInquiry()
{
    QByteArray aeMode("\x81\x09\x04\x39\xFF", 5);

    emit sendInquiryToSerialPort(aeMode);
}

void CameraInquiry::autoSlowShutterInquiry()
{
    QByteArray autoSlowShutter("\x81\x09\x04\x5A\xFF", 5);

    emit sendInquiryToSerialPort(autoSlowShutter);
}

void CameraInquiry::irisPosInquiry()
{
    QByteArray irisPos("\x81\x09\x04\x4B\xFF", 5);

    emit sendInquiryToSerialPort(irisPos);
}

void CameraInquiry::gainPosInquiry()
{
    QByteArray gainPos("\x81\x09\x04\x4C\xFF", 5);

    emit sendInquiryToSerialPort(gainPos);
}

void CameraInquiry::gainLimitInquiry()
{
    QByteArray gainLimit("\x81\x09\x04\x2C\xFF", 5);

    emit sendInquiryToSerialPort(gainLimit);
}

void CameraInquiry::brightPosInquiry()
{
    QByteArray brightPos("\x81\x09\x04\x4D\xFF", 5);

    emit sendInquiryToSerialPort(brightPos);
}

void CameraInquiry::expCompModeInquiry()
{
    QByteArray expCompMode("\x81\x09\x04\x3E\xFF", 5);

    emit sendInquiryToSerialPort(expCompMode);
}

void CameraInquiry::expCompPosInquiry()
{
    QByteArray expCompPos("\x81\x09\x04\x4E\xFF", 5);

    emit sendInquiryToSerialPort(expCompPos);
}

void CameraInquiry::backLightModeInquiry()
{
    QByteArray backLightMode("\x81\x09\x04\x33\xFF", 5);

    emit sendInquiryToSerialPort(backLightMode);
}

void CameraInquiry::spotAeModeInquiry()
{
    QByteArray spotAeMode("\x81\x09\x04\x59\xFF", 5);

    emit sendInquiryToSerialPort(spotAeMode);
}

void CameraInquiry::spotAePosInquiry()
{
    QByteArray spotAePos("\x81\x09\x04\x29\xFF", 5);

    emit sendInquiryToSerialPort(spotAePos);
}

void CameraInquiry::veModeInquiry()
{
    //this command is valid also for WD Mode inquiry
    QByteArray veMode("\x81\x09\x04\x3D\xFF", 5);

    emit sendInquiryToSerialPort(veMode);
}

void CameraInquiry::veParameterInquiry()
{
    //this command is valid also for WD Parameter inquiry
    QByteArray veParameter("\x81\x09\x04\x2D\xFF", 5);

    emit sendInquiryToSerialPort(veParameter);
}

void CameraInquiry::aeResponseInquiry()
{
    QByteArray aeResponse("\x81\x09\x04\x5D\xFF", 5);

    emit sendInquiryToSerialPort(aeResponse);
}

void CameraInquiry::defogInquiry()
{
    QByteArray defog("\x81\x09\x04\x37\xFF", 5);

    emit sendInquiryToSerialPort(defog);
}

void CameraInquiry::apertureInquiry()
{
    QByteArray aperture("\x81\x09\x04\x42\xFF", 5);

    emit sendInquiryToSerialPort(aperture);
}

void CameraInquiry::hrModeInquiry()
{
    QByteArray hrMode("\x81\x09\x04\x52\xFF", 5);

    emit sendInquiryToSerialPort(hrMode);
}

void CameraInquiry::nrInquiry()
{
    QByteArray nrInq("\x81\x09\x04\x53\xFF", 5);

    emit sendInquiryToSerialPort(nrInq);
}

void CameraInquiry::gammaInquiry()
{
    QByteArray gamma("\x81\x09\x04\x5B\xFF", 5);

    emit sendInquiryToSerialPort(gamma);
}

void CameraInquiry::highSensitivityInquiry()
{
    QByteArray highSens("\x81\x09\x04\x5E\xFF", 5);

    emit sendInquiryToSerialPort(highSens);
}

void CameraInquiry::lrReverseModeInquiry()
{
    QByteArray lrReverse("\x81\x09\x04\x61\xFF", 5);

    emit sendInquiryToSerialPort(lrReverse);
}

void CameraInquiry::freezeModeInquiry()
{
    QByteArray freezeMode("\x81\x09\x04\x62\xFF", 5);

    emit sendInquiryToSerialPort(freezeMode);
}

void CameraInquiry::pictureEffectModeInquiry()
{
    QByteArray pictureEffect("\x81\x09\x04\x63\xFF", 5);

    emit sendInquiryToSerialPort(pictureEffect);
}

void CameraInquiry::pictureFlipModeInquiry()
{
    QByteArray pictureFlip("\x81\x09\x04\x66\xFF", 5);

    emit sendInquiryToSerialPort(pictureFlip);
}

void CameraInquiry::icrModeInquiry()
{
    QByteArray icrMode("\x81\x09\x04\x01\xFF", 5);

    emit sendInquiryToSerialPort(icrMode);
}

void CameraInquiry::autoIcrModeInquiry()
{
    QByteArray autoIcrMode("\x81\x09\x04\x51\xFF", 5);

    emit sendInquiryToSerialPort(autoIcrMode);
}

void CameraInquiry::autoIcrThresholdInquiry()
{
    QByteArray autoIcrThreshold("\x81\x09\x04\x21\xFF", 5);

    emit sendInquiryToSerialPort(autoIcrThreshold);
}

void CameraInquiry::autoIcrAlarmReplyInquiry()
{
    QByteArray autoIcrAlarm("\x81\x09\x04\x31\xFF", 5);

    emit sendInquiryToSerialPort(autoIcrAlarm);
}

void CameraInquiry::memoryInquiry()
{
    QByteArray memory("\x81\x09\x04\x3F\xFF", 5);

    emit sendInquiryToSerialPort(memory);
}

void CameraInquiry::memorySaveInquiry()
{
    QByteArray memorySave("\x81\x09\x04\x23\x0X\xFF", 6);

    emit sendInquiryToSerialPort(memorySave);
}

void CameraInquiry::displayModeInquiry()
{
    QByteArray displayMode("\x81\x09\x04\x15\xFF", 5);

    emit sendInquiryToSerialPort(displayMode);
}

void CameraInquiry::stabilizerModeInquiry()
{
    QByteArray stabilizerMode("\x81\x09\x04\x34\xFF", 5);

    emit sendInquiryToSerialPort(stabilizerMode);
}

void CameraInquiry::muteModeInquiry()
{
    QByteArray muteMode("\x81\x09\x04\x75\xFF", 5);

    emit sendInquiryToSerialPort(muteMode);
}

void CameraInquiry::privacyDisplayInquiry()
{
    QByteArray privacyDisplay("\x81\x09\x04\x77\xFF", 5);

    emit sendInquiryToSerialPort(privacyDisplay);
}

void CameraInquiry::privacyPanTiltInquiry()
{
    QByteArray privacyPanTilt("\x81\x09\x04\x79\xFF", 5);

    emit sendInquiryToSerialPort(privacyPanTilt);
}

void CameraInquiry::privacyMonitorInquiry()
{
    QByteArray privacyMonitor("\x81\x09\x04\x6F\xFF", 5);

    emit sendInquiryToSerialPort(privacyMonitor);
}

void CameraInquiry::idInquiry()
{
    QByteArray idInq("\x81\x09\x04\x22\xFF", 5);

    emit sendInquiryToSerialPort(idInq);
}

void CameraInquiry::versionInquiry()
{
    QByteArray version("\x81\x09\x04\x02\xFF", 5);

    emit sendInquiryToSerialPort(version);
}

void CameraInquiry::mdModeInquiry()
{
    QByteArray mdMode("\x81\x09\x04\x1B\xFF", 5);

    emit sendInquiryToSerialPort(mdMode);
}

void CameraInquiry::mdFunctionInquiry()
{
    QByteArray mdFuncion("\x81\x09\x04\x1C\xFF", 5);

    emit sendInquiryToSerialPort(mdFuncion);
}

void CameraInquiry::mdWindowInquiry(int detectionFrame)
{
    //mdWindow[4] selects the detection frame, values between 0 and 3
    QByteArray mdWindow("\x81\x09\x04\x1D\x00\xFF", 6);

    mdWindow[4] = detectionFrame;

    emit sendInquiryToSerialPort(mdWindow);
}

void CameraInquiry::continuousZoomPosReplyModeInquiry()
{
    QByteArray contZoomPosRepMode("\x81\x09\x04\x69\xFF", 5);

    emit sendInquiryToSerialPort(contZoomPosRepMode);
}

void CameraInquiry::zoomPosReplyIntervalTimeInquiry()
{
    QByteArray zoomPosIntTime("\x81\x09\x04\x6A\xFF", 5);

    emit sendInquiryToSerialPort(zoomPosIntTime);
}

void CameraInquiry::continuousFocusPosReplyModeInquiry()
{
    QByteArray contFocusPosRep("\x81\x09\x04\x16\xFF", 5);

    emit sendInquiryToSerialPort(contFocusPosRep);
}

void CameraInquiry::focusRepIntervalTimeInquiry()
{
    QByteArray focusRepIntTime("\x81\x09\x04\x1A\xFF", 5);

    emit sendInquiryToSerialPort(focusRepIntTime);
}

void CameraInquiry::registerValueInquiry(int regNum)
{
    //registerValue[4] selects the register number from 00f to 7Fh
    QByteArray registerValue("\x81\x09\x04\x24\x00\xFF", 6);

    registerValue[4] = regNum;

    emit sendInquiryToSerialPort(registerValue);
}

void CameraInquiry::colorEnhanceOnOffInquiry()
{
    QByteArray colorEnhanceOnOff("\x81\x09\x04\x50\xFF", 5);

    emit sendInquiryToSerialPort(colorEnhanceOnOff);
}

void CameraInquiry::colorEnhanceInquiry()
{
    QByteArray colorEnhance("\x81\x09\x04\x20\xFF", 5);

    emit sendInquiryToSerialPort(colorEnhance);
}

void CameraInquiry::chromaSuppressInquiry()
{
    QByteArray chromaSuppress("\x81\x09\x04\x5F\xFF", 5);

    emit sendInquiryToSerialPort(chromaSuppress);
}

void CameraInquiry::colorGainInquiry()
{
    QByteArray colorGain("\x81\x09\x04\x49\xFF", 5);

    emit sendInquiryToSerialPort(colorGain);
}

void CameraInquiry::colorHueInquiry()
{
    QByteArray colorHue("\x81\x09\x04\x4F\xFF", 5);

    emit sendInquiryToSerialPort(colorHue);
}

void CameraInquiry::lensTemperatureInquiry()
{
    QByteArray lensTemp("\x81\x09\x04\x68\xFF", 5);

    emit sendInquiryToSerialPort(lensTemp);
}

void CameraInquiry::gammaOffsetInquiry()
{
    QByteArray gammaOffset("\x81\x09\x04\x1E\xFF", 5);

    emit sendInquiryToSerialPort(gammaOffset);
}

void CameraInquiry::contrastAdjLevelInquiry()
{
    QByteArray colorAdjLev("\x81\x09\x04\x5D\xFF", 5);

    emit sendInquiryToSerialPort(colorAdjLev);
}

void CameraInquiry::exExpCompPosInquiry()
{
    //Exposure compensation level between 00h and FFh
    QByteArray expCompPos("\x81\x09\x04\x1F\x4E\xFF", 6);

    emit sendInquiryToSerialPort(expCompPos);
}

void CameraInquiry::exApertureInquiry()
{
    QByteArray exAperture("\x81\x09\x04\x1F\x42\xFF", 6);

    emit sendInquiryToSerialPort(exAperture);
}

void CameraInquiry::exColorGainInquiry()
{
    QByteArray exColorGain("\x81\x09\x04\x1F\x49\x00\xFF", 7);

    emit sendInquiryToSerialPort(exColorGain);
}

void CameraInquiry::exColorHueInquiry()
{
    QByteArray exColorHue("\x81\x09\x04\x1F\x4F\x00\xFF", 7);

    emit sendInquiryToSerialPort(exColorHue);
}

void CameraInquiry::exAutoIcrThresholdInq()
{
    QByteArray exAutoIcrThresh("\x81\x09\x04\x1F\x21\x00\xFF", 7);

    emit sendInquiryToSerialPort(exAutoIcrThresh);
}

void CameraInquiry::exAutoIcrOnLevelInquiry()
{
    QByteArray exAutoIcrOn("\x81\x09\x04\x1F\x21\x01\xFF", 7);

    emit sendInquiryToSerialPort(exAutoIcrOn);
}

void CameraInquiry::minShutterInquiry()
{
    QByteArray minShutter("\x81\x09\x04\x12\xFF", 5);

    emit sendInquiryToSerialPort(minShutter);
}

void CameraInquiry::minShutterLimitInquiry()
{
    QByteArray minShutterLimit("\x81\x09\x04\x13\xFF", 5);

    emit sendInquiryToSerialPort(minShutterLimit);
}

void CameraInquiry::hlcInquiry()
{
    QByteArray hlcInq("\x81\x09\x04\x14\xFF", 5);

    emit sendInquiryToSerialPort(hlcInq);
}





