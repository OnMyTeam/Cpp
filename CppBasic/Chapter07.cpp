// Chapter07 난수와 확률 & if문의 활용
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    // ?궃?닔諛쒖깮
    srand((unsigned int)time(0));

    cout << rand() << endl;
    cout << rand() << endl;
    cout << ((rand() % 100) + 100) << endl;
    cout << ((rand() % 10000 / 100.f) ) << endl;

    int iUpgrade = 0;

    float fPercent = rand() % 10000 / 100.f;
    cout << "Upgrade 기본 수치를 입력하세요 : ";
    cin >> iUpgrade;

    // 0 ~ 3 100%, 4 ~ 6 : 40%, 7 ~ 9 : 10%

    cout << "Upgrade : " << iUpgrade << endl;
    cout << "Percent : " << fPercent << endl;

    if(iUpgrade <= 3)
        cout << "강화 성공" << endl;
    else if(4 <= iUpgrade <= 6){
        if (fPercent < 40.f)
            cout << "강화 성공" << endl;
        else
            cout << "강화 실패" << endl;
    }
    else if(7 <= iUpgrade <= 9){
        if (fPercent < 10.f)
            cout << "강화 성공" << endl;
        else
            cout << "강화 실패" << endl;
    }
    
    return 0;
}