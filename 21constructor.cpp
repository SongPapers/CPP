#include<iostream>
#include<string.h>
using namespace std;

// 构造函数：初始化 析构函数：清理
class Data{
    private:
        int mA;
    public:
    // 无参构造函数
        Data(){
            mA = 0;
            cout<<"无参构造函数"<<endl;
        }

        Data(int a){
            mA = a;
            cout<<"有参构造函数"<<endl;
        }
};
void test1(){
    // 隐式调用无参构造函数（推荐）
    Data ob1;

    // 显示调用无参构造函数
    Data ob2 = Data();

    // 隐式调用有参构造函数（推荐）
    Data ob3(10);

    // 显示调用有参构造函数
    Data ob4 = Data(10);

    // 匿名对象（无参）当前语句技术 立即释放
    Data();
    Data(20);

    // 构造函数隐式转换（类中只有一个数据成员）
    Data ob5 = 100;
}

// 无构造函数时，系统提供一个空的无参构造函数
int main(){
    test1();

    return 0;
}
