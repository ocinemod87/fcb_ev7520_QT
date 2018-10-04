import QtQuick 2.9
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: brightnessIcon
    implicitHeight: height
    implicitWidth: width
    Image{
        //this image is 64 pixel in GIMP
        width: brightnessIcon.width
        height: brightnessIcon.height
        source: "qrc:/qml/Icons/FocusIcon.png"
        anchors.centerIn: brightnessIcon.Center
    }
    onClicked: {
        if(focusPage.visible === false){
            focusPage.visible = true
            zoomPage.visible = false
            secondPage.visible = false
            exposurePage.visible = false
        }else if(focusPage.visible === true){
            focusPage.visible = false
        }
    }
}
