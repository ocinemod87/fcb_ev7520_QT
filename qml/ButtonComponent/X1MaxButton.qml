import QtQuick.Window 2.10
import QtQuick 2.9
import QtQuick.Controls 2.3
import "ButtonsCustomStyle"

Item {
    Button {
        id: x1Max
        x: 0
        y: 773
        text: qsTr("x1/Max")
        visible: true
        onPressed: commandSignal.maxSwitchReceiver()
    }
}
