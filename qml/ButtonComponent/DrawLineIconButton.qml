import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import "ButtonsCustomStyle"

IconButtonStyle{
    id: drawLineIconButton
    width: 30
    height: 30
    implicitWidth: width
    implicitHeight: height
    Image{
        //this image is 64 pixel in GIMP
        width: drawLineIconButton.width
        height: drawLineIconButton.height
        source: "qrc:/qml/Icons/drawLineIcon.png"
        anchors.centerIn: drawLineIconButton.Center
    }
    ToolTip {
            parent: mouseAreaIconButton
            visible: mouseAreaIconButton.containsMouse
            text: "Draw Line"
            delay: 500
            timeout: 1500
        }
}
