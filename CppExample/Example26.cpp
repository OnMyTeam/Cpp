// 코드업 기초 100제 - [기초-데이터형] 실수 한 개 입력받아 그대로 출력하기2
/*
문제 : 
실수 한 개를 입력받아 그대로 출력해보자.
(단, 입력되는 실수의 범위는 +- 1.7*10^-308 ~ 1.7*10^308 이다.)

입력
소수점 이하 자리수가 11개 이하인 실수 한 개가 입력된다.
(단, 입력되는 실수의 범위는 +- 1.7*10^-308 ~ 1.7*10^308 이다.)

출력
입력된 실수를 소수점 이하 11번째 자리까지 출력한다.

입력 예시   
3.14159265359

출력 예시
3.14159265359
 */ 

#include<stdio.h>

int main(){
    double dNumber;
    scanf("%lf",&dNumber);
    printf("%.11lf",dNumber);

    return 0;
}