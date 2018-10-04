import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderComponent"
import "ButtonComponent"

Item {
    id: firstPageSideMenu
    clip: false
    visible: true
    property int sliderSpacing: 4
    property int grooveSlidersImplicitHeight: 15
    property int groveSlidersHeight: 6
    property int handleSlidersWidth: 20
    property int handleSlidersHeight: 20
    property real generalOpacity: 1
    property real backgroundOpacity: 0.95
    property int labelLeftMarginLayout: 10
    property int labelTopMarginLayout: 15
    property int columnLayoutLeftMargin: 10


    Rectangle{
        id: background1stPage
        width: firstPageLayout.childrenRect.width + 50
        height: firstPageLayout.childrenRect.height + 20
        visible: true
        opacity: 0.9
        Image{
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: "qrc:/qml/Images/ToolBarTopBackGreenGrey3.png"
        }
    }
    ColumnLayout{
        spacing: 5
        id: firstPageLayout

        ZoomSlider{
            anchors.left: parent.left
            anchors.leftMargin: labelLeftMarginLayout
        }
        ZoomPositionSlider{
            anchors.left: parent.left
            anchors.leftMargin: labelLeftMarginLayout
        }
        DigitalZoomSlider{
            anchors.left: parent.left
            anchors.leftMargin: labelLeftMarginLayout
        }
        DigitalZoomPositionSlider{
            id: zoomPosSliderSideMenu
            anchors.left: parent.left
            anchors.leftMargin: labelLeftMarginLayout
        }
        GridLayout{
            id: firstPageGridLayout
            anchors.top: zoomPosSliderSideMenu.bottom
            columns: 2
            anchors.margins: 10
            Layout.leftMargin: 15
            rowSpacing: 10
            columnSpacing: 10

            DigitalZoomSwitch{
                id: digitalZoomSwitchSideMenu
            }

        }
        ZoomModesRadio{}
    }
}



