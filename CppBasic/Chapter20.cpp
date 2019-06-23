//Chapter20 더블 링크드리스트1

// 사용자가 만든 헤더파일을 포함시킬때는 ""안에 적어준다.
#include "Chapter20.h"

using namespace std;
/*

 */
enum MAIN_MENU
{
    MM_NONE,
    MM_INSERT,
    MM_DELETE,
    MM_SEARCH,
    MM_OUTPUT,
    MM_EXIT
};

void InitList(PLIST pList)
{
    pList->pBegin = new NODE;
    pList->pEnd = new NODE;
    pList->iSize = 0;

    pList->pBegin->pNext = pList->pEnd;
    pList->pEnd->pPrev = pList->pBegin;

    pList->pBegin->pPrev = NULL;
    pList->pEnd->pNext = NULL;
}
void DestoryList(PLIST pList)
{
    PNODE pNode = pList->pBegin;
    while (pNode != NULL)
    {
        PNODE pNext = pNode->pNext;
        delete pNode;
        pNode = pNext;
    }
    pList->iSize = 0;
    pList->pBegin = NULL;
    pList->pEnd = NULL;
}
int OutputMenu()
{
    system("cls");
    cout << "1. 학생추가" << endl;
    cout << "2. 학생삭제" << endl;
    cout << "3. 학생탐색" << endl;
    cout << "4. 학생출력" << endl;
    cout << "5. 종료" << endl;
    cout << "메뉴를 선택하세요 : ";
    int iInput = InputInt();
    if (iInput < MM_NONE || iInput > MM_EXIT)
        return MM_NONE;

    return iInput;
}

void ClearList(PLIST pList)
{
    PNODE pNode = pList->pBegin;

    while (pNode != NULL)
    {

        delete pNode;
        PNODE pNext = pNode->pNext;
        pNode = pNext;
    }
    pList->pBegin = NULL;
    pList->pEnd = NULL;
    pList->iSize = 0;
}
void Push_Back(PLIST pList)
{
    cin.clear();

    system("cls");
    cout << "==================== 학생 추가 =================" << endl;
    STUDENT tStudent = {};
    cout << "이름 : ";
    InputString(tStudent.strName, NAME_SIZE);
    cout << "학번 : ";
    tStudent.iNumber = InputInt();
    cout << "국어 : ";
    tStudent.iKor = InputInt();
    cout << "영어 : ";
    tStudent.iEng = InputInt();
    cout << "수학 : ";
    tStudent.iMath = InputInt();

    tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
    tStudent.fAvg = tStudent.iTotal / 3.f;

    PNODE pNode = new NODE;
    pNode->tStudent = tStudent;

    // 새로 추가되는 노드는 End 노드의 이전노드와 End 노드사이에 추가해야 한다.
    PNODE pPrev = pList->pEnd->pPrev;
    // pEnd 노드 이전 노드의 다음으로 추가할 노드를 지정한다.
    pPrev->pNext = pNode;
    // 추가할 노드의 이전 노드로 End의 이전 노드를 지정한다.
    pNode->pPrev = pPrev;

    // 새로 추가할 노드의 다음 노드를 pEnd에 연결한다.
    pNode->pNext = pList->pEnd;

    // pEnd 노드의 이전 노드로 새로 추가할 노드를 지정한다.
    pList->pEnd->pPrev = pNode;
    ++pList->iSize;
}
void Output(PLIST pList)
{
    int iMenu;
    while (true)
    {
        system("cls");
        cout << "==================== 학생 출력 =================" << endl;
        cout << "1. 정방향 출력" << endl;
        cout << "2. 역방향 출력" << endl;
        cout << "메뉴를 선택하세요 : ";
        iMenu = InputInt();
        if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
            break;
    }
    PNODE pNode = NULL;
    switch (iMenu)
    {
    case OT_OUTPUT:
        // 추가된은 노드들은 begin과 end사이에 배치된다. 그러므로 begin의 다음노드를 얻어온다.
        pNode = pList->pBegin->pNext;
        // 노드가 End노드와 같아지면 더이상 출력할 노드가 없으므로 반복을 종료한다.
        while (pNode != pList->pEnd)
        {
            OutputStudent(&pNode->tStudent);
            pNode = pNode->pNext;
        }
        break;
    case OT_INVERSE:
        // 역방향으로 출력을 할떄는 end의 이전 노드를 얻어오고 계속 이전노드로 진행한다.
        pNode = pList->pEnd->pPrev;
        // begin과 같아질 경우 반복을 종료한다.
        while (pNode != pList->pBegin)
        {
            OutputStudent(&pNode->tStudent);
            pNode = pNode->pPrev;
        }
        break;
    }
    cout << "학생수 : " << pList->iSize << endl;
    system("pause  ");
}
void Search(PLIST pList)
{
    int iMenu;
    while (true)
    {
        system("cls");
        cout << "==================== 학생 탐색 =================" << endl;
        cout << "1. 정방향 탐색" << endl;
        cout << "2. 역방향 탐색" << endl;
        cout << "메뉴를 선택하세요 : ";
        iMenu = InputInt();
        if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
            break;
    }
    system("cls");
    cout << "==================== 학생 탐색 ================="<< endl;       
    cout << "탐색할 이름을 입력하세요 : "<< endl;    
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);
    PNODE pNode = NULL;
    switch (iMenu)
    {
    case OT_OUTPUT:
        // 추가된은 노드들은 begin과 end사이에 배치된다. 그러므로 begin의 다음노드를 얻어온다.
        pNode = pList->pBegin->pNext;
        // 노드가 End노드와 같아지면 더이상 출력할 노드가 없으므로 반복을 종료한다.
        while (pNode != pList->pEnd)
        {
            if (strcmp(pNode->tStudent.strName, strName) == 0)
            {
                OutputStudent(&pNode->tStudent);
                system("pause");
                return;
            }
            else
            {
                pNode = pNode->pNext;
            }
        }
        cout << "찾으실 학생이 없습니다." << endl;
        system("pause");
        break;
    case OT_INVERSE:
        // 역방향으로 출력을 할떄는 end의 이전 노드를 얻어오고 계속 이전노드로 진행한다.
        pNode = pList->pEnd->pPrev;
        // begin과 같아질 경우 반복을 종료한다.
        while (pNode != pList->pBegin)
        {
            if (strcmp(pNode->tStudent.strName, strName) == 0)
            {
                OutputStudent(&pNode->tStudent);
                system("pause");
                return;
            }
            else
            {
                pNode = pNode->pPrev;
            }
        }
        cout << "찾으실 학생이 없습니다." << endl;
        system("pause");        
        break;
    }

    system("pause  ");
}
void Delete(PLIST pList)
{
    system("cls");
    cout << "==================== 학생 삭제 ================="<< endl;       
    cout << "삭제할 이름을 입력하세요 : "<< endl;    
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);
    
    PNODE pNode = pList->pBegin->pNext;
    while(pNode !=pList->pEnd)
    {
        if(strcmp(pNode->tStudent.strName,strName) == 0)
        {
            //현재 지울 노드의 이전노드의 다음은 현재 지울 노드로 되어있다.
            // 지울 노드는 지워져야 하기 때문에 이전노드의 다음노드를 지울 노드의 다음노드로 준다.
            // 다음 노드의 이전은 현재 노드인데 이전노드로 준다.
           pNode->pPrev->pNext = pNode->pNext;
           pNode->pNext->pPrev = pNode->pPrev;
           delete pNode;
           --pList->iSize;
           cout << strName << " 학생을 삭제하였습니다. " << endl;
           system("pause");
           return;
        }
        pNode = pNode -> pNext; 
    }
    cout << " 학생을 찾을 수 없습니다. " << endl;
    system("pause");
}
int main()
{
    LIST tList;
    InitList(&tList);
    while (true)
    {
        int iMenu = OutputMenu();
        if (iMenu == MM_EXIT)
            break;

        switch (iMenu)
        {
        case MM_INSERT:
            Push_Back(&tList);
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
    DestoryList(&tList);
    return 0;
}