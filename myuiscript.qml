import QtQuick 2.0

Rectangle {
	id: bgRect
	width: 200
	height: 200
	    color: "black"
	    Component {
id: myDelegate
	    Item {
width: 200
	       height: 40
	       Rectangle {
		       anchors.fill: parent
			       anchors.margins: 2
			       radius: 5
			       color: "lightsteelblue"
			       Row {
				       anchors.verticalCenter: parent.verticalCenter
					       Text {
text: model.lastName
	      color: "black"
	      font.bold: true
					       }
				       Text {
text: model.firstName
	      color: "black"
				       }
			       }
	       }
	    }
	    }
    ListView {
id: myListView
	    anchors.fill: parent
	    delegate: myDelegate
	    model: myModel
    }
}
