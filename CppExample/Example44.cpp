// 코드업 기초 100제 - [기초-비트시프트연산] 정수 한 개 입력받아 2 곱해 출력하기
/*
문제 : 
정수 한 개를 입력했을 때 2를 곱해 출력하는 프로그램을 작성해보자.

(단, -1073741824 ~ 1073741823)

입력
정수 한 개가 입력된다.
(단, -1073741824 ~ 1073741823)

출력
입력 받은 정수 * 2의 계산 결과가 출력된다.

입력 예시   
1024

출력 예시
2048
 */ 
 
#include<stdio.h>

int main(){
    int ia;
    scanf("%d",&ia);
    printf("%d",ia<<1);
    


    return 0;
}
