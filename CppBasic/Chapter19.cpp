//Chapter18 �̱� ��ũ�帮��Ʈ 1 �����̷�

#include <iostream>
#include <string.h>
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
void InputString(char* pString, int iSize)
{
    cin.clear();
    cin.ignore(1024, '\n');
    cin.getline(pString, iSize - 1);
     
}
void Insert(PLIST pList)
{
    cin.clear();

    system("cls");
    cout << "==================== �л� �߰� ================="<< endl;
    STUDENT tStudent = {};
    cout << "�̸� : ";
    InputString(tStudent.strName, NAME_SIZE);
    cout << "�й� : ";
    tStudent.iNumber = InputInt();
    cout << "���� : ";
    tStudent.iKor = InputInt();
    cout << "���� : ";
    tStudent.iEng = InputInt();
    cout << "���� : ";
    tStudent.iMath = InputInt();    

    tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
    tStudent.fAvg = tStudent.iTotal/3.f;

    //�߰��� ����Ʈ ��带 ��������!
    // NODE �����ŭ ������ �Ҵ�ǰ� �� �޸� �ּҸ� pNode�� ������ �ȴ�.
    PNODE pNode = new NODE;
    // ���� �̳��� �������ڸ��� ���� �������� �߰��Ǳ� ������ ���� ��尡 �������� ����.
    pNode -> pNext = NULL;
    pNode ->tStudent = tStudent;
    if(pList ->pBegin == NULL)
        pList -> pBegin = pNode;
    else
        pList -> pEnd -> pNext = pNode;
    
    pList -> pEnd = pNode;
    ++pList -> iSize;

        
}
void ClearList(PLIST pList){
    PNODE pNode = pList -> pBegin;

    while(pNode !=NULL){
        PNODE pNext = pNode -> pNext;
        delete pNode;
        pNode = pNext;
    }
    pList -> pBegin = NULL;
    pList -> pEnd = NULL;
    pList -> iSize = 0;

}
// const �������̱� ������ ����Ű�� ����� ���� ������ �� ����.
void OutputStudent(const PSTUDENT pStudent)
{
    cout << "�л� : " << pStudent->strName << " �й� : " << pStudent->iNumber << endl;
    cout << "���� : " << pStudent->iEng << " ���� : " << pStudent->iMath << endl;
    cout << "���� : " << pStudent->iKor << endl; 
    cout << "���� : " << pStudent->iTotal << " ��� : " << pStudent->fAvg << endl;

}
void Output(PLIST pList)
{
    system("cls");
    cout << "==================== �л� ��� ================="<< endl;    
    PNODE pNode = pList -> pBegin;
    while(pNode != NULL)
    {
        OutputStudent(&pNode->tStudent);        
        pNode = pNode -> pNext;
    }
    cout << "�л��� : " << pList -> iSize << endl;
    system("pause");
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
void Search(PLIST pList)
{
    system("cls");
    cout << "==================== �л� Ž�� ================="<< endl;       
    cout << "Ž���� �̸��� �Է��ϼ��� : "<< endl;
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);
    PNODE pNode = pList -> pBegin;
    while(pNode != NULL)
    {
        if(strcmp(pNode ->tStudent.strName,strName) == 0){
            OutputStudent(&pNode ->tStudent);
            system("pause");
            return;
        }
    }    
    cout << "ã���� �л��� �����ϴ�." << endl;
    system("pause");
}
void Delete(PLIST pList){
    system("cls");
    cout << "==================== �л� ���� ================="<< endl;       
    cout << "������ �̸��� �Է��ϼ��� : "<< endl;
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);
    PNODE pNode = pList -> pBegin;
    PNODE pPrev = NULL;
    while(pNode != NULL)
    {
        if(strcmp(pNode ->tStudent.strName,strName) == 0){
            // ���� ����� ���� ��带 ���´�.
            PNODE pNext = pNode -> pNext;

            if(pPrev == NULL){
                delete pNode;
                pList -> pBegin = pNext;
                if(pNext == NULL)
                    pList -> pEnd = NULL;
            }
            else{
                delete pNode;
                pPrev->pNext = pNext;
                if(pNext == NULL){
                    pList ->pEnd = pPrev;
                }
            }
            cout << strName << "�л� �����Ϸ�!." << endl;
            --pList -> iSize;
            system("pause");
            return;
        }
    }    
    cout << "ã���� �л��� �����ϴ�." << endl;
    system("pause");
    return;
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
                Insert(&tList);
                break;
            case MM_DELETE:
                Delete(&tList);
                break;
            case MM_SEARCH:
                Search(&tList);
                break;
            case MM_OUTPUT:
                Output(&tList);
                break;

        }
    }
    return 0;
}