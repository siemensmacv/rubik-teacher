import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtCanvas3D 1.1
import QtQuick.Controls.Material 2.1
import Qt.labs.settings 1.0


ApplicationWindow {
    id:window
    title: qsTr("ztest3d")
    width: 1280
    height: 768
    visible: true

    header: ToolBar {
        Material.foreground: "white"

        RowLayout {
            spacing: 20
            anchors.fill: parent

            Label {
                id: titleLabel
                text: "Gallery"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "menu.png"
                }
                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "Settings"
                        onTriggered: settingsDialog.open()
                    }
                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }
            }
        }
    }

    Dialog {
        id:settingsDialog

        x: Math.round((window.width - width) / 2)
        y: Math.round(window.height / 6)
        width: Math.round(Math.min(window.width, window.height) / 3 * 2)
        modal: true
        focus: true
        title: "Settings"

        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: {

            settings.style = styleBox.displayText
            settingsDialog.close()
        }
        onRejected: {
            styleBox.currentIndex = styleBox.styleIndex
            settingsDialog.close()
        }

        contentItem: ColumnLayout {
            id: settingsColumn
            spacing: 20

            RowLayout {
                spacing: 10

                Label {
                    text: "Style:"
                }

                ComboBox {
                    id: styleBox
                    property int styleIndex: -1
                    textRole: "key"
                    model: ListModel{
                        ListElement{key: " First ";value: 123}
                        ListElement{key: " Second ";value: 123}
                        ListElement{key: " Third ";value: 123}

                    }
                    Component.onCompleted: {
                        styleIndex = find(settings.style, Qt.MatchFixedString)
                        if (styleIndex !== -1)
                            currentIndex = styleIndex
                    }
                    Layout.fillWidth: true
                }
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Repeater {
            model: 4

            Pane {
                id:pane1
                 width: swipeView.width
                 height: swipeView.height

                 Rectangle {
                     id:theShiet
                    width: 100
                    height: 100
                    Label{
                        id:textLabel
                        anchors.centerIn: parent
                        text:{
                            if(swipeView.currentIndex==0){
                                "Prajeler"
                            }
                            else{
                                "text1"
                            }
                        }
                        wrapMode:Text.WordWrap
                    }

                    x: window.width/2 - 55
                    y: window.height - 300
                    color: "red"
                    border.color: "black"
                    border.width: 3
                    radius: 10


                 }

                Column {
                    spacing: 40
                    width: parent.width

                    Label {
                        width: parent.width
                        wrapMode: Label.Wrap
                        horizontalAlignment: Qt.AlignHCenter
                        text: "TabBar is a bar with icons or text which allows the user"
                              + " to switch between different subtasks, views, or modes."
                    }
                }
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            id:first
            text: "First"
        }
        TabButton {
            id:second
            text: "Second"
        }
        TabButton {
            id:third
            text: "Third"
        }
        TabButton {
            id:fourth
            text: "Fourth"
        }
    }

}
