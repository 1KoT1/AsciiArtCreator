import QtQuick 2.0

Rectangle {
    border.width: 1
    TextInput{
        id: txtin
        x: 1
        y: 1
        selectByMouse: true
        cursorVisible: true
    }
    property alias text: txtin.text
    signal accepted()
    Component.onCompleted: {
        txtin.accepted.connect(accepted)
    }
    width: txtin.width + txtin.x * 2
    height: txtin.height + txtin.y * 2
}
