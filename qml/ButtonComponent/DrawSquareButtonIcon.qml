import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

IconButtonStyle{
    id: drawSquareIconButton
    width: 30
    height: 30
    implicitWidth: width
    implicitHeight: height
    Image{
        //this image is 64 pixel in GIMP
        width: drawSquareIconButton.width
        height: drawSquareIconButton.height
        source: "qrc:/qml/Icons/drawSquareIcon.png"
        anchors.centerIn: drawSquareIconButton.Center
    }
    ToolTip {
            parent: mouseAreaIconButton
            visible: mouseAreaIconButton.containsMouse
            text: "Draw Square"
            delay: 500
            timeout: 1500
        }
}
