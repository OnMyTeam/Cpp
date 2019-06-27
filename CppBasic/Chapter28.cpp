//Chapter28 Ŭ���� ��� ����

#include<iostream>

using namespace std;

/*
    ��� : Ŭ������ ���ΰ��� �θ� �ڽİ��踦 ���� �� �� �ִ�.
           �ڽ� Ŭ������ �θ�Ŭ������ ��� ������ ��� �� �� �ִ�.
           �θ�Ŭ�������ִ� ����������� public �̳� protected�� �Ǿ� �ִ� ������� ����� ����������,
           private���� �Ǿ� �ִ� ����� �ڽĿ����� ����� �Ұ����ϴ�. 


    ����� ���� : public, private ����� �ִ�.
 */

class CParent
{
    public:
    CParent()
    {
        cout << "CParent ������" << endl;

    }
    ~CParent()
    {
        cout << "CParent �Ҹ���" << endl;
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
        // m_iC�� CParent�� private �����̱� ������ ������ �Ұ��� �ϴ� 
        //m_iC = 300;
        cout << "CChild ������" << endl;
    }
    ~CChild()
    {
        cout << "CChild �Ҹ���" << endl;
    }

    protected:
         int m_iD;
};
class CChild1 : private CParent
{
    public:
    CChild1()
    {
        //private���� ��� �޾Ƶ� �ȿ����� ������ ������
        m_iA = 100;
        cout << "CChild1 ������" << endl;
    }
    ~CChild1()
    {
        cout << "CChild1 �Ҹ���" << endl;
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
        cout << "CChildChild ������" << endl;
    }
    ~CChildChild()
    {
         cout << "CChildChild �Ҹ���" << endl;
    }

    private:
        int m_iE; 
};
int main()
{
    /*
        ��Ӱ��迡���� ������ ȣ�� ���� : �θ� -> �ڽ� ��
        ��Ӱ��迡���� �Ҹ��� ȣ�� ���� : �ڽ� -> �θ� ��
     */
    CParent parent;
    CChild  child;
    CChild1 child1;
    CChildChild childchild;

    parent.m_iA = 100;
    child.m_iA = 200;
    //�ܺο����� private���� ��ӹ����� ������ ����.
    //child1.m_iA = 300;
    return 0;
}