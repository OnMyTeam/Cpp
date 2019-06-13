//Chapter12 구조체와 문자열 함수	

 #include <iostream>	
#include <string.h>	

 using namespace std;	
#define NAME_SIZE 32	
/*	
    구조체 : 관련있는 변수를 모아 하나의 새로운 타입을 만들어주는 기능. 사용자 정의 변수 타입이다.	
    형태 : struct 구조체명 {}; 의 형태로 구성된다.	
    배열과 구조체의 공통점 : 1. 데이터 집합이다.	
                           2. 연속된 메모리 블럭에 할당된다. 구조체 멤버들은 연속된 메모리 블록으로 잡히게 됨.	
                           3. 	
  */	
//_tag : 구조체 변수 타입이다 라는 것을 명시함	
// 학생과 관련있는 변수를 선언해놓으면 됨	
// 아래의 구조체는 총 52byte를 잡아놓고 쓰게됨.	
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
    //52byte 100개가 할당됨	
    _tagStudent tStudentArr[100] = {};	
     // 구조체 멤버변수에 접근하기 위해 .을 사용한다.	
    tStudent.iKor = 90;	
    tStudent.iEng = 100;	
    //tStudent.strName = 	
    // 문자열을 배열에 넣어줄 때에는 단순 대입으로는 불가능하다.	
    // strcpy 함수를 이용해서 문자열을 복사해 주어야 한다.	
    // 이 함수는 오른쪽에 있는 문자열을 왼족으로 복사해 준다.	
    strcpy_s(tStudent.strName,"가나다라마바사");	
    cout << "이름 길이 : " << strlen(tStudent.strName) << endl;	
    // strcat함수는 문자열을 붙여주는 기능이다. 오른쪽에 있는 문자열을 왼쪽에 붙여준다.	
    strcat(tStudent.strName, " 문자열 붙이기");	
    // strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환하고 다를경우 0이아닌 값을 반환한다.	
    if(strcmp(tStudent.strName, "가나다라마바사 문자열 붙이기") == 0)	
    {	
        cout << "같습니다~" << endl;	
    }	


     /*	
    문자열의 끝은 항상 0(NULL)로 끝나야 한다. 그런데 쓰레기값이 들어가있는 상태에서 아래처럼	
    각 배열 요소에 값을 넣어주게 되면 그 값이 출력되고 넣어주지 않은 부분은 쓰레기값으로 그대로 출력된다.	
    왜냐하면 출력할때 문자열의 끝을 인식할 수 없기 ??문이다.	
     */ 	


     cout << "이름 : " << tStudent.strName << endl;	
    cout << "학번 : " << tStudent.iNumber << endl;	
    cout << "영어 : " << tStudent.iEng << endl;	
    cout << "국어 : " << tStudent.iKor << endl;	
    cout << "평균 : " << tStudent.fAVG << endl;	
    cout << "합계 : " << tStudent.iTotal << endl;	

     return 0;	
}