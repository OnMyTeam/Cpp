//Chapter15 이중포인터


#include <iostream>

using namespace std;
/*
    이중포인터 : 포인터 변수의 메모리 주소를 저장하는 변수
    특징 : 이중포인터는 **를 2개 붙인다. 일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수라면
           이중포인터는 포인터 변수의 메모리 주소를 저장하는 변수이다.
 */
int main(){
    int iNumber = 111;
    int iNumber1 = 222;
    int* pNum = &iNumber;
    int **ppNum = &pNum;

    *pNum = 333;
    cout << "iNumber : " << iNumber << endl;
    cout << "iNumber Addr : " << &iNumber << endl;
    cout << "*pNum : " << *pNum << endl;
    cout << "pNum Value : " << pNum << endl;
    cout << "pNum Addr : " << &pNum << endl;
    cout << "*ppNum : " << *ppNum << endl;
    cout << "**ppNum : " << **ppNum << endl;
    cout << "ppNum Value : " << ppNum << endl;
     
    return 0;
}
