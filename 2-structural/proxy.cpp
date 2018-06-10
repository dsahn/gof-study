/* proxy pattern
 * proxy - subject 간 call interface는 동일한게 특징
 * source from :
 * http://copynull.tistory.com/133 */
 
#include <iostream>

using namespace std;

//------------------------------------------------------------------
// Subject 인터페이스
class Image
{
public:
    /* 이렇게 해야 base ptr에 대고 delete 할때 생기는 warning이 발생하지 않음 
     * https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP52-CPP.+Do+not+delete+a+polymorphic+object+without+a+virtual+destructor */ 
    virtual ~Image() = default;
    virtual void ShowImage() = 0;
};
 
//------------------------------------------------------------------
// RealSubject 상속 클래스
class RealImage : public Image
{
public:
    RealImage(const char* name) : mFile(name) {}
 
public:
    void LoadImage() { wcout << "disk from loading file : " << mFile.c_str() << endl; }
    void ShowImage() { wcout << "show image : " << mFile.c_str() << endl; }
 
private:
    string mFile;
};
 
//------------------------------------------------------------------
// Proxy 상속 클래스
class ProxyImage : public Image
{
public:
    ProxyImage(const char* name) : mFile(name), mImage(NULL) {}
    ~ProxyImage() { if (mImage) delete mImage; }
 
public:
    void ShowImage() 
    {
        if (!mImage)
        {
            mImage = new RealImage(mFile.c_str());
            mImage->LoadImage();
        }
 
        mImage->ShowImage();
    }
 
private:
    string mFile;
    RealImage* mImage;
};
 
//------------------------------------------------------------------
// Main
int main(int argc, char* argv[])
{
    // 요렇게 생성하는게 포인트
    Image* pImage = new ProxyImage("Image.png");
    pImage->ShowImage();    // 로딩 및 출력
    pImage->ShowImage();    // 캐싱 출력
    pImage->ShowImage();    // 캐싱 출력
    delete pImage;
 
    return 0;
}
