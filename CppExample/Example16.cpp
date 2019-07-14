// 코드업 기초 100제 - [기초-입출력] 년월일 입력받아 형식에 맞게 출력하기
/*
문제 : 
년, 월, 일을 입력받아 형식에 맞게 출력하는 프로그램을 작성해보자.

입력
년, 월, 일이 ".(닷)"으로 구분되어 입력된다.

출력
입력받은 년, 월, 일을 출력한다. 단, 자릿수는 yyyy.mm.dd형태로 출력한다.
(입출력 예시 참고, %02d를 사용하면 2칸을 사용해 출력하는데, 1자리 수인 경우 앞에 0이 붙어 출력된다.)

입력 예시   
2012.11.21

출력 예시
2012.11.21
 */ 

#include<stdio.h>


int main()
{
    int iy,im,id;
    scanf("%04d.%02d.%02d", &iy,&im,&id);
    printf("%04d.%02d.%02d",iy,im,id);
    
    return 0;
};
