//Chapter29 클래스 상속과 다형성 가상함수 

#include<iostream>

using namespace std;

/*
    다형성 : 상속관계에 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.
    가상함수 : 함수 오보라이딩 이라고도 부른다. 함수를 재정의하는 기능이다.
    멤버함수 앞에 virtual 키워드를 붙이면 해당 함수는 가상함수가 된다.
    만약 CParent 클래스에 virtual void Output() 함수가 있다면 자식 클래스에서는 이 가상함수를 재정의 할 수 있다.
    재정의는 함수 이름과 인자가 완전히 똑같아야 한다.  
              
    가상함수를 가지고 있는 클래스는 내부적으로 가상함수 테이블이라는 것을 생성한다.
    가상 함수 테이블은 가상함수들의 메모리 주소를 저장하는 테이블이다.

    만약 CParent의 Output이 가상함수 있고 CChild 클래스에 Output을 재정의 하고 CChild 객체를 생성하면
    가상함수 테이블에는 CChild 클래스의 Output 주소가 올라가게 된다.
    만약 CParent 객체를 생성한다면 CParent의 Output 주소가 올라가게 된다.

    그래서 Output 함수,즉 가상함수를 호출하게되면 먼저 가상함수 테이블을 참조해서 메모리 주소를 확인한다. 가상함수 테이블에
    CChild의 Output주소가 들어가 있따면 그 주소의 함수를 호출해 주는 개념이다. 

    소멸자도 가상함수로 만들 수 있다. 부모의 소멸자를 가상함수로 만들어두자.
 */

class CParent
{
    public:
    CParent()
    {
        cout << "CParent 생성자" << endl;

    }
    virtual ~CParent()
    {
        cout << "CParent 소멸자" << endl;
    }
    public:
        int m_iA;
    protected:
        int m_iB;
    private:
        int m_iC;
    
    public:
        virtual void Output()
        {
        cout << "Parent Output Function" << endl;
        }
        // 순수가상함수 : 함수 뒤에 = 을 붙여주면 해당 가상함수는
        // 순수 가상함수가 된다. 순수 가상함수는 구현 부분이 존재하지 않는다.
        // 순구 가상함수를 가지고 있는 클래스를 추상클래스라고 부른다.
        // 추상클래스는 인스턴스(객체) 생성이 불가능하다.
        // 순수 가상함수는 자식에서 반드시 재정의 해야 한다. 왜냐면 정의 부분이 없기 떄문에 자식부분에서 재정의 해야한다.
        virtual void OutputPure() = 0;

};

class CChild : public CParent
{

    public:
    CChild()
    {
        m_iB = 200;
        // m_iC는 CParent의 private 변수이기 떄문에 접근이 불가능 하다 
        //m_iC = 300;
        cout << "CChild 생성자" << endl;
    }
    virtual ~CChild()
    {
        cout << "CChild 소멸자" << endl;
    }

    protected:
         int m_iD;
        
    public:
    void ChildOutPut()
    {
        cout << "Child Output Function" << endl;
    }
    void Output()
    {   CParent::Output();
        cout << "Child Output Function" << endl;
    }
    virtual void OutputPure()
    {

    }
};
class CChild1 : private CParent
{
    public:
    CChild1()
    {
        //private으로 상속 받아도 안에서는 접근이 가능함
        m_iA = 100;
        cout << "CChild1 생성자" << endl;
    }
    ~CChild1()
    {
        cout << "CChild1 소멸자" << endl;
    }
    private:
         int m_iD;    

};

class CChildChild : public CChild
{
    public:
    CChildChild()
    {
        m_iD = 500;
        cout << "CChildChild 생성자" << endl;
    }
    ~CChildChild()
    {
         cout << "CChildChild 소멸자" << endl;
    }

    private:
        int m_iE; 
};
int main()
{
    // CChild 클래스는CParent 클래스를 상속받고 있다.
    // new CChild를 하게 되면 CChild를 객체 하나를 생성해주고 그 메모리 주소를 봔한한다.
    // 아래처럼 부모 포인터 타입에 CChild의 메모리 주소를 넣을 수 있는 이유는
    // 상속관계에 있기 떄문이다. 자식 메모리 주소를 부모 파인터 타입으로 형변환 된것 이기 때문이다. 이런 형변환을 업캐스팅 이라한다.
    // 자식 -> 부모 타입 형변환 : 업캐스티
    // 부모 -> 자식 타입 형변환 : 다운캐스팅
    CParent* pParent = new CChild;
    //CParent* pParent1 = new CChild1;
    // pParent3 객체는 OutputPure의 순수가상함수가 있기 떄문에 객체 생성이 안된다. 추상클래스 이기 떄문에.
    CParent pParent3;
    CParent* pParent2 = new CChildChild;
    // CChild 클래스에 있는 ChildOutput 함수에 접근 할 수 없다.
    // 왜냐면 pParent는 CParent 포인터 타입이기 떄문에 자식 멤버에 접근이 불가능 하다.
    // 접근하고 싶다면 형변환 해야 한다.
    ((CChild*)pParent)->ChildOutPut();
    pParent->Output();
    CParent* pParentArr[2] = {};
    pParentArr[0] = new CChild;
    pParentArr[1] = new CChildChild;


    // 아래 두 클래스는 모두 CParent 클래스를 상속받고 있는데, pParent는 두 타입 모두 다운 캐스팅 가능하다.
    // pParent는 CChild로 할당한 객체이기 때문에, 이 객체를 CChild1 타
    //입으로 다운캐스팅 하여 넣어주게 되면
    // 이 객체를 사용할떄 문제가 발생할 수 있다. 왜냐면 애초에 생성한 객체가 아닌 다른타입으로 변환됐기 떄문이다.
    CChild* pChild = (CChild*)pParent; 
    CChild1* pChild1 = (CChild1*)pParent;

    delete pParent;
    delete pParent2;

    for(int i = 0   ; i < 2; i++){
        delete pParentArr[i];
    }
    return 0;
}