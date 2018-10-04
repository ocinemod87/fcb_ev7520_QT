import QtQuick 2.9
import QtQuick.Layouts 1.3
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
        source: "qrc:/qml/Icons/PowerIcon.png"
        anchors.centerIn: powerIconButton.Center

    }
}
