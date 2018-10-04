import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

IconButtonStyle{
    id: drawCurveIconButton
    width: 30
    height: 30
    implicitWidth: width
    implicitHeight: height

    Image{
        //this image is 64 pixel in GIMP
        width: drawCurveIconButton.width
        height: drawCurveIconButton.height
        source: "qrc:/qml/Icons/drawCurveIcon.png"
        anchors.centerIn: drawCurveIconButton.Center
    }
    ToolTip {
            parent: mouseAreaIconButton
            visible: mouseAreaIconButton.containsMouse
            text: "Draw Curve"
            delay: 500
            timeout: 1500
        }
}
