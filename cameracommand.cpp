#include "cameracommand.h"
#include "controller.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlProperty>
#include <QThread>


// contructor for CameraCommand object --------------------need to clean up
CameraCommand::CameraCommand()
{
    //bool needed for string conversion to int
    ok = new bool;

//    cameraSetup();
}

void CameraCommand::cameraSetup()
{
    //These are the default values when switching on the camera
    QByteArray exposureOn("\x81\x01\x04\x3E\x02\xFF",6);

    emit sendToSerialPort(exposureOn);

    QByteArray zoomCombined("\x81\x01\x04\x36\x00\xFF",6);
    emit sendToSerialPort(zoomCombined);

    QByteArray displayOn("\x81\x01\x04\x15\x02\xFF",6);
    emit sendToSerialPort(displayOn);

    QByteArray autoFocusON("\x81\x01\x04\x38\x02\xFF", 6);
    emit sendToSerialPort(autoFocusON);

    QByteArray infraRedOFF("\x81\x01\x04\x01\x03\xFF", 6);
    emit sendToSerialPort(infraRedOFF);

    QByteArray irCorrectionStandard("\x81\x01\x04\x11\x00\xFF");
    emit sendToSerialPort(irCorrectionStandard);
}

void CameraCommand::valueInQML(QString mes)
{
    emit sendInQML(mes);
}

void CameraCommand::sendZoomSpeed(int mes)
{
    QByteArray zoomVal("\x81\x01\x04\x07\x00\xFF",6);
    if(mes < 0) {
        zoomVal[4] = 48-(mes+1);
    } else if(mes > 0) {
        zoomVal[4] = 32+(mes-1);
    } else if (mes == 0) {
        zoomVal[4] = 00;
    }

    emit sendToSerialPort(zoomVal);
}

void CameraCommand::sendZoomPosition(int mes)
{
    QString hex;                // check if there is a way how to minify it
    hex.setNum(mes, 16);
    hex = hex.rightJustified(4,'0');

    QByteArray zoomPosition("\x81\x01\x04\x47\x00\x00\x00\x00\xFF", 9);

    zoomPosition[4] = QString(hex.at(0)).toInt(ok,16); // try true instead of ok
    zoomPosition[5] = QString(hex.at(1)).toInt(ok,16);
    zoomPosition[6] = QString(hex.at(2)).toInt(ok,16);
    zoomPosition[7] = QString(hex.at(3)).toInt(ok,16);

    emit sendToSerialPort(zoomPosition);
}

void CameraCommand::sendDigitalZoomSwitch(int mes)
{

    QByteArray digitalzoom("\x81\x01\x04\x06\x02\xFF", 6);

    digitalzoom[4] = mes;

    emit sendToSerialPort(digitalzoom);
}

void CameraCommand::sendZoomMode(int mes)
{
    QByteArray zoomMode("\x81\x01\x04\x36\x00\xFF",6);

    zoomMode[4] = mes;

    emit sendToSerialPort(zoomMode);
}

void CameraCommand::sendDigitalZoomValue(int mes)
{
    QByteArray digitalZoomVal("\x81\x01\x04\x06\x00\xFF",6);

    int x;
    x = mes;

    if(x<0)
    {
        digitalZoomVal[4] = 48-(x+1);
    }else if(x>0)
    {
        digitalZoomVal[4] = 32+(x-1);
    }else if(x==0)
    {
        digitalZoomVal[4] = 00;
    }

    emit sendToSerialPort(digitalZoomVal);
}

void CameraCommand::sendDigitalZoomPosition(int mes)
{
    QString hex;
    hex.setNum(mes, 16);
    hex = hex.rightJustified(2,'0');
    QString a = hex.at(0);
    QString b = hex.at(1);

    QByteArray zoomDigitalPosition = "\x81\x01\x04\x46\x00\x00";
    zoomDigitalPosition.resize(9);

    zoomDigitalPosition[6] = a.toInt(ok,16);
    zoomDigitalPosition[7] = b.toInt(ok,16);
    zoomDigitalPosition[8] = 255;

    emit sendToSerialPort(zoomDigitalPosition);
}

void CameraCommand::sendMaxSwitch()
{
    QByteArray maxSwitch("\x81\x01\x04\x06\x10\xFF");

    emit sendToSerialPort(maxSwitch);
}

void CameraCommand::sendExposureCompensation(int mes)
{

    QByteArray exposureVal ("\x81\x01\x04\x0E\x02\xFF");


    exposureVal[4] = mes;

    emit sendToSerialPort(exposureVal);
}

void CameraCommand::sendFocusSpeed(int mes)
{
    QByteArray focusVal("\x81\x01\x04\x08\x00\xFF",6);

    if(mes<0)
    {
        focusVal[4] = 48-(mes+1);
    }else if(mes>0)
    {
        focusVal[4] = 32+(mes-1);
    }else if(mes==0)
    {
        focusVal[4] = 00;
    }

    emit sendToSerialPort(focusVal);
}

void CameraCommand::sendFocusFixedPosition(int mes)
{
    QString hex;

    hex.setNum(mes, 16);

    //Justification is needed to always have at least four digits to put in the Byte Array
    hex = hex.rightJustified(4, '0');

    //Estract the digits to put in the Byte Array
    QString a = hex.at(0);

    QString b = hex.at(1);

    QString c = hex.at(2);

    QString d = hex.at(3);

    //this method is more reliable than others
    QByteArray focusPosition = "\x81\x01\x04\x48";

    focusPosition.resize(9);
    focusPosition[4] = a.toInt(ok, 16);
    focusPosition[5] = b.toInt(ok, 16);
    focusPosition[6] = c.toInt(ok, 16);
    focusPosition[7] = d.toInt(ok, 16);
    focusPosition[8] = 255;

    emit sendToSerialPort(focusPosition);
}

void CameraCommand::sendFocusNearLimit(int mes)
{
    QString hex;

    hex.setNum(mes, 16);

    //Justification is needed to always have at least four digits to put in the Byte Array
    hex = hex.rightJustified(4, '0');

    //Estract the digits to put in the Byte Array
    QString a = hex.at(0);

    QString b = hex.at(1);

    QString c = hex.at(2);

    QString d = hex.at(3);

    //this method is more reliable than others
    QByteArray focusPosition = "\x81\x01\x04\x28";

    focusPosition.resize(9);
    focusPosition[4] = a.toInt(ok, 16);
    focusPosition[5] = b.toInt(ok, 16);
    focusPosition[6] = c.toInt(ok, 16);
    focusPosition[7] = d.toInt(ok, 16);
    focusPosition[8] = 255;

    emit sendToSerialPort(focusPosition);
}

void CameraCommand::sendAutoManualFocus(QString mes)
{
    //QString a = "3";
    QByteArray autofocus ("\x81\x01\x04\x38\x02\xFF", 6);

    autofocus [4] = mes.toInt(ok);


    emit sendToSerialPort(autofocus);
}

void CameraCommand::sendAutoFocusMode(QString mes)
{
    QByteArray afmode("\x81\x01\x04\x57\x00\xFF",6);

    afmode[4] = mes.toInt(ok);


    emit sendToSerialPort(afmode);
}

void CameraCommand::sendOnePushAFTrigger()
{
    QByteArray onepushaf("\x81\x01\x04\x38\x02\xFF");

    emit sendToSerialPort(onepushaf);
}

void CameraCommand::sendAfSens(QString mes)
{
    QByteArray afsens("\x81\x01\x04\x58\x02\xFF");

    afsens[4] = mes.toInt(ok);

    emit sendToSerialPort(afsens);
}

void CameraCommand::sendInfraRed(QString mes)
{
    QByteArray infraRed("\x81\x01\x04\x01\x03\xFF");

    infraRed[4] = mes.toInt(ok);
    
    emit sendToSerialPort(infraRed);
}

void CameraCommand::sendIrCorrection(QString mes)
{
    QByteArray irCorrection("\x81\x01\x04\x11\x00\xFF");
    if(mes == "irLight")
    {
        irCorrection[4] = 0x01;
    }
    emit sendToSerialPort(irCorrection);
}

void CameraCommand::sendCameraCommandInit(QString mes)
{
    QByteArray cameraInit;
    if(mes == "LensInit")
    {
        cameraInit = "\x81\x01\x04\x19\x01\xFF";
    }else if (mes == "CameraReset")
    {
        cameraInit = "\x81\x01\x04\x19\x03\xFF";
    }
    emit sendToSerialPort(cameraInit);
}

void CameraCommand::sendCameraCommandPower(QString mes)
{
    QByteArray cameraPower("\x81\x01\x04\x00\x02\xFF", 6);

    cameraPower[4] = mes.toInt(ok);

    emit sendToSerialPort(cameraPower);
}

void CameraCommand::sendCameraCommandMode(QString mes)
{
    QByteArray cameraMode("\x81\x01\x04\x35\x00\xFF", 6);
    if(mes == "normalAuto")
    {
        cameraMode[4] = 0x00;
    }else if(mes == "indoorMode")
    {
        cameraMode[4] = 0x01;
    }else if(mes == "outdoorMode")
    {
        cameraMode[4] = 0x02;
    }else if(mes == "onePushWBMode")
    {
        cameraMode[4] = 0x03;
    }else if(mes == "autoTracingWhiteBalance")
    {
        cameraMode[4] = 0x04;
    }else if(mes == "manualControlMode")
    {
        cameraMode[4] = 0x05;
    }else if(mes == "onePushWBTrigger")
    {
        cameraMode[3] = 0x10;
        cameraMode[4] = 0x05;
    }else if(mes == "outdoorAuto")
    {
        cameraMode[4] = 0x06;
    }else if(mes == "autoInclSodiumLamp")
    {
        cameraMode[4] = 0x07;
    }else if(mes == "sodiumLampFixed")
    {
        cameraMode[4] = 0x08;
    }else if(mes == "sodiumOutdoorAuro")
    {
        cameraMode[4] = 0x09;
    }

    emit sendToSerialPort(cameraMode);
}

void CameraCommand::sendRGain(QString mes)
{
    QByteArray rGain ("\x81\x01\x04\x03\x00\xFF", 6);

    if(mes == "plusRGain")
    {
        rGain[4] = 0x02;
    }else if(mes == "minusRGain")
    {
        rGain[4] = 0x03;
    }else if(mes == "resetRGain")
    {
        rGain[4] = 0x00;
    }

    emit sendToSerialPort(rGain);
}

void CameraCommand::sendBGain(QString mes)
{
    QByteArray bGain ("\x81\x01\x04\x04\x00\xFF", 6);

    if(mes == "plusBGain")
    {
        bGain[4] = 0x02;
    }else if(mes == "minusBGain")
    {
        bGain[4] = 0x03;
    }else if(mes == "resetBGain")
    {
        bGain[4] = 0x00;
    }

    emit sendToSerialPort(bGain);
}

void CameraCommand::sendExposureMode(QString mes)
{
    QByteArray exposureMode("\x81\x01\x04\x39\x00\xFF", 6);
    if(mes == "autoExp")
    {
        exposureMode[4] = 0x00;
    }else if(mes == "manualExp")
    {
        exposureMode[4] = 0x03;
    }else if(mes == "shutterExp")
    {
        exposureMode[4] = 0x0A;
    }else if(mes == "irisExp")
    {
        exposureMode[4] = 0x0B;
    }else if(mes == "brightExp")
    {
        exposureMode[4] = 0x0D;
    }
    emit sendToSerialPort(exposureMode);
}

void CameraCommand::sendAutoSlowShutter(QString mes)
{
    QByteArray autoSlowShutter("\x81\x01\x04\x5A\x02\xFF", 6);

    autoSlowShutter[4] = mes.toInt(ok);

    emit sendToSerialPort(autoSlowShutter);
}

void CameraCommand::sendShutter(QString mes)
{
    QByteArray shutter("\x81\x01\x04\x0A\x00\xFF", 6);
    if(mes == "resetShutter")
    {
        shutter[4] = 0x00;
    }else if(mes == "plusShutter")
    {
        shutter[4] = 0x02;
    }else if(mes == "minusShutter")
    {
        shutter[4] = 0x03;
    }

    emit sendToSerialPort(shutter);
}

void CameraCommand::sendIrisValue(QString mes)
{
    QByteArray iris ("\x81\x01\x04\x0B\x00\xFF", 6);
    if(mes == "resetIris")
    {
        iris[4] = 0x00;
    }else if(mes == "plusIris")
    {
        iris[4] = 0x02;
    }else if(mes == "minusIris")
    {
        iris[4] = 0x03;
    }

    emit sendToSerialPort(iris);
}

void CameraCommand::sendGainValue(QString mes)
{
    QByteArray gain ("\x81\x01\x04\x0C\x00\xFF", 6);
    if(mes == "resetGain")
    {
        gain[4] = 0x00;
    }else if(mes == "plusGain")
    {
        gain[4] = 0x02;
    }else if(mes == "minusGain")
    {
        gain[4] = 0x03;
    }

    emit sendToSerialPort(gain);
}

void CameraCommand::sendBrightValue(QString mes)
{
    QByteArray bright ("\x81\x01\x04\x0D\x00\xFF", 6);
    if(mes == "resetBright")
    {
        bright[4] = 0x00;
    }else if(mes == "plusBright")
    {
        bright[4] = 0x02;
    }else if(mes == "minusBright")
    {
        bright[4] = 0x03;
    }

    emit sendToSerialPort(bright);
}

void CameraCommand::sendBackLightValue(QString mes)
{
    QByteArray backLight("\x81\x01\x04\x33\x02\xFF", 6);
    if(mes == "On")
    {
        backLight[4] = 0x02;
    }else if(mes == "Off")
    {
        backLight[4] = 0x03;
    }
    emit sendToSerialPort(backLight);
}

void CameraCommand::sendAeSpotModeValue(QString mes)
{
    QByteArray spotMode("\x81\x01\x04\x59\x02\xFF", 6);

    spotMode[4] = mes.toInt(ok);

    emit sendToSerialPort(spotMode);
}

void CameraCommand::sendAePositionSpotValue(QString x, QString y)
{
    //    convert QString to int

    QString a = x.at(0);
    QString b = x.at(1);
    QString c = y.at(0);
    QString d = y.at(1);
    QByteArray e = QByteArray::fromHex(a.toUtf8());
    QByteArray f = QByteArray::fromHex(b.toUtf8());
    QByteArray g = QByteArray::fromHex(c.toUtf8());
    QByteArray h = QByteArray::fromHex(d.toUtf8());

    //this method is more reliable than others
    QByteArray AEPosition = "\x81\x01\x04\x47";

    AEPosition.resize(9);
    AEPosition[4] = e[0];
    AEPosition[5] = f[0];
    AEPosition[6] = g[0];
    AEPosition[7] = h[0];
    AEPosition[8] = 255;

    emit sendToSerialPort(AEPosition);
}

void CameraCommand::sendAeResponseValue(QString mes)
{
    QByteArray AEResponse ("\x81\x01\x04\x5D\x00\xFF", 6);
    AEResponse[4] = mes.toInt(ok);

    emit sendToSerialPort(AEResponse);
}

void CameraCommand::sendCamVeMode(QString mes)
{
    QByteArray camVeMode ("\x81\x01\x04\x3D\x03\xFF", 6);
    camVeMode[4] = mes.toInt(ok);

    emit sendToSerialPort(camVeMode);
}

void CameraCommand::sendCamVeParameter(QString bright, QString compSel, QString compLevel)
{
    QByteArray camVeParameter ("\x81\x01\x04\x2D\x00\x00\x00\x00\x00\x00\x00\x00\xFF", 13);

    camVeParameter[5] = bright.toInt(ok);
    camVeParameter[6] = compSel.toInt(ok);
    camVeParameter[7] = compLevel.toInt(ok);

    emit sendToSerialPort(camVeParameter);
}

void CameraCommand::sendCamWdMode(QString mes)
{
    QByteArray camWdMode ("\x81\x01\x04\x3D\x03\xFF", 6);
    camWdMode[4] = mes.toInt(ok);

    emit sendToSerialPort(camWdMode);
}

void CameraCommand::sendDefogMode(QString state, QString level)
{
    QByteArray defogMode ("\x81\x01\x04\x37\x03\x03\xFF", 7);
    defogMode[4] = state.toInt(ok);   //State on/off
    defogMode[5] = level.toInt(ok);

    emit sendToSerialPort(defogMode);
}

void CameraCommand::sendCamAperture(QString aperture)
{
    QByteArray apertureValue ("\x81\x01\x04\x02\x00\xFF", 6);
    apertureValue[4] = aperture.toInt(ok);

    emit sendToSerialPort(apertureValue);
}

void CameraCommand::sendCamAperturePosition(QString aperturePos)
{
    QString a = aperturePos.at(0);
    QString b = aperturePos.at(1);

    QByteArray x = QByteArray::fromHex(a.toUtf8());
    QByteArray y = QByteArray::fromHex(b.toUtf8());

    QByteArray apertureValuePos ("\x81\x01\x04\x42\x00\x00\x00\x00\xFF", 9);
    apertureValuePos[6] = x[0];
    apertureValuePos[7] = y[0];

    emit sendToSerialPort(apertureValuePos);
}

void CameraCommand::sendCamHrMode(QString hrMode)
{
    QByteArray hrValue ("\x81\x01\x04\x52\x02\xFF", 6);
    hrValue[4] = hrMode.toInt(ok);   //State on/off

    emit sendToSerialPort(hrValue);
}

void CameraCommand::sendCamNoiseReduction(QString nrValue)
{
    QByteArray noiseRed ("\x81\x01\x04\x53\x00\xFF", 6);
    noiseRed[4] = nrValue.toInt(ok);

    emit sendToSerialPort(noiseRed);
}

void CameraCommand::sendNoiseReductionIntipendent(QString nrInd)
{
    QString a = nrInd.at(0);
    QString b = nrInd.at(1);

    QByteArray x = QByteArray::fromHex(a.toUtf8());
    QByteArray y = QByteArray::fromHex(b.toUtf8());

    QByteArray noiseIndipendentReduction ("\x81\x01\x05\x53\x00\x00\xFF", 7);
    noiseIndipendentReduction[4] = x[0];
    noiseIndipendentReduction[5] = y[0];

    emit sendToSerialPort(noiseIndipendentReduction);
}

void CameraCommand::sendCamGammaValue(QString gamma)
{
    QByteArray gammaValue ("\x81\x01\x04\x5B\x00\xFF", 6);
    gammaValue[4] = gamma.toInt(ok);

    emit sendToSerialPort(gammaValue);
}

void CameraCommand::sendHighSensitivityMode(QString mode)
{
    QByteArray sensMode ("\x81\x01\x04\x5E\x02\xFF", 6);
    sensMode[4] = mode.toInt(ok);

    emit sendToSerialPort(sensMode);
}

void CameraCommand::sendLrReverse(QString mode)
{
    QByteArray lrMode ("\x81\x01\x04\x61\x02\xFF", 6);
    lrMode[4] = mode.toInt(ok);

    emit sendToSerialPort(lrMode);
}

void CameraCommand::sendCamFreeze(QString mode)
{
    QByteArray freezeValue ("\x81\x01\x04\x62\x02\xFF", 6);
    freezeValue[4] = mode.toInt(ok);

    emit sendToSerialPort(freezeValue);
}

void CameraCommand::sendPictureEffect(QString mode)
{
    //0 off, 2 Neg.Art, 3 Black & White
    QByteArray pictureEffect ("\x81\x01\x04\x63\x02\xFF", 6);
    pictureEffect[4] = mode.toInt(ok);

    emit sendToSerialPort(pictureEffect);
}

void CameraCommand::sendMinimumShutterMode(QString mode)
{
    QByteArray minShutterMode ("\x81\x01\x04\x12\x03\xFF", 6);
    minShutterMode[4] = mode.toInt(ok);

    emit sendToSerialPort(minShutterMode);
}

void CameraCommand::sendMinimumShutterLimitPos(QString pos)
{
    QString a = pos.at(0);
    QString b = pos.at(1);

    QByteArray x = QByteArray::fromHex(a.toUtf8());
    QByteArray y = QByteArray::fromHex(b.toUtf8());

    QByteArray minShutterPos ("\x81\x01\x04\x13\x00\x00\x00\xFF", 8);
    minShutterPos[5] = x[0];
    minShutterPos[6] = y[0];

    emit sendToSerialPort(minShutterPos);
}

void CameraCommand::sendPictureFlipMode(QString mode)
{
    QByteArray flipMode ("\x81\x01\x04\x66\x03\xFF", 6);
    flipMode[4] = mode.toInt(ok);

    emit sendToSerialPort(flipMode);
}

void CameraCommand::sendIcrMode(QString mode)
{
    QByteArray icrMode ("\x81\x01\x04\x01\x03\xFF", 6);
    icrMode[4] = mode.toInt(ok);

    emit sendToSerialPort(icrMode);
}

void CameraCommand::sendAutoIcrMode(QString mode)
{
    QByteArray autoIcrMode ("\x81\x01\x04\x51\x03\xFF", 6);
    autoIcrMode[4] = mode.toInt(ok);

    emit sendToSerialPort(autoIcrMode);
}

void CameraCommand::sendAutoIcrThresholdLevel(QString level)
{
    QString a = level.at(0);
    QString b = level.at(1);

    QByteArray x = QByteArray::fromHex(a.toUtf8());
    QByteArray y = QByteArray::fromHex(b.toUtf8());

    QByteArray threshLevel ("\x81\x01\x04\x21\x00\x00\x00\x00\xFF", 9);
    threshLevel[6] = x[0];
    threshLevel[7] = y[0];

    emit sendToSerialPort(threshLevel);
}

void CameraCommand::sendAutoIcrAlarmMode(QString mode)
{
    QByteArray icrAlarmMode ("\x81\x01\x04\x31\x03\xFF", 6);
    icrAlarmMode[4] = mode.toInt(ok);

    emit sendToSerialPort(icrAlarmMode);
}

void CameraCommand::sendCamStabilizerMode(QString mode)
{
    //2 On, 3 Off, 0 Hold
    QByteArray camStab ("\x81\x01\x04\x34\x03\xFF", 6);
    camStab[4] = mode.toInt(ok);

    emit sendToSerialPort(camStab);
}

void CameraCommand::sendCamMemory(QString mode, QString memNum)
{
    QByteArray camMem ("\x81\x01\x04\x3F\x00\x00\xFF", 7);
    camMem[4] = mode.toInt(ok);
    camMem[5] = memNum.toInt(ok);

    emit sendToSerialPort(camMem);
}

void CameraCommand::sendCamCustomMode(QString mode)
{
    //Starts up in this mode when the power is turned off
    //0 reset, 1 set, 2 recall
    QByteArray camCustom ("\x81\x01\x04\x3F\x00\x7F\xFF", 7);
    camCustom[4] = mode.toInt(ok);

    emit sendToSerialPort(camCustom);
}

void CameraCommand::sendMemorySave(QString address, QString dataValue)
{
    //    convert QString to int
    dataValue = dataValue.rightJustified(4, '0');

    QString a = dataValue.at(0);
    QString b = dataValue.at(1);
    QString c = dataValue.at(2);
    QString d = dataValue.at(3);
    QByteArray e = QByteArray::fromHex(a.toUtf8());
    QByteArray f = QByteArray::fromHex(b.toUtf8());
    QByteArray g = QByteArray::fromHex(c.toUtf8());
    QByteArray h = QByteArray::fromHex(d.toUtf8());

    QByteArray memSave = "\x81\x01\x04\x23";

    memSave.resize(10);
    memSave[4] = address.toInt(ok);
    memSave[5] = e[0];
    memSave[6] = f[0];
    memSave[7] = g[0];
    memSave[8] = h[0];
    memSave[9] = 255;

    emit sendToSerialPort(memSave);
}

void CameraCommand::sendCamDisplay()
{
    //Switch on and off with the same command
    QByteArray displaySwitch("\x81\x01\x04\x15\x10\xFF", 6);

    emit sendToSerialPort(displaySwitch);
}

void CameraCommand::sendMuteMode()
{
    //Switch on and off with the same command
    QByteArray muteMode("\x81\x01\x04\x75\x10\xFF", 6);

    emit sendToSerialPort(muteMode);
}

void CameraCommand::sendCamIDWriteOn()
{
    //Switch on and off with the same command
    QByteArray idWriteOn("\x81\x01\x04\x7C\x04\xFF", 6);

    emit sendToSerialPort(idWriteOn);
}

void CameraCommand::sendContinuousZoomPosReply(QString mode)
{
    //If contZoomReply[4] is 02 mode On, if contZoomReply[4] is 03 mode Off
    QByteArray contZoomReply ("\x81\x01\x04\x69\x03\xFF", 6);
    contZoomReply[4] = mode.toInt(ok);

    emit sendToSerialPort(contZoomReply);
}

void CameraCommand::sendZoomReplyIntervalTime(QString interTime)
{
    QString a = interTime.at(0);
    QString b = interTime.at(1);

    QByteArray x = QByteArray::fromHex(a.toUtf8());
    QByteArray y = QByteArray::fromHex(b.toUtf8());

    QByteArray itervalZoom ("\x81\x01\x04\x6A\x00\x00\x00\x00\xFF", 9);
    itervalZoom[6] = x[0];
    itervalZoom[7] = y[0];

    emit sendToSerialPort(itervalZoom);
}

void CameraCommand::sendContinuousFocusPosReply(QString mode)
{
    //If contFocusReply[4] is 02 mode On, if contFocusReply[4] is 03 mode Off
    QByteArray contFocusReply ("\x81\x01\x04\x16\x03\xFF", 6);
    contFocusReply[4] = mode.toInt(ok);

    emit sendToSerialPort(contFocusReply);
}

void CameraCommand::sendFocusReplyIntervalTime(QString interTime)
{
    QString a = interTime.at(0);
    QString b = interTime.at(1);

    QByteArray x = QByteArray::fromHex(a.toUtf8());
    QByteArray y = QByteArray::fromHex(b.toUtf8());

    QByteArray itervalFocus ("\x81\x01\x04\x1A\x00\x00\x00\x00\xFF", 9);
    itervalFocus[6] = x[0];
    itervalFocus[7] = y[0];

    emit sendToSerialPort(itervalFocus);
}

void CameraCommand::sendRegisterValue(QString regNum, QString regValue)
{
    //    convert QString to int
    regNum = regNum.rightJustified(2, '0');

    QString a = regNum.at(0);
    QString b = regNum.at(1);

    QByteArray c = QByteArray::fromHex(a.toUtf8());
    QByteArray d = QByteArray::fromHex(b.toUtf8());

    QByteArray registerToChange ("\x81\x01\x04\x24\x00\x00\x00\xFF", 8);

    registerToChange[4] = regValue.toInt(ok);
    registerToChange[5] = c[0];
    registerToChange[6] = d[0];

    emit sendToSerialPort(registerToChange);
}

void CameraCommand::sendColorEnhanceMode(QString mode)
{
    //2 On 3 Off
    QByteArray colorEnhance ("\x81\x01\x04\x50\x03\xFF", 6);
    colorEnhance[4] = mode.toInt(ok);

    emit sendToSerialPort(colorEnhance);
}

void CameraCommand::sendColorEnhanceValue(QString thresholdLev, QString yHigh, QString crHigh, QString cbHigh, QString yLow, QString crLow, QString cbLow)
{
    //All values from 00h to 7Fh
    QByteArray colorHenance("\x81\x01\x04\x20\x00\x00\x00\x00\x00\x00\x00\x00\xFF", 13);

    colorHenance[4] = thresholdLev.toInt(ok);
    colorHenance[6] = yHigh.toInt(ok);
    colorHenance[7] = crHigh.toInt(ok);
    colorHenance[8] = cbHigh.toInt(ok);
    colorHenance[9] = yLow.toInt(ok);
    colorHenance[10] = crLow.toInt(ok);
    colorHenance[11] = cbLow.toInt(ok);

    emit sendToSerialPort(colorHenance);
}

void CameraCommand::sendChromaSuppressLevel(QString chromaLevel)
{
    //00 Off, levels from 01h to 03h, effect increases as the level number increases
    QByteArray chromeArray ("\x81\x01\x04\x5F\x00\xFF", 6);
    chromeArray[4] = chromaLevel.toInt(ok);

    emit sendToSerialPort(chromeArray);
}

void CameraCommand::sendColorGainLevel(int gainLevel)
{
    //Color Gain Setting 0h(60%) to Eh(200%)
    QByteArray colorGain("\x81\x01\x04\x49\x00\x00\x00\x00\xFF", 9);
    colorGain[7] = gainLevel;

    emit sendToSerialPort(colorGain);
}

void CameraCommand::sendColorHueLevel(int hueLevel)
{
    //Color Hue Setting 0h(-14 degrees) to Eh(+14 degrees)
    QByteArray colorHue("\x81\x01\x04\x4F\x00\x00\x00\x00\xFF", 9);

    colorHue[7] = hueLevel;

    emit sendToSerialPort(colorHue);
}

void CameraCommand::sendGammaOffset(int polarityOffset, int offset)
{
    //polarityOffset 0 is minus, 1 is plus,
    //if polarityOffset is 0 offset is between 00h and 40h, if is 1 offset between 00h and 10h
    QByteArray gammaOffset("\x81\x01\x04\x1E\x00\x00\x00\x00\x00\x00\xFF", 11);

    gammaOffset[7] = polarityOffset;
    gammaOffset[8] = offset/10;
    gammaOffset[9] = offset%10;

    emit sendToSerialPort(gammaOffset);
}

void CameraCommand::sendContrastAdjLevel(int contrast)
{
    /*contrast between 00h and FFh.
      00h to 7Fh: Smaller the value is, the lower the contrast becomes.
      80h initial setting
      81h to FFh: The larger the value is, the higher the contrast becomes*/

    QByteArray contrastLevel("\x81\x01\x05\x5D\x01\x00\x00\xFF", 8);

    contrastLevel[5] = contrast/10;
    contrastLevel[6] = contrast%10;

    emit sendToSerialPort(contrastLevel);
}

void CameraCommand::sendExExpComp(int value, int upDownReset)
{
    /*If upDownReset is 0 then reset, if it's 2 then up, if it's 3 then down, value can be between 00h and 07h*/

    QByteArray exposureComp("\x81\x01\x04\x1F\x0E\x00\x00\xFF", 8);

    exposureComp [5] = upDownReset;
    exposureComp [6] = value;

    emit sendToSerialPort(exposureComp);
}

void CameraCommand::sendExAperture(int value, int upDownReset)
{
    /*If upDownReset is 0 then reset, if it's 2 then up, if it's 3 then down, value can be between 00h and 07h*/

    QByteArray exposureAperture("\x81\x01\x04\x1F\x02\x00\x00\xFF", 8);

    exposureAperture [5] = upDownReset;
    exposureAperture [6] = value;

    emit sendToSerialPort(exposureAperture);
}

void CameraCommand::sendExAutoICR(int value, int switchOnOff)
{
    /*If switchOnOff is 0 then from On to Off and Threshold level when Auto ICR is from 00h to FFh
      if switchOnOff is 1 then from Off to On and Threshold level when Auto ICR is from 00h to 1Ch*/

    QByteArray exAutoICR("\x81\x01\x04\x1F\x21\x00\x00\x00\x00\xFF", 10);

    exAutoICR [5] = switchOnOff;
    exAutoICR [7] = value/10;
    exAutoICR [8] = value%10;

    emit sendToSerialPort(exAutoICR);
}

void CameraCommand::sendExColorGain(int value)
{
    //value is Gain setting level between 00h(0%) and FFh(200%)

    QByteArray exColorGain("\x81\x01\x04\x1F\x49\x00\x00\x00\x00\xFF", 10);

    exColorGain[7] = value/10;
    exColorGain[8] = value%10;

    emit sendToSerialPort(exColorGain);
}

void CameraCommand::sendExColorHue(int value)
{
    //value is Phase setting level between 00h(-14 degrees) and FFh(14 degrees)

    QByteArray exColorHue("\x81\x01\x04\x1F\x4F\x00\x00\x00\x00\xFF", 10);

    exColorHue[7] = value/10;
    exColorHue[8] = value%10;

    emit sendToSerialPort(exColorHue);
}

void CameraCommand::sendHclLevel(int level,int maskLevel)
{
    /*level 0 Off; 1 Low; 2 Mid; 3 High
     * maskLevel 0 Off, then from 1 low to F high level*/

    QByteArray hclLevel("\x81\x01\x04\x14\x00\x00\xFF", 7);

    hclLevel[4] = level;
    hclLevel[5] = level;

    emit sendToSerialPort(hclLevel);
}

void CameraCommand::sendBaudRate(QString mes)
{
    QByteArray baudRate("\x81\x01\x04\x24\x00\x00\x00\xFF", 8);
    if(mes == "9600")

        baudRate[6] = mes.toInt(ok);

    int baudInt = mes.toInt(ok, 10);
    emit sendToSerialPort(baudRate);
}
