// 코드업 기초 100제 - [기초-입출력] 문자 두 개 입력받아 순서 바꿔 출력하기
/*
문제 : 
두 개의 문자를 입력받은 후 순서를 바꿔 출력해보자.

입력
두 개의 문자가 공백으로 구분되어 입력된다.

출력
입력한 두 문자의 순서를 바꿔 출력한다.

입력 예시   
A b

출력 예시
b A
 */

#include<stdio.h>


using namespace std;


int main()
{
    char cx,cy;
    scanf("%c %c", &cx, &cy);
    printf("%c %c", cy, cx);
    
    return 0;
};
