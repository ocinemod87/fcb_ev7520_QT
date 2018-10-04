import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: gainButtonsColumnLayout.height
    implicitWidth: gainButtonsColumnLayout.width
    ColumnLayout{
        id: gainButtonsColumnLayout
        LabelButtonStyle{
            id: gainLabel
            text: "Gain"
        }
        Row{
            id: gainLayout
            spacing: spacingButtonLayout
            IconButtonStyle{
                id: plusGainIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusGainIconButton.width
                    height: plusGainIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusGainIconButton.Center
                }
                onClicked: commandSignal.gainSignalReceiver("plusGain")
            }

            IconButtonStyle{
                id: minusGainIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusGainIconButton.width
                    height: minusGainIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusGainIconButton.Center
                }
                onClicked: commandSignal.gainSignalReceiver("minusGain")
            }

            IconButtonStyle{
                id: resetGainIconButton
                width: 50
                height: 30
                implicitWidth: width
                implicitHeight: height
                Text{
                    text: "Reset"
                    color: "white"
                    anchors.centerIn: resetGainIconButton.Center
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                onClicked: commandSignal.gainSignalReceiver("resetGain")
            }
        }
    }
}
