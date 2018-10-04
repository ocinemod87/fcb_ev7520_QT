import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderStyle"

Item {
    implicitWidth: focusFixedPositionSlider.width
    implicitHeight: focusFixedPositionColumnLayout.height
    height: childrenRect.height
    width: childrenRect.width
    ColumnLayout{
        id: focusFixedPositionColumnLayout
        LabelCustom{
            id: focusFixedPosLabel
            text: "Focus Position"
        }

        SliderCustom{
            id: focusFixedPositionSlider
            anchors.top: focusFixedPosLabel.bottom
            stepSize: 1
            from: 4096
            to: 61440
            value: 4096
            onMoved: commandSignal.focusFixedPositionSignalReceiver(valueAt(position))
            ToolTip {
                    parent: focusFixedPositionSlider.handle
                    visible: focusFixedPositionSlider.pressed
                    text: focusFixedPositionSlider.position
                }
            ToolTip {

                    parent: focusFixedPositionSlider
                    visible: focusFixedPositionSlider.hovered
                    text: "Focus Position"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}
