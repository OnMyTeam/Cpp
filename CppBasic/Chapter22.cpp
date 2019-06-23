// Chapter22 파일입출력
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    FILE* pFile = NULL;
    // 1번 인자 : 파일의 이중포인터
    // 2번 인자 : 파일 경로이다. 파일이 생성되는 기준 경로는 현재 프로젝트가 있는 폴더 기준. exe가 있다면 그 파일이 있는 위치
    // 3번 인자 : 모드인데, 파일 읽기, 쓰기, 접근이 있으며 파일 형태, 텍스트 파일, 바이너리 파일로 합쳐서 씀
    // r : 읽기, w: 쓰기, a  : 접근         t: 텍스트파일   b:  바이너리 파일
    //fopen_s(&pFile,)
    pFile = fopen("test.txt","w");
    if(pFile != NULL)
    {
        // fwrite, fread 2개의 함수가 제공된다.
        char *pText = "abcd";
        // 1번인자는 저장하고자 하는 값의 메모리 주소를 넣어준다.
        // 2번인자는 저장하고자 하는 값의 변수타입의 메모리 크기를 넣어준다.
        // 3번인자는 저장하고자 하는 문자열의 개수를 넣어준다.
        // 4번인자는 저장할 파일의 스트림을 넣어준다.
        fwrite(pText, 1, 4, pFile);
        fclose(pFile);
        cout << "파일 생성 완료 " << endl;

    }

    // ======================= 파일 읽어보자 ==============================

    pFile = fopen("text.txt","rt");
    if(pFile)
    {
        char strText[5] = {};
        fread(strText, 1, 4, pFile);
        cout << strText << endl;
    }

    return 0; 
} 