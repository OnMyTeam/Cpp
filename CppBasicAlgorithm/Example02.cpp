// Chapter 02 버블 정렬(Bubble Sort)

/*
    설명 : 다음숫자들을 오름차순으로 정렬하는 프로그램을 짜보자
           바로 가까이에 있는 두 숫자끼리 비교해서 바로 더작은 순자를 앞으로 보내주는 것을 반복하는 것
           즉, 버블 정렬이란 옆에 있는 값과 비교하여 더 작은 값을 반복적으로 앞으로 보내는 정렬 방법이다.
           결과적으로 가장 큰값이 하나씩 맨 뒤로가게됨.




 */

#include <stdio.h>
#include <array>

using namespace std;
int main(void){
    
    int irArray[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int ilength = sizeof(irArray)/sizeof(irArray[0]);
     
    int i, j, min, index, temp;

    for(i=0; i<ilength; i++){
        for(j=0; j<ilength-(i+1); j++){
            if(irArray[j]>irArray[j+1]){
                temp = irArray[j];
                irArray[j] = irArray[j + 1];
                irArray[j + 1] = temp;
            }
                
        }
    } 

    for(int k=0; k < ilength; k++){
        printf("%d ",irArray[k]);
    }
    
    /*   버블 정렬 시간 복잡도 O(N^2) 

        버블정렬이 선택정렬보다 더 느린이유는 무엇일까?
        선택정렬은 가장 작은 값에대한 인덱스 값을 찾아 마지막에 교체를 하지만
        버블정렬은 계속해서 자리를 바꾸는 연산을 하기 때문에 훨씬 느리다.
        
    
    */

    return 0;
}