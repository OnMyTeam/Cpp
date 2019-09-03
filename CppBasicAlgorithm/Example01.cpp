// Chapter 01 정렬 알고리즘의 개요와 선택 정렬(Selection Sort)

/*
    설명 : 다음숫자들을 오름차순으로 정렬하는 프로그램을 짜보자
            선택정렬 알고리즘은 가장 작은 것을 선택해서 제일 앞으로 보내는 방법이며,
            가장 원시적이고 기초적인 방법이다




 */
 
#include <stdio.h>
#include <array>

using namespace std;
int main(void){
    
    int irArray[7] = {1, 8, 5, 10, 2, 7, 9};
    int ilength = sizeof(irArray)/sizeof(irArray[0]);
     
    int i, j, min, index, temp;

    for(i=0; i<ilength;i++){
        min = 9999;
        for(j=i; j<ilength; j++){
            
            if(min > irArray[j]){
                
                min = irArray[j];
                index = j;

            }

        }
        temp = irArray[i];
        irArray[i] = min;
        irArray[index] = temp;

        
    }
    for(int i=0; i<ilength; i++){
        printf("%d\n", irArray[i]);
    }
    
    /*  시간 복잡도 O(N^2 ) */
    return 0;
}