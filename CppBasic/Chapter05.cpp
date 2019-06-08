// Chapter05 비트논리연산자와 쉬프트 연산자

#include <iostream>

using namespace std;

int main(){
    /* 
     상수  : 변하지 않는 수
     상수는 선언과 동시에 값을 지정해 두어야 한다.
     16진수 표기방법 :  앞에 0x를 붙인다.
     */
    const int   iAttack = 0x0000001;    //      1
    const int   iArmor = 0x00000002;    //     10
    const int   iHP = 0x0000004;        //    100
    const int   iMP = 0x0000008;        //   1000
    const int   iCritical = 0x0000010;  // 100000

    //          0001   | 0100| 0001 0000 = 10101
    int iBuf = iAttack | iHP | iCritical;
    // 연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
    // iBuf = iBuf ^ iHP;
    // 10101 ^ 00100 = 10001 버프 꺼짐
    iBuf ^=iHP;
    // 10001 ^ 00100 = 10100 버프 켜짐
    iBuf ^=iHP;

    // 10101 & 0001 = 00001
    cout << "Attack : " << (iBuf & iAttack) << endl;
    // 10101 & 00010 = 00000
    cout << "Armor : " << (iBuf & iArmor) << endl;
    // 10101 & 00100 = 00100
    cout << "HP : " << (iBuf & iHP) << endl;
    // 10101 & 01000 = 00000
    cout << "MP : " << (iBuf & iMP) << endl;
    // 10101 & 10000 = 10000
    cout << "Critical : " << (iBuf & iCritical) << endl;

    // 왜 비트단위 논리연산자, 쉬프트 연산자를 쓸까? -> 속도가 빠르다!

    /*
    쉬프트 연산자 : <<,>> 값 대 값을 연산하여 값이 나옴.
    이 연산자 또한 이진수 단위의 연산을 하게됨.
    쉬프트 연산자는 곱하기가 훨씬 빠르다.
    20 << 1 = 40
    20을 2진수로 변환해 보자(왼쪽으로 1칸 이동해라).
    0001 0100 -> 0010 1000    
    20 << 2 = 80
    20을 2진수로 변환해 보자(왼쪽으로 2칸 이동해라).
    0001 0100 -> 0101 0000    
    20 << 2 = 80
    20을 2진수로 변환해서 (왼쪽으로 2칸 이동해라).
    0001 0100 -> 0101 0000
    20 << 3 = 160
    20을 2진수로 변환해서 (왼쪽으로 3칸 이동해라).
    0001 0100 -> 1010 0000
    20 << 4 = 32
    20을 2진수로 변환해서 (왼쪽으로 4칸 이동해라).
    0001 0100 -> 0001 0100 0000

    ** A << B = A * 2^B **

    20 >> 2 = 10
    0001 0100 -> 0000 1010

    20 >> 2 = 5
    0001 0100 -> 0000 0101

    20 >> 3 = 2
    0001 0100 -> 0000 0010

    ** A >> B = A % 2^B **
   
    */
    int iHigh = 187;
    int iLow = 13560;
    
    int iNumber = iHigh;
    // 현재 iNumber 에는 iHigh값이 있으며, 이값을 << 방향으로 16비트 이동시키면?
    iNumber <<= 16;
    // 하위 16비트를 iLow로 채운다.
    iNumber |= iLow;
 
    // High 값만 출력
    cout << "High :  " <<(iNumber >> 16) << endl;
    // Low 값만 출력
    cout << "Low :  " <<(iNumber & 0x0000ffff) << endl;     

    // 증감 연산자 : ++.-- 가 있다. 1증가, 1감소
    iNumber = 10;
    // 전치
    ++iNumber;
    // 후치
    iNumber++;
    cout << iNumber << endl;
    cout << iNumber++ << endl;
    cout << iNumber << endl;
    return 0;
}