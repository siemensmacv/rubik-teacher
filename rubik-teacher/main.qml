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

    Settings {
        id: settings
        property string style: "Default"
    }

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
                    source: "images/menu.png"
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
                    model: availableStyles
                    Component.onCompleted: {
                        styleIndex = find(settings.style, Qt.MatchFixedString)
                        if (styleIndex !== -1)
                            currentIndex = styleIndex
                    }
                    Layout.fillWidth: true
                }
                Label {
                    text: "Restart required"
                    color: "#e41e25"
                    opacity: styleBox.currentIndex !== styleBox.styleIndex ? 1.0 : 0.0
                    horizontalAlignment: Label.AlignHCenter
                    verticalAlignment: Label.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        //Repeater {
          //  model: 4

            Pane {
                id:pane1
                width: swipeView.width
                height: swipeView.height
            }
            Pane {
                id:pane2
                width: swipeView.width
                height: swipeView.height
                Image{
                    source:"images/menu.png"
                }
            }
            Pane {
                id:pane3
                width: swipeView.width
                height: swipeView.height
                Image{
                    source:"images/100x100bb.jpg"
                }
            }
            Pane {
                id:pane4
                width: swipeView.width
                height: swipeView.height
                Image{
                    source:"images/menu.png"
                }
            }
      //  }

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
