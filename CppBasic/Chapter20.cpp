//Chapter20 ���� ��ũ�帮��Ʈ1

// ����ڰ� ���� ��������� ���Խ�ų���� ""�ȿ� �����ش�.
#include "Chapter20.h"

using namespace std;


enum MAIN_MENU
{
    MM_NONE,
    MM_INSERT,
    MM_DELETE,
    MM_SEARCH,
    MM_OUTPUT,
    MM_EXIT
};


void InitList(PLIST pList){
    pList->pBegin = new NODE;
    pList->pEnd = new NODE;
    pList->iSize = 0;

    pList->pBegin->pNext = pList->pEnd;
    pList->pEnd->pPrev = pList->pBegin;
    
    pList->pBegin->pPrev = NULL;
    pList->pEnd->pPrev = NULL;
}
void DestoryList(PLIST pList){
    PNODE pNode = pList->pBegin;
    while(pNode !=NULL){
        PNODE pNext = pNode ->pNext;
        delete pNode;
        pNode = pNext;
    }
    pList -> iSize = 0;
    pList -> pBegin = NULL;
    pList -> pEnd = NULL; 
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


void ClearList(PLIST pList){
    PNODE pNode = pList -> pBegin;

    while(pNode !=NULL){
        
        delete pNode;
        PNODE pNext = pNode -> pNext;
        pNode = pNext;
    }
    pList -> pBegin = NULL;
    pList -> pEnd = NULL;
    pList -> iSize = 0;

}
void Push_Back(PLIST pList)
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


    PNODE pNode = new NODE;
    pNode -> tStudent = tStudent;

    // ���� �߰��Ǵ� ���� End ����� �������� End �����̿� �߰��ؾ� �Ѵ�.
    PNODE pPrev = pList->pEnd->pPrev;
    // pEnd ��� ���� ����� �������� �߰��� ��带 �����Ѵ�.
    pPrev->pNext = pNode;
    // �߰��� ����� ���� ���� End�� ���� ��带 �����Ѵ�.
    pNode->pPrev = pPrev;

    // ���� �߰��� ����� ���� ��带 pEnd�� �����Ѵ�.
    pNode->pNext = pList->pBegin;

    // pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�.
    pList -> pEnd -> pPrev = pNode;
    ++pList->iSize;


        
}
void Output(PLIST pList){
    system("cls");
    cout << "==================== �л� ��� ================="<< endl;    
    cout << "1. ������ ���"<< endl;    
    cout << "2. ������ ���"<< endl;    
    cout << "�޴��� �����ϼ��� : ";
    int iMenu = InputInt();
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
                Push_Back(&tList);
                break;
            case MM_DELETE:
                //Delete(&tList);
                break;
            case MM_SEARCH:
                //Search(&tList);
                break;
            case MM_OUTPUT:
                //Output(&tList);
                break;

        }
    }    
    return 0;
}