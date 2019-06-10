// Chapter 10 for문과 중첩 for문
#include <iostream>

using namespace std;
/*
    for문 : 반복문의 한 종류이다. 
    형태 : for(초기값; 조건식; 증감값){}의 형태로 이루어져 있음.
    조건식이 true이면 코드블럭의 코드가 동작된다.
    무한루프를 돌릴때는 for(;;){}을 해주면 무한으로 돌아가게 된다.
    for문에서 초기값은 처음 for문에 진입할때 1번만 동작된다. 그후 조건식을 체크하고
    조건식이 true이면 코드블럭의 코드가 동작된 후에 증감값을 처리한다.
    그후 다시 조건을 체크하고 true면 동작되고 증감 -> 조건 -> 증감 -> 조건의 
    순서로 처리되다가 조건이 false이거나 break를 만나게 되면 for문을 빠져나가게 된다.
 */

int main(){
    for(int i=0; i<=10; i++){
        cout << i << endl;
    }

    // 구구단
    int iNumber;
    cout << "숫자를 입력해 주세요";
    cin >> iNumber;

    for(int i=0; i<10 ; i++){
        cout << i * iNumber << endl;

    }
    // 1 ~ 100 사이의 숫자중 짝수만 출력하는 for문을 작성해보자.
    for(int i=1; i<=100; i++){
        if(i % 2 == 0){
            cout << i << endl;
        }
    }

    // 중첩 for문 : for문 안에 또다른 for문이 존재하는 형태이다.
    for(int i=0 ; i<= 10; i++){
        for(int j=0; j<=i ; j++){
            cout << i << " " << j << endl;
        }
    }
    return 0;
}