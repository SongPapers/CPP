#include<iostream>
using namespace std;
void fun1(){
    cout<<"fun1"<<endl;
}

void test1(){
    int a = 10;
    // 需求：给变量a取个别名叫b
    int &b = a; // 引用必须初始化 &引用说明符
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"&a = "<<&a<<endl;
    cout<<"&b = "<<&b<<endl;
    // 操作b等于操作a
    b = 100;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    // 数组引用
    int arr[5] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);

    int (&myarr)[5] = arr;
    for(int i=0;i<n;i++)
        cout<<myarr[i]<<" ";
    cout<<endl;
    // 指针变量的引用
    int num = 10;
    int *p = &num;
    int *(&myp) = p;
    cout<<"*p = "<<*p<<endl;
    cout<<"*myp = "<<*myp<<endl;
    // 函数的引用
    void (&myfun)(void) = fun1;
    myfun();
}

// 引用作为函数的参数
// 函数内部通过引用操作外部函数
void swap1(int *p1, int *p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void swap2(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}
void test2(){
    int a = 10, b = 20;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap2(a,b);
    cout<<"a = "<<a<<", b = "<<b<<endl;
}

// 引用作为函数的返回值
int &getData(void){
    int num = 10;
    // 不要返回局部变量的引用, 会出现段错误
    return num; // 返回num，函数调用的结果 就是num的别名
}
void test3(){
    // b是num别名
    int &b = getData();
}
// 返回值类型作为引用 可以完成链式操作
struct Stu{
    Stu printStu(Stu &ob, int value){
        cout<<value<<" ";
        return ob;
    }
};
void test4(){
    Stu ob1;
    ob1.printStu(ob1, 100).printStu(ob1, 200).printStu(ob1, 300);   // 100 200 300
}

// 常引用 防止函数内部修改外部的值
void printInt(const int &a){
    cout<<"a = "<<a<<endl;
}
void test5(){
    // int &a = 100; 错误
    const int &a = 100;
    int b = 100;
    printInt(b);
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
