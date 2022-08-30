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

int main(int argc, char *argv[]){
    test1();
    test2();
    // test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
