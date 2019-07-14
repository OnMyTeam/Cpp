// 코드업 기초 100제 - [기초-입출력] 정수 두개 입력받아 출력하기
/*
문제 : 
키보드로 입력한 실수(소수점이 있는 수)를 그대로 출력하는 프로그램을 작성해보자.

입력
두 개의 정수가 공백으로 구분되어 입력된다.

출력
입력받은 두 정수를 공백으로 구분하여 그대로 출력한다.

입력 예시   
1 2

출력 예시
1 2
 */

#include<stdio.h>


using namespace std;


int main()
{
    int ix,iy;
    scanf("%d %d", &ix,&iy);
    printf("%d %d", ix,iy);
    
    return 0;
};
