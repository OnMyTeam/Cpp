// Chapter17 동적할당

#include <iostream>

using namespace std;

/*
    동적할당 : 메모리 생성을 원하는 시점에 할 수 있는 기능이다.
              메모리 영역중 Heap영역에 공간이 할당된다. 힙의 특성상 메모리를 해지하기 전 까지는 계속 남아있다.
              동적할당을 하고 메모리를 해제하지 않으면 공간이 계속 잡혀있게 된다.
              해당 공간은 다른곳에서 사용이 불가능하다. 이런 현상을 메모리릭 이라고 한다.
    동적할당은 new 키워드를 이용해서 쓸 수 있다. Heap영역에 메모리 공간을 할당하고 해당 메모리의 주소를 반환해 준다.
    new 할당할타입; 방식으로 처리한다.
    delete 키워드를 이용해서 할당된 공간을 지울수 있다.
    delete 뒤에 메모리 주소를 넣어주면 된다.
 */
int main(){
    // 아래처럼 할당하게 되면 new 뒤에 들어오는 타입인 int의 크기만큼 공간을 할당한다.
    // 즉 4byte 공간을 할당하고, 할당한 공간의 메모리 주소를 pNumber에 넣어준다.
    // pNumber은 지역변수 이므로 stack 영역에 할당되게 되고, 단순히 Heap영역에 공간을 할당하고 난뒤 그 반환된 주소를 가리키는 것이다.
    int* pNumber = new int;
    *pNumber = 100;
    
    cout << pNumber << endl;
    cout << *pNumber << endl;
    delete pNumber;
    cout << *pNumber << endl;

    /*
        동적배열 할당방법 : new 타입[개수]; 의 형태로 사용할 수 있다.
        아래처럼 동적배열로 할당하면 메모리 공간에 400바이트 만큼 공간을 할당하고
        해당 메모리의 시작 주소를 반환한다.
     */
    int* pArray =new int[100];
    pArray[1] = 300;
    delete[] pArray;
    return 0;
}