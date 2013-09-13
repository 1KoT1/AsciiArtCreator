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
        id: address
        anchors.left: parent.left
        anchors.top: inputImage.bottom
        anchors.topMargin: 5
        selectByMouse: true
        text: gameModel.image
    }

    Row{
        anchors.left: address.right
        anchors.leftMargin: 5
        anchors.top: inputImage.bottom
        anchors.topMargin: 5
        spacing: 5
        Text { text: qsTr("Белый символ") }
        TextInput{ text: gameModel.whiteChar
            selectByMouse: true
            onAccepted: {
                controller.setWhiteChar(text);
                controller.calcAsciiArt();
            }
        }
        Text { text: qsTr("Чёрный символ") }
        TextInput{
            text: gameModel.blackChar
            selectByMouse: true
            onAccepted: {
                controller.setBlackChar(text);
                controller.calcAsciiArt();
            }
        }
        Text { text: qsTr("Ширина в символах") }
        TextInput{
            text: gameModel.asciiArtWight
            selectByMouse: true
            onAccepted: {
                controller.setAsciiArtWight(text);
                controller.calcAsciiArt();
            }
        }
    }
}
