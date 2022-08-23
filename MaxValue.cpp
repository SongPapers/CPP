#include<iostream>
using namespace std;

// 定义两个变量，求最大值
int main(){
    int a,b;
    cout<< "获取两个变量"<<endl;
    cin>>a>>b;
    if(a>b){
        cout<<"max value:"<<a<<endl;
    }
    else {
        cout<<"max value:"<<b<<endl;
    }
    return 0;
}
