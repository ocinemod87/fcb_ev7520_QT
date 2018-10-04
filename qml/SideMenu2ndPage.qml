import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "ButtonComponent"
import "SliderComponent"

Item {

    property int buttonHeight: 40
    property int buttonWidth: 40
    property int buttonResetWidth: 70
    property int spacingButtonLayout: 3
    property real generalOpacity: 1
    property real backgroundOpacity: 0.95
    property int leftMarginLayout: 15
    Rectangle{
        id: backgroundSecondPage
        width: secondPageLayout.childrenRect.width + 50
        height: secondPageLayout.childrenRect.height + 20
        visible: true
        Image{
            //this image is 64 pixel in GIMP
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: "qrc:/qml/Images/ToolBarTopBackGreenGrey3.png"
        }
    }


    ColumnLayout{
        id: secondPageLayout
        spacing: 3

        GridLayout{
            id: secondPageGridLayout
//            anchors.top: focusNearLimitSideMenu.bottom
            anchors.margins: 10
            columns: 2
            columnSpacing: 20
            rowSpacing: 10
            Layout.leftMargin: 15

            X1MaxButton{}

            RgainButtons{}

            BgainButtons{}

            ShutterButtons{}

            IrisButtons{}

            GainButtons{}

            BrightButtons{}
        }
    }
}
