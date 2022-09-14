#include<iostream>
using namespace std;

// explicit 禁止通过构造函数进行的隐式转换，
// 声明为explicit的构造函数不能再隐式转换中使用
class MyString{
    public:
    explicit MyString(int n){
        cout << "MyString(int n)!" << endl;
    }
    MyString(const char* str){
        cout << "MyString(const char* str)!" << endl;
    }
};

// 类的对象数组
class A{
    public:
        int mA;
    public:
    A(){
        mA = 0;
        cout << "A类无参构造mA="<< mA << endl;
    }
    A(int a){
        mA = a;
        cout << "A类有参构造mA="<< mA << endl;
    }
    ~A(){
        cout << "A类析构函数mA="<< mA << endl;
    }
};

// 对象数组的每个元素都会调用构造函数和析构函数
void test1(){
    A arr1[5];
    A arr2[5] = {A(10), A(20), A(30), A(40), A(50)};
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int i = 0;
    for (i = 0; i < n;i++){
        cout << arr2[i].mA << " ";
    }
}

int main(int argc, char *argv[]){
    // 给字符串赋值还是初始化？
    // MyString str1 = 1;

    MyString str3 = "abcd";
    MyString str4("abcd");

    test1();
    return 0;
}