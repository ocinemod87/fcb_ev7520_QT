import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.10
import Qt.labs.platform 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls.Material 2.2
import "ButtonComponent"
import "SliderComponent"




Item {
    property int someNumber: 80
    id: homeToolBar
    width: toolBarRawLayout.childrenRect.width + 50
    height: someNumber
    property int labelLeftMarginLayout: 10
    property int labelTopMarginLayout: 10
    property int anchorsLeftMarginValue: 20
    property int zoomInq: 4
    property int columnVerticalMargin: 20
    property real generalOpacity: 1
    property real backgroundOpacity: 1
    property int radiusValue: 20
    property int slidersTopMargin: 10

    Rectangle{

        id: homeToolBarBackground
        width: homeToolBar.width
        height: homeToolBar.height
        opacity: 0.9
        radius: radiusValue
        Image{
            id: imageBackground
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: "qrc:/qml/Images/ToolBarTopBackGreenGrey3.png"
            visible: false

        }
        Rectangle{
            id: rectangleMask
            smooth: true
            visible: false
            width: parent.width
            height: parent.height
            radius: radiusValue
        }
        OpacityMask{
            anchors.fill: imageBackground
            source: imageBackground
            maskSource: rectangleMask
        }
    }

    MouseArea {
        anchors.centerIn: parent
        drag.target: homeToolBar
        anchors.fill: parent
        drag.minimumX: 0
        drag.maximumX: window.width - homeToolBar.width
        drag.minimumY: 0
        drag.maximumY: window.height - homeToolBar.height
    }
    //    }

    RowLayout{
        id: toolBarRawLayout
        anchors.fill: parent
        height: homeToolBar.height
        width: homeToolBar.width
        //            width: parent.width
        //            height: parent.height
        spacing: 10
        ZoomSlider{
            id: zoomSliderToolBar
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: slidersTopMargin
            //                Component.onCompleted: print(x,y,width, height)
        }
        FocusSlider{
            id: focusSliderToolBar
            anchors.left: zoomSliderToolBar.right
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: slidersTopMargin
        }
        ExposureButton{
            id: exposureButtonToolBar
            anchors.leftMargin: anchorsLeftMarginValue
            anchors.left: focusSliderToolBar.right
            anchors.top: parent.top
            anchors.topMargin: 5
        }
        PowerIcon{
            id: powerIconToolBar
            anchors.left: exposureButtonToolBar.right
            anchors.leftMargin: anchorsLeftMarginValue
            anchors.verticalCenter: parent.verticalCenter
        }
        DrawLineIconButton{
            id: drawLineButtonToolBar
            anchors.left: powerIconToolBar.right
            anchors.leftMargin: anchorsLeftMarginValue
            anchors.verticalCenter: parent.verticalCenter
        }
        DrawCurveIcon{
            id:drawCurveButtonToolBar
            anchors.left: drawLineButtonToolBar.right
            anchors.leftMargin: anchorsLeftMarginValue
            anchors.verticalCenter: parent.verticalCenter
        }
        DrawSquareButtonIcon{
            id:drawSquareButtonToolBar
            anchors.left: drawCurveButtonToolBar.right
            anchors.leftMargin: anchorsLeftMarginValue
            anchors.verticalCenter: parent.verticalCenter
        }
        ScreenShotButton{
            id: screenshotButtonToolBar
            anchors.left: drawSquareButtonToolBar.right
            anchors.leftMargin: anchorsLeftMarginValue
            anchors.verticalCenter: parent.verticalCenter
        }

        InquiryResult{
            id: inquiryResultToolBar
            anchors.left: screenshotButtonToolBar.right
            anchors.leftMargin: anchorsLeftMarginValue
        }
    }
}
