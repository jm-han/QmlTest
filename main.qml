import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import ConnectEvent 1.0//등록한 클래스 타입을 import해준다.
import "."

Window {
    property bool mbImageClicked : true
    property int mCount : 0

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qmlSignalStringData(var stringData); //qml에서 signal을 선언해주는 부분
    signal qmlSignalintData(var intData); //qml에서 signal을 선언해주는 부분

    function qmlSlotTestData(data){//slot으로 등록한 함수
        console.log("qmlSlotTestData data:" + data);
    }
    ConnectEvent//qml에 클래스를 선언해 주는 곳
    {
        id:connectEvent;//클래스를 선언해주고 id를 등록
    }

    StackView
    {
        id:stackView
        anchors.fill: parent


        initialItem: Item  //제일 첫화면을 설정하는 것으로 설정을 안하면 되돌아오기가 안된다.
        {
            objectName: "mainscreen"//이전화면에 대한 정보를 얻기위해 설정하는 값
            Rectangle//배경 색을 지정하는 부분
            {
                anchors.fill: parent
                color:"red"
            }

            Button
            {
                id:strButton //string형 데이터를 매개변수에 넣어서 cpp함수를 호출하는 버튼
                anchors.rightMargin: 30
                text:"String Data"
                onClicked:
                {
                    console.log("qml signal strButton click")
                    connectEvent.cppStringTestMethod("qml register class method"); //등록한 클래스의 함수를 호출 하는 방법
                }
            }
        }
    }
}
