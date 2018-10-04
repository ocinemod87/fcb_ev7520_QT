import QtQuick 2.3
import CpuInfo 1.0

Rectangle {
    width: 200
    height: 400
    id: cpuRectangle
    color: "gray"

    CpuInfo {
        id: id_cpuInfo
    }

    Timer {
        repeat: true
        interval: 1000
        running: true

        onTriggered: {
            id_cpuInfo.update()
        }
    }

    Rectangle {
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        color: "blue"
        height: id_cpuInfo.cpuUsage * parent.height / 100
    }

    Text {
        text: id_cpuInfo.cpuUsage + " %"
        anchors.centerIn: parent
        font.pixelSize: 50
    }
    MouseArea {
        anchors.centerIn: parent
        drag.target: cpuRectangle
        anchors.fill: parent
        drag.minimumX: 0
        drag.maximumX: window.width - sideMenuBar.width
        drag.minimumY: 0
        drag.maximumY: window.height - sideMenuBar.height
    }
}
