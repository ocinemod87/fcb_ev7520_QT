import QtQuick 2.9
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

IconButtonStyle{
    opacity: generalOpacity
    id: iconExposureButton
    implicitHeight: height
    implicitWidth: width

    Image{
        //this image is 64 pixel in GIMP
        width: iconExposureButton.width
        height: iconExposureButton.height
        source: "qrc:/qml/Icons/ExposureIcon.png"
        anchors.centerIn: iconExposureButton.Center

    }
    onClicked: {
        if(exposurePage.visible === false){
            exposurePage.visible = true
            zoomPage.visible = false
            secondPage.visible = false
            focusPage.visible = false
        }else if(exposureIconSideMenu.visible === true){
            exposurePage.visible = false
        }
    }
}
