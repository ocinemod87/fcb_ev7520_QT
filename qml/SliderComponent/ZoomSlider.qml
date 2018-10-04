import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderStyle"

Item {

    implicitWidth: zoomSlider.width
    implicitHeight: zoomSliderColumnLayout.height
    height: childrenRect.height
    width: childrenRect.width

    ColumnLayout{
        id: zoomSliderColumnLayout
        LabelCustom{
            id: zoomSliderLabel
            text: "Zoom"
        }

        SliderCustom{
            id: zoomSlider
            anchors.top: zoomSliderLabel.bottom
            stepSize: 1
            from: -7
            to: 7
            value: 0
            onMoved: {
                commandSignal.zoomSignalReceiver(valueAt(position))              
            }
            onPressedChanged: {
                if(pressed){
                    commandSignal.zoomSignalReceiver(valueAt(position))
                }else {
                    value = 0
                    commandSignal.zoomSignalReceiver(valueAt(position))
                }
            }

            ToolTip {
                    parent: zoomSlider.handle
                    visible: zoomSlider.pressed
                    text: zoomSlider.position
                }
            ToolTip {

                    parent: zoomSlider
                    visible: zoomSlider.hovered
                    text: "Zoom"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}

