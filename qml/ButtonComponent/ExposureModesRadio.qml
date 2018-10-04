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
        title: "Exposure Mode"
        ColumnLayout{
            x: 0
            width: 170
            height: 130
            anchors.fill: parent
            Layout.margins: 2
            RadioButtonStyle{
                height: 25
                width: 150
                id: autoExposureMode
                x: 0
                y: -10
                checkable: true
                checked: menuBarMain.autoExpModeChecked
                text: qsTr("Auto")
                onCheckedChanged: if(checked == true){
                                      commandSignal.exposureModeSignalReceiver("autoExp")
                                      menuBarMain.autoExpModeChecked = true
                                  }
            }
            RadioButtonStyle{
                height: 25
                width: 150
                id: manualExposureMode
                text: qsTr("Manual")
                anchors.top: autoExposureMode.bottom
                checkable: true
                checked: menuBarMain.manualExpModeChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.exposureModeSignalReceiver("manualExp")
                                      menuBarMain.manualExpModeChecked = true
                                  }
            }
            RadioButtonStyle{
                height: 25
                width: 150
                id: sutterExposureMode
                text: qsTr("Shutter Priority")
                anchors.top: manualExposureMode.bottom
                checkable: true
                checked: menuBarMain.shutterPriorityExpModeChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.exposureModeSignalReceiver("manualExp")
                                      menuBarMain.shutterPriorityExpModeChecked = true
                                  }
            }
            RadioButtonStyle{
                height: 25
                width: 150
                id: irisExposureMode
                text: qsTr("Iris Priority")
                anchors.top: sutterExposureMode.bottom
                checkable: true
                checked: menuBarMain.irisPriorityExpModeChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.exposureModeSignalReceiver("irisExp")
                                      menuBarMain.irisPriorityExpModeChecked = true
                                  }
            }
            RadioButtonStyle{
                height: 25
                width: 150
                id: brightExposureMode
                text: qsTr("Bright")
                anchors.top: irisExposureMode.bottom
                checkable: true
                checked: menuBarMain.brightExpModeChecked
                onCheckedChanged: if(checked == true){
                                      commandSignal.exposureModeSignalReceiver("brightExp")
                                      menuBarMain.brightExpModeChecked = true
                                  }
            }

        }
    }
}

