// 코드업 기초 100제 - [기초-입출력] 실수 한 개 입력받아 그대로 출력하기
/*
문제 : 
키보드로 입력한 실수(소수점이 있는 수)를 그대로 출력하는 프로그램을 작성해보자.

입력
소숫점이하가 6자리인 실수 한 개가 입력된다.

출력
입력된 실수를 그대로 출력한다. 


 */

#include<stdio.h>


using namespace std;


int main()
{
    float fInputFloat;
    scanf("%f", &fInputFloat);
    printf("%f", fInputFloat);
    
    return 0;
};
