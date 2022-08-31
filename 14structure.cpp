#include<iostream>
#include<string.h>
using namespace std;

// 先定义结构体，再定义结构体变量
// 定义结构体同时，定义结构体变量
// 定义一次性结构体
struct Stu{
    int num;
    char name[64];
};

void test1(){
    Stu lucy;
    cout<<lucy.num<<" "<<lucy.name<<endl;
    Stu haha={100, "haha"};
    cout<<haha.num<<" "<<haha.name<<endl;  
}

void test2(){
    Stu lucy={100, "lucy"};
    cout<<lucy.num<<" "<<lucy.name<<endl;
    // 清空整个结构体 string memset
    memset(&lucy, 0, sizeof(lucy));
    cout<<lucy.num<<" "<<lucy.name<<endl;
}

// 键盘输入结构体
void test3(){
    Stu lucy;
    memset(&lucy, 0, sizeof(Stu));
    cout<<"请输入学号，姓名;";
    cin>>lucy.num>>lucy.name;
    cout<<lucy.num<<" "<<lucy.name<<endl;
}
// 单个操作结构体成员
void test4(){
    Stu lucy = {100, "name"};
    lucy.num += 100;
    // name成员时数组名、位符号常量、不允许用=给name赋值
    // lucy.name = "bob" // 错误
    strcpy(lucy.name, "Bob");
    cout<<lucy.num<<" "<<lucy.name<<endl;
}
// 相同类型结构体变量之间的赋值
void test5(){
    Stu lucy = {100, "lucy"};
    Stu bob;
    // 第一种 逐个成员赋值
    bob.num = lucy.num;
    strcpy(bob.name, lucy.name);
    cout<<bob.num<<" "<<bob.name<<endl;
    // 第二种，相同类型结构体可以直接赋值
    Stu tom;
    tom = lucy;
    cout<<tom.num<<" "<<tom.name<<endl;
    // 第三种， 内存拷贝，是第二种的底层实现
    Stu jam;
    memcpy(&jam, &lucy, sizeof(Stu));
    cout<<jam.num<<" "<<jam.name<<endl;
}

// 结构体嵌套结构体
// struct Student{
//     int num;
//     char name[32];
//     Data ob;
// };
// lucy.ob.month

// 结构体数组
void test6(){
    Stu arr[5] = {{100,"lucy"}, {101,"bob"}, {102, "tom"}, {103, "德玛"}, {104, "小炮"}};
    // 清空数组
    // memset(arr, 0, sizeof(arr))
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    for (i=0; i<n; i++) {
        cout<<arr[i].num<<" "<<arr[i].name<<endl;
    }
}
void test7(){
    Stu arr[5];
    memset(arr, 0, sizeof(arr));
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    cout<<"请输入"<<n<<"个学员信息"<<endl;
    for (i=0; i<n; i++) {
        cin>>arr[i].num>>arr[i].name;
    }
    cout<<"----------"<<endl;
    for (i=0; i<n; i++) {
        cout<<arr[i].num<<" "<<arr[i].name<<endl;
    }
}

// 结构体指针变量
void test8(){
    Stu lucy = {100, "lucy"};
    Stu *p = &lucy;
    // *p
    cout<<"结构体指针变量"<<endl;
    cout<<lucy.num<<" "<<lucy.name<<endl;
    cout<<(*p).num<<" "<<(*p).name<<endl;
    cout<<p->num<<" "<<p->name<<endl;
    cout<<(&lucy)->num<<" "<<(&lucy)->name<<endl;
}
void inputStuArray(Stu *arr, int n){
    cout<<"请输入"<<n<<"个学生信息(num, name)"<<endl;
    for(int i=0;i<n;i++){
        cin>>(arr+i)->num>>(arr+i)->name;
    }
}

void sortStuArray(Stu *arr, int n){
    int i=0;
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if ((arr+j)->num > (arr+j+1)->num) {
                Stu tmp = *(arr+j);
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
void outputStuArray(Stu *arr, int n){
    for(int i=0;i<n;i++){
         cout<<(arr+i)->num<<" "<<arr[i].name<<endl;
    }
}
void test9(){
    Stu arr[5];
    memset(arr, 0, sizeof(arr));
    int n = sizeof(arr)/sizeof(arr[0]);

    // 封装函数获取键盘输入
    inputStuArray(arr, n);
    // 排序
    sortStuArray(arr, n);
    // 输出
    outputStuArray(arr, n);
}
// 结构体成员指针指向堆区
struct Stu1
{
    int num;
    char *name;
};
void test10(){
    Stu1 lucy;
    lucy.num = 100;
    lucy.name = new char [64];
    strcpy(lucy.name, "hello world");
    cout<<lucy.num<<" "<<lucy.name<<endl;
    delete [] lucy.name;
}

// 深拷贝浅拷贝
// 浅拷贝：将结构体变量空间内容 赋值一份 到另一个相同类型的结构体变量空间中
// 没有指针成员 不会有问题，如果有会存在问题
void test11(){
    Stu1 lucy;
    lucy.num = 100;
    lucy.name = new char [64];
    strcpy(lucy.name, "hello world");

    Stu1 bob;
    bob = lucy;

    cout<<bob.num<<" "<<bob.name<<endl;
    // 导致同一时间多次释放
    delete [] lucy.name;
    delete [] bob.name;
}
// 深拷贝：为指针成员 申请独立空间
void test12(){
    Stu1 lucy;
    lucy.num = 100;
    lucy.name = new char [64];
    strcpy(lucy.name, "hello world");

    Stu1 bob;
    bob.num = lucy.num;
    bob.name = new char[64];
    strcpy(bob.name, lucy.name);

    cout<<bob.num<<" "<<bob.name<<endl;
    delete [] lucy.name;
    delete [] bob.name;
}
// 结构体在堆区
void test13(){
    // 结构体在堆区
    Stu1 *p = new Stu1;
    // 结构体中指针成员指向堆区
    p->name = new char[32];
    // 赋值
    p->num = 100;
    strcpy(p->name, "hello world");
    cout<<p->num<<" "<<p->name<<endl;
    // 释放空间
    delete [] p->name;
    delete p;
}
// 结构体对齐规则
struct A{
    // 相邻位域压缩
    unsigned char a:2;
    unsigned char b:2;
    unsigned char c:4;
};

void test14(){
    cout<<"sizeof(A)"<<sizeof(A)<<endl;
    A ob;
    // 不能对位域取地址
    // &ob.a
    ob.a = 13;  // 13 0101
    cout<<"ob.a = "<<(int)ob.a<<endl;
}
struct B{
    // 相邻位域压缩
    unsigned char a:4;
    unsigned char :0;   // 另起一个存储单元
    unsigned char b:4;
};
struct C{
    // 相邻位域压缩
    unsigned char a:4;
    unsigned char :2;   // 无意义位段
    unsigned char b:2;
};
void test15(){
    cout<<"sizeof(B)"<<sizeof(B)<<endl;
    cout<<"sizeof(C)"<<sizeof(C)<<endl;
}
// 共用体
union Data{
    char a;
    short b;
    int c;
};

void test16(){
    Data ob;
    ob.a = 10;
    ob.b = 20;
    ob.c = 30;
    cout<<ob.a + ob.b + ob.c<<endl;
}
// 枚举
enum POKER_COLOR{HONGTAO, MEIHUA, FANGKUAI, HEITAO};
enum POKER_COLOR1{HONGTAO1, MEIHUA1=10, FANGKUAI1, HEITAO1};
void test17(){
    POKER_COLOR pc = HONGTAO;
    // 默认 0 1 2 3
    cout<<HONGTAO<<" "<<MEIHUA<<" "<<FANGKUAI<<" "<<HEITAO<<endl;
    // 修改 依次递增
    cout<<HONGTAO1<<" "<<MEIHUA1<<" "<<FANGKUAI1<<" "<<HEITAO1<<endl;
}
int main(int argc, char *argv[]){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    // test10();
    // test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    return 0;
}
