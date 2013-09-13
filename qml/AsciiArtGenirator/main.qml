import QtQuick 2.0
import QtQuick.Controls 1.0

Rectangle {
    width: 800
    height: 600


    ScrollView {
        id: asciiResult
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 2
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        TextEdit {
            text: gameModel.asciiArt;
            wrapMode: Text.WrapAnywhere
            font.pixelSize: 12
            selectByMouse: true
        }
    }

    Image{
        id: inputImage;
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        source: gameModel.image
    }

    TextInput{
        anchors.left: parent.left
        anchors.top: inputImage.bottom
        anchors.topMargin: 5
        selectByMouse: true
        text: gameModel.image
    }
}
