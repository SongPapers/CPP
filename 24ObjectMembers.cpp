#include<iostream>
using namespace std;

class A{
    public:
        int mA;
    public:
    A(){
        cout << "A类无参构造" << endl;
    }
    A(int a){
        cout << "A类有参构造" << endl;
    }
    ~A(){
        cout << "A类析构函数" << endl;
    }
};

class B{
    public:
        int mB;
        A ob;   // 对象成员
    public:
    B(){
        cout << "B类无参构造" << endl;
    }
    // 初始化列表,调用有参构造
    B(int a, int b):ob(a){
        mB = b;
        cout << "B类有参构造" << endl;
    }
    ~B(){
        cout << "B类析构函数" << endl;
    }
};

// 想调用有参
int main(int argc, char *argv[]){
    // B ob1;
    B ob2(10, 20);
    return 0;
}