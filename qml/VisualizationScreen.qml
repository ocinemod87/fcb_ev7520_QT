import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3

Item{

    TabBar {
        id: bar
        width: window.width * 0.3
        height: 30
        visible: true
        TabButton{
            id: optionButton
            x: 0
            text: qsTr("Options")
            onClicked: {
                if(bar.currentIndex == 0){
                    bar.setCurrentIndex(1)
                }else if(bar.currentIndex == 1){
                    bar.setCurrentIndex(0)
                }
            }
        }
    }

    StackLayout {
        width: window.width * 0.3
        height: window.height
        visible: true
        currentIndex: bar.currentIndex
        Item {
            id: optionVisualized
            SideMenuView{
                width: window.width
                height: window.height
                visible: true
                y: 40
            }
        }

        Item {
            id: optionHidden
        }
        Item {
            id: activityTab
        }
        onCurrentIndexChanged: console.log(currentIndex)
    }
}
