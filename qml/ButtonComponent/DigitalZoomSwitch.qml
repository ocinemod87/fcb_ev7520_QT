import QtQuick 2.9
import "ButtonsCustomStyle"

SwitchButtonStyle{
    text: "Digital Zoom Off/On"
    checked: menuBarMain.digitalZoomChecked
    onCheckedChanged: {
        if (checked){
            commandSignal.digitalzoomswitchSignalReceiver(2)
            console.log("On")
            menuBarMain.digitalZoomChecked = true
        }
        else{
            commandSignal.digitalzoomswitchSignalReceiver(3)
            console.log("off")
            menuBarMain.digitalZoomChecked = false
        }
    }
}
