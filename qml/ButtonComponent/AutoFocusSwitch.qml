import QtQuick 2.9
import "ButtonsCustomStyle"
import "qrc:/qml"

SwitchButtonStyle{
    text: "AF Off/On"
    checked: menuBarMain.afchecked
    onCheckedChanged: {
        if (checked){
            commandSignal.autofocusSignalReceiver("2")
            console.log("on")
            menuBarMain.afchecked = true
        }
        else{
            commandSignal.autofocusSignalReceiver("3")
            console.log("off")
            menuBarMain.afchecked = false
        }
    }
}
