// 코드업 기초 100제 -  [기초-논리연산] 참/거짓이 서로 다를 때에만 참 출력하기
/*
문제 : 
두 가지의 참(1) 또는 거짓(0)이 입력될 때,

참/거짓이 서로 다를 때에만 참이 계산되는 프로그램을 작성해보자.

이러한 논리 연산을 XOR(exclusive or, 배타적 논리합)연산이라고도 부른다.

집합의 의미로는 합집합에서 교집합을 뺀 것을 의미한다. 모두 같은 의미이다.

입력
1 또는 0의 값만 가지는 2개의 정수가 공백을 두고 입력된다.

출력
참/거짓이 서로 다를 때에만 1을 출력하고 이외의 경우에는 0을 출력한다.

입력 예시   
1 1

출력 예시
0
 */ 
 
#include<stdio.h>

int main(){
    int ia,ib;
    
    scanf("%d %d", &ia, &ib);
    printf("%d\n", ia^ib);
    
    return 0;
}
