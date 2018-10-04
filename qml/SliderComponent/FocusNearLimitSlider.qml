import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderStyle"

Item {
    implicitWidth: focusNearLimitSlider.width
    implicitHeight: focusNearLimitColumnLayout.height
    height: childrenRect.height
    width: childrenRect.width
    ColumnLayout{
        id: focusNearLimitColumnLayout
        LabelCustom{
            id: focusNearLimitLabel
            text: "Focus Near Limit"
        }

        SliderCustom{
            id: focusNearLimitSlider
            anchors.top: focusNearLimitLabel.bottom
            stepSize: 1
            from: 4096
            to: 61440
            value: 4096
            onMoved: commandSignal.focusNearLimitSignalReceiver(valueAt(position))
            ToolTip {
                    parent: focusNearLimitSlider.handle
                    visible: focusNearLimitSlider.pressed
                    text: focusNearLimitSlider.position
                }
            ToolTip {

                    parent: focusNearLimitSlider
                    visible: focusNearLimitSlider.hovered
                    text: "Focus Near Limit"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}
