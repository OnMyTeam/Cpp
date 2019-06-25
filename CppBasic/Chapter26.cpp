//Chapter26 함수 포인터와 C++11 Functional

#include<iostream>
#include<functional>

using namespace std;
/*

    함수 포인터 : 함수의 메모리 주소를 저장하기 위한 포인터 변수를 선언할 수 있다.
                 전역함수의 경우 함수명이 곧 함수의 메모리 주소이다.

    선언방법    : 반환타입 (*포인터명)(인자타입); 형태로 구성이 된다.


 */

int Sum(int a, int b)
{
    return a+b;
}

int OutSum(int a, int b)
{
    cout << a - b << endl;
    return a - b;
}

void Output()
{
    cout << "Output Function" << endl;
}

class CHanzo
{

    public:
    CHanzo()
    {
        m_iTest = 10;
    }
    ~CHanzo()
    {

    }
    public:
        int m_iTest;
    public:
        void OutPut()
        {
            cout << "Hanzo" << endl;
            //this -> 는 생략할 수 있다.
            cout << "Test : " << this->m_iTest << endl;
        }
};
int main()
{
    int (*pFunc)(int, int) = Sum;
    void (*pFunc1)() = Output;

    cout << pFunc(10, 20) << endl;
    pFunc = OutSum;
    pFunc(10, 20);
    // 아래는 void 타입이고 인자 타입이 없으므로 별도로 다시 선언해야함
    //pFunc = Output;
    pFunc1();   

    CHanzo hanzo1, hanzo2;

    hanzo1.m_iTest = 100;
    hanzo2.m_iTest = 200;

    // this 포인터 : 클래스 안에서 this를 사용할 경우 해당 객체의 메모리 주소가 된다. 즉 자기자신의 포인터이다.
    // 멤버함수를 호출할떄
    hanzo1.OutPut();
    hanzo2.OutPut();
    // 멤버함수포인터 선언시 포인터변수 이름앞에 클래스명:: 을 붙여준다.
    // :: 범위지정 연산자
    void (CHanzo::*pFunc2)() =&CHanzo::OutPut;
    
    (hanzo1.*pFunc2)();
    /*
        function 기능은 C++11부터 지원해 주는 기능이다. 이 기능은 함수포인터를  전역, 멤버 가리지 않고
        쉽게 주소를 저장해서 호출해 줄수 있또록 만들어주는 기능이다.

        선언방법 : function<반환타입(인자타입)> 변수명; 의 형태로 선언함

     */
    function<void()> func;
    function<void()> func1;
    // bind를 이용해서 함수를 묶어 준다.  
    func = bind(Output);
    func1 = bind(&CHanzo::OutPut, &hanzo1);
    cout << "================== Functional ==================" << endl; 
    func();
    func1();

    function<int(int, int)> func3;
    // 함수에 인자가 있을 경우 placeholders를 이용해서 인자의 순서를 정의할 수 있다. 아래처럼 2, 1로 넣어주면 인자가 서로 바뀐다.
    func3 = bind(OutSum, placeholders::_2, placeholders::_1);
    func3(10, 20);
    return 0;  
}
