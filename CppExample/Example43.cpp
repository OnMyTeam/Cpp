// 코드업 기초 100제 - [기초-산술연산] 정수 세 개 입력받아 합과 평균 출력하기
/*
문제 : 
정수 세 개를 입력받아 합과 평균을 출력하는 프로그램을 작성해보자.
(단, -2147483648 ~ 2147483647)

입력
정수 세 개가 공백을 두고 입력된다.
(단, -2147483648 ~ 2147483647)

출력
입력 받은 정수 세 개의 합과 평균을 줄을 바꿔 출력한다.

평균은 소수점 이하 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.

입력 예시   
1 2 3

출력 예시
6
2.0
 */ 
 
#include<stdio.h>

int main(){
    int ia,ib,ic;
    scanf("%d %d %d",&ia,&ib,&ic);
    printf("%d\n",ia+ib+ic);
    printf("%.1f\n",float((ia+ib+ic))/3);


    return 0;
}