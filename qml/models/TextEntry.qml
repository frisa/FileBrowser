import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

RowLayout{
    id: root
    signal append(string text)

    function setAppendValue(text){
        textField.text = text
    }

    function setEditValue(index, text){
        internal.index = index
        textField.text = text
    }

    QtObject{
        id: internal
        property int index
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
        id: buttonEdit
        text: "Edit"
        onClicked: {
            root.edit(internal.index, textField.text)
        }
    }
    Button{
        text: "Append"
        onClicked: {
            root.append(textField.text)
        }
    }
}
