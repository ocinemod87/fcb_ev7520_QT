import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: irisButtonsColumnLayout.height
    implicitWidth: irisButtonsColumnLayout.width
    ColumnLayout{
        id: irisButtonsColumnLayout
        LabelButtonStyle{
            id: irisLabel
            text: "Iris"
        }
        Row{
            id: irisLayout
            spacing: spacingButtonLayout
            IconButtonStyle{
                id: plusIrisIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusIrisIconButton.width
                    height: plusIrisIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusIrisIconButton.Center
                }
                onClicked: commandSignal.irisSignalReceiver("plusIris")
            }

            IconButtonStyle{
                id: minusIrisIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusIrisIconButton.width
                    height: minusIrisIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusIrisIconButton.Center
                }
                onClicked: commandSignal.irisSignalReceiver("minusIris")
            }

            IconButtonStyle{
                id: resetIrisIconButton
                width: 50
                height: 30
                implicitWidth: width
                implicitHeight: height
                Text{
                    text: "Reset"
                    color: "white"
                    anchors.centerIn: resetIrisIconButton.Center
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                onClicked: commandSignal.irisSignalReceiver("resetIris")
            }
        }
    }
}
