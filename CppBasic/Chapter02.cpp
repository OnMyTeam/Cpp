// chapter 02 변수
#include <iostream>
  
/*
변수 : 말 그대로 변하는 수. 값이 바뀔 수 있다. 변수의 종류는 매우 다양함. 이 변수는 주기억장치(메모리) 공간이 만들어 지고 저장된다.
용량의 최소 단위 : bit
1byte = 8bit
1kbyte = 1024byte
1mbyte = 1024kbyte
1gbyte = 1024mbyte

문자를 표현하는 방법 : ASCII 코드 표를 가지고있다.
                     각 문자마다 코드 표를 참고해서 숫자에 대응 되는 문자를 표현 한다.
false : 0
true : 0이 아닌 모든수
unsigned : 부호가 없다.
종류        |   용량         |  데이터   |  표현범위          | unsigned     |
char        |   1byte        |  문자    |   -128 ~ 127      |   0 ~ 244     |
bool        |   1byte        |  참/거짓 |   true/false      |   true/false  |
short       |   2byte        |  정수    |   -32768 ~ 32767  |   0 ~ 65535   |
int         |   4byte        |  정수    |   약 --2억 ~ 21억  |  0 ~ 약 43억  |
float       |   4byte        |  실수    |      
double      |   8byte        |  실수    |

*/
using namespace std;

int main(){
    //변수를 만들때도 목적에 맞는 이름으로 지어줄 필요가 있다.
    // C++ 에서 = 는 대입연산자 이다. 오른쪽에 있는 값을 왼쪽으로 대입한다.
    int Number = 10;
    cout << Number << endl;

    bool bTest = true;
    cout << bTest << endl;
    // 영문자, 숫자 1byte
    // 한글,한문은 2byte를 차지하기 때문에 char 변수하나에 저장하기 힘들다.
    // 문자 하나 쓸땐 작은 따옴표;
    char cTest = 't';
    cout << cTest << endl;
    // 뒤에 f를 붙이면 float타입
    // f를 안붙이면 double 타입
    float fNumber  = 3.14f;
    cout << fNumber << endl;

    double dNumber = 123.4567;
    cout << dNumber << endl;
    return 0;
}