import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "SliderStyle"

Item {
    implicitWidth: digitalZoomSlider.width
    implicitHeight: digitalZoomColumnLayout.height
    height: childrenRect.height
    width: childrenRect.width
    ColumnLayout{
        id: digitalZoomColumnLayout
        LabelCustom{
            id: digitalZoomLabel
            text: "Digital Zoom"
        }
        SliderCustom{
            id: digitalZoomSlider
            anchors.top: digitalZoomLabel.bottom
            stepSize: 1
            from: -7
            to: 7
            value: 0
            onMoved: {
                commandSignal.zoomDigitalValueSignalReceiver(valueAt(position))
            }
            onPressedChanged: {
                if(pressed){
                    commandSignal.zoomDigitalValueSignalReceiver(valueAt(position))
                }else {
                    value = 0
                    commandSignal.zoomDigitalValueSignalReceiver(valueAt(position))
                }
            }
            ToolTip {
                    parent: digitalZoomSlider.handle
                    visible: digitalZoomSlider.pressed
                    text: digitalZoomSlider.position
                }
            ToolTip {

                    parent: digitalZoomSlider
                    visible: digitalZoomSlider.hovered
                    text: "Digital Zoom"
                    delay: 500
                    timeout: 1500
                }
        }
    }
}
