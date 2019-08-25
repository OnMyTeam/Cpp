// 코드업 기초 100제 -   [기초-종합] 짝수 합 구하기
/*
문제 설명    
'q'가 입력될 때까지 입력한 문자를 계속 출력하는 프로그램을 작성해보자. 


입력
문자들이 1개씩 계속해서 입력된다. 


출력
'q'가 입력될 때까지 입력된 문자를 줄을 바꿔 한 줄씩 출력한다. 


입력 예시   
x b k d l q g a c

출력 예시
x
b
k
d
l
q
 */ 
 
#include<stdio.h>



int main(){
    
    char ca;
    

    repeat:
        scanf("%c",&ca);
        printf("%c",ca);
        if(ca!='q')    
            goto repeat;
    
    return 0;
}
