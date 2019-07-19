// 코드업 기초 100제 -[기초-입출력] 단어 한 개 입력받아 그대로 출력하기
/*
문제 : 
하나의 단어를 입력받아 그대로 출력해보자.

입력
한 단어가 입력된다.
(단, 단어의 길이는 50글자 이하이다.)

출력
입력받은 단어를 그대로 출력한다.

입력 예시   
Informatics

출력 예시
Informatics
 */ 

#include<stdio.h>

int main(){
    char a[51];
    scanf("%s",&a);
    printf("%s",a);

    return 0;
}