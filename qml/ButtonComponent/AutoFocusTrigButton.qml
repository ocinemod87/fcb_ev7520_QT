import QtQuick.Window 2.10
import QtQuick 2.9
import QtQuick.Controls 2.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: afText.height + 4
    implicitWidth: afText.width
    width: afText.height + 10
    height: afText.width + 10

            IconButtonStyle{
                id: afTriggerIconButton
                height: afText.height + 10
                width: afText.width + 20
                implicitWidth: width
                implicitHeight: height
                Text{
                    anchors.centerIn: parent.Center
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: afText
                    text: "AF"
                    color: "white"
                }
                onClicked: commandSignal.onepushafSignalReceiver(state)
            }
        }

