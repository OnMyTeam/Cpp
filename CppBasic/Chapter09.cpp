// Chapter09 while문과 가위바위보 게임

#include <iostream>
#include <time.h>
using namespace std;
/*
반복문 : 특정 작업을 반복해서 수행해 주는 기능이다.
종류 : for, while, do while 있음.

while(조건식){} 형태로 구성됨.
   while문은 조건식을 체크해서 true경우 코드블럭안에 코드가 실행되고
   조건식이 false가 되면 while문을 빠져나가게 된다.
   break문 또한 while문을 빠져나가게한다.



 */

enum SRP
{
    SRP_S = 1, //가위
    SRP_R,      //바위
    SRP_P,      //보
    SPR_END
};
int main(){
    int iNumber = 0;

    while (iNumber <= 5){
        cout << iNumber << endl;
        ++iNumber;
        
    }
    // 화면을 깨끗히 지워줌.
    system("cls");
    // 난수테이블 생성
    srand((unsigned int)time(0));

    int iPlayer, iAI;
    while(true){
        cout << "1. 가위" << endl;
        cout << "2. 바위" << endl;
        cout << "3. 보" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        cin >> iPlayer;
        
        if(iPlayer < SRP_S || iPlayer > SRP_P){
            cout << "잘못된 값을 입력하였습니다. "<< endl;
            system("pause");
            continue;
        }
        else if (iPlayer == SPR_END)
            break;

        // 봇이 선택함.
        iAI = (rand() % 3) + SRP_S;
        switch(iAI){

            case SRP_S:
                cout << "AI 가위 선택." << endl;
                break;
            case SRP_R:
                cout << "AI 바위 선택." << endl;
                break;
            case SRP_P:
                cout << "AI 보 선택." << endl;
                break;

            default:
                cout << "종료" << endl;                                                

        }
        int iWin = iPlayer - iAI;
        if(iWin == 1 || iWin == -2 )
            cout << "Player 승리" << endl;
        else if(iWin ==0)
            cout << "비김" << endl;
        else
            cout << "AI 승리" << endl;
        
        system("pause");
    }
    return 0;
}