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

        Rectangle{
            width: 180
            height: 200
            Component{
                id: fileDelegate
                Item{
                    width: 180
                    height: 40
                    Column{
                        Text{ text: "<b>Name: </b>" + name}
                        Text{ text: "<b>Extension: </b>" + extension}
                    }
                }
            }
        }
        initialItem: ListView{
            anchors.fill: parent
            width: 200
            height: 300
            model: FileModel{}
            delegate: fileDelegate
            highlight: Rectangle{ color: "lightsteelblue"; radius: 5}
            focus: true
        }
    }
}