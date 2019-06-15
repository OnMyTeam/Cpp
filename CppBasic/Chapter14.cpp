// Chapter14 �����Ϳ� �迭, void ������, ����ü ������

#include <iostream>

using namespace std;

struct _tagStudent
{
    int iKor;
    int iEng;
    int iMaht;
    int iTotal;
    float fAvg;
};
/*
    �����͸� ���� ����? �ٸ� ������ �޸� �ּҸ� �̿��ؼ� �����Ͽ� ���� �����ϱ� ����.
 */
int main(){
    int iNumber = 100;
    _tagStudent tStudent = {};
    tStudent.iKor = 100;

    _tagStudent *pStudent = &tStudent;
    // ������ �켱������ ���� .�� ���� �ν��ؼ� �޸� �ּ� .�� �߸���
    // *pStudent�� ��ȣ�� ���� ���Ŀ� .�� �̿��ؼ� ��������� ��������
    (*pStudent).iKor = 50;
    cout << tStudent.iKor << endl;
    // '�޸� �ּ�->' �� �̿��ϸ� ����Ű�� ����� ��������� ������ �� �ִ�.
    // '(*pStudent).iKor' = 'pStudent->iKor'
    pStudent->iKor = 80;
    cout << tStudent.iKor << endl;

    // void : Ÿ���� ����. return�� Ÿ���̾���. 
    // void* ������ ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ���� �����ϴ�.
    // ��, �������� �Ұ����ϴ�. �޸� �ּҸ� ������ ������.
    void* pVoid = &iNumber;
    cout << "iNumber Address : " << pVoid << endl;
    // �Ʒ��� �������� �Ұ�����.
    *pVoid = 10;
    // �Ʒ��� ���� intŸ���� ����ȯ�� ���ؼ� pConvert ������ �����ѵ� �������ؼ� �����ؾ� ��.
    int *pConvert = (int*)pVoid;
    *pConvert = 200;
    
    cout << "iNumber : " << iNumber << endl;
    pVoid = &tStudent;
    cout << "tStudent Address : " << pVoid << endl;

    
    return 0;
}