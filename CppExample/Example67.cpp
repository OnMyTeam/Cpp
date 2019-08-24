// 코드업 기초 100제 - [기초-조건/선택실행구조] 월 입력받아 계절 출력하기(설명)
/*
문제 : 
월을 의미하는 1개의 정수가 입력된다.(1 ~ 12) 


출력
계절 이름을 출력한다. 

월 : 계절 이름
12, 1, 2 : winter
  3, 4, 5 : spring
  6, 7, 8 : summer
  9, 10, 11 : fall



입력 예시   
12

출력 예시
winter

 */ 
 
#include<stdio.h>



int main(){
    
    int ia;
    scanf("%d", &ia);

    switch(ia)
    {
        case 12:
        case 1:
        case 2:
        printf("winter");
        break;
        case 3:
        case 4:
        case 5:
        printf("spring");
        break;
        case 6:
        case 7:
        case 8:
        printf("summer");
        break;
        case 9:
        case 10:
        case 11:
        printf("fall");
        break;        
    }

    return 0;
}
