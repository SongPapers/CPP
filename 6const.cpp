#include<iostream>
using namespace std;

void consttest(){
    // const修饰普通变量为只读变量，只能被初始化，不能被赋值
    const int data=100;
    // data = 100;
    int *p=(int *)&data;
    *p = 2000;
    cout<<"*p="<<*p<<endl;
    cout<<"data="<<data<<endl;
    // 变量初始化,自定义类型变量，没有符号常量表
    int a = 10;
    const int data0 = a;
        int *p0=(int *)&data0;
    *p0 = 2000;
    cout<<"*p="<<*p0<<endl;
    cout<<"data="<<data0<<endl;
}
int main(){
    consttest();
    return 0;
}
