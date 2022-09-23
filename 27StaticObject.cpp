#include <iostream>
using namespace std;

// 静态成员static
class Data
{
private:
    int data;
    static int c;

public:
    int a;
    // 静态成员，共享一份静态数据
    static int b;
    static int getC()
    {
        // 静态成员韩叔叔 只能操作 静态成员数据 而data为普通成员数据
        // data = 10;
        return c;
    }


};
// 类外初始化
int Data::b = 100;

void test1()
{
    // 静态成员数据 通过类名称直接访问（属于类）
    cout << Data::b << endl;

    // 静态成员数据 通过对象访问（共享）
    Data ob1;
    cout << ob1.b << endl;
    ob1.b = 200;
    Data ob2;
    ob2.b = 300;
    cout << Data::b << endl;
}

int main()
{
    test1();
    return 0;
}
