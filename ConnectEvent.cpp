#include "ConnectEvent.h"
ConnectEvent::ConnectEvent()
{
    cout << "ConnectEvent" << endl;
    qmlRegisterType<ConnectEvent>("ConnectEvent", 1, 0, "ConnectEvent");//class를 qml에서 사용하기 위해서 등록해주는 부분

}

ConnectEvent::~ConnectEvent()
{
}

void ConnectEvent::setWindow(QQuickWindow* Window)
{
    mMainView = Window;//connection을 해주기 위해 윈도우를 등록
}

void ConnectEvent::cppStringTestMethod(QString stringData)//qml 소스코드에서 클래스를 등록해서 클래스의 함수를 직접 호출하는 함수
{
    cout << "cppStringTestMethod call" << endl;
    std::string data_str = stringData.toStdString();//QVariant를 std::string으로 변환
    cout << "cppStringTestMethod data_str: " << data_str << endl;
    for(int i=0;i<5;i++){
        cout << i << endl;
    }

}

// text 입력함수
QString ConnectEvent::setText(QString Value)
{
    return Value;
}
