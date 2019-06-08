// chapter 01 프로젝트 생성과 출력

//앞에 #붙어 있는건 전처리기 라고함.
//#include : 헤더파일을 이 파일에 포함시키는 기능이다.
//ex :  <iostream> -> 입출력을 위한 표준기능이 <iostream>에 있다. 이것은 이미 만들어져 있으며 우리가 가져다 쓰는 것이다.
#include <iostream>
  
using namespace std;
// C++의 시작점은 항상! main()함수 이다.main()함수는 반드시 있어야 한다. 
int main(){
    // C++ 표준 기능의 대부분은 std라는 namespace 안에 존재하고 있다. 이름이 겹치는 것을 방지하기 위해
    // cout : 콘솔창에 출력해주는 기능이다
    // endl : 개행기능
    cout << "Test Output:" << endl;
    cout << "Test end:" << endl;
    return 0;
}
// 실행과정 : 컴파일 ->  빌드 -> 실행
// Compiler란?
// C++은 HighLevel 언어이다. 여기서 HighLlevel이란? 사람이 좀더 쉽고 편하게 익힐 수 있는 언어이다.
// C++은 컴퓨터가 이해하지 못하는 언어이기 떄문에 컴퓨터가 이해하기 쉬운 언어로 번역을 해야한다.
// 따라서 Compiler는 HighLevel의 언어를 컴퓨터가 이해하기 쉽게(바이너리 코드) Low Level로 바꿔주는 번역작업을 말한다.