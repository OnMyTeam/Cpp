// Chapter 03 삽입 정렬(Insertion Sort)

/*
    설명 : 다음숫자들을 오름차순으로 정렬하는 프로그램을 짜보자
          각 숫자를 적절한 위치에 삽입하는 방법을 삽입정렬(Insertion Sort)이다.
          다른 정렬 방식은 무조건 위치를 바꾸는 방식이었다면 삽입정렬은 '필요할 떄만' 위치를 바꾸게 된다.





 */

#include <stdio.h>
#include <array>

using namespace std;
int main(void){
    
    int irArray[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int ilength = sizeof(irArray)/sizeof(irArray[0]);
     
    int i, j, min, index, temp;

    for(i=0; i < ilength; i++){
        j = i;
        while(irArray[j] > irArray[j+1]){
            temp = irArray[j];
            irArray[j] = irArray[j+1];
            irArray[j + 1] = temp;
            j--;
        }
    }
    for(int k=0; k < ilength; k++){
        printf("%d ", irArray[k]);
    }
    /*  삽입 정렬 시간 복잡도 O(N^2) 

        거의 정렬이 이루어진 상태면 굉장히 빠르다.
        삽입 정렬은 필요할 때에 한해서만 삽입을 진행하기 떄문에 매우 빠르다.
        
    
    */

    return 0;
}