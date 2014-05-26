import QtQuick 2.0
import QtQuick.Controls 1.0
import AsciiArtGenirator 1.0

Rectangle {
    width: 800
    height: 600


    Item{
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: controlPanel.top
        Rectangle{
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.verticalCenter
            border.color: "black"
            color: "red"
            Flickable{
                anchors.fill: parent
                Image{
                    id: inputImage;
                    source: gameModel.modifedImgURI
                }
            }
        }

        TextArea {
            id: asciiResult
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.verticalCenter
            height: width
            text: gameModel.asciiArt;
            readOnly: true
            font.pixelSize: 12
        }
    }

    Column{
        id: controlPanel
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: childrenRect.height
        spacing: 3
        Item{
            id: controlPanelImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.right
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

                SpinBox{
                    id: mimgw
                    width: 100
                    maximumValue: 1000
                    value: gameModel.modifedImgWidth
                    onValueChanged: {
                        controller.setModifedImgWidth(value);
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

                SpinBox{
                    id: mimgh
                    width: 100
                    maximumValue: 1000
                    value: gameModel.modifedImgHeight
                    onValueChanged: {
                        controller.setModifedImgHeight(value);
                        controller.calcAsciiArt();
                    }
                }
            }
        }

        ComboBox{
            id: algortncheck
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.right
            model: ["Один пиксель — один символ", "Один пиксель — несколько символов"]
            currentIndex: gameModel.algorithm
            onCurrentIndexChanged:{
                controller.setAlgorithm(currentIndex);
                controller.calcAsciiArt();
            }
        }

        Loader{
            id: controlPanelAscii
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.right
            source: gameModel.algorithm == Algorithmes.OnePixelOneChar? "OnePixelOneChar.qml" : "OnePixelMoneyChars.qml";
        }
    }



    //    Flow{
    //        anchors.left: parent.left
    //        anchors.leftMargin: 5
    //        anchors.top: asciiResult.bottom
    //        anchors.topMargin: 5
    //        anchors.right: parent.right
    //        spacing: 15

    //        Row{
    //            spacing: 3

    //            TextField {
    //                id: address
    //                width: inputImage.width / 2
    //                text: gameModel.image
    //            }
    //            Button{
    //                text: qsTr("Выбрать файл...")
    //                onClicked:{
    //                    controller.setImage();
    //                    controller.calcAsciiArt();
    //                }
    //            }
    //        }

    //        Row{
    //            spacing: 3
    //            Text { text: qsTr("Белый символ") }
    //            TextField {
    //                width: 20
    //                text: gameModel.whiteChar
    //                onAccepted: {
    //                    controller.setWhiteChar(text);
    //                    controller.calcAsciiArt();
    //                }
    //            }
    //        }

    //        Row{
    //            spacing: 3
    //            Text { text: qsTr("Чёрный символ") }
    //            TextField{
    //                width: 20
    //                text: gameModel.blackChar
    //                onAccepted: {
    //                    controller.setBlackChar(text);
    //                    controller.calcAsciiArt();
    //                }
    //            }
    //        }

    //        Row{
    //            spacing: 3
    //            Text { text: qsTr("Ширина в символах") }
    //            TextField{
    //                width: 50
    //                text: gameModel.asciiArtWight
    //                onAccepted: {
    //                    controller.setAsciiArtWight(text);
    //                    controller.calcAsciiArt();
    //                }
    //            }
    //        }
    //    }
}
