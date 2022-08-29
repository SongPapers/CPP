#include<iostream>
using namespace std;

void test1(){
    int *p = NULL;
    p = new int;    // 从堆区申请int类型大小的空间
    *p = 100;
    cout<<"*p = "<<*p<<endl;
    // 释放空间
    delete p;

    // 申请空间的同时 初始化空间内容
    int *p1 = NULL;
    p1 = new int(100);
    cout<<"*p1 = "<<*p1<<endl;
    delete p1;

    // 操作数组空间
    int *arr = NULL;
    arr = new int[5]{10,20,30,40,50};

    int i=0;
    for(i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete [] arr;
}
int main(int argc, char *argv[]){
    test1();
    return 0;
}
