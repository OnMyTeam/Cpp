// #pragama once : �� ��������� �� 1���� ���Խ�Ű�ڴ� ��� �ǹ���.

#pragma once
#include <iostream>
#include <string.h>
using namespace std;
// ������Ͽ��� ���� �Լ� ����κ��� ������ش�.

#define NAME_SIZE 32
#define STUDENT_MAX 10

enum OUTPUT_TYPE{
    OT_NONE,
    OT_OUTPUT,
    OT_INVERSE
};
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
    STUDENT     tStudent;
    _tagNode*   pPrev;
    _tagNode*   pNext;

}NODE, *PNODE;

// ����Ʈ ����ü�� ������ش�.
typedef struct _tagList
{
    // pBegin�� pEnd�� ��������� ó���� ���� �ǹ��ϵ��� �����. ���� �����͸� �����ϴ� ���� �ƴ�.
    // ���� �����͸� �����ϴ� ���� pBegin�� pEnd ���̿� �����ϱ� �������
    PNODE pBegin;
    PNODE pEnd;
    int iSize;
}LIST, *PLIST;

void OutputStudent(const PSTUDENT pStudent)
{
    cout << "�л� : " << pStudent->strName << " �й� : " << pStudent->iNumber << endl;
    cout << "���� : " << pStudent->iEng << " ���� : " << pStudent->iMath << endl;
    cout << "���� : " << pStudent->iKor << endl; 
    cout << "���� : " << pStudent->iTotal << " ��� : " << pStudent->fAvg << endl;

}

void InitList(PLIST pList);
void DestoryList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void OutputStudent(PLIST pList);
void Output(PLIST pList);