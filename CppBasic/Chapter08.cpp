//Chapter 08 switch문과 열거체

#include <iostream>
using namespace std;

/*

1. switch 문 : 분기문의 한 종류이다. if문이 조건을 체크하는 분기문이라면
            switch문은 값이 무엇인지 체크하는 분기문이다.
    형태  : switch(변수) {}의 형태로 구성된다. 코드블럭 안에는 case break  구문이 들어가게 된다.
        case 상수: 이런 형태로 처리가 되고 변수값이 무엇인지에 따라서 case 뒤에 오는 상수를 비교하게 된다.

2. 열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다.
   형태   : enum 열거체명 {} 의 형태로 구성된다.
   열거체명을 이용해서 열거체 타입의 변수를 선언하는 것도 가능하다.
   즉, 열거체 자체가 사용자 정의 변수 타입이 될 수 있다.

 */

enum NUM
{
    NUM_0, // 아무것도 부여하지 않은 경우 0부터 1씩 차례로 값이 부여된다.
    NUM_1,
    NUM_2,
    NUM_3,

};
// 앞에 #이 붙이면 전처리라고 했다.
// 컴파일 할때, 특정 값이 정해진다고 볼 수 있다.
#define NUM_4 4
int main(){
    int iNumber;
    cout << "숫자를 입력하세요 : ";
    cin  >> iNumber;

    switch(iNumber)
    {
        case NUM_0: // iNumber값이 무엇인지에 따라서 실행되는 case 구문이 결정된다.
            cout << "1 실행" << endl;
            break;
        case NUM_1:
            cout << "1 실행" << endl;
            // 만약 break가 없을 경우 아래에 있는 case 구문도 강제로 실행된다.
            break;
        case NUM_2:
            cout << "2 실행" << endl;
            break;
        case NUM_3:
            cout << "3 실행" << endl;
            break;            
        case NUM_4:
            cout << "4 실행" << endl;
            break;            
        default: // case 로 지정되지 않는 숫자가 입력될 경우 실행된다.
            cout << "그 외에 숫자입니다." << endl;
            break;
    }
    // 열거체 타입의 변수 선언; 열거체 타입 변수는 무조건 4byte를 차지하게 됨
    // 열거체를 선언한 변수는 값의 표현범위는 열거체에 나열된 값들 안에서 선택해서 사용된다.
    NUM eNUM = NUM_3;
    cout << "eNUM의 사이즈는?? "<< sizeof(eNUM) << endl;
    cout << eNUM << endl;
    return 0;
}

