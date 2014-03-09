import QtQuick 2.0
import QtQuick.Controls 1.0

Rectangle {
    width: 800
    height: 600


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
            clip: true
            contentWidth: inputImage.width;
            contentHeight: inputImage.height
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

    Item{
        id: controlPanel
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: childrenRect.height
        Item{
            id: controlPanelImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.horizontalCenter
            height: childrenRect.height

            Button{
                id: openImgBtn
                text: qsTr("Выбрать файл...")
                anchors.top: parent.top
                anchors.right: parent.right
                onClicked:{
                    controller.setImage();
                    controller.calcAsciiArt();
                }
            }

            TextField {
                id: address
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.right: openImgBtn.left
                anchors.rightMargin: 3
                text: gameModel.image
                onAccepted:{
                    controller.setImage(address.text);
                    controller.calcAsciiArt();
                }
            }

            Row{
                id: imgW
                anchors.top: address.bottom
                spacing: 3
                Text {
                    id: imgWlable
                    text: qsTr("Ширина")
                }

                NumberikUpDown{
                    id: mimgw
                    text: gameModel.modifedImgWidth
                    onAccepted: {
                        controller.setModifedImgWidth(text);
                        controller.calcAsciiArt();
                    }
                }
            }

            Row{
                id: imgH
                anchors.top: imgW.bottom
                spacing: 3
                Text {
                    id: imgHlable
                    text: qsTr("Высота")
                    width: imgWlable.width
                }

                NumberikUpDown{
                    id: mimgh
                    text: gameModel.modifedImgHeight
                    onAccepted: {
                        controller.setModifedImgHeight(text);
                        controller.calcAsciiArt();
                    }
                }
            }
        }

        ComboBox{
            id: algortncheck
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 5
            anchors.right: parent.right
            model: ["Один пиксель — один символ"]
        }

        Loader{
            id: controlPanelAscii
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.top: algortncheck.bottom
            anchors.topMargin: 5
            source: "OnePixelOneChar" + ".qml"
        }
    }

}
