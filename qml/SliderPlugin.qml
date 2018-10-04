import SliderPlugin 1.0
import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    SliderPlugin{
        id: sliderPlugin
    }
    Slider{
        id: visibleSlider
        onValueChanged: sliderPlugin.updateSlider(position)
    }
    Label {
        anchors.top: visibleSlider.bottom
        text: sliderPlugin.sliderValue
    }
}
