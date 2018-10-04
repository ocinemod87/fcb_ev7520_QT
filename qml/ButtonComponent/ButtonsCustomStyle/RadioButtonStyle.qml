import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2

RadioButton{
    id: radioButtonStyle
    implicitHeight: height
    Material.accent: "#001824"
    onCheckedChanged: if(checked === true){
                          font.weight = Font.Medium
                      }else if(checked === false){
                          font.weight = Font.Normal
                      }
}
