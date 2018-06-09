/* source from http://copynull.tistory.com/138 */
#include <iostream>

using namespace std;

class SubClassA
{
public:
    void operation() { cout << "SubClass A" << endl; }
};
 
class SubClassB
{
public:
    void operation() { cout << "SubClass B" << endl; }
};
 
class SubClassC
{
public:
    void operation() { cout << "SubClass C" << endl; }
};
 
class Facade
{
public:
    Facade(SubClassA *a, SubClassB *b, SubClassC* c) : mSubA(a), mSubB(b), mSubC(c) {}
 
public:
    void operation() { mSubA->operation(); mSubB->operation(); mSubC->operation(); }
 
private:
    SubClassA* mSubA;
    SubClassB* mSubB;
    SubClassC* mSubC;
};
 
//------------------------------------------------------------------
// Main
int main(int argc, char* argv[])
{
    SubClassA subA;
    SubClassB subB;
    SubClassC subC;
 
    Facade facade(&subA, &subB, &subC);
 
    facade.operation();
 
    return 0;
}
