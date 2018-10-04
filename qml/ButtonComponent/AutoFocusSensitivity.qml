import QtQuick 2.9
import QtQuick.Controls 2.2
import "ButtonsCustomStyle"

SwitchButtonStyle{
    text: "AF Sensitivity\nLow/High"
    id: afSesitivitySwitch
    checked: menuBarMain.afSensitivitychecked
    checkable: true
    onCheckedChanged: {
        if (checked){
            commandSignal.afsensSignalReceiver("2")
            console.log("on")
            menuBarMain.afSensitivitychecked = true
        }
        else{
            commandSignal.afsensSignalReceiver("3")
            console.log("off")
            menuBarMain.afSensitivitychecked = false
        }
    }
}
