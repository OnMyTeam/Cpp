// 코드업 기초 100제 - [기초-입출력] 문자 한 개 입력받아 그대로 출력하기
/*
문제 : 
키보드로 입력한 문자를 그대로 출력하는 프로그램을 작성해보자.

입력
문자 한 개가 입력된다.
 
출력
입력된 문자를 그대로 출력한다.


 */

#include<stdio.h>


using namespace std;


int main()
{
    char cInputChar;
    scanf("%s", &cInputChar);
    printf("%c", cInputChar);
    
    return 0;
};
