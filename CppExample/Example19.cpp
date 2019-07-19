// 코드업 기초 100제 - [기초-입출력] 문장 한 개 입력받아 그대로 출력하기
/*
문제 : 
한 개의 문장을 입력받아 그대로 출력하는 프로그램을 작성해보자.

입력
한 개의 문장이 입력된다.
(문장은 여러 개의 단어로 구성될 수 있고 문장의 입력은 엔터키로 끝나며, 문장의 길이는 공백을 포함하여 2000글자를 넘지 않는다.)

출력
입력한 문장을 그대로 출력한다.

입력 예시   
C++ programming is very fun!!

출력 예시
C++ programming is very fun!!
 */ 

#include<stdio.h>

int main(){
    char a[2001];
    
    fgets(a,2001,stdin);
    printf("%s",a);

    return 0;
}