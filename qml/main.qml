import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar{
        MenuBarItem{
            text: "File"
        }
        MenuBarItem{
            text: "Edit"
        }
        MenuBarItem{
            text: "Command"
        }
        MenuBarItem{
            text: "Help"
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
    footer: TabBar{
        
    }
    StackView{
        anchors.fill: parent
        initialItem: ListView{
            anchors.fill: parent
            width: 200
            height: 300
            model: model
            delegate: Text{
                text: name + "." + extension
                color: "red"
            }

        }
    }
}