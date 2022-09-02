#include<iostream>
using namespace std;

void CharValue(){
    char ch1='x';
    cout<<ch1<<endl;
    ch1 = 120;
    cout<<ch1<<endl;
    ch1 = 122;
    cout<<ch1<<endl;
    char ch2=0;
    cout<<ch2<<endl;
    char ch3=(char)0;
    cout<<ch3<<endl;
    char ch4='\0';
    cout<<ch4<<endl;
}

int main(){
    CharValue();
    return 0;
}
