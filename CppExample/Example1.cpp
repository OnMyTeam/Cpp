//Example1 while���� Ȱ���� ��������������

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
    // seed���� �޾� ����ǥ�� ���� ������ �ٲٴ� ��
    srand((unsigned int)time(0));

    int iPlayer,iAI;

    while(true)
    {
        cout << "1. ����" << endl;
        cout << "2. ����" << endl;
        cout << "3. ��" << endl;
        cout << "4. ����" << endl;        
        cout << "�޴��� ������ �ּ���." << endl;
        cin >> iPlayer;
        if(iPlayer < ROCK || iPlayer >=OTHER)
        {
            cout << "�ٽ� ������ �ּ���." << endl;
            continue;
        }
        if(iPlayer == QUIT)
            break;
        system("cls");
        iAI = (rand() % 3) + 1;
        switch (iAI)
        {
        case ROCK:
            cout << "AI ���� ����" << endl;
            break;
        case SISSORS:
            cout << "AI ���� ����" << endl;
        case PAPER:
            cout << "AI �� ����" << endl;            
        default:
            break;
        }

    }

    return 0;
}