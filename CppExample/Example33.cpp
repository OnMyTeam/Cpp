// 코드업 기초 100제 - [기초-출력변환] 영문자 한 개 입력받아 10진수로 출력하기
/*
문제 : 
영문자 한 개를 입력받아 아스키코드 10진수값으로 출력하는 프로그램을 작성해보자.

입력
영문자 한 개가 입력된다.

출력
입력 받은 문자에 해당되는 아스키코드값을 10진수로 출력한다.

입력 예시   
A

출력 예시
65
 */ 

#include<stdio.h>

int main(){
    char cCharacter;
    scanf("%c",&cCharacter);
    printf("%d",cCharacter);

    return 0;
}
