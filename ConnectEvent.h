#ifndef CONNECTEVENT_H
#define CONNECTEVENT_

#include <QQuickView>
#include <QObject>
#include <iostream>
using namespace std;

class ConnectEvent : public QObject//connection을 사용하기 위해 상속 받아야 하는 클래스
{
public:
    Q_OBJECT
public:
    ConnectEvent();
    ~ConnectEvent();

    void setWindow(QQuickWindow* Window);
    Q_INVOKABLE void cppStringTestMethod(QString stringData);//함수앞에 Q_INVOKABLE를 선언해서 qml에서 직접 호출이 가능한 함수를 만들어 준다.
private:

    QQuickWindow* mMainView;
};

#endif // CONNECTEVENT_H
