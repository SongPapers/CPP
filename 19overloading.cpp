#include<iostream>
using namespace std;

// 重载 用一个函数名，代表不同的函数功能
// 函数返回值不能作为重载条件，禁止
void test1(){
    int a = 10;
    // 需求：给变量a取个别名叫b
    int &b = a; // 引用必须初始化 &引用说明符
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

// 函数的默认参数
// 默认参数和函数重载 同时出现，注意二义性

// 占位参数
// void func(int, int=20)

// C++ 调用C语言

#if __cplusplus
extern "C"{
#endif
    void func1();
    void func1(){
        printf("Hello world");
    }

#if __cplusplus
}
#endif


int main(){
    test1();
    func1();
    return 0;
}
