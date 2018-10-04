import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import "ButtonComponent"

Item{
    y:40
    id: sideMenuBar
    width: window.width/18
    height: window.height/2

    property int labelLeftMarginLayout: 10
    property int labelTopMarginLayout: 10
    property int columnLayoutLeftMargin: 10
    property int columnVerticalMargin: 20
    property real generalOpacity: 1
    property real backgroundOpacity: 0.8
    property int radiusValue: 10

    Rectangle{
        id: sideMenuBackground
        width: sideMenuBar.width
        height: sideMenuBar.height
        radius: radiusValue
        opacity: 0.9
        Image{
            id: sideMenuImageBackgoround
            width: parent.width
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: "qrc:/qml/Images/lowPolyBackgroundVertical.png"
            visible: false
        }
        Rectangle{
            id: sideMenuRectangleMask
            smooth: true
            visible: false
            width: parent.width
            height: parent.height
            radius: radiusValue
        }
        OpacityMask{
            anchors.fill: sideMenuImageBackgoround
            source: sideMenuImageBackgoround
            maskSource: sideMenuRectangleMask
        }

    }

    MouseArea {
        anchors.centerIn: parent
        drag.target: sideMenu
        anchors.fill: parent
        drag.minimumX: 0
        drag.maximumX: window.width - sideMenuBar.width
        drag.minimumY: 0
        drag.maximumY: window.height - sideMenuBar.height
    }
    //            Loader{id: pageLoader}
    ColumnLayout{
        id: sideMenuColumnLayout
        anchors.fill: parent
        spacing: 5
        SettingsIcon{
            id: settingsIconSideMenu
            Layout.alignment: Qt.AlignCenter
            anchors.top: parent.top
            anchors.topMargin: 10
        }

        BrightnessIcon{
            id: brightnessIconSideMenu
            Layout.alignment: Qt.AlignCenter
            anchors.top: settingsIconSideMenu.bottom
            anchors.topMargin: 5
        }

        FocusIconButton{
            id: focusIconSideMenu
            Layout.alignment: Qt.AlignCenter
            anchors.top: brightnessIconSideMenu.bottom
            anchors.topMargin: 5
        }
        ExposureIconButton{
            id: exposureIconSideMenu
            Layout.alignment: Qt.AlignCenter
            anchors.top: focusIconSideMenu.bottom
            anchors.topMargin: 5
        }
    }

    ZoomSidePage{
        id: zoomPage
        visible: false
        x: sideMenuBar.width
    }
    SideMenu2ndPage{
        id: secondPage
        visible: false
        x: sideMenuBar.width
    }
    FocusSidePage{
        id: focusPage
        visible: false
        x: sideMenuBar.width
    }
    ExposureSideMenuPage{
        id: exposurePage
        visible: false
        x: sideMenuBar.width
    }
}
