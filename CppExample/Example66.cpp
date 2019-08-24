// 코드업 기초 100제 - [기초-조건/선택실행구조] 정수 한 개 입력받아 평가 출력하기
/*
문제 : 
영문자 1개가 입력된다.
(A, B, C, D 등의 한 문자가 입력된다.) 


출력
평가내용에 따라 다른 내용이 출력된다. 

평가 : 내용
A : best!!!
B : good!!
C : run!
D : slowly~
나머지 문자들 : what?


입력 예시   
A

출력 예시
best!!!

 */ 
 
#include<stdio.h>



int main(){
    
    char ca;
    scanf("%c", &ca);

    switch(ca)
    {
        case 'A':
        printf("best!!!");
        break;
        case 'B':
        printf("good!!");
        break;
        case 'C':
        printf("run!");
        break;
        case 'D':
        printf("slowly~");
        break;
        default:
        printf("what?");
    }

    return 0;
}
