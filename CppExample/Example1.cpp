//Example1 while문을 활용한 가위바위보게임

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum SRP
{
    ROCK=1,
    SISSORS,
    PAPER,
    QUIT,
    OTHER
};


int main()
{
    // seed값을 받아 난수표에 시작 지점을 바꾸는 것
    srand((unsigned int)time(0));

    int iPlayer,iAI;

    while(true)
    {
        cout << "1. 가위" << endl;
        cout << "2. 바위" << endl;
        cout << "3. 보" << endl;
        cout << "4. 종료" << endl;        
        cout << "메뉴를 선택해 주세요." << endl;
        cin >> iPlayer;
        if(iPlayer < ROCK || iPlayer >=OTHER)
        {
            cout << "다시 선택해 주세요." << endl;
            continue;
        }
        if(iPlayer == QUIT)
            break;
        system("cls");
        iAI = (rand() % 3) + 1;
        switch (iAI)
        {
        case ROCK:
            cout << "AI 바위 선택" << endl;
            break;
        case SISSORS:
            cout << "AI 가위 선택" << endl;
        case PAPER:
            cout << "AI 보 선택" << endl;            
        default:
            break;
        }

    }

    return 0;
}