import QtQuick 2.9
import QtQuick.Controls 2.2
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: minusExposureIconButton
    width: 30
    height: 30
    implicitWidth: width
    implicitHeight: height
    Image{
        //this image is 64 pixel in GIMP
        width: minusExposureIconButton.width
        height: minusExposureIconButton.height
        source: "qrc:/qml/Icons/minusIcon.png"
        anchors.centerIn: minusExposureIconButton.Center
    }

    onClicked: commandSignal.exposureSignalReceiver(3)
}
