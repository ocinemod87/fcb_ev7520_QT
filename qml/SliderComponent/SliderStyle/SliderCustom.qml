import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Slider {
    Material.accent: "#001824"
    property int grooveSlidersImplicitHeight: 2
    property int groveSlidersHeight: 2
    property int grooveSlidersImplicitWidth: 150
    property int grooveSlidersWidth: 150
    property int handleSlidersWidth: 15
    property int handleSlidersHeight: 15
    property int topMargin: 3

    id: customSlider
    width: grooveSlidersWidth
    height: 100
    font.capitalization: Font.Capitalize
    orientation: Qt.Horizontal
    live: false
    wheelEnabled: true
    padding: 6
    spacing: 0
    font.family: "Arial"
    stepSize: 1
    to: 8
    from: -8
    value: 0
    anchors.topMargin: topMargin

    background: Rectangle {
        y: (customSlider.height-height)/2
        width: grooveSlidersWidth
        implicitWidth: grooveSlidersImplicitWidth
        implicitHeight: grooveSlidersImplicitHeight
        height: groveSlidersHeight
        radius: 1
        color: "#002F46"
        anchors.verticalCenter: parent.Center
        anchors.horizontalCenter: parent.Center
        anchors.leftMargin: 5
    }

}
