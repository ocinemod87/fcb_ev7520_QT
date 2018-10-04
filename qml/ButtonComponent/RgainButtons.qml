import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: rGainButtonsColumnLayout.height
    implicitWidth: rGainButtonsColumnLayout.width
    ColumnLayout{
        id: rGainButtonsColumnLayout
        LabelButtonStyle{
            id: rGainLabel
            text: "R Gain"
        }
        Row{
            id: rGainLayout
            spacing: spacingButtonLayout
            IconButtonStyle{
                id: plusRGainIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusRGainIconButton.width
                    height: plusRGainIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusRGainIconButton.Center
                }
                onClicked: commandSignal.rGainSignalReceiver("plusRGain")
            }

            IconButtonStyle{
                id: minusRGainIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusRGainIconButton.width
                    height: minusRGainIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusRGainIconButton.Center
                }
                onClicked: commandSignal.rGainSignalReceiver("minusRGain")
            }

            IconButtonStyle{
                id: resetRGainIconButton
                width: 50
                height: 30
                implicitWidth: width
                implicitHeight: height
                Text{
                    text: "Reset"
                    color: "white"
                    anchors.centerIn: resetRGainIconButton.Center
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                onClicked: commandSignal.rGainSignalReceiver("resetRGain")
            }
        }
    }
}
