import QtQuick 2.9
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: iconFirstPage
    implicitHeight: height
    implicitWidth: width

    Image{
        //this image is 64 pixel in GIMP
        width: iconFirstPage.width
        height: iconFirstPage.height
        source: "qrc:/qml/Icons/settingsIcon.png"
        anchors.centerIn: iconFirstPage.Center

    }
    onClicked: {
        if(zoomPage.visible === false){
            zoomPage.visible = true
            secondPage.visible = false
            focusPage.visible = false
            exposurePage.visible = false
        }else if(zoomPage.visible === true){
            zoomPage.visible = false
        }
    }
}
