import QtQuick 2.0
import QtQuick.Controls 1.4
import MeshDevelop 1.0

Rectangle {
    color: '#909294'
    Text{
        y: 30
        text: "Welcome to measurement plugin!"
    }
    Component.onCompleted: SubBackends.construction()
}
