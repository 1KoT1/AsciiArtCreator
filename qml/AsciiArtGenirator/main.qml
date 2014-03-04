import QtQuick 2.0
import QtQuick.Controls 1.0

Rectangle {
    width: 800
    height: 600


    Flow{
        id: controlPanel
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 100
        spacing: 15

        Row{
            spacing: 3

            TextField {
                id: address
                text: gameModel.image
                onAccepted:{
                    controller.setImage(address.text);
                    controller.calcAsciiArt();
                }
            }
            Button{
                text: qsTr("Выбрать файл...")
                onClicked:{
                    controller.setImage();
                    controller.calcAsciiArt();
                }
            }
        }

        TextField{
            id: mimgh
            text: gameModel.modifedImgHeight
            onAccepted: {
                controller.setModifedImgHeight(text);
                controller.calcAsciiArt();
            }
        }

        TextField{
            id: mimgw
            text: gameModel.modifedImgWidth
            onAccepted: {
                controller.setModifedImgWidth(text);
                controller.calcAsciiArt();
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

    Rectangle{
        id: inputImageArea
        anchors.left: parent.left
        anchors.right: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: controlPanel.top
        anchors.bottomMargin: 5
        border.color: "black"
        Flickable{
            anchors.fill: parent
            Image{
                id: inputImage;
                cache: false
                source: gameModel.modifedImgURI
                Connections{
                    target: gameModel
                    onModifedImgChanged: { inputImage.source = ""; inputImage.source = gameModel.modifedImgURI; }
                }
            }
        }
    }

    TextArea {
        id: asciiResult
        anchors.left: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: inputImageArea.bottom
        text: gameModel.asciiArt;
        readOnly: true
        font.pixelSize: 12
    }
}
