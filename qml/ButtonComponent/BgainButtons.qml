import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: bGainButtonsColumnLayout.height
    implicitWidth: bGainButtonsColumnLayout.width
    ColumnLayout{
        id: bGainButtonsColumnLayout
        LabelButtonStyle{
            id: bGainLabel
            text: "B Gain"
        }
        Row{
            id: gainLayout
            spacing: spacingButtonLayout
            IconButtonStyle{
                id: plusBGainIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusBGainIconButton.width
                    height: plusBGainIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusBGainIconButton.Center
                }
                onClicked: commandSignal.bGainSignalReceiver("plusBGain")
            }
            IconButtonStyle{
                id: minusBGainIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusBGainIconButton.width
                    height: minusBGainIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusBGainIconButton.Center
                }
                onClicked: commandSignal.bGainSignalReceiver("minusBGain")
            }
            IconButtonStyle{
                id: resetBGainIconButton
                width: 50
                height: 30
                implicitWidth: width
                implicitHeight: height
                Text{
                    text: "Reset"
                    color: "white"
                    anchors.centerIn: resetBGainIconButton.Center
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                onClicked: commandSignal.bGainSignalReceiver("resetBGain")
            }
        }
    }
}
