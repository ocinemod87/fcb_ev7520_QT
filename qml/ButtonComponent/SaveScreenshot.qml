import QtQuick 2.9
import QtQuick.Controls 2.2
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: saveScreenshotButton
    width: 30
    height: 30
    implicitWidth: width
    implicitHeight: height
    Text{
        text: "Save Screenshot"
        color: "white"
        anchors.centerIn: parent.Center
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
    onClicked: commandSignal.saveScreenshotReceiver()
}
