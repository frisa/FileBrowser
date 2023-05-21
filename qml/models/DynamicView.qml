import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import models.sys 1.0

// https://www.qt.io/product/qt6/qml-book/ch17-qtcpp-cpp-models needs to be finished

Rectangle {
    color: "blue"
    DynamicEntryModel {
        id: dynamicModel
        onCountChanged: {
            print('new count: ' + dynamicModel.count)
            print('last entry: ' + dynamicModel.get(dynamicModel.count - 1))
        }
    }
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 8
        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            ListView {
                model: dynamicModel
                delegate: ListDelegate {
                    required property var model
                    width: ListView.view.width
                    text: model.name
                    onClicked: {
                        view.currentIndex = model.index
                        view.focus = true
                    }
                    onRemove: {
                        dynamicModel.remove(model.index)
                    }
                }
            }
        }
        TextEntry {
            id: textEntry
            onAppend: function(name){
            dynamicModel.append(name)
        }
    }
}
}
