// 코드업 기초 100제 - [기초-비교연산] 두 정수 입력받아 비교하기1
/*
문제 : 
두 정수(a, b)를 입력받아 

a가 b보다 크면 1,

a가 b와 같거나 b가 a보다 크다면 0

을 출력하는 프로그램을 작성해보자.

입력
두 정수 a, b가 공백을 두고 입력된다.
(-2147483648 ~ 2147483647)

출력
a가 b보다 큰 경우 1을, 그렇지 않은 경우 0을 출력한다.

입력 예시   
9 1

출력 예시
1
 */ 
 
#include<stdio.h>

int main(){
    int ia,ib;
    
    scanf("%d %d",&ia,&ib);
    printf("%d\n",ia > ib);
    return 0;
}