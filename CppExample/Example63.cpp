// 코드업 기초 100제 -[기초-조건/선택실행구조] 정수 세 개 입력받아 짝/홀 출력하기
/*
문제 : 
세 정수 a, b, c가 입력되었을 때,

짝 even(짝)/odd(홀)을 출력해보자.

입력
세 정수 a, b, c 가 공백을 두고 입력된다.
(0 ~ 2147483647)

출력
순서대로 even(짝)/odd(홀)을 줄을 바꿔 출력한다.

입력 예시   
1 2 8

출력 예시
odd
even
even
 

 */ 
 
#include<stdio.h>



int main(){
    
    int ia,ib,ic;
    scanf("%d %d %d", &ia,&ib,&ic);
    if(ia%2 == 0)
        printf("even\n",ia);
    else
        printf("odd\n",ia);
    if(ib%2 == 0)
        printf("even\n",ia);
    else
        printf("odd\n",ia);
    if(ic%2 == 0)
        printf("even\n",ia);
    else
        printf("odd\n",ia);
    return 0;
}
