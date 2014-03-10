import QtQuick 2.0
import QtQuick.Controls 1.1

Column {
    height: childrenRect.height
    Row{
        spacing: 3
        Text { text: qsTr("Белый символ") }
        TextField {
            width: 20
            maximumLength: 1
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
            maximumLength: 1
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
