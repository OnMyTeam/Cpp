// Chapter06 if��(�б⹮)

#include <iostream>

using namespace std;

/*
�б⹮���� 2���� ������ �ִ�!
1. if�� : ������ üũ�� �ִ� ���
   ���� : if(���ǽ�){}(�ڵ��)
   Ư¡ : ���ǽ��� true�� �� ��쿡�� �ڵ�� ���� �ڵ尡 ����ȴ�. false�� ��� ���� �ȵ�
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
        cout << "�� �Դϴ�." << endl;
    }
    // if�� �Ʒ��� �� �ڵ尡 1���� ��� {}(�ڵ��)�� ���� �� �� �ִ�.
    if((iBuf & iAttack) != 0)
        cout << "Attack  ������ �ֽ��ϴ�." << endl;    
    if((iBuf & iArmor) != 0)
        cout << "Armor ������ �ֽ��ϴ�." << endl;
    if((iBuf & iHP) != 0)
        cout << "HP ������ �ֽ��ϴ�." << endl;
    if((iBuf & iMP) != 0)
        cout << "MP ������ �ֽ��ϴ�." << endl;
    if((iBuf & iCritical) != 0)
        cout << "iCritical ������ �ֽ��ϴ�." << endl;      
        
    /*
    else : if���� �ݵ�� ���� ��� �Ǿ�� �Ѵ�.
    if���� ������ false�� ��� else�� �ִٸ� else ���� ���� �ڵ尡 ���۵ȴ�.

    else if : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
    if�� �Ʒ��� �;� �ϰ� else���ٴ� ���� �־�� �Ѵ�.
    else if�� �ڽ��� ���� �ִ� ���ǽ��� false�� ��� ���� else if�� ���ǽ��� üũ�Ѵ�.
    else if�� ��� ����� �����ϴ�.
    
     */            
    int iNumber;       
    cout << "���ڸ� �Է��ϼ���. : "       ;
    cin >> iNumber;

    if (10 <= iNumber && iNumber <=20)
        cout << "10 ~ 20�� �����Դϴ�." << endl;

    else if (21 <= iNumber && iNumber <=30)
        cout << "21 ~ 30�� �����Դϴ�." << endl;
    else
        cout << "�� ������ ����." << endl;
    return 0;
}