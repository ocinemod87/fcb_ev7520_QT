import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

//Implementation of the Button control.
Item {
    id: button
    width: 50
    height: 50
    property alias buttonText: innerText.text;
    property color color: "#001824"
    property color hoverColor: "#aaaaaa"
    property color pressColor: "slategray"
    property int fontSize: 10
    property int borderWidth: 1
    property int borderRadius: 2
    scale: state === "Pressed" ? 0.96 : 1.0
    onEnabledChanged: state = ""
    signal clicked
    opacity: 0.9
    property alias mouseAreaIconButton: mouseAreaIconButton


    //define a scale animation
    Behavior on scale {
        NumberAnimation {
            duration: 100
            easing.type: Easing.InOutQuad
        }
    }

    //Rectangle to draw the button
    Rectangle {
        id: rectangleButton
        opacity: 1
        anchors.fill: parent
        radius: borderRadius
        color: button.enabled ? button.color : "grey"
        layer.enabled: true
        layer.effect: Glow{
            samples: 4
            color: "#696969"
            transparentBorder: true
        }

        Text {
            id: innerText
            font.pointSize: fontSize
            anchors.centerIn: parent
        }
    }

    //change the color of the button in differen button states
    states: [
        State {
            name: "Hovering"
            PropertyChanges {
                target: rectangleButton
                color: hoverColor
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: rectangleButton
                color: pressColor
            }
        }
    ]

    //define transmission for the states
    transitions: [
        Transition {
            from: ""; to: "Hovering"
            ColorAnimation { duration: 200 }
        },
        Transition {
            from: "*"; to: "Pressed"
            ColorAnimation { duration: 10 }
        }
    ]

    //Mouse area to react on click events
    MouseArea {
        id: mouseAreaIconButton
        hoverEnabled: true
        anchors.fill: button
        onEntered: { button.state='Hovering'}
        onExited: { button.state=''}
        onClicked: { button.clicked();}
        onPressed: { button.state="Pressed" }
        onReleased: {
            if (containsMouse)
              button.state="Hovering";
            else
              button.state="";
        }
    }
}
