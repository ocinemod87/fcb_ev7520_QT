import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderComponent"
import "ButtonComponent"

Item {
    id: firstPageSideMenu
    clip: false
    visible: true
    //    width: children.width + 50
    //    height: children.height *2
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
        //        width: firstPageLayout.childrenRect.width + 50
        //        height: firstPageLayout.childrenRect.height + 20
        width: 300
        height: 400
        //        color: "#262626"
        visible: true
        //        visible: true

        opacity: 0.9
        Image{
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: "qrc:/qml/Images/ToolBarTopBackGreenGrey3.png"
        }
    }
    ColumnLayout{
        ExposureButton{}
        ExposureModesRadio{}
    }
}
