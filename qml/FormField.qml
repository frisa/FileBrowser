import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
    property alias title: label.text
    property alias value: value.text
    Label {
        id: label
    }
    Label{
        text: ": "
    }
    Label {
        id: value
        color: "lightgreen"
    }
}
