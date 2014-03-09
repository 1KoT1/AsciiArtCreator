import QtQuick 2.0
import QtQuick.Controls 1.1

TextField {
    id:namberveiw
    width: 70
    text: "0"

    validator: IntValidator{}

    Button{
        id: up
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.verticalCenter
        width: 15
        text: "▲"
        onClicked: {
            namberveiw.text ++;
            namberveiw.accepted();
        }
    }

    Button{
        id: down
        anchors.top: parent.verticalCenter
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: up.left
        text: "▼"
        onClicked: {
            namberveiw.text --;
            namberveiw.accepted();
        }
    }
}
