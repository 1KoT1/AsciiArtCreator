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
        anchors.bottomMargin: 100
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
        anchors.bottomMargin: 100
        source: gameModel.image
    }

    Flow{
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: inputImage.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        spacing: 15

        Row{
            spacing: 3
            MyTextInput{
                id: address
                text: gameModel.image
                onAccepted: {
                    controller.setImage(text);
                    controller.calcAsciiArt();
                }
            }

            Button{
                text: qsTr("Выбрать файл.")
                onClicked:{
                    controller.setImage();
                    controller.calcAsciiArt();
                }
            }
        }

        Row{
            spacing: 3
            Text { text: qsTr("Белый символ") }
            MyTextInput{
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
            MyTextInput{
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
            MyTextInput{
                text: gameModel.asciiArtWight
                onAccepted: {
                    controller.setAsciiArtWight(text);
                    controller.calcAsciiArt();
                }
            }
        }
    }
}
