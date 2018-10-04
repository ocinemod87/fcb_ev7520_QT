import QtQuick 2.9
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: brightnessIcon
    implicitHeight: height
    implicitWidth: width
    //    Layout.leftMargin: (sideMenu.width - width)/2
    //    Layout.topMargin: columnVerticalMargin
    Image{
        //this image is 64 pixel in GIMP
        width: brightnessIcon.width
        height: brightnessIcon.height
        source: "qrc:/qml/Icons/brightnessIcon.png"
        anchors.centerIn: brightnessIcon.Center
    }
    onClicked: {
        if(secondPage.visible === false){
            secondPage.visible = true
            zoomPage.visible = false
            focusPage.visible = false
            exposurePage.visible = false
        }else if(secondPage.visible === true){
            secondPage.visible = false
        }
    }
}
