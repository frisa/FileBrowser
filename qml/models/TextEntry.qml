import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

RowLayout{
    id: root
    signal append(string text)

    function setAppendValue(text){
        textField.text = text
    }
    TextField{
        id: textField
        Layout.fillWidth: true
        text: "Enter Name .."
        focus: true
        onAccepted: {
            selectAll()
        }
    }
    Button{
        text: "Append"
        onClicked: {
            root.append(textField.text)
        }
    }
}
