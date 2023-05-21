import QtQuick
import QtQuick.Layouts
import models.sys 1.0

Rectangle {
    color: "blue"
    ListView {
        DynamicEntryModel {
            id: dynamicModel
            onCountChanged: {
                print('new count: ' + dynamicModel.count)
            }
        }
        anchors.fill: parent
        model: dynamicModel
        delegate: RowLayout {
            Text {
                color: "white"
                text: model.name
            }
            Text {
                color: "white"
                text: model.description
            }
        }
    }
}
