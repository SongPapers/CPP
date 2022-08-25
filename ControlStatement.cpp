#include<iostream>
#include<bitset>
using namespace std;

void useswitchcase(){
    int data = 10;
    // 表达式只能是整型和字符char
    switch (data%3) {
        case 1:
            cout<<data<<"对3的余数为1"<<endl;
            break;
        case 2:
            cout<<data<<"对3的余数为2"<<endl;
            break;
        default:
            cout<<data<<"对3的余数为0"<<endl;
            break;
    }
    // 1-100求和
    int i = 0;
    int sum;
    for(i=1,sum=0;i<=100;i++){
        sum += i;
    }
    cout<<"sum="<<sum<<endl;

    // 九九乘法表
    int j=0;
    for(j=1;j<10;j++){
        for(i=1;i<=j;i++){
            cout<<i<<"*"<<j<<"="<<j*i<<"\t";
        }
        cout<<endl;
    }

    // while 求100 和
    i = 1;
    sum = 0;
    while(i<=100){
        sum+=i;
        i++;
    }
    cout<<sum<<endl;

    i = 1;
    sum = 0;
    do{
        sum+=i;
        i++;
    }while(i<=100);
    cout<<sum<<endl;
}

int main(){
    useswitchcase();
    return 0;
}
