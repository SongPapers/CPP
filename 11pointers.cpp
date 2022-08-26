#include<iostream>
using namespace std;
void pointsize(){
    // 32平台任何类型的指针变量都是 4 字节
    cout<<sizeof(char *)<<endl;
    cout<<sizeof(short *)<<endl;
    cout<<sizeof(long *)<<endl;
    cout<<sizeof(int *)<<endl;
    cout<<sizeof(float *)<<endl;
    cout<<sizeof(double *)<<endl;
    cout<<sizeof(int ********)<<endl;
}

void test(){
    // 指针不初始化，，回报错
    // int *p;
    // cout<<*p<<endl;  // 会出现段错误
    int *q=NULL;
    cout<<"----001-----"<<endl;
    cout<<*q<<endl;

}

void test1(){

    int num = 0x01020304;
    int *p1 = &num;
    cout<<hex<<*p1<<endl;
    short *p2 = (short *)&num;  // 0x0304
    cout<<hex<<*p2<<endl;
    char *p3 = (char *)&num;  // 0x0304
    cout<<hex<<(int)*p3<<endl;
}

void test2(){
    int num = 0x01020304;
    // 取出0x0102的值
    short *p1 = (short *)&num;
    cout<<*(p1+1)<<endl;
    // 取出0x02的值
    char *p2 = (char*)&num;
    cout<<(int)*(p2+2)<<endl;
    // 取出0x0203的值
    char *p3 = (char*)&num;
    cout<<*(short *)(p3+1)<<endl;
    // 万能指针
    void *p4;
}
int main(int argc, char *argv[]){
    pointsize();
    // test();
    test1();
    test2();
    return 0;
}
