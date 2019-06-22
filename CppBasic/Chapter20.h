// #pragama once : 이 헤더파일을 딱 1번만 포함시키겠다 라는 의미임.

#pragma once
#include <iostream>
#include <string.h>
using namespace std;
// 헤더파일에는 보통 함수 선언부분을 만들어준다.

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

// 리스트 노드를 만들자.
typedef struct _tagNode
{
    STUDENT     tStudent;
    _tagNode*   pPrev;
    _tagNode*   pNext;

}NODE, *PNODE;

// 리스트 구조체를 만들어준다.
typedef struct _tagList
{
    // pBegin과 pEnd는 명시적으로 처음과 끝을 의미하도록 만든다. 실제 데이터를 저장하는 노드는 아님.
    // 실제 데이터를 저장하는 노드는 pBegin과 pEnd 사이에 존재하기 만들거임
    PNODE pBegin;
    PNODE pEnd;
    int iSize;
}LIST, *PLIST;

void OutputStudent(const PSTUDENT pStudent)
{
    cout << "학생 : " << pStudent->strName << " 학번 : " << pStudent->iNumber << endl;
    cout << "영어 : " << pStudent->iEng << " 수학 : " << pStudent->iMath << endl;
    cout << "국어 : " << pStudent->iKor << endl; 
    cout << "총합 : " << pStudent->iTotal << " 평균 : " << pStudent->fAvg << endl;

}

void InitList(PLIST pList);
void DestoryList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void OutputStudent(PLIST pList);
void Output(PLIST pList);