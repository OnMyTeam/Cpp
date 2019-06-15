// Chapter14 포인터와 배열, void 포인터, 구조체 포인터

#include <iostream>

using namespace std;

struct _tagStudent
{
    int iKor;
    int iEng;
    int iMaht;
    int iTotal;
    float fAvg;
};
/*
    포인터를 쓰는 이유? 다른 변수의 메모리 주소를 이용해서 접근하여 값을 제어하기 위함.
 */
int main(){
    int iNumber = 100;
    _tagStudent tStudent = {};
    tStudent.iKor = 100;

    _tagStudent *pStudent = &tStudent;
    // 연산자 우선순위로 인해 .을 먼저 인식해서 메모리 주소 .은 잘못됨
    // *pStudent를 괄호로 감싸 준후에 .을 이용해서 멤버변수에 접근하자
    (*pStudent).iKor = 50;
    cout << tStudent.iKor << endl;
    // '메모리 주소->' 을 이용하면 가리키는 대상의 멤버변수에 접근할 수 있다.
    // '(*pStudent).iKor' = 'pStudent->iKor'
    pStudent->iKor = 80;
    cout << tStudent.iKor << endl;

    // void : 타입이 없다. return할 타입이없다. 
    // void* 포인터 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 저장 가능하다.
    // 단, 역참조가 불가능하다. 메모리 주소만 저장이 가능함.
    void* pVoid = &iNumber;
    cout << "iNumber Address : " << pVoid << endl;
    // 아래는 역참조가 불가능함.
    *pVoid = 10;
    // 아래와 같이 int타입의 형변환을 통해서 pConvert 변수에 저장한뒤 역참조해서 접근해야 함.
    int *pConvert = (int*)pVoid;
    *pConvert = 200;
    
    cout << "iNumber : " << iNumber << endl;
    pVoid = &tStudent;
    cout << "tStudent Address : " << pVoid << endl;

    
    return 0;
}