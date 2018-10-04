import QtQuick 2.9
import QtQuick.Controls 2.2

GroupBox {
    id: control
    title: qsTr("GroupBox")
    topPadding: 20
    padding: 5
    leftPadding: 10

    background: Rectangle {
        y: control.topPadding
        x: control.leftPadding
        width: parent.width
        height: parent.height - control.topPadding - 5
        color: "transparent"
        border.color: "#001824"
        radius: 2
    }

    label: Label {
        x: control.leftPadding
        width: control.availableWidth
        text: control.title
        color: "#001824"
        elide: Text.ElideRight
    }

//    Label {

//    }
}
