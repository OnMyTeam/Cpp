//Chapter12 ����ü�� ���ڿ� �Լ�

#include <iostream>
#include <string.h>

using namespace std;
#define NAME_SIZE 32
/*
    ����ü : �����ִ� ������ ��� �ϳ��� ���ο� Ÿ���� ������ִ� ���. ����� ���� ���� Ÿ���̴�.
    ���� : struct ����ü�� {}; �� ���·� �����ȴ�.
    �迭�� ����ü�� ������ : 1. ������ �����̴�.
                           2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������� ������ ��.
                           3. 

 */
//_tag : ����ü ���� Ÿ���̴� ��� ���� �����
// �л��� �����ִ� ������ �����س����� ��
// �Ʒ��� ����ü�� �� 52byte�� ��Ƴ��� ���Ե�.
struct _tagStudent{
    char strName[NAME_SIZE];
    int iNumber;
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAVG;
};
int main(){

    _tagStudent tStudent = {};
    //52byte 100���� �Ҵ��
    _tagStudent tStudentArr[100] = {};
     // ����ü ��������� �����ϱ� ���� .�� ����Ѵ�.
    tStudent.iKor = 90;
    tStudent.iEng = 100;
    //tStudent.strName = 
    // ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
    // strcpy �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
    // �� �Լ��� �����ʿ� �ִ� ���ڿ��� �������� ������ �ش�.
    strcpy_s(tStudent.strName,"�����ٶ󸶹ٻ�");
    cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;
    // strcat�Լ��� ���ڿ��� �ٿ��ִ� ����̴�. �����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�.
    strcat(tStudent.strName, " ���ڿ� ���̱�");
    // strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ� �ٸ���� 0�̾ƴ� ���� ��ȯ�Ѵ�.
    if(strcmp(tStudent.strName, "�����ٶ󸶹ٻ� ���ڿ� ���̱�") == 0)
    {
        cout << "�����ϴ�~" << endl;
    }


    /*
    ���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�. �׷��� �����Ⱚ�� ���ִ� ���¿��� �Ʒ�ó��
    �� �迭 ��ҿ� ���� �־��ְ� �Ǹ� �� ���� ��µǰ� �־����� ���� �κ��� �����Ⱚ���� �״�� ��µȴ�.
    �ֳ��ϸ� ����Ҷ� ���ڿ��� ���� �ν��� �� ���� �����̴�.
     */ 
    

    cout << "�̸� : " << tStudent.strName << endl;
    cout << "�й� : " << tStudent.iNumber << endl;
    cout << "���� : " << tStudent.iEng << endl;
    cout << "���� : " << tStudent.iKor << endl;
    cout << "��� : " << tStudent.fAVG << endl;
    cout << "�հ� : " << tStudent.iTotal << endl;

    return 0;
}
