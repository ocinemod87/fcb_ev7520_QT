import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderStyle"

Item {
    implicitWidth: digitalZoomPosition.width
    implicitHeight: digitalZoomPosColumnLayout.height
    height: childrenRect.height
    width: childrenRect.width
    ColumnLayout{
        id: digitalZoomPosColumnLayout
        LabelCustom{
            id: digitalZoomPositionLabel
            text: "Digital Zoom Position"
        }

        SliderCustom{
            id: digitalZoomPosition
            anchors.top: digitalZoomPositionLabel.bottom
            from: 0
            to: 235
            stepSize: 1
            value: 0
            onMoved: commandSignal.zoomDigitalPositionSignalReceiver(valueAt(position))
            onPressedChanged: commandSignal.zoomDigitalPositionSignalReceiver(valueAt(position))
            ToolTip {
                    parent: digitalZoomPosition.handle
                    visible: digitalZoomPosition.pressed
                    text: digitalZoomPosition.position
                }
            ToolTip {

                    parent: digitalZoomPosition
                    visible: digitalZoomPosition.hovered
                    text: "Digital Zoom Position"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}
