//Chapter16 함수


#include <iostream>
 
// 코드블럭 외부에 변수를 선언하게 되면 전역변수가 된다. 전역변수는 이 변수를 선언한 아래의 모든 부분에서 사용가능하다.
// 전역변수는 소속된 코드블럭이 없으므로 프로그램이 종료될때까지 메모리에 존재하게 된다.
// 프로그램이 종료되면 메모리에서 해제가 된다.
int g_iNumber = 0;

using namespace std;
/*
    함수 : 기능을 만들어 준다.
          특정 상황에 동작하는 코드 집합을 만들어 내는 것이다.
    
    형태 : 반환타입 함수명(인자){} 의 형태로 구성됨.
    반환타입 : 함수가 기능을 수행하고 기능의 결과를 봔한해야 할 경우 지정한다.
              정수를 반환할때는 정수타입, 실수를 반환할때는 실수타입으로 지정한다.
    함수명 : 함수의 이름을 의미한다. 함수명은 가급적이면 이 함수가 하는 역할을 정확하게 표시해 주는 것이 좋다.
    인자 : 해당 함수를 사용할떄 넘겨줄 값이 있을 경우 인자를 활용한다. 인자는 있을수도 있고 없을수도 있다.
 */


// 아래 함수처럼 인자를 넘겨받게 될 경우 이 인자는 이 함수 코드블럭의 지역에 속해있다고 판단된다.
// 즉 함수의 지역변수가 되고 stack에 할당된다.
// OutputNumber 함수를 호출하는 순간 새로운 영역에 iNumber 이름의 메모리가 할당되고 그 할당된 공간에 새로운 값이 들어가는 것이다.
// 할당된 지역변수는 해당 지역변수가 소속된 코드블럭이 닫히게 되면 메모리에서 해제된다.
void ChangeNumber(int iNumber){
    g_iNumber = 456;
    iNumber = 999;
    cout << "Number : " << iNumber << endl;
}
// 아래 함수는 결과값을 인자로 받아와서 결과를 반환해 준다. 
// 이런형태의 함수를 Call by Address
void ChangeNumber1(int* pNumber){
    *pNumber = 999;
}

/*
    함수의 오보로딩 : 같은 이름의 함수지만 기능이 다르고 인자가 다른 함수를 말한다.
    오보로딩 조건 : 함수 이름이 무조건 같아야 한다. 단, 인자의 개수 혹은 타입이 달라야 오보로딩이 성립된다. 
                    반환타입은 영향을 안줌

 */ 
// 아래 함수처럼 결과를 반환해 주는 함수 형태를 Call by Value
int Sum(int a, int b){

    //return 키워드를 이용해 이 함수의 반환타입에 맞는 값을 반환해야 한다.
    return a + b;
}
float Sum(float a, float b)
{
    return a + b;
}

void outputText(){
    int iSum = Sum(10, 20);
    cout << "Sum : " << iSum << endl;
}
/*
    함수의 디폴트인자 : 인자는 기본적으로 값을 넘겨받게 설계되어 있다. 인자의 기본값을 대입해 주면
                      인자를 넘겨주지 않을 경우 기본 설정한 값이 되고 인자를 넘겨줄 경우 넘겨받은 값으로 저장이 된다.
                      디폴트 인자는 가장 오른쪽 부터 지정해 주어야 함.

 */
void Output(int iNum1, int iNum2 = 20){
    cout << iNum1 <<  endl;
    cout << iNum2 <<  endl;
}
void Output(int iNum1){
    cout << iNum1 <<  endl;
}
int main(){
    // 함수를 호출할떄는 함수명(인자값); 의 형태로 호출한다.
    // 아래처럼 특정 코드블럭 안에서 선언되는 변수를 지역변수라고 한다.
    // 지역변수는 메모리 영역중 stack에 할당된다.
    // 똑같은 타입의 iNumber 변수여도 속해있는 함수가 다르기 때문에 각각 다른 메모리 영역에 할당된다.
    int iNumber = 0;
    cout << Sum(10, 20) << endl;
    cout << Sum(10.f, 20.f) << endl;
    cout << Sum(100, 200) << endl;
    outputText();
    ChangeNumber(iNumber);
    cout << iNumber << endl;
    ChangeNumber1(&iNumber);
    cout << iNumber << endl;
    cout << g_iNumber << endl;
    Output(10,40);
    return 0;
}