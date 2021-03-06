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
            text: gameModel.onePixelOneCharModel.whiteChar
            onAccepted: {
                controller.setOnePixelOneCharWhiteChar(text);
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
            text: gameModel.onePixelOneCharModel.blackChar
            onAccepted: {
                controller.setOnePixelOneCharBlackChar(text);
                controller.calcAsciiArt();
            }
        }
    }
}
