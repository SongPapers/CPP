// 单例模式
// 这个类只能实例化一个对象
#include <iostream>
using namespace std;

// 单例模式
class SingleTon
{
    // 1. 防止该类在外界实例化对象 构造函数私有化
private:
    SingleTon() {}
    SingleTon(const SingleTon &ob) {}
    ~SingleTon() {}

private:
    // 2. 定义一个静态的指针变量保存唯一一个实例的地址
    static SingleTon * const p;
    int num;

public:
    // 3. 获得唯一的实例地址
    static SingleTon * getSingleTon(void){
        return p;
    } 
    // 4. 用户定义的没任务函数
    void printString(char *str){
        cout<<"打印："<<str<<endl;
    }
};
SingleTon *const SingleTon::p = new SingleTon;

int main(int argc, char *argv[])
{
    SingleTon *p1 = SingleTon::getSingleTon();
    p1->printString("离职证明1");
    p1->printString("学历证明1");
    p1->printString("学位证明1");
    p1->printString("身份证明1");

    SingleTon *p2 = SingleTon::getSingleTon();
    p2->printString("离职证明2");
    p2->printString("学历证明2");
    p2->printString("学位证明2");
    p2->printString("身份证明2");
    
    return 0;
}
