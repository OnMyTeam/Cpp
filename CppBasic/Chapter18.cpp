//Chapter18 �̱� ��ũ�帮��Ʈ 1 �����̷�

#include <iostream>

using namespace std;
/*
    ��ũ�� ����Ʈ : �ڷᱸ���� �� �����̴�. �ڷᱸ���� �����͸� �����ϴ� ���.
                   ��ũ�帮��Ʈ�� ������ ����� ������Ѽ� ������ �� �ִ� ������ �����Ѵ�.
                   ��ũ�帮��Ʈ�� �����͸� �����ϱ� ���� ����� ���� �����Ѵ�. �� ����� Ư¡��
                   ���� ��带 �� �� �ְ� �ȴ�.(���� ����� �޸� �ּҸ� �����Ѵٴ� �ǹ�)

    ����Ʈ vs �迭 : ����Ʈ�� ���������� �Ǿ��ִ�. �׷��� ������ �迭ó�� Ư�� ��ҿ� �ٷ� ������ �Ұ����ϴ�.
                    ������ �տ��� ���� ���ʴ�� Ÿ�� ���� �Ѵ�.
                    ��带 ���� �߰� �Ҷ��� ��带 �����ϰ� ������ ��忡 ���Ḹ ���ָ� �Ǽ� ������ ������ ����

 */
#define NAME_SIZE 32
#define STUDENT_MAX 10

enum MAIN_MENU
{
    MM_NONE,
    MM_INSERT,
    MM_DELETE,
    MM_SEARCH,
    MM_OUTPUT,
    MM_EXIT
};
typedef struct _tagStudent
{
    char strName[NAME_SIZE];
    int iNumber;
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
}STUDENT, *PSTUDENT;

// ����Ʈ ��带 ������.
typedef struct _tagNode
{
    STUDENT tStudent;
    _tagNode* pNext;

}NODE, *PNODE;

// ����Ʈ ����ü�� ������ش�.
typedef struct _tagList
{
    PNODE pBegin;
    PNODE pEnd;
    int iSize;
}LIST, *PLIST;

void InitList(PLIST pList)
{
    // �����ʹ� �������̸� �ʱ�ȭ�Ҷ� NULL(0)���� �ʱ�ȭ �صΰ� ���� ���� ����.
    // �ֳĸ� 0�� false 0�� �ƴ� ��� ���� true�̱� �����̴�.
    // �ʱ�ȭ ���� ���� ��� �����Ⱚ�� ���ִµ� �� �����Ⱚ ���� true dlek.
    pList -> pBegin = NULL;
    pList -> pEnd = NULL;
    pList -> iSize = 0;
}
int InputInt()
{
    int iInput;
    cin >> iInput;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1024,'\n');
        return INT16_MAX;

    }
    return iInput;
}
int OutputMenu()
{
    system("cls");
    cout << "1. �л��߰�" << endl;
    cout << "2. �л�����" << endl;
    cout << "3. �л�Ž��" << endl;
    cout << "4. �л����" << endl;
    cout << "5. ����" << endl;
    cout << "�޴��� �����ϼ��� : " ;
    int iInput = InputInt();
    if(iInput < MM_NONE || iInput > MM_EXIT)
        return MM_NONE;
    
    return iInput;

}

int main(){

    LIST tList;
    InitList(&tList);
    while(true){
        int iMenu = OutputMenu();
        if(iMenu == MM_EXIT)
            break;
        
        switch(iMenu)
        {
            case MM_INSERT:
                break;
            case MM_DELETE:
                break;
            case MM_OUTPUT:
                break;

        }
    }
    return 0;
}