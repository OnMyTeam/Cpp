// Chapter07 ������ Ȯ�� & if���� Ȱ��
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    // ?��?��발생
    srand((unsigned int)time(0));

    cout << rand() << endl;
    cout << rand() << endl;
    cout << ((rand() % 100) + 100) << endl;
    cout << ((rand() % 10000 / 100.f) ) << endl;

    int iUpgrade = 0;

    float fPercent = rand() % 10000 / 100.f;
    cout << "Upgrade �⺻ ��ġ�� �Է��ϼ��� : ";
    cin >> iUpgrade;

    // 0 ~ 3 100%, 4 ~ 6 : 40%, 7 ~ 9 : 10%

    cout << "Upgrade : " << iUpgrade << endl;
    cout << "Percent : " << fPercent << endl;

    if(iUpgrade <= 3)
        cout << "��ȭ ����" << endl;
    else if(4 <= iUpgrade <= 6){
        if (fPercent < 40.f)
            cout << "��ȭ ����" << endl;
        else
            cout << "��ȭ ����" << endl;
    }
    else if(7 <= iUpgrade <= 9){
        if (fPercent < 10.f)
            cout << "��ȭ ����" << endl;
        else
            cout << "��ȭ ����" << endl;
    }
    
    return 0;
}