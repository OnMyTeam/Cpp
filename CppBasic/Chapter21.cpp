//Chapter21 ���� ��ũ�帮��Ʈ ����

// ����ڰ� ���� ��������� ���Խ�ų���� ""�ȿ� �����ش�.
#include "Chapter20.h"

using namespace std;

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
    cout << "1. �л��߰�" << endl;
    cout << "2. �л�����" << endl;
    cout << "3. �л�Ž��" << endl;
    cout << "4. �л����" << endl;
    cout << "5. �л�����" << endl;
    cout << "6. ����" << endl;
    cout << "�޴��� �����ϼ��� : ";
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
    cout << "==================== �л� �߰� =================" << endl;
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
    tStudent.fAvg = tStudent.iTotal / 3.f;

    PNODE pNode = new NODE;
    pNode->tStudent = tStudent;

    // ���� �߰��Ǵ� ���� End ����� �������� End �����̿� �߰��ؾ� �Ѵ�.
    PNODE pPrev = pList->pEnd->pPrev;
    // pEnd ��� ���� ����� �������� �߰��� ��带 �����Ѵ�.
    pPrev->pNext = pNode;
    // �߰��� ����� ���� ���� End�� ���� ��带 �����Ѵ�.
    pNode->pPrev = pPrev;

    // ���� �߰��� ����� ���� ��带 pEnd�� �����Ѵ�.
    pNode->pNext = pList->pEnd;

    // pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�.
    pList->pEnd->pPrev = pNode;
    ++pList->iSize;
}
void Output(PLIST pList)
{
    int iMenu;
    while (true)
    {
        system("cls");
        cout << "==================== �л� ��� =================" << endl;
        cout << "1. ������ ���" << endl;
        cout << "2. ������ ���" << endl;
        cout << "�޴��� �����ϼ��� : ";
        iMenu = InputInt();
        if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
            break;
    }
    PNODE pNode = NULL;
    switch (iMenu)
    {
    case OT_OUTPUT:
        // �߰����� ������ begin�� end���̿� ��ġ�ȴ�. �׷��Ƿ� begin�� ������带 ���´�.
        pNode = pList->pBegin->pNext;
        // ��尡 End���� �������� ���̻� ����� ��尡 �����Ƿ� �ݺ��� �����Ѵ�.
        while (pNode != pList->pEnd)
        {
            OutputStudent(&pNode->tStudent);
            pNode = pNode->pNext;
        }
        break;
    case OT_INVERSE:
        // ���������� ����� �ҋ��� end�� ���� ��带 ������ ��� �������� �����Ѵ�.
        pNode = pList->pEnd->pPrev;
        // begin�� ������ ��� �ݺ��� �����Ѵ�.
        while (pNode != pList->pBegin)
        {
            OutputStudent(&pNode->tStudent);
            pNode = pNode->pPrev;
        }
        break;
    }
    cout << "�л��� : " << pList->iSize << endl;
    system("pause  ");
}
void Search(PLIST pList)
{
    int iMenu;
    while (true)
    {
        system("cls");
        cout << "==================== �л� Ž�� =================" << endl;
        cout << "1. ������ Ž��" << endl;
        cout << "2. ������ Ž��" << endl;
        cout << "�޴��� �����ϼ��� : ";
        iMenu = InputInt();
        if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
            break;
    }
    system("cls");
    cout << "==================== �л� Ž�� =================" << endl;
    cout << "Ž���� �̸��� �Է��ϼ��� : " << endl;
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);
    PNODE pNode = NULL;
    switch (iMenu)
    {
    case OT_OUTPUT:
        // �߰����� ������ begin�� end���̿� ��ġ�ȴ�. �׷��Ƿ� begin�� ������带 ���´�.
        pNode = pList->pBegin->pNext;
        // ��尡 End���� �������� ���̻� ����� ��尡 �����Ƿ� �ݺ��� �����Ѵ�.
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
        cout << "ã���� �л��� �����ϴ�." << endl;
        system("pause");
        break;
    case OT_INVERSE:
        // ���������� ����� �ҋ��� end�� ���� ��带 ������ ��� �������� �����Ѵ�.
        pNode = pList->pEnd->pPrev;
        // begin�� ������ ��� �ݺ��� �����Ѵ�.
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
        cout << "ã���� �л��� �����ϴ�." << endl;
        system("pause");
        break;
    }

    system("pause  ");
}
void Delete(PLIST pList)
{
    system("cls");
    cout << "==================== �л� ���� =================" << endl;
    cout << "������ �̸��� �Է��ϼ��� : " << endl;
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);

    PNODE pNode = pList->pBegin->pNext;
    while (pNode != pList->pEnd)
    {
        if (strcmp(pNode->tStudent.strName, strName) == 0)
        {
            //���� ���� ����� ��������� ������ ���� ���� ���� �Ǿ��ִ�.
            // ���� ���� �������� �ϱ� ������ ��������� ������带 ���� ����� �������� �ش�.
            // ���� ����� ������ ���� ����ε� �������� �ش�.
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
            delete pNode;
            --pList->iSize;
            cout << strName << " �л��� �����Ͽ����ϴ�. " << endl;
            system("pause");
            return;
        }
        pNode = pNode->pNext;
    }
    cout << " �л��� ã�� �� �����ϴ�. " << endl;
    system("pause");
}
void Sort(PLIST pList)
{
    

    system("cls");
    cout << "==================== �л� ���� =================" << endl;
    cout << "1. �й����� " << endl;
    cout << "2. ��ձ��� " << endl;
    cout << "�޴��� �����ϼ��� : ";
    int iMenu = InputInt();
    if (iMenu <= ST_NONE || iMenu > ST_AVG)
    {
        cout << "�߸� �����ϼ̽��ϴ�. " << endl;
        system("pause");
        return;
    }
    cout << endl;
    cout << "1. �������� " << endl;
    cout << "2. �������� " << endl;
    cout << "�޴��� �����ϼ��� : ";
    int iOption = InputInt();    
    if (iOption <= SO_NONE || iOption > SO_DSCRIVE)
    {
        cout << "�߸� �����ϼ̽��ϴ�. " << endl;
        system("pause");
        return;
    }    
    PNODE pFirst = pList->pBegin->pNext;
    PNODE pSecond = NULL;
    // First�� End�� ���� ���� �������� �Ǹ� ���̻� ���� ��尡 �����Ƿ� �����Ѵ�.
    while (pFirst != pList->pEnd->pPrev)
    {
        // Second�� End ���� ���� �ݺ��ؾ� �ϹǷ� End�� �ƴҵ��ȸ� �ݺ��Ѵ�.
        pSecond = pFirst->pNext;
        while (pSecond != pList->pEnd)
        {
            bool bSwap = false;
            switch (iMenu)
            {
            case ST_NUMBER:
                switch(iOption)
                {
                    case SO_CRIVE:
                        if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber)
                            bSwap = true;
                        break;
                    case SO_DSCRIVE:
                        if (pFirst->tStudent.iNumber < pSecond->tStudent.iNumber)
                            bSwap = true;
                        break;                    
                }
                break;

            case ST_AVG:
                switch(iOption)
                {
                    case SO_CRIVE:
                        if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg)
                            bSwap = true;
                        break;
                    case SO_DSCRIVE:
                        if (pFirst->tStudent.fAvg < pSecond->tStudent.fAvg)
                            bSwap = true;
                        break;                    
                }
                break;
            }
            if (bSwap)
            {
                // Fisrt����� ������ ������带 �����Ѵ�.
                PNODE pFirstPrev = pFirst->pPrev;
                PNODE pFirstNext = pFirst->pNext;
                // Second ����� ������ ������带 �����Ѵ�.
                PNODE pSecondPrev = pSecond->pPrev;
                PNODE pSecondNext = pSecond->pNext;



                //���� �� ��尡 ���� �ٲ����Ƿ� ����Ǿ� �ִ� pNext�� pPrev�� �ٲ��־�� �Ѵ�.
                // �׷��� pFirstPrev ����� �������� �ٲ� pFirst�� �����ϰ� �ٲ� pFirst�� �������� pFirstPrev��带 �������ش�.
                // ���� ���鵵 ���������� ��ü�� �־�� �Ѵ�.
                pFirstPrev->pNext = pSecond;
                pSecond->pPrev = pFirstPrev;

                // �ٲٷ��� �� ��尡 �پ� ���� �������
                if (pSecond != pFirstNext)
                {
                    pFirstNext->pPrev = pSecond;
                    pFirst->pNext = pFirstNext;
                    pSecondPrev->pNext = pSecond;
                    pFirst->pPrev = pSecondPrev;
                }
                // ��尡 �پ� �ִٸ�
                else
                {
                    pSecond ->pNext = pFirst;
                    pFirst ->pPrev = pSecond;   
                }
                
                pSecondNext->pPrev = pFirst;
                pFirst->pNext = pSecondNext;
                // �� ��带 �ٲ��ش�.
                PNODE pTemp = pFirst;
                pFirst = pSecond;
                pSecond = pTemp;                
            }
            pSecond = pSecond->pNext;
        }
        pFirst = pFirst->pNext;
    }

    cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
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

        case MM_SORT:
            Sort(&tList);
            break;
        }
    }
    DestoryList(&tList);
    return 0;
}