//Chapter25 Ŭ���� �����ڿ� �Ҹ���

#include<iostream>
#include<string.h>
using namespace std;

/*
    �����ڿ� �Ҹ���

    1. ������ : � Ŭ������ �̿��ؼ� ��ü�� �����Ҷ� �ڵ����� ȣ��Ǵ� �Լ� �̴�. ��ü ������ ȣ��Ǵ� �Լ� �̱� ������
                ��ü�� ��������� �ʱ�ȭ �ҋ� �����ϰ� ����. �����ڸ� ����� ���� ���� ��� ���������� �⺻ �����ڰ� �־
                �⺻ �����ڸ� �ڵ����� ȣ�����ְ� �ȴ�.
        ���� : Ŭ������(){};
    2. �Ҹ��� : � Ŭ������ �̿��ؼ� ������ ��ü�� �޸𸮿��� �����ɶ�, ���� ��� ���� ���� �Ἥ �ڵ���� ����ǰų�
                �����Ҵ��� ���� �ּҸ� �ް� ���� Delete�ؼ� �޸𸮿� �����ɋ� �ڵ����� ȣ��Ǵ� �Լ��̴�. ��ü�� ����ϰ� �� ��
                ������ �۾��� ���ً� �����ϰ� ����� �� �ִ�. 

        ���� : ~Ŭ������(){}

    2. 
 */
class CTracer
{   

    char m_cStrName[32];
    //  public Ű���� �Ʒ��� �ִ� ����� ��� �ܺο��� ������ �����ϴ�.
    public:
        int m_iAttack;
        int m_iHP; 
    private:
        int m_iFlash;
        int m_iBack;

    public:
        // ������
        // ������ ���� �����ε��� �����ϴ�.
        CTracer()
        {
            cout << "������ ����" << endl; 
            strcpy(m_cStrName,"pName");
        }
        CTracer(const char* pName)
        {
            strcpy(m_cStrName,pName);
        }
        CTracer(const char* pName, int iFlash, int iBack) : 
            // �Ʒ��� ���� �������� ���� �ʱ�ȭ �ϴ°ſ� ����.
            m_iBack(iBack),
            m_iFlash(iFlash)
        {
            strcpy(m_cStrName,pName);
            //m_iFlash = iFlash; 
        }        
        // �Ҹ���
        ~CTracer()
        {
            cout << "�Ҹ��� ����" << endl;
        }
    public:
        void OutPut()
        {
            cout << "���" << endl;
            cout << "Name : "<< m_cStrName << endl;
            cout << "iBacks : "<< m_iBack << endl;
            cout << "iFlash : "<< m_iFlash << endl;
        }
};
int main()
{
      // main() �Լ� ���� Ŭ���� �ܺ��̱� ������ public���� ���� �Ǿ� �ִ� ������� ������ �����ϴ�.
    CTracer tr1("�����ε� �Լ�", 3, 1);
    tr1.OutPut();
    
    return 0;
}