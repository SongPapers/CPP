#include<iostream>
#include<bitset>
using namespace std;

void casecalculate(){
    short data1 = -10;
    cout<<bitset<16>(data1)<<endl;
    short data2 = 6;
    cout<<bitset<16>(data2)<<endl;
    short data3 = 0x8080;
    cout<<bitset<16>(data3)<<endl;
    unsigned short data = -10;
    cout<<bitset<16>(data)<<"data="<<data<<endl;


}
int main(){
    casecalculate();
    return 0;
}
