#include<iostream>
#include<string.h>
using namespace std;

class Data{
    // 默认私有
private:
    int a;
protected:
    int b;
public:
    int c;
    void showData(void){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};

void test1(){
    Data ob;
    // cout<<ob.a<<endl; // 错误
    cout<<ob.c<<endl;
    ob.showData();
}
// 设计一个Person类
class Person{
private:
    char mName[32];
    int mAge;
public:
    // 初始化 
    void personInit(char *name, int age){
        strcpy(mName, name);
        if(age>0 &&age<=100){
            mAge = age;
        }
        else {
            cout<<"输入年龄："<<age<<"不合法"<<endl;
        }
    }
    // 设置mAge
    void setAge(int age){
        if(age>0 &&age<=100){
            mAge = age;
        }
        else{
            cout<<"输入年龄："<<age<<"不合法"<<endl;
        }
    }
    // 得到mAge
    int getAge(void){
        return mAge;
    }
    // 设置mName
    void setName(char *name){
        strcpy(mName, name);
    }
    // 得到mName
    char *getName(void){
        return mName;
    }
    // 显示年龄和姓名
    void showPerson(){
        cout<<"姓名："<<mName<<"， 年龄："<<mAge<<endl;
    }
};

void test2(){
    Person lucy;
    lucy.personInit("lucy", 18);
    lucy.setName("肉丝");
    lucy.setAge(16);
    cout<<lucy.getName()<<" "<<lucy.getAge()<<endl;
    lucy.showPerson();
}

// 设计立方体的类
class Cube{
private:
    int mL;
    int mW;
    int mH;
public:
    void cubeInit(int l, int w, int h){
        mL = l;
        mW = w;
        mH = h;
    }
    int getL(void){
        return mL;
    }
    int getW(void){
        return mW;
    }
    int getH(void){
        return mH;
    }
    int getS(void){
        return (mL*mW + mL*mH + mW*mH)*2;
    }
    int getV(void){
        return mL*mW*mH;
    }
    // 成员函数实现
    bool cubeCompare(Cube &ob){
        if(mL==ob.mL && mH==ob.mH && mW==ob.mW){
            return true;
        }
        else {
            return false;
        }
    }
};

// 全局函数实现， 立方体比较
bool cubeCompare1(Cube &ob1, Cube &ob2){
    if(ob1.getH() == ob2.getH() && ob1.getL() == ob2.getL() && ob1.getW() == ob2.getW()){
        return true;
    }
    else {
        return false;
    }
}
void test3(){
    Cube ob1;
    ob1.cubeInit(10,20,30);
    cout<<"面积："<<ob1.getS()<<endl;
    cout<<"体积："<<ob1.getV()<<endl;

    Cube ob2;
    ob2.cubeInit(10,20,30);
    // 全局函数 
    if(cubeCompare1(ob1,ob2)){
        cout<<"相等"<<endl;
    }
    else {
        cout<<"不相等"<<endl;
    }
    // 成员函数
    if(ob1.cubeCompare(ob2)){
        cout<<"相等"<<endl;
    }
    else {
        cout<<"不相等"<<endl;
    }
}
// 类外实现类的成员函数
class Data1{
    private:
        int mA;
    public:
        void setA(int a);
        int getA();
};
// 类外实现
void Data::setA(int a){
    mA = a;
}

int Data::getA(){
    return mA;
}
int main(){
    test1();
    test2();
    test3();
    return 0;
}
