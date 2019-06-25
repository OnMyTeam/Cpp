//Chapter26 �Լ� �����Ϳ� C++11 Functional

#include<iostream>
#include<functional>

using namespace std;
/*

    �Լ� ������ : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� �ִ�.
                 �����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.

    ������    : ��ȯŸ�� (*�����͸�)(����Ÿ��); ���·� ������ �ȴ�.


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
            //this -> �� ������ �� �ִ�.
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
    // �Ʒ��� void Ÿ���̰� ���� Ÿ���� �����Ƿ� ������ �ٽ� �����ؾ���
    //pFunc = Output;
    pFunc1();   

    CHanzo hanzo1, hanzo2;

    hanzo1.m_iTest = 100;
    hanzo2.m_iTest = 200;

    // this ������ : Ŭ���� �ȿ��� this�� ����� ��� �ش� ��ü�� �޸� �ּҰ� �ȴ�. �� �ڱ��ڽ��� �������̴�.
    // ����Լ��� ȣ���ҋ�
    hanzo1.OutPut();
    hanzo2.OutPut();
    // ����Լ������� ����� �����ͺ��� �̸��տ� Ŭ������:: �� �ٿ��ش�.
    // :: �������� ������
    void (CHanzo::*pFunc2)() =&CHanzo::OutPut;
    
    (hanzo1.*pFunc2)();
    /*
        function ����� C++11���� ������ �ִ� ����̴�. �� ����� �Լ������͸�  ����, ��� ������ �ʰ�
        ���� �ּҸ� �����ؼ� ȣ���� �ټ� �ֶǷ� ������ִ� ����̴�.

        ������ : function<��ȯŸ��(����Ÿ��)> ������; �� ���·� ������

     */
    function<void()> func;
    function<void()> func1;
    // bind�� �̿��ؼ� �Լ��� ���� �ش�.  
    func = bind(Output);
    func1 = bind(&CHanzo::OutPut, &hanzo1);
    cout << "================== Functional ==================" << endl; 
    func();
    func1();

    function<int(int, int)> func3;
    // �Լ��� ���ڰ� ���� ��� placeholders�� �̿��ؼ� ������ ������ ������ �� �ִ�. �Ʒ�ó�� 2, 1�� �־��ָ� ���ڰ� ���� �ٲ��.
    func3 = bind(OutSum, placeholders::_2, placeholders::_1);
    func3(10, 20);
    return 0;  
}
