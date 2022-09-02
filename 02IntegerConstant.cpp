#include<iostream>
# include<bitset>
// 使用命名空间 std
using namespace std;

int main(int argc, char *argv[]){
    cout<<"Hello world!"<<endl;
    cout<<0b00001010<<endl;// 二进制
    cout<<0x0123<<endl; // 八进制
    cout<<0xab<<endl;   // 十六进制
    cout<<bitset<8>(0b00001010)<<endl;
    cout<<oct<<0123<<endl;
    cout<<hex<<0xab<<endl;
    return 0;
}
