//Chapter28 클래스 상속 기초

#include<iostream>

using namespace std;

/*
    상속 : 클래스는 서로간에 부모 자식관계를 형성 할 수 있다.
           자식 클래스는 부모클래스의 멤버 변수를 사용 할 수 있다.
           부모클래스에있는 멤버변수들은 public 이나 protected로 되어 있는 멤버들은 사용이 가능하지만,
           private으로 되어 있는 멤버는 자식에서도 사용이 불가능하다. 


    상속의 형태 : public, private 상속이 있다.
 */

class CParent
{
    public:
    CParent()
    {
        cout << "CParent 생성자" << endl;

    }
    ~CParent()
    {
        cout << "CParent 소멸자" << endl;
    }
    public:
        int m_iA;
    protected:
        int m_iB;
    private:
        int m_iC;

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
    ~CChild()
    {
        cout << "CChild 소멸자" << endl;
    }

    protected:
         int m_iD;
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
    /*
        상속관계에서의 생성자 호출 순서 : 부모 -> 자식 순
        상속관계에서의 소멸자 호출 순서 : 자식 -> 부모 순
     */
    CParent parent;
    CChild  child;
    CChild1 child1;
    CChildChild childchild;

    parent.m_iA = 100;
    child.m_iA = 200;
    //외부에서는 private으로 상속받으면 접근을 못함.
    //child1.m_iA = 300;
    return 0;
}