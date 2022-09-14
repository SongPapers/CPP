#include<iostream>
#include<string.h>
using namespace std;

// C++ 申请空间 初始化new 释放空间delete

// Person *person = new Person;

// 动态对象数组
class Person{
    public:
        Person(){
            pName = NULL;
            mAge = 0;
        }
        Person(char* name, int age){
            pName = new char[strlen(name) + 1];
            strcpy(pName, name);
            mAge = age;
        }
        ~Person(){
            if(pName != NULL){
                delete[] pName;
            }
        }
    public:
        char *pName;
        int mAge;
};

void test(){
    // 栈聚合初始化
    Person person[] = {Person("johm", 20), Person("Smith", 30)};
    cout << person[1].pName << endl;
    // 创建堆上对象数组必须提供构造函数
    Person *workers = new Person[20];
    delete[] workers;
}
int main(int argc, char *argv[]){
    test();
    return 0;
}