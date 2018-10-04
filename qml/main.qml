import QtQuick.Window 2.10
import QtQuick 2.9
import QtQuick.Controls 2.3
import Qt.labs.platform 1.0
import Qt.labs.calendar 1.0
import com.amin.classes 1.0
import QtMultimedia 5.9
import com.amin.classes 1.0
//import QtQml 2.2
//import id.qml.inquiry 1.0


ApplicationWindow {
    id: windowMain
    visible: true
    property alias window: windowMain
    width: Screen.width
    height: Screen.height
    Item {
        anchors.fill: parent
        focus: true
        Keys.onPressed: console.log(event.key)
    }
    MouseArea{
        anchors.fill: parent
        id: mouseWindow
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        hoverEnabled: true
//        onClicked: {
//            console.log(mouseX)
//            console.log(mouseY)
//        }
        onClicked: if(mouse.button & Qt.LeftButton){
                       console.log("left")
                       console.log(mouseX)
                       console.log(mouseY)
                   }else if(mouse.button & Qt.RightButton){
                       console.log("right")
                       console.log(mouseX)
                       console.log(mouseY)
                   }

        onPositionChanged:{
            console.log("X: " + mouseX)
            console.log("Y: " + mouseY)
        }


        Image{
            id: videoLayer
            anchors.fill: parent
            cache: false
            onSourceChanged:{
                videoProvider.framePainted()
            }
        }

        Connections
        {
            target: videoProvider
            property int frameCounter: 0
            onFrameChanged:
            {
                videoLayer.source = "image://videoCapture/" + frameCounter;
                frameCounter ^= 1;
            }
        }

        MenuBarCustom{
            id: menuBarMain
        }

        //    CpuUsage{
        //        x: 500
        //        y: 300
        //    }

        SliderPlugin{
            x: 700
            y: 200
        }

        MenuBarHome{
            id: homeBarMenu
            //        anchors.right: window.right
            x: (window.width-width)/2
        }

        SideMenuView{
            id: sideMenu
            y: (window.height-height)/2
        }
    }
}





