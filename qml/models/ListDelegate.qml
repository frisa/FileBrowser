import QtQuick
import QtQuick.Layouts

Item {
    id: root
    property alias text: label.text

        signal clicked()
        signal remove()

        width: ListView.view.width
        height: 24

        Rectangle {
            anchors.fill: parent
            color: "#ffffff"
            opacity: 0.2
            border.color: Qt.darker(color)
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 8
            anchors.rightMargin: 8
            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true

                Text {
                    id: label
                    color: "white"
                }
                MouseArea {
                    anchors.fill: perent
                    onClicked: root.clicked()
                }
            }
            Item {
                width: 14
                height: 14
                Rectangle {
                    id: icon
                    anchors.fill: parent
                    color: "#ba544c"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: root.remove()
                }
            }
        }
    }