import QtQuick.Window 2.3
import QtQuick 2.9
import QtQuick.Controls 2.3
import Qt.labs.platform 1.0

Menu {

    id: cameraSetting
    title: "Camera Settings"
    Menu{
        id: baudRate
        title: "Baud Rate"
        MenuItemGroup{
            id: cameraSettingGroup
        }
        MenuItem{
            checked: true
            checkable: true
            text: qsTr("9600")
            group: cameraSettingGroup
            onTriggered: {
                commandSignal.baudRateSignalReceiver("0")
                console.log("9600")
            }
        }
        MenuItem{
            checked: false
            checkable: true
            text: qsTr("19200")
            group: cameraSettingGroup
            onTriggered: {
                commandSignal.baudRateSignalReceiver("1")
                console.log("19200")
            }
        }
        MenuItem{
            checked: true
            checkable: true
            text: qsTr("38400")
            group: cameraSettingGroup
            onTriggered: {
                commandSignal.baudRateSignalReceiver("2")
                console.log("38400")
            }
        }
        MenuItem{
            checked: true
            checkable: true
            text: qsTr("115200")
            group: cameraSettingGroup
            onTriggered: {
                commandSignal.baudRateSignalReceiver("3")
                console.log("115200")
            }
        }
    }
}
