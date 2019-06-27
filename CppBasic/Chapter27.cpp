//Chapter27 operator

#include<iostream>

// C++에선 구조체에서도 생성자를 만들 수 있다.
typedef struct _tagPoint
{
    int x;
    int y;

    _tagPoint():
    x(0),
    y(0)
    {

    }
    _tagPoint(int _x, int _y):
    x(_x),
    y(_y)
    {
      
    }
    _tagPoint(const _tagPoint& pt)
    {
        //얕은 복사를 한다. 이렇게 해줄 경우 this는 자기자신의 포인터이고
        //*을 붙여서 자기자신을 역참조하여 모든 데이터를 복사하게 된다.
      *this = pt;
    }
    // operator 도 오보로딩이 가능함
    _tagPoint operator +(const _tagPoint &pt)
    {
        _tagPoint pt1;
        pt1.x = x + pt.x;
        pt1.y = y + pt.y;

        return pt1;

    } 
    _tagPoint operator +(int a)
    {
        _tagPoint pt1;
        pt1.x = a;
        pt1.y = a;

        return pt1;

    }     
    void operator << (const _tagPoint& pt)
    {
        x = pt.x;
        y = pt.y;
    }

}POINT, *PPOINT;
using namespace std;
/*
    operator 는 연산자를 재정의 하는 것이다!
    예를 들어 클래스 끼리 더하는건 원래 힘든데 operator를 통해 클래스간의 +을 정의 할 수 있다.


 */
int main()
{
    cout << "================ Point ===============" << endl;

    POINT pt1(10, 20), pt2(30, 40), pt3;

    // 원래 아래는 연산이 불가능 하지만 operator를 통해 연산을 정의 할  수 있다.
    // POINT 구조체는 +연산자가 operator로 재정의 되어 있다.
    // 그래서 + 연산이 가능하게 되고 pt1의 + 연산자 함수를 호출해주는 개념이다.
    // pt2를 인자로 넘겨준다. pt1의 함수 인자값으로 
    pt3 = pt1 + pt2;
    pt1 << pt2;
    pt3 = pt2 + 1000;
    cout << "x : "<< pt3.x << "\ny : "<< pt3.y << endl;
    return 0;
}