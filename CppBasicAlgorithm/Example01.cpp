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
    

    return 0;
}