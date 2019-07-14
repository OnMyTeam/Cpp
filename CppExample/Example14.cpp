// 코드업 기초 100제 - [기초-입출력] 정수 한 개 입력받아 세 번 출력하기
/*
문제 : 
정수(integer) 한 개를 입력받아 3번 출력해보자.

입력
정수 한 개가 입력된다.

출력
입력받은 정수를 공백으로 구분해 세 번 출력한다.

입력 예시   
125

출력 예시
125 125 125
 */ 

#include<stdio.h>
#include<cmath>


int main()
{
    int iX;
    scanf("%d", &iX);
    printf("%d %d %d",iX, iX, iX);
    
    return 0;
};
