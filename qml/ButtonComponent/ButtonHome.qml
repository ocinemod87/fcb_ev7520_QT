import QtQuick.Window 2.10
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item {
    RowLayout{
        id: exposureLayout
        spacing: 2
        Material.theme: Material.Cyan
        Material.elevation: 6
        Button {
            id: plusExposure
            text: qsTr("+")
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
            Layout.fillHeight: false
            spacing: 4
            font.pointSize: 8
            focusPolicy: Qt.NoFocus
            x: 1
            y: -18
            width: 40
            height: 40
            //            Material.background: Material.Orange
            highlighted: true
            Material.background: Material.Orange

        }

        Button {
            id: minusExposure
            x: 49
            y: -18
            width: 40
            height: 40
            text: qsTr("-")
            font.pointSize: 13
            padding: 6
            hoverEnabled: false
            spacing: 2
            focusPolicy: Qt.WheelFocus
            Layout.preferredHeight: 40
            Layout.preferredWidth: 40
            visible: true
            highlighted: true
            Material.background: Material.Cyan

        }
    }


}



