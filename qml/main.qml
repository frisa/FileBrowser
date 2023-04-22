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
            id: listView
            anchors.fill: parent
            width: 200
            height: 300
            model: FileModel{}
            Component{
                id: fileDelegate
                Rectangle{
                    id: wrapper
                    width: 180
                    height: fileInfo.height
                    color: ListView.isCurrentItem ? "black" : "white"
                    Text{
                        id: fileInfo
                        text: name + "." + extension
                        color: wrapper.ListView.isCurrentItem ? "white" : "black"
                    }
                }
            }

            delegate: fileDelegate
            highlight: Rectangle{ color: "lightsteelblue"; radius: 5}
            focus: true
        }
    }
}