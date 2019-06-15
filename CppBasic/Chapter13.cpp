//Chapter13 포인터 이론

#include <iostream>
#include <typeinfo>

using namespace std;
/*
    1. 포인터 : 가리킨다? 일반 변수는 일반적인 값을 저장하게 되지만 포인터 변수는 메모리
                주소를 저장하게 된다. 모든 변수 타입은 포인터 타입을 선언할 수 있다.
                예를 들어, int 변수의 주소는 int 포인터 변수에 저장을 해야 한다.
                포인터는 메모리 주소를 저장하는 변수이기 떄문에 x86으로 개발할때는 4byte, x64일떄는 8byte가 나온다.    
                메모리주소는 16진수로 표현, 8자리로 표현된다.

    2.  포인터 변수가 뭘할까? 포인터는 자기 스스로 아무런일을 못함. 반드시 변수의 메모리 주소를 가지고 있어야
                            일을 할 수 있는데 가지고 있는 그 메모리 주소에 접근해서 값을 제어 할 수 있다.

    3.  형태 : 변수타입 *변수명
 */
int main(){

    int iNumber = 100;
    int iNumber1 = 100;
    // 변수 선언시 *를 붙여주면 해당 타입의 포인터 변수가 된다.
    // 변수명 앞에 &을 붙여주면 해당 변수의 메모리 주소가 된다.
    // pNum은 iNumber변수의 메모리 주소값을 갖기 때문에 pNum을 이용해서 iNumber의 값을 제어할 수 있다.
    int *pNum = &iNumber;
    


    // 아래의 int, char, double 타입 등등의 포인터는 메모리 주소의 크기를 나타내기 때문에 모두 4byte이다.
    cout << sizeof(int*) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(double*) << endl;

    // iNumber의 주소
    cout << "iNumber의 Address : " << &iNumber << endl;
    // pNum은 포인터 변수이기 때문에 iNumber의 주소를 값으로 받는다.    
    cout << "pNum의 Value : " << pNum << endl;
    // 포인터 변수 pNum의 메모리 주소값
    cout << "pNum의 Address : " <<  &pNum << endl;

    // pNum을 이용해서 iNumber의 값을 제어해보자.
    // 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
    // 역참조는 이미 선언된 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
    *pNum = 200;
    cout << "pNum의 역참조 값 : " <<  *pNum << endl;
    cout << "iNumber 값 : " <<  iNumber << endl;        

    /*
        포인터와 배열의 관계 : 배열명은 포인터다. 배열명 자체가 해당 배열의 메모리에서의 시작점 주소이다.
     */
    int iArray[10] = {1,2,3,4,5,6,7,8,9};
    cout << "iArray의 Address :  " << iArray << endl;
    cout << "iArray의 Address :  " << &iArray << endl;

    int *pArray = iArray;
    cout << pArray[2] << endl;

    /*
        포인터 연산 : +,- 연산을 제공한다. 1을 증가하게 되면 단순히 메모리주소값이 1 증가하는 것이 아니다.
                     int 포인터의 경우 int타입의 메모리 주소를 갖게 되는데 메모리 주소에 1을 더해주면
                     1증가가 아니라 가리키는 해당 포인터 타입의 변수타입 크기만큼 증가하게 된다.
                     int 포인터는 int의 크기인 4byte만큼 값이 증가하게 되는 것이다.

     */
    cout << pArray << endl;
    cout << pArray + 2 << endl;
    // pArray는 배열의 첫번재 시작점 주소를 갖기떄문에 첫번째 인덱스 값이 나옴
    cout << *pArray << endl;
    cout << *(pArray + 2) << endl;
    cout << *pArray + 100 << endl;

    // 내부적으로 "테스트 문자열" 이라는 문자가 메모리 주소가 잡힌다.
    // 배열로 문자열을 저장하기 위해 공간이 할당되고 저장하게 된다. 즉, 알아서 Char 배열이 잡힘!
    char *pText = "테스트 문자열";
    // 아래와 같이 배열이 잡힌상태에서 값을 변경하려고 해도 안된다. 이유는 const 이기 때문!
    pText[0] = 'a';
    pText[1] = 'b';
    
    cout << pText << endl;
    
    return 0;
}
