//Chapter30 ���ø� �̷�

#include<iostream>
#include<typeinfo>
using namespace std;

/*
    ���ø� : ������ �ܰ迡�� Ÿ���� �������� ����̴�.
            Ÿ���� �پ��ϰ� �ٲ� �� �ִ�.
            template<typename ���ϴ� �̸�>�� ���·� ��� �����ϴ�.
            template<class ���ϴ� �̸�>�� ���·� ��� �����ϴ�.
    
    ��) template <typename T>
    void Output()
    {
        cout << typeid(T).name() << endl;
    }
    ��ó�� �Լ��� ����� ȣ���
    Output<int>();
    Output<float>();
    �̷��� ���ָ� int, float���� Ÿ���� ��������. ��Ȳ�� ���� �־��ִ� Ÿ������ Ÿ���� ���������� �ٲ�� ����.
    ����Ÿ���� �������� ������ �� �� �ִ�.
    template<typename T, typename T1>
    void Output()
    {

    }


 */
 
template<typename T>
void OutputType()
{
    cout << typeid(T).name() << endl; 
}
template <typename T>
void OutputData(T data)
{
    cout << "==== OutputData ====" << endl; 
    cout << typeid(T).name() << endl;
    cout << data << endl;
}

typedef struct _tagStudent
{

}STUDENT, *PSTUDENT;
class CCar
{
    public:
        CCar()
        {
            
        }
        ~CCar()
        {

        }
};
enum TEST
{

};

class CTemplate
{
    public:
    CTemplate()
    {

    }
    ~CTemplate()
    {

    }
public:
    template <class T, class T1>
    void Output(T a, T1 b)
    {
         cout << a << endl;
         cout << b << endl;
    }

};

template<typename T>
class CTemplate1
{
    public:
    CTemplate1()
    {
        cout << "Template1 class Type: " << typeid(T).name() << endl;
    }
    ~CTemplate1()
    {

    }
    private:
    T m_Data;
    public:
    void Output(){
        cout << typeid(T).name() << endl;
        cout << m_Data << endl;
    }
};
int main()
{ 
    OutputType<int>();
    OutputType<float>();
    OutputType<STUDENT>();
    OutputType<CCar>();
    OutputType<TEST>();

    OutputData(10);
    OutputData(3.1);
    OutputData(382.383f);
    OutputData('a');
    OutputData("�������� ");

    CTemplate tem;
    tem.Output(10, 3.14f); 

    CTemplate1<int> tem1;
    tem1.Output();
    CTemplate1<CTemplate> tem2;
    return 0;
}
