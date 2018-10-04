import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {

    implicitHeight: shutterButtonsColumnLayout.height
    implicitWidth: shutterButtonsColumnLayout.width
    ColumnLayout{
        id: shutterButtonsColumnLayout
        LabelButtonStyle{
            id: shutterLabel
            text: "Shutter"
        }
        Row{
            id: shutterLayout
            spacing: spacingButtonLayout
            IconButtonStyle{
                id: plusShutterIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusShutterIconButton.width
                    height: plusShutterIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusShutterIconButton.Center
                }
                onClicked: commandSignal.shutterSignalReceiver("plusShutter")
            }

            IconButtonStyle{
                id: minusShutterIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusShutterIconButton.width
                    height: minusShutterIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusShutterIconButton.Center
                }
                onClicked: commandSignal.shutterSignalReceiver("minusShutter")
            }

            IconButtonStyle{
                id: resetShutterIconButton
                width: 50
                height: 30
                implicitWidth: width
                implicitHeight: height
                Text{
                    text: "Reset"
                    color: "white"
                    anchors.centerIn: resetShutterIconButton.Center
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                onClicked: commandSignal.shutterSignalReceiver("resetShutter")
            }
        }
    }
}
