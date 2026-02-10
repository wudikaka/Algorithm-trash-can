#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main() 
{
    system("chcp 65001 > nul"); // 设置控制台为UTF-8编码
    SetConsoleOutputCP(65001); // 支持中文输出
    
    cout<<"aaaaaaaa1111222333"<<endl;

    system("pause");
    return 0;
}