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
    StackView{
        anchors.fill: parent
        initialItem: TreeView{
            anchors.fill: parent
            model: fileSystemModel
            delegate: Item{
                id: treeDelegate
                implicitWidth: padding + label.x + label.implicitWidth + padding
                implicitHeight: label.implicitHeight * 1.5

                readonly property real indent: 20
                readonly property real padding: 5

                required property TreeView treeView
                required property bool isTreeNode
                required property bool expanded
                required property int hasChildren
                required property int depth

                TapHandler{
                    onTapped: treeView.toggleExpanded(row)
                }
                Text{
                    id: indicator
                    visible: treeDelegate.isTreeNode && treeDelegate.hasChildren
                    text:"▸"
                    color: "white"
                    x: padding + (treeDelegate.depth * treeDelegate.indent)
                    anchors.verticalCenter: label.verticalCenter
                    rotation: treeDelegate.expanded ? 90:0
                }
                Text{
                    text: model.fileName
                    color: "white"
                    x: padding + (treeDelegate.isTreeNode ? (treeDelegate.depth + 1) * treeDelegate.indent:0)
                    width: treeDelegate.width - treeDelegate.padding - x
                    clip: true
                }
            }
        }
    }
}