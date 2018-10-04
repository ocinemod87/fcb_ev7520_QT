import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    implicitHeight: exposureColumnLayout.height
    implicitWidth: exposureRowLayout.width
    ColumnLayout{
        id: exposureColumnLayout
        LabelButtonStyle{
            id: exposureLabel
            text: "Exposure"
        }
        RowLayout{
            id: exposureRowLayout
            anchors.top: exposureLabel.bottom
            anchors.topMargin: 6
//            anchors.fill: parent

            IconButtonStyle{
                opacity: generalOpacity
                id: minusExposureIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: minusExposureIconButton.width
                    height: minusExposureIconButton.height
                    source: "qrc:/qml/Icons/minusIcon.png"
                    anchors.centerIn: minusExposureIconButton.Center
                }

                onClicked: commandSignal.exposureSignalReceiver(3)
            }
            IconButtonStyle{
                opacity: generalOpacity
                id: plusExposureIconButton
                width: 30
                height: 30
                implicitWidth: width
                implicitHeight: height
                Image{
                    //this image is 64 pixel in GIMP
                    width: plusExposureIconButton.width
                    height: plusExposureIconButton.height
                    source: "qrc:/qml/Icons/plusIcon.png"
                    anchors.centerIn: plusExposureIconButton.Center
                }
                onClicked: commandSignal.exposureSignalReceiver(2)
            }
        }
    }
}
