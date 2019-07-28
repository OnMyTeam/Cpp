// 코드업 기초 100제 - [기초-출력변환] 10진 정수 한 개 입력받아 16진수로 출력하기1
/*
문제 : 
10진수를 입력받아 16진수(hexadecimal)로 출력하는 프로그램을 작성해보자.

입력
10진수 1개가 입력된다.

출력
입력 받은 10진수를 16진수로 바꾸어 출력한다.

입력 예시   
255

출력 예시
ff
 */ 

#include<stdio.h>

int main(){
    int iNumber;
    scanf("%d",&iNumber);
    printf("%x",iNumber);

    return 0;
}