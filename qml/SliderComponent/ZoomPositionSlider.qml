import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import "SliderStyle"

Item {
    implicitWidth: zoomPositionSlider.width
    implicitHeight: zoomPositionColumnLayout.height
    height: childrenRect.height
    width: childrenRect.width
    ColumnLayout{
        id: zoomPositionColumnLayout
        LabelCustom{
            id: zoomPositionLabel
            text: "Zoom Position"
        }

        SliderCustom{
            id: zoomPositionSlider
            anchors.top: zoomPositionLabel.bottom
            from: 0
            to: 31424
            onMoved: commandSignal.zoomPositionSignalReceiver(valueAt(position))
            onPressedChanged: commandSignal.zoomPositionSignalReceiver(valueAt(position))
            ToolTip {
                    parent: zoomPositionSlider.handle
                    visible: zoomPositionSlider.pressed
                    text: zoomPositionSlider.position
                }
            ToolTip {

                    parent: zoomPositionSlider
                    visible: zoomPositionSlider.hovered
                    text: "Zoom Position"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}
