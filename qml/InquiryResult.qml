import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: inquiryItem
    width: 90
    height: 50
    implicitHeight: rectangleInquiry.height
    implicitWidth: rectangleInquiry.width
    property int topMargin: 5
    property int fontSize: 10
    property int borderWidth: 1
    property int borderRadius: 2
    Rectangle {

        width: inquiryItem.width
        height: inquiryItem.height
        id: rectangleInquiry
        anchors.fill: parent
        radius: borderRadius
        color: "#001824"
        border.width: borderWidth
        border.color: "black"
        ColumnLayout{
            anchors.top: parent.top
            Text {
                anchors.top: parent.top
                id: inqTextInfo
                color: "white"
                font.pointSize: fontSize
                text: "Info"
            }
            RowLayout{
                anchors.top: inqTextInfo.bottom
                anchors.topMargin: topMargin
                Text {
                    id: inqTextInfoZoom
                    color: "white"
                    font.pointSize: fontSize
                    anchors.centerIn: parent
                    text: "Zoom"
                }
                Text {
                    id: inqTextZoom
                    color: "white"
                    font.pointSize: fontSize
                    anchors.centerIn: parent
                    text: inquirySignal.getZoomInquiryValue
                }
            }
        }
    }
}
