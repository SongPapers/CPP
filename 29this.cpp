#include<iostream>
using namespace std;
/*
C++ 实现了“封装”，“数据”和处理数据的操作（函数）是分开存储的

变量和函数是分开存储的

1. 非静态数据成员直接内含在对象中，
2. 成员函数虽然含在class中，却不出现在对象中，
3. 每一个非内联函数成员函数只会诞生在一份函数实例
*/


// 通过this指针指向被调用的成员函数所属的对象
// 可通过this指针知道操作的是哪个对象的数据，
// this 是一种隐含指针，无需定义

class Data1
{
public:
    int a;
public:
// 函数形参和成员同名可以使用this指针解决
    Data1(int a)
    {
        this->a = a;
        cout << this << endl;
    }

// this来完成链式操作
    Data1& myPrintf(char *str)
    {
        cout << str << " ";
        return *this;   // 返回调用该成员函数的对象
    }
};
void test1(){
    Data1 ob1(10);
    cout << ob1.a << endl;
    cout << &ob1 << endl;
}

void test2(){
    Data1(10).myPrintf("hehe").myPrintf("haha").myPrintf("xixix");
}

// const 修饰成员函数
/*
用const修饰的成员函数时，const修饰this指针指向的内存区域，成员函数体内不可以修改本类中的任何普通成员变量，
当成员变量类型符前用mutable修饰时例外
*/

class Data{
public:
    int a;
    int b;
    mutable int c;
public:
    Data(int a, int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    // const 修饰成员函数为只读（该成员函数不允许对 成员数据 赋值）
    // mutable修饰的成员除外
    void showData(void) const {
        // a = 100; // err
        c = 100;
        cout << a << " " << b << " " << endl;
    }
};


void test3(){
    Data ob1(10, 20, 30);
    ob1.showData();
}
int main(){
    test1();
    test2();
    test3();
    return 0;
}
