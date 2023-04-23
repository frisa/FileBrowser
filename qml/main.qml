import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar{
        Menu{
            title: "&File"
            Action{ text: "&New" }
            Action{ text: "&Exit"; onTriggered: Qt.quit();
            }
        }
        Menu{
            title: "&Edit"
        }
        Menu{
            title: "&Command"
        }
        Menu{
            title: "&Help"
        }
    }

    header: ToolBar{
        RowLayout{
            ToolButton{
                text: "New"
            }
            ToolButton{
                text: "Open"
            }
            ToolButton{
                text: "Find"
            }
            ToolButton{
                text: "Connect"
            }
            ToolButton{
                text: "Quit"
            }
        }
    }
    footer: Text{
        text: fileSystem.currentPath
        color: "white"
    }
    DelegateModel{
        id: fileSystemModelDelegate
        model: fileSystemModel
        delegate: Rectangle{
            height:25
            width: 100
            Text{
                text: "Name:" + fileName
            }
        }
    }
    StackView{
        anchors.fill: parent
        initialItem: ListView{
            anchors.fill: parent
            model: fileSystemModelDelegate
        }
    }
}