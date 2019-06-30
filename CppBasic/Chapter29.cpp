//Chapter29 Ŭ���� ��Ӱ� ������ �����Լ� 

#include<iostream>

using namespace std;

/*
    ������ : ��Ӱ��迡 �ִ� Ŭ�������� ���� ����ȯ�� ������ ������ ���Ѵ�.
    �����Լ� : �Լ� �������̵� �̶�� �θ���. �Լ��� �������ϴ� ����̴�.
    ����Լ� �տ� virtual Ű���带 ���̸� �ش� �Լ��� �����Լ��� �ȴ�.
    ���� CParent Ŭ������ virtual void Output() �Լ��� �ִٸ� �ڽ� Ŭ���������� �� �����Լ��� ������ �� �� �ִ�.
    �����Ǵ� �Լ� �̸��� ���ڰ� ������ �Ȱ��ƾ� �Ѵ�.  
              
    �����Լ��� ������ �ִ� Ŭ������ ���������� �����Լ� ���̺��̶�� ���� �����Ѵ�.
    ���� �Լ� ���̺��� �����Լ����� �޸� �ּҸ� �����ϴ� ���̺��̴�.

    ���� CParent�� Output�� �����Լ� �ְ� CChild Ŭ������ Output�� ������ �ϰ� CChild ��ü�� �����ϸ�
    �����Լ� ���̺��� CChild Ŭ������ Output �ּҰ� �ö󰡰� �ȴ�.
    ���� CParent ��ü�� �����Ѵٸ� CParent�� Output �ּҰ� �ö󰡰� �ȴ�.

    �׷��� Output �Լ�,�� �����Լ��� ȣ���ϰԵǸ� ���� �����Լ� ���̺��� �����ؼ� �޸� �ּҸ� Ȯ���Ѵ�. �����Լ� ���̺�
    CChild�� Output�ּҰ� �� �ֵ��� �� �ּ��� �Լ��� ȣ���� �ִ� �����̴�. 

    �Ҹ��ڵ� �����Լ��� ���� �� �ִ�. �θ��� �Ҹ��ڸ� �����Լ��� ��������.
 */

class CParent
{
    public:
    CParent()
    {
        cout << "CParent ������" << endl;

    }
    virtual ~CParent()
    {
        cout << "CParent �Ҹ���" << endl;
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
        // ���������Լ� : �Լ� �ڿ� = �� �ٿ��ָ� �ش� �����Լ���
        // ���� �����Լ��� �ȴ�. ���� �����Լ��� ���� �κ��� �������� �ʴ´�.
        // ���� �����Լ��� ������ �ִ� Ŭ������ �߻�Ŭ������� �θ���.
        // �߻�Ŭ������ �ν��Ͻ�(��ü) ������ �Ұ����ϴ�.
        // ���� �����Լ��� �ڽĿ��� �ݵ�� ������ �ؾ� �Ѵ�. �ֳĸ� ���� �κ��� ���� ������ �ڽĺκп��� ������ �ؾ��Ѵ�.
        virtual void OutputPure() = 0;

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
    virtual ~CChild()
    {
        cout << "CChild �Ҹ���" << endl;
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
    // CChild Ŭ������CParent Ŭ������ ��ӹް� �ִ�.
    // new CChild�� �ϰ� �Ǹ� CChild�� ��ü �ϳ��� �������ְ� �� �޸� �ּҸ� �����Ѵ�.
    // �Ʒ�ó�� �θ� ������ Ÿ�Կ� CChild�� �޸� �ּҸ� ���� �� �ִ� ������
    // ��Ӱ��迡 �ֱ� �����̴�. �ڽ� �޸� �ּҸ� �θ� ������ Ÿ������ ����ȯ �Ȱ� �̱� �����̴�. �̷� ����ȯ�� ��ĳ���� �̶��Ѵ�.
    // �ڽ� -> �θ� Ÿ�� ����ȯ : ��ĳ��Ƽ
    // �θ� -> �ڽ� Ÿ�� ����ȯ : �ٿ�ĳ����
    CParent* pParent = new CChild;
    //CParent* pParent1 = new CChild1;
    // pParent3 ��ü�� OutputPure�� ���������Լ��� �ֱ� ������ ��ü ������ �ȵȴ�. �߻�Ŭ���� �̱� ������.
    CParent pParent3;
    CParent* pParent2 = new CChildChild;
    // CChild Ŭ������ �ִ� ChildOutput �Լ��� ���� �� �� ����.
    // �ֳĸ� pParent�� CParent ������ Ÿ���̱� ������ �ڽ� ����� ������ �Ұ��� �ϴ�.
    // �����ϰ� �ʹٸ� ����ȯ �ؾ� �Ѵ�.
    ((CChild*)pParent)->ChildOutPut();
    pParent->Output();
    CParent* pParentArr[2] = {};
    pParentArr[0] = new CChild;
    pParentArr[1] = new CChildChild;


    // �Ʒ� �� Ŭ������ ��� CParent Ŭ������ ��ӹް� �ִµ�, pParent�� �� Ÿ�� ��� �ٿ� ĳ���� �����ϴ�.
    // pParent�� CChild�� �Ҵ��� ��ü�̱� ������, �� ��ü�� CChild1 Ÿ
    //������ �ٿ�ĳ���� �Ͽ� �־��ְ� �Ǹ�
    // �� ��ü�� ����ҋ� ������ �߻��� �� �ִ�. �ֳĸ� ���ʿ� ������ ��ü�� �ƴ� �ٸ�Ÿ������ ��ȯ�Ʊ� �����̴�.
    CChild* pChild = (CChild*)pParent; 
    CChild1* pChild1 = (CChild1*)pParent;

    delete pParent;
    delete pParent2;

    for(int i = 0   ; i < 2; i++){
        delete pParentArr[i];
    }
    return 0;
}