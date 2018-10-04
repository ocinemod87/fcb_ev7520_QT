import QtQuick.Window 2.3
import QtQuick 2.9
import QtQuick.Controls 2.3
import Qt.labs.platform 1.0
import "ButtonComponent"


Item {
    id: customMenu2
    //  This property alias are needed for connection with the behavior of the same option showed in the others menu
    property alias afchecked: autoFocus.checked
    property alias digitalZoomChecked: digitalZoom.checked
    property alias afSensitivitychecked: afSensitivityMenuItem.checked
    property alias zoomCombinedChecked: combinedMode.checked
    property alias zoomSeparatedChecked: separatedMode.checked
    property alias afNormalChecked: afnormalMode.checked
    property alias afintervalChecked: afintervalMode.checked
    property alias afZoomTriggerChecked: afzoomtriggerMode.checked
    property alias autoExpModeChecked: autoExposure.checked
    property alias manualExpModeChecked: manualExposure.checked
    property alias shutterPriorityExpModeChecked: shutterPriorityExposure.checked
    property alias irisPriorityExpModeChecked: irisPriotityExposure.checked
    property alias brightExpModeChecked: brightExposure.checked

    MenuBar{

        id: menuBar
        Menu{
            title: "windows"
            MenuItem{
                text: "show win"
                checkable: true
                checked: false
                onCheckedChanged: {
                    if(checked === true){
                        SideMenuView.visible = true
                    }else if(checked === false){
                        SideMenuView.visible = false
                    }
                }
            }
            MenuItem{
                text: "Back Light Compensation"
                checkable: true
                checked: true
                onCheckedChanged: {
                    if (checked){
                        BackLight.backLightSignalReceiver("2")
                        console.log("On")
                    }
                    else{
                        BackLight.backLightSignalReceiver("3")
                        console.log("off")
                    }
                }
            }
            MenuItem{
                text: "Auto Exposure Spot On/Off"
                checkable: true
                checked: true
                onCheckedChanged: {
                    if (checked){
                        commandSignal.aeSpotModeSignalReceiver("2")
                        console.log("On")
                    }
                    else{
                        commandSignal.aeSpotModeSignalReceiver("3")
                        console.log("off")
                    }
                }
            }
        }

        Menu{
            id: settingsMenu
            title: qsTr("Settings")
            visible: true
            MenuItem{
                text: "Digital Zoom"
                id: digitalZoom
                checkable: true
                checked: true
                onCheckedChanged: {
                    if (checked){
//                        commandSignal.digitalzoomswitchSignalReceiver(2)
//                        console.log("On")
                    }
                    else{
//                        commandSignal.digitalzoomswitchSignalReceiver(3)
//                        console.log("off")
                    }
                }
            }
            MenuItem{
                text: "Auto Focus"
                id: autoFocus
                checkable: true
                checked: true
                onCheckedChanged: {
                    if (checked == true){
                        commandSignal.autofocusSignalReceiver("2")
                        console.log("on")
                    }
                    else{
                        commandSignal.autofocusSignalReceiver("3")
                        console.log("off")
                    }
                }
            }
            MenuItem{
                text: "Auto Focus Sensitivity High/Low"
                id: afSensitivityMenuItem
                checkable: true
                onCheckedChanged: {
                    if (checked == true){
                        commandSignal.afsensSignalReceiver("2")
                        console.log("on")
                        //look at this https://stackoverflow.com/questions/40407583/how-to-send-a-signal-from-one-qml-to-another?rq=1
                    }
                    else{
                        commandSignal.afsensSignalReceiver("3")
                        console.log("off")
                    }
                }
            }
            MenuItem{
                text: "Infra Red"

                checkable: true
                onCheckedChanged: {
                    if (checked){
                        commandSignal.infraRedSignalReceiver("2")
                        console.log("on")
                    }
                    else{
                        commandSignal.infraRedSignalReceiver("3")
                        console.log("off")
                    }
                }
                //                Component.onCompleted: InfraRed.infraRedSignalReceiver("Off")
            }
            MenuItem{
                text: "x1/Max"
                id: maxSwitchover
                enabled: false
                checkable: true
                checked: false
                onTriggered:
                    if(combinedMode.checked == true){
                        enabled = false
                    }
                    else{enabled = true}


                onCheckedChanged: {
                    if (checked == true){
                        commandSignal.maxSwitchReceiver("On")
                        console.log("on")
                    }
                    else if (checked == false){
                        commandSignal.maxSwitchReceiver("Off")
                        console.log("off")
                    }
                }
            }
            MenuItem{
                text: "Auto Slow Shutter"
                checkable: true
                onTriggered: {
                    if(checked == true){commandSignal.autoSlowShutterReceiver("2")}
                    else if(checked == false){commandSignal.autoSlowShutterReceiver("3")}
                }
            }

            MenuSeparator {
                id: menuSeparatorid
            }
            //Zoom Modes Combined Separated
            Menu{
                id: zoomModesMenu
                title: "Zoom Mode"
                visible: true

                MenuItemGroup{
                    id: zoomModeGroup
                }

                MenuItem{
                    id: combinedMode
                    checkable: true
                    checked: true
                    text: qsTr("Combine Mode")
                    group: zoomModeGroup
                    onCheckedChanged: if(checked == true){
                                          commandSignal.zoommodeSignalReceiver(0)
                                          maxSwitchover.checked = false
                                          maxSwitchover.enabled = false
                                          separatedMode.checked = false
                                      }
                }
                MenuItem{
                    id: separatedMode
                    text: qsTr("Separate Mode")
                    checkable: true
                    checked: false
                    group: zoomModeGroup
                    onCheckedChanged: if(checked == true){
                                          commandSignal.zoommodeSignalReceiver(1)
                                          maxSwitchover.enabled = true

                                      }
                }
            }
            Menu{
                id: autofocusModesMenu
                title: "Auto Focus Mode"
                visible: true

                MenuItemGroup{
                    id: autofocusModeGroup
                }
                MenuItem{
                    id: afnormalMode
                    checkable: true
                    checked: true
                    text: qsTr("Normal")
                    group: autofocusModeGroup
                    onTriggered: commandSignal.autofocusmodeSignalReceiver("1")
                }
                MenuItem{
                    id: afintervalMode
                    checkable: true
                    checked: false
                    text: qsTr("Interval")
                    group: autofocusModeGroup
                    onTriggered: commandSignal.autofocusmodeSignalReceiver("2")
                }
                MenuItem{
                    id: afzoomtriggerMode
                    checkable: true
                    checked: false
                    text: qsTr("Zoom Trigger")
                    visible: true
                    group: autofocusModeGroup
                    onTriggered: commandSignal.autofocusmodeSignalReceiver("3")
                }

            }

            Menu{
                id: exposureMode
                title: "Exposure Mode"
                visible: true

                MenuItemGroup{
                    id: exposureModeGroup
                }
                MenuItem{
                    id: autoExposure
                    checked: true
                    checkable: true
                    text: qsTr("Auto Exposure")
                    group: exposureModeGroup
                    onTriggered: commandSignal.exposureModeSignalReceiver("autoExp")
                }
                MenuItem{
                    id: manualExposure
                    checkable: true
                    checked: false
                    text: qsTr("Manual Exposure")
                    group: exposureModeGroup
                    onTriggered: commandSignal.exposureModeSignalReceiver("manualExp")
                }
                MenuItem{
                    id: shutterPriorityExposure
                    checkable: true
                    checked: false
                    text: qsTr("Shutter Priority Auto Exposure")
                    group: exposureModeGroup
                   onTriggered: commandSignal.exposureModeSignalReceiver("shutterExp")
                }
                MenuItem{
                    id: irisPriotityExposure
                    checkable: true
                    checked: false
                    text: qsTr("Iris Priority Auto Exposure")
                    group: exposureModeGroup
                    onTriggered: commandSignal.exposureModeSignalReceiver("irisExp")
                }
                MenuItem{
                    id: brightExposure
                    checkable: true
                    checked: false
                    text: qsTr("Bright")
                    group: exposureModeGroup
                    onTriggered: commandSignal.exposureModeSignalReceiver("brightExp")
                }

            }
            Menu{
                id: irCorrection
                title: "IR Correction"

                MenuItemGroup{
                    id: irCorrectionGroup
                }
                MenuItem{
                    id: standardCorrectionMode
                    checked: true
                    checkable: true

                    text: qsTr("Standard")
                    group: irCorrectionGroup
                    onTriggered: commandSignal.irCorrectionSignalReceiver("standard")
                }
                MenuItem{
                    id: irLightCorrectionMode
                    checkable: true
                    checked: false
                    text: qsTr("IR Light")
                    group: irCorrectionGroup
                    onTriggered: commandSignal.irCorrectionSignalReceiver("irLight")
                }
            }
        }
        Menu{
            title: "example"
            MenuItem{
                id: cameraPower
                text: "Camera Power"
                checkable: true
                checked: true
                onCheckedChanged: {
                    if (checked){
                        commandSignal.cameraPowerSignalReceiver("2")
                        console.log("On")
                    }
                    else{
                        commandSignal.cameraPowerSignalReceiver("3")
                        console.log("Off")
                    }
                }
            }

            Menu{
                id: cameraInit
                title: "Camera Initialization"
                MenuItem{
                    id: lensInit
                    text: "Lens Initialization"
                    onTriggered: commandSignal.cameraInitSignalReceiver("LensInit")
                }
                MenuItem{
                    id: cameraReset
                    text: "Camera Reset"
                    onTriggered: {
                        cameraPower.checked = false
                        commandSignal.cameraInitSignalReceiver("CameraReset")
                    }
                }
            }
            Menu{
                id: cameraMode
                title: "Camera Mode"

                MenuItemGroup{
                    id: cameraModeGroup
                }
                MenuItem{
                    id: normalAuto
                    checked: true
                    checkable: true
                    text: qsTr("Normal Auto")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("normalAuto")
                }
                MenuItem{
                    id: indoorMode
                    checked: false
                    checkable: true
                    text: qsTr("Indoor Mode")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("indoorMode")
                }
                MenuItem{
                    id: outdoorMode
                    checked: false
                    checkable: true
                    text: qsTr("Outdoor Mode")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("outdoorMode")
                }
                MenuItem{
                    id: onePushWBMode
                    checked: false
                    checkable: true
                    text: qsTr("One Pus WB Mode")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("onePushWBMode")
                }
                MenuItem{
                    id: autoTracingWhiteBalance
                    checked: false
                    checkable: true
                    text: qsTr("Auto Tracing White Balance")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("autoTracingWhiteBalance")
                }
                MenuItem{
                    id: manualControlMode
                    checked: false
                    checkable: true
                    text: qsTr("Manual Control Mode")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("manualControlMode")
                }
                MenuItem{
                    id: onePushWBTrigger
                    checked: false
                    checkable: true
                    text: qsTr("One Push WB Trigger")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("onePushWBTrigger")
                }
                MenuItem{
                    id: outdoorAuto
                    checked: false
                    checkable: true
                    text: qsTr("Outdoor Auto")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("outdoorAuto")
                }
                MenuItem{
                    id: autoInclSodiumLamp
                    checked: false
                    checkable: true
                    text: qsTr("Auto Including Sodium Lamp Source")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("autoInclSodiumLamp")
                }
                MenuItem{
                    id: sodiumLampFixed
                    checked: false
                    checkable: true
                    text: qsTr("Sodium Lamp Fixed Mode")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("sodiumLampFixed")
                }
                MenuItem{
                    id: sodiumOutdoorAuto
                    checked: false
                    checkable: true
                    text: qsTr("Outdoor Auto Including Sodium Lamp Source")
                    group: cameraModeGroup
                    onTriggered: commandSignal.cameraModeSignalReceiver("sodiumOutdoorAuro")
                }
            }
        }
        RegisterSettings{

        }
    }
}
