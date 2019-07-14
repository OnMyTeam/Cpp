// 코드업 기초 100제 - [기초-입출력] 실수 한 개 입력받아 소수점 이하 둘쨰 자리까지 출력하기
/*
문제 : 
실수(float) 한 개를 입력받아 소수점 이하 3째 자리에서 반올림 하여 2째 자리까지 출력하시오.

입력
실수 한 개가 입력된다.

출력
입력한 실수를 소수점 이하 3째 자리에서 반올림 하여 2째 자리까지 출력한다.

입력 예시   
1.59254

출력 예시
1.59
 */

#include<stdio.h>
#include<cmath>


using namespace std;


int main()
{
    float fX;
    scanf("%f", &fX);
    printf("%.2f",round(fX * 100) / 100);
    
    return 0;
};
