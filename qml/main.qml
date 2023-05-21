import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    menuBar: MenuBar {
        Menu {
            title: "&File"
            Action { text: "&New" }
            Action { text: "&Exit"; onTriggered: Qt.quit();
            }
        }
        Menu {
            title: "&Edit"
        }
        Menu {
            title: "&Command"
        }
        Menu {
            title: "&Help"
        }
    }
    header: ToolBar {
        RowLayout {
            ToolButton {
                text: "New"
            }
            ToolButton {
                text: "Open"
            }
            ToolButton {
                text: "Find"
            }
            ToolButton {
                text: "Connect"
            }
            ToolButton {
                text: "Quit"
            }
        }
    }
    footer: Text {
        text: "Here will be the current path"
        color: "white"
    }
    Rectangle {
        anchors.fill: parent
        color: "white"
        TabBar {
            id: bar
            width: parent.width
            TabButton {
                text: "Listing Information"
            }
            TabButton {
                text: "Computer Information"
            }
            TabButton {
                text: "Browsing"
            }
            TabButton {
                text: "FTP"
            }
            TabButton {
                text: "Login"
            }
        }
        StackLayout {
            width: parent.width
            height: parent.height - bar.height
            currentIndex: bar.currentIndex
            anchors {
                top: bar.bottom
            }
            Item {
                Rectangle {
                    anchors.fill: parent
                    color: "green"
                    ListView {
                        anchors.fill: parent
                        model: InfoList {}
                        delegate: InfoListDelegate {}
                    }
                }
            }
            Item {
                TreeView {
                    anchors.fill: parent
                    model: fileSystemModel
                    delegate: TreeViewDelegate {
                    }
                }
            }
            Item {
                Rectangle {
                    anchors.fill: parent
                    color: "#426cf5"
                    FormField {
                        title: "Computer Name"
                        value: sysInfo.getHostNameItf()
                    }
                }
            }
            Item {
                id: ftp
                Rectangle {
                    anchors.fill: parent
                    color: "green"
                }
            }
            Item {
                id: login
                Rectangle {
                    anchors.fill: parent
                    color: "red"
                }
            }
        }
    }
}