// 코드업 기초 100제 -   [기초-비트단위논리연산] 비트단위로 and 하여 출력하기
/*
문제 : 
입력 된 정수 두 개를 비트단위로 and 연산한 후 그 결과를 정수로 출력해보자.

입력
두 개의 정수가 공백을 두고 입력된다.
(-2147483648 ~ 2147483647)

출력
두 정수를 비트단위로 and 계산을 수행한 결과가 10진수로 출력된다.

입력 예시   
3 5

출력 예시
1


 */ 
 
#include<stdio.h>

int main(){
    
    int ia,ib;
    scanf("%d %d", &ia,&ib);
    printf("%d\n",(ia&ib));
    return 0;
}