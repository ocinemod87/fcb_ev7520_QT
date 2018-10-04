import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import "SliderStyle"

Item {
    implicitWidth: focusSlider.width
    implicitHeight: focusSliderLayout.height
    height: childrenRect.height
    width: childrenRect.width
    ColumnLayout{
        id: focusSliderLayout
        LabelCustom{
            id: focusSliderLabel
            text: "Focus"
        }

        SliderCustom{
            id: focusSlider
            anchors.top: focusSliderLabel.bottom
            onMoved: commandSignal.focusSignalReceiver(valueAt(position))
            onPressedChanged: {
                if(pressed){
                    commandSignal.focusSignalReceiver(valueAt(position))
                }else {
                    value = 0
                    commandSignal.focusSignalReceiver(valueAt(position))
                }
            }
            ToolTip {
                    parent: focusSlider.handle
                    visible: focusSlider.pressed
                    text: focusSlider.position
                }
            ToolTip {

                    parent: focusSlider
                    visible: focusSlider.hovered
                    text: "Focus"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}
