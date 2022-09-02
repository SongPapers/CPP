#include<iostream>
#include<bitset>
using namespace std;

#include<time.h>
void userand(){
    // 设置随机数种子, 默认为1
    // 获取当前是时间
    // srand(10);
    srand(time(NULL));
    // 产生随机数
    cout<<rand()<<endl;
}

void usebitwise(){
    // 位运算 按位与& 将指定位清零
    // 按位或 指定位 1
    // 按位取反 0变1  1变0 
    // 按位异或 和1异或取反 和0异或不变
    // 左移运算符：左边丢弃，右边补零
    // 右移运算符：右边丢弃，左边补零 逻辑右移（补1 算术右移）
    short data =-10;        // 1111 1111 1111 0110
    data = data>>4;
    // 0000 1111 1111 1111 逻辑右移
    // 1111 1111 1111 1111 算术右移
    cout<<bitset<16>(data)<<endl;
    // 三目运算符
    cout<<(10<20? 10:20)<<endl;
    int data1 = 10;
    int data2 = 20;
    (data1>data2?data1:data2) = 200;
    cout<<"data1="<<data1<<endl;
    cout<<"data2="<<data2<<endl;
}
int main(){
    userand();
    usebitwise();
    return 0;
}
