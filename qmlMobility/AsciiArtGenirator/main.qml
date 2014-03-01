import QtQuick 2.0
import QtQuick.Controls 1.0

Rectangle {
    width: 800
    height: 600


    Rectangle{
        anchors.left: parent.left
        anchors.right: parent.horizontalCenter
        anchors.top: parent.top
        height: width
        border.color: "black"
        Flickable{
            anchors.fill: parent
            Image{
                id: inputImage;
                source: gameModel.image
            }
        }
    }

    ScrollView {
        id: asciiResult
        anchors.left: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        height: width
        TextEdit {
            text: gameModel.asciiArt;
            wrapMode: Text.WrapAnywhere
            font.pixelSize: 12
            selectByMouse: true
        }
    }


    Flow{
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: asciiResult.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        spacing: 15

        Row{
            spacing: 3

            TextField {
                id: address
                width: inputImage.width / 2
                text: gameModel.image
            }
            Button{
                text: qsTr("Выбрать файл...")
                onClicked:{
                    controller.setImage();
                    controller.calcAsciiArt();
                }
            }
        }

        Row{
            spacing: 3
            Text { text: qsTr("Белый символ") }
            TextField {
                width: 20
                text: gameModel.whiteChar
                onAccepted: {
                    controller.setWhiteChar(text);
                    controller.calcAsciiArt();
                }
            }
        }

        Row{
            spacing: 3
            Text { text: qsTr("Чёрный символ") }
            TextField{
                width: 20
                text: gameModel.blackChar
                onAccepted: {
                    controller.setBlackChar(text);
                    controller.calcAsciiArt();
                }
            }
        }

        Row{
            spacing: 3
            Text { text: qsTr("Ширина в символах") }
            TextField{
                width: 50
                text: gameModel.asciiArtWight
                onAccepted: {
                    controller.setAsciiArtWight(text);
                    controller.calcAsciiArt();
                }
            }
        }
    }
}
