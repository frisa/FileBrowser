import QtQuick
import QtQuick.Layouts

Component{
    id: listModelDelegate
    RowLayout{
        Text{
            text: name
        }
        Text{
            text: description
        }
    }
}