//Chapter23 Reference

#include<iostream>

using namespace std;
/*

    참조(레퍼런스) : 다른 대상을 참조하게 만들어주는 기능이다.
    참조를 하게 되면 그 대상에 접근하여 값을 변경할 수 있다.
    단, 레퍼런스는 처음 레퍼런스 변수 생성시 참조하는 대상을 지정해 주어야 한다.
    특히 인자값넘길때 4byter값만 넘기므로 빠르다

    변수타입 &레퍼런스명 = 참조할변수명; 으로 선언함.

 */

int main()
{
    int iNumber = 100;
    int iNumber1 = 9999;
    // 이 레퍼런스 변수는 iNumber를 참조한다.
    int &iRefNum = iNumber;

    iRefNum = 1234;
    iRefNum = iNumber1;
    cout << iRefNum << endl;
    cout << sizeof(int&) << endl;

    
    return 0;
}