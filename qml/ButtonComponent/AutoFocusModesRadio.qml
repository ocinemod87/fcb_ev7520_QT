import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import "ButtonsCustomStyle"

Item{
    id: autoFocusModeItem
    x: 0
    width: 170
    height: 130
    implicitWidth: width
    implicitHeight: height



    BoxCustomStyle{
        title: "Focus Mode"

        ColumnLayout{
            width: 170
            height: 130
            anchors.fill: parent
            Layout.margins: 2
            RadioButtonStyle{
                height: 25
                width: 140
                id: normalMode
                checkable: true
                checked: menuBarMain.afNormalChecked
                text: qsTr("Normal")
                font.weight: Font.Medium
                onCheckedChanged: if(checked == true){
                                      commandSignal.autofocusmodeSignalReceiver("1")
                                      menuBarMain.afNormalChecked = true
                                  }
            }

            RadioButtonStyle{
                height: 25
                width: 140
                id: intervalMode
                text: qsTr("Interval")
                anchors.top: normalMode.bottom
                checkable: true
                checked: menuBarMain.afintervalChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.autofocusmodeSignalReceiver("2")
                                      menuBarMain.afintervalChecked = true
                                  }
            }

            RadioButtonStyle{
                height: 25
                width: 150
                id: zoomTriggerMode
                text: qsTr("Zoom Trigger")
                anchors.top: intervalMode.bottom
                checkable: true
                checked: menuBarMain.afZoomTriggerChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.autofocusmodeSignalReceiver("3")
                                      menuBarMain.afZoomTriggerChecked = true
                                  }
            }
        }
    }
}

