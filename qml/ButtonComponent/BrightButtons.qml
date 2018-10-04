import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: brightButtonsColumnLayout.height
    implicitWidth: brightButtonsColumnLayout.width
    ColumnLayout{
        id: brightButtonsColumnLayout
        LabelButtonStyle{
            id: brightLabel
            text: "Bright"
        }
        Row{
            id: brighjtLayout
            spacing: spacingButtonLayout
            IconButtonStyle{
                id: plusBrightIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusBrightIconButton.width
                    height: plusBrightIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusBrightIconButton.Center
                }
                onClicked: commandSignal.brightSignalReceiver("plusBright")
            }

            IconButtonStyle{
                id: minusBrightIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusBrightIconButton.width
                    height: minusBrightIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusBrightIconButton.Center
                }
                onClicked: commandSignal.brightSignalReceiver("minusBright")
            }

            IconButtonStyle{
                id: resetBrightIconButton
                width: 50
                height: 30
                implicitWidth: width
                implicitHeight: height
                Text{
                    text: "Reset"
                    color: "white"
                    anchors.centerIn: resetBrightIconButton.Center
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                onClicked: commandSignal.brightSignalReceiver("resetBright")
            }
        }
    }
}
