import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item{
    width: 170
    height: 130
    implicitWidth: width
    implicitHeight: height
    BoxCustomStyle{
        title: "Zoom Mode"
        ColumnLayout{
            x: 0
            width: 170
            height: 130
            anchors.fill: parent
            Layout.margins: 2
            RadioButtonStyle{
                height: 25
                width: 150
                id: combinedModee
                x: 0
                y: -10
                checkable: true
                checked: menuBarMain.zoomCombinedChecked
                text: qsTr("Combine")
                onCheckedChanged: if(checked == true){
                                      commandSignal.zoommodeSignalReceiver(0)
                                      menuBarMain.zoomCombinedChecked = true
                                  }
            }
            RadioButtonStyle{
                height: 25
                width: 150
                id: separatedModee
                text: qsTr("Separate")
                anchors.top: combinedMode.bottom
                checkable: true
                checked: menuBarMain.zoomSeparatedChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.zoommodeSignalReceiver(1)
                                      menuBarMain.zoomSeparatedChecked = true
                                  }
            }
        }
    }
}
