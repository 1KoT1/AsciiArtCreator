import QtQuick 2.0
import QtQuick.Controls 1.1

Column {
    height: childrenRect.height
    Row{
        spacing: 3
        Text { text: qsTr("Белый символ") }
        TextField {
            text: gameModel.onePixelMoneyCharsModel.whiteChars
            onAccepted: {
                controller.setOnePixelMoneyCharsWhiteChars(text);
                controller.calcAsciiArt();
            }
        }
    }

    Row{
        spacing: 3
        Text { text: qsTr("Чёрный символ") }
        TextField{
            text: gameModel.onePixelMoneyCharsModel.blackChars
            onAccepted: {
                controller.setOnePixelMoneyCharsBlackChars(text);
                controller.calcAsciiArt();
            }
        }
    }
}
