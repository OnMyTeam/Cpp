//Chapter25 클래스 생성자와 소멸자

#include<iostream>
#include<string.h>
using namespace std;

/*
    생성자와 소멸자

    1. 생성자 : 어떤 클래스를 이용해서 객체를 생성할때 자동으로 호출되는 함수 이다. 객체 생성시 호출되는 함수 이기 때문에
                객체의 멤버변수를 초기화 할떄 유용하게 사용됨. 생성자를 만들어 주지 않을 경우 내부적으로 기본 생성자가 있어서
                기본 생성자를 자동으로 호출해주게 된다.
        형태 : 클래스명(){};
    2. 소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서 해제될때, 예를 들어 지역 변수 써서 코드블럭이 종료되거나
                동적할당을 통해 주소를 받고 난뒤 Delete해서 메모리에 해제될떄 자동으로 호출되는 함수이다. 객체를 사용하고 난 뒤
                마무리 작업을 해줄떄 유용하게 사용할 수 있다. 

        형태 : ~클래스명(){}

    2. 
 */
class CTracer
{   

    char m_cStrName[32];
    //  public 키워드 아래에 있는 멤버는 모두 외부에서 접근이 가능하다.
    public:
        int m_iAttack;
        int m_iHP; 
    private:
        int m_iFlash;
        int m_iBack;

    public:
        // 생성자
        // 생성자 또한 오보로딩이 가능하다.
        CTracer()
        {
            cout << "생성자 생성" << endl; 
            strcpy(m_cStrName,"pName");
        }
        CTracer(const char* pName)
        {
            strcpy(m_cStrName,pName);
        }
        CTracer(const char* pName, int iFlash, int iBack) : 
            // 아래는 변수 선언하자 마자 초기화 하는거와 같다.
            m_iBack(iBack),
            m_iFlash(iFlash)
        {
            strcpy(m_cStrName,pName);
            //m_iFlash = iFlash; 
        }        
        // 소멸자
        ~CTracer()
        {
            cout << "소멸자 생성" << endl;
        }
    public:
        void OutPut()
        {
            cout << "출력" << endl;
            cout << "Name : "<< m_cStrName << endl;
            cout << "iBacks : "<< m_iBack << endl;
            cout << "iFlash : "<< m_iFlash << endl;
        }
};
int main()
{
      // main() 함수 안은 클래스 외부이기 때문에 public으로 설정 되어 있는 멤버에만 접근이 가능하다.
    CTracer tr1("오보로딩 함수", 3, 1);
    tr1.OutPut();
    
    return 0;
}