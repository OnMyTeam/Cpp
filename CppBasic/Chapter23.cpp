//Chapter23 Reference

#include<iostream>

using namespace std;
/*

    ����(���۷���) : �ٸ� ����� �����ϰ� ������ִ� ����̴�.
    ������ �ϰ� �Ǹ� �� ��� �����Ͽ� ���� ������ �� �ִ�.
    ��, ���۷����� ó�� ���۷��� ���� ������ �����ϴ� ����� ������ �־�� �Ѵ�.
    Ư�� ���ڰ��ѱ涧 4byter���� �ѱ�Ƿ� ������

    ����Ÿ�� &���۷����� = �����Һ�����; ���� ������.

 */

int main()
{
    int iNumber = 100;
    int iNumber1 = 9999;
    // �� ���۷��� ������ iNumber�� �����Ѵ�.
    int &iRefNum = iNumber;

    iRefNum = 1234;
    iRefNum = iNumber1;
    cout << iRefNum << endl;
    cout << sizeof(int&) << endl;

    
    return 0;
}