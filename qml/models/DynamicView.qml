import QtQuick
import QtQuick.Layouts
import models.sys 1.0

Rectangle{
    color: "blue"
    ListView{
        anchors.fill: parent
        model: DynamicEntryModel{}
        delegate: RowLayout{
            Text{
                color: "white"
                text: model.name
            }
            Text{
                color: "white"
                text: model.description
            }
        }
    }
}