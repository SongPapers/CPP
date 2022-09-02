#include<iostream>
#include<string.h>
using namespace std;

// 拷贝构造函数
class Data{
    public:
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
    // 拷贝构造函数
        // Data(const Data &ob){
        //     mA = ob.mA;
        //     cout<<"拷贝构造函数"<<endl;
        // } 
    // 析构函数
        ~Data(){
            cout<<"析构函数 mA = "<<mA<<endl;
        }
};

// 拷贝构造函数：旧对象 初始化 新对象才会调用的拷贝构造
// 编译器会提供给一个默认的拷贝构造
void test1(){
    Data ob1(10);
    // 会发现缺少一个ob2构造函数
    Data ob2 = ob1;
    cout<<"ob2.mA = "<<ob2.mA<<endl;
}

// 如果用户定义了拷贝构造函数或者有参构造，都会屏蔽无参构造
// 如果用户定义了无参构造或者有参构造，不会屏蔽拷贝构造

// 拷贝构造几种调用形式
// 1. 旧对象给新对象初始化，调用拷贝构造
    // Data ob1(10);
    // Data ob2 = ob1; // 调用拷贝构造

// 2. 给对象取别名 不会调用拷贝构造
    // Data ob1(10);
    // Data &ob2 = ob1;    // 不会调用拷贝构造

// 3. 普通对象作为函数参数 调用函数时 会发生拷贝构造
    // void func (Data ob){    // Data ob = ob1

    // }
    // void test2(){
    //     Data ob1(100);  // 有参构造
    //     func(ob1);      // 拷贝构造
    // }

// 4. 函数返回值普通对象
// visual sutdio 会发生
    // Data getObject(void){
    //     Data ob1(10);
    //     return ob1;
    // }
    // void test3(){
    //     Data ob2 = getObject(); // 拷贝构造发生在 匿名对象 匿名对象在栈区临时区域
    // }

// Qtcreater linux 
// 不会创建匿名对象

// 拷贝构造 深拷贝
// 默认拷贝函数都是浅拷贝
// 类中没有指针成员，不用实现拷贝和析构函数
// 如果类中有指针成员，且指向堆区空间， 必须实现析构函数释放指针成员指向的堆区空间，必须实现拷贝构造完成深拷贝动作
// 不能浅拷贝，会出现内存多次释放的问题，必须深拷贝
class Data5{
    public:
        char *name;
    public:
    // 无参构造函数
        Data5(){
            name = NULL;
            cout<<"无参构造函数"<<endl;
        }
        Data5(char *str){
            name = new char[strlen(str)+1];
            strcpy(name, str);
            cout<<"有参构造函数name = "<<name<<endl;
        }
    // 拷贝构造函数 深拷贝
        Data5(const Data5 &ob){
            // 为对象的指针成员申请独立的空间
            name = new char[strlen(ob.name)+1];
            strcpy(name, ob.name);
            cout<<"拷贝构造函数name = "<<name<<endl;
        } 
    // 析构函数
        ~Data5(){
            cout<<"析构函数 name = "<<name<<endl;
            if (name!=NULL) {
                delete [] name;
                name = NULL;
            }
        }
};
void test4(){
    Data5 ob("lucy");
}

int main(){
    test1();
    return 0;
}
