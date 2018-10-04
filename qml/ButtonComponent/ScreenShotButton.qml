import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: powerIconButton
    width: 30
    height: 30
    implicitWidth: width
    implicitHeight: height
    Layout.leftMargin: (sideMenu.width - width)/2
    Layout.topMargin: columnVerticalMargin
    Image{
        //this image is 64 pixel in GIMP
        width: powerIconButton.width
        height: powerIconButton.height
        source: "qrc:/qml/Icons/CameraIcon64.png"
        anchors.centerIn: powerIconButton.Center
    }
    ToolTip {
            parent: mouseAreaIconButton
            visible: mouseAreaIconButton.containsMouse
            text: "Screen Shot"
            delay: 500
            timeout: 1500
        }
}
