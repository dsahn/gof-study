/* 참고 :
 * https://sourcemaking.com/design_patterns/chain_of_responsibility */
#include <iostream>

using namespace std;

//------------------------------------------------------------------
// Handler 인터페이스 클래스
class Handler
{
public:
    Handler(Handler* pHandle) : pHandler(pHandle) {}
    virtual ~Handler() { if (pHandler) delete pHandler; }
 
public:
    virtual void handleRequest(int i)
    {
        if (pHandler != NULL)
            pHandler->handleRequest(i);
        else
            cout << "unhandled case" << endl;
    }
 
private:
    Handler* pHandler;
};
 
//------------------------------------------------------------------
// EvenHandler 상속 클래스
class EvenHandler : public Handler
{
public:
    EvenHandler(Handler* pHandle) : Handler(pHandle) {}
 
public:
    void handleRequest(int i) override
    {
        if (i % 2 == 0)
            cout << "짝수 입니다" << endl;
        else
            Handler::handleRequest(i);
    }
};
 
//------------------------------------------------------------------
// OddHandler 상속 클래스
class OddHandler : public Handler
{
public:
    OddHandler(Handler* pHandle) : Handler(pHandle) {}
 
public:
    void handleRequest(int i) override 
    {
        if (i % 2 != 0)
            cout << "홀수 입니다" << endl;
        else
            Handler::handleRequest(i);
    }
};
 
//------------------------------------------------------------------
// Main
int main(int argc, char* argv[])
{
    Handler* pHandler = new EvenHandler(new OddHandler(NULL));
 
    pHandler->handleRequest(25);
    pHandler->handleRequest(26);

    Handler* pHandler1 = new EvenHandler(nullptr);
    pHandler1->handleRequest(25);
    pHandler1->handleRequest(26);
 
    delete pHandler;
    delete pHandler1;
 
    return 0;
}
