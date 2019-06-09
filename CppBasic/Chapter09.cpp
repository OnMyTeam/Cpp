// Chapter09 while���� ���������� ����

#include <iostream>
#include <time.h>
using namespace std;
/*
�ݺ��� : Ư�� �۾��� �ݺ��ؼ� ������ �ִ� ����̴�.
���� : for, while, do while ����.

while(���ǽ�){} ���·� ������.
   while���� ���ǽ��� üũ�ؼ� true��� �ڵ���ȿ� �ڵ尡 ����ǰ�
   ���ǽ��� false�� �Ǹ� while���� ���������� �ȴ�.
   break�� ���� while���� �����������Ѵ�.



 */

enum SRP
{
    SRP_S = 1, //����
    SRP_R,      //����
    SRP_P,      //��
    SPR_END
};
int main(){
    int iNumber = 0;

    while (iNumber <= 5){
        cout << iNumber << endl;
        ++iNumber;
        
    }
    // ȭ���� ������ ������.
    system("cls");
    // �������̺� ����
    srand((unsigned int)time(0));

    int iPlayer, iAI;
    while(true){
        cout << "1. ����" << endl;
        cout << "2. ����" << endl;
        cout << "3. ��" << endl;
        cout << "4. ����" << endl;
        cout << "�޴��� �����ϼ��� : ";
        cin >> iPlayer;
        
        if(iPlayer < SRP_S || iPlayer > SRP_P){
            cout << "�߸��� ���� �Է��Ͽ����ϴ�. "<< endl;
            system("pause");
            continue;
        }
        else if (iPlayer == SPR_END)
            break;

        // ���� ������.
        iAI = (rand() % 3) + SRP_S;
        switch(iAI){

            case SRP_S:
                cout << "AI ���� ����." << endl;
                break;
            case SRP_R:
                cout << "AI ���� ����." << endl;
                break;
            case SRP_P:
                cout << "AI �� ����." << endl;
                break;

            default:
                cout << "����" << endl;                                                

        }
        int iWin = iPlayer - iAI;
        if(iWin == 1 || iWin == -2 )
            cout << "Player �¸�" << endl;
        else if(iWin ==0)
            cout << "���" << endl;
        else
            cout << "AI �¸�" << endl;
        
        system("pause");
    }
    return 0;
}