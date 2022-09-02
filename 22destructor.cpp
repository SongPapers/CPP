#include<iostream>
#include<string.h>
using namespace std;

// 构造函数：初始化 析构函数：清理
// 编译器默认给有空的析构函数
// 类中有指针成员，必须写析构函数
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
            cout<<"有参构造函数"<<mA<<endl;
        }
    // 析构函数
        ~Data(){
            cout<<"析构函数 mA = "<<mA<<endl;
        }
};
Data ob1(10);
void test1(){
    Data ob2(20);
    {
        Data ob3(30);
    }
    Data(40);
}


class Data2{
    public:
        char *name;
    public:
        Data2(){
            name = NULL;
        }
        Data2(char *str){
            name = new char[strlen(str)+1];
            strcpy(name, str);
            cout<<"有参构造"<<endl;
        }
        ~Data2(){
            if(name != NULL){
                delete [] name;
                cout<<"析构函数"<<endl;
            }
        }
};

void test2(){
    Data2 ob("hello world");
    cout<<ob.name<<endl;
}
int main(){
    test1();
    test2();
    return 0;
}
