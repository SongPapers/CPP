#include<iostream>
using namespace std;

// 内联函数
// 在编译阶段，将内联函数中的函数体 替换函数调用处，避免函数调用的开销
// 是否 内联由编译器决定
int myadd(int, int);
void test1(){
    int a = 10;
    // 需求：给变量a取个别名叫b
    int &b = a; // 引用必须初始化 &引用说明符
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}
inline int myadd(int a, int b){
    return x+y;
}
int main(){
    test1();
    return 0;
}
