#include "controller.h"
#include "cameracommand.h"
#include "serial.h"
#include <QQmlContext>

Controller::Controller() // if not needed then delete it
{

}

void Controller::zoomSignalReceiver(int message)
{
    emit signalZoomToSend(message);
}

void Controller::zoomPositionSignalReceiver(int message)
{
    emit signalZoomPositionToSend(message);
}

void Controller::digitalzoomswitchSignalReceiver(int message)
{
    emit signalDigitalZoomSwitchToSend(message);
}

void Controller::zoommodeSignalReceiver(int message)
{
    emit signalZoomModeToSend(message);
}

void Controller::zoomDigitalValueSignalReceiver(int message)
{
    emit signalDigitalZoomValueToSend(message);
}

void Controller::zoomDigitalPositionSignalReceiver(int message)
{
    emit signalDigitalZoomPositionToSend(message);
}

void Controller::maxSwitchReceiver(void)
{
    emit signalMaxSwitch();
}

void Controller::focusSignalReceiver(int message)
{
    emit signalFocusToSend(message);
}

void Controller::focusFixedPositionSignalReceiver(int message)
{
    emit signalFocusFixedPositionToSend(message);
}

void Controller::focusNearLimitSignalReceiver(int message)
{
    emit signalFocusNearLimitToSend(message);
}

void Controller::exposureSignalReceiver(int message)
{
    emit signalExposureToSend(message);
}

void Controller::autofocusSignalReceiver(QString message)
{
    emit signalAutoFocusToSend(message);
}

void Controller::autofocusmodeSignalReceiver(QString message)
{
    emit signalAutoFocusModeToSend(message);
}

void Controller::onepushafSignalReceiver(QString message)
{
    emit signalOnePushAFToSend(message);

}

void Controller::afsensSignalReceiver(QString message)
{
    emit signalAfSensToSend(message);
}

void Controller::infraRedSignalReceiver(QString message)
{
    emit signalInfraRedToSend(message);

}

void Controller::irCorrectionSignalReceiver(QString message)
{
    emit signalIRCorrectionToSend(message);
}

void Controller::cameraInitSignalReceiver(QString message)
{
    emit signalCameraInitToSend(message);
}

void Controller::cameraPowerSignalReceiver(QString message)
{
    emit signalCameraPowerToSend(message);
}

void Controller::cameraModeSignalReceiver(QString message)
{
    emit signalCameraModeToSend(message);
}

void Controller::rGainSignalReceiver(QString message)
{
    emit signalRGainToSend(message);
}

void Controller::bGainSignalReceiver(QString message)
{
    emit signalBGainToSend(message);
}

void Controller::exposureModeSignalReceiver(QString message)
{
    emit signalExposureModeToSend(message);
}

void Controller::autoSlowShutterReceiver(QString message)
{
    emit signalAutoSlowShutter(message);
}

void Controller::shutterSignalReceiver(QString message)
{
    emit signalShutterToSend(message);
}

void Controller::irisSignalReceiver(QString message)
{
    emit signalIrisToSend(message);
}

void Controller::gainSignalReceiver(QString message)
{
    emit signalGainToSend(message);
}

void Controller::brightSignalReceiver(QString message)
{
    emit signalBrightToSend(message);
}

void Controller::backLightSignalReceiver(QString message)
{
    emit signalBackLightToSend(message);
}

void Controller::aeSpotModeSignalReceiver(QString message)
{
    emit signalAeSpotModeToSend(message);
}

void Controller::baudRateSignalReceiver(QString message)
{
    emit signalBaudRateToSend(message);
}

void Controller::newScreenshotReceiver()
{
    emit signalNewScreenshot();
}

void Controller::saveScreenshotReceiver()
{
    emit signalSaveScreenshot();
}

QString Controller::getZoomInquiryValue()
{
    return zoomInquiryValue;
}

void Controller::setZoomVarToBeRead(QString message)
{
    zoomInquiryValue = message;
    emit dataChanged();

    qDebug()<<"inside setzoomvar"<<message;
}
