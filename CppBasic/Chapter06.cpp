// Chapter06 if문(분기문)

#include <iostream>

using namespace std;

/*
분기문에는 2가지 종류가 있다!
1. if문 : 조건을 체크해 주는 기능
   형태 : if(조건식){}(코드블럭)
   특징 : 조건식이 true가 될 경우에만 코드블럭 안의 코드가 실행된다. false일 경우 동작 안됨
2. 


 */
int main(){
    const int   iAttack = 0x0000001;    //      1
    const int   iArmor = 0x00000002;    //     10
    const int   iHP = 0x0000004;        //    100
    const int   iMP = 0x0000008;        //   1000
    const int   iCritical = 0x0000010;  // 100000

    
    int iBuf = iAttack | iHP | iCritical;    
    if(false){
        cout << "참 입니다." << endl;
    }
    // if문 아래에 들어갈 코드가 1줄일 경우 {}(코드블럭)을 생략 할 수 있다.
    if((iBuf & iAttack) != 0)
        cout << "Attack  버프가 있습니다." << endl;    
    if((iBuf & iArmor) != 0)
        cout << "Armor 버프가 있습니다." << endl;
    if((iBuf & iHP) != 0)
        cout << "HP 버프가 있습니다." << endl;
    if((iBuf & iMP) != 0)
        cout << "MP 버프가 있습니다." << endl;
    if((iBuf & iCritical) != 0)
        cout << "iCritical 버프가 있습니다." << endl;      
        
    /*
    else : if문과 반드시 같이 사용 되어야 한다.
    if문이 조건이 false일 경우 else가 있다면 else 구문 안의 코드가 동작된다.

    else if : if문과 반드시 같이 사용이 되어야 한다.
    if문 아래에 와야 하고 else보다는 위에 있어야 한다.
    else if는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을 체크한다.
    else if는 몇개든 사용이 가능하다.
    
     */            
    int iNumber;       
    cout << "숫자를 입력하세요. : "       ;
    cin >> iNumber;

    if (10 <= iNumber && iNumber <=20)
        cout << "10 ~ 20의 숫자입니다." << endl;

    else if (21 <= iNumber && iNumber <=30)
        cout << "21 ~ 30의 숫자입니다." << endl;
    else
        cout << "응 나머지 숫자." << endl;
    return 0;
}