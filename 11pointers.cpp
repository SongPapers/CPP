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
void setNum01(int data){
    data = 100;
}
void setNum02(int *p){
    *p = 100;
}
// 指针函数作为函数参数
void test3(){
    int num=0;
    // 单向传递：传值
    setNum01(num);
    cout<<"num="<<num<<endl;    // 修改失败
    // 单向传递：传地址
    setNum02(&num);
    cout<<"num="<<num<<endl;    // 修改成功
}

// 一维数组做函数参数, 会被编译器，优化为 指针变量
void outputIntArray(int*arr, int n){
    cout<<"内部sizeof(arr)="<<sizeof(arr)<<endl;
    int i=0;
    for(i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

void outputIntArray1(int arr[6], int n){
    cout<<"内部sizeof(arr)="<<sizeof(arr)<<endl;
    int i=0;
    for(i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
// 一维数组做函数参数, 会被编译器，优化为 指针变量
void test4(){
    int arr[5] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"外部sizeof(arr)="<<sizeof(arr)<<endl;
    // 遍历数组
    outputIntArray(arr, n);
    outputIntArray1(arr, n);
}

void outputIntArray3(int arr[3][4], int row, int col){
    cout<<"内部sizeof(arr)="<<sizeof(arr)<<endl;
}
void outputIntArray4(int (*arr)[4], int row, int col){
    cout<<"内部sizeof(arr)="<<sizeof(arr)<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
// 二维的数组作为函数参数，会被优化成一维的数组指针
void test5(){
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int row = sizeof(arr)/sizeof(arr[0]);
    int col = sizeof(arr[0])/sizeof(arr[0][0]);
    cout<<"外部sizeof(arr) = "<<sizeof(arr)<<endl;
    outputIntArray3(arr, row, col);
    outputIntArray4(arr, row, col);
}

// 函数指针作为函数参数
int* getAddr(void){
    // int data = 100;
    // 不要返回局部变量的地址
    static int data = 100;
    return &data;
}

void test6(){
    int *p = NULL;
    p = getAddr();
    // 此处有段错误
    cout<<"*p = "<<*p<<endl;
}

// 函数指针
int myAdd(int x, int y);
void test7(){
    // 函数指针
    int (*p)(int x, int y) = NULL;
    cout<<"sizeof(p) = "<<sizeof(p)<<endl;
    // 函数指针 和 函数入口建立联系
    p = myAdd;
    // 通过p调用myAdd函数（函数+（实参））
    cout<<p(10, 20)<<endl;
    // ******p会被优化为p
    cout<<(***p)(10, 20)<<endl;
}
void test8(){
    // 给函数指针取别名
    typedef int (*FUN_TYPE)(int x, int y);
    FUN_TYPE p = NULL;

    cout<<"sizeof(p) = "<<sizeof(p)<<endl;
    // 函数指针 和 函数入口建立联系
    p = myAdd;
    // 通过p调用myAdd函数（函数+（实参））
    cout<<p(10, 20)<<endl;
    // ******p会被优化为p
    cout<<(***p)(10, 20)<<endl;
}

// 目的：让算法功能多样化
int myAdd(int x, int y){
    return x+y;
}
int mySub(int x, int y){
    return x-y;
}
int myMul(int x, int y){
    return x*y;
}
int myDiv(int x, int y){
    return x/y;
}
// 设计一个算法 操作上面的函数
int myCalc(int x, int y, int (*func)(int, int)){
    return func(x,y);
}

void test9(){
    cout<<myCalc(10, 20 ,myAdd)<<endl;
    cout<<myCalc(10, 20 ,mySub)<<endl;
    cout<<myCalc(10, 20 ,myMul)<<endl;
    cout<<myCalc(10, 20 ,myDiv)<<endl;
}

int main(int argc, char *argv[]){
    // pointsize();
    // test();
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    test8();
    test9();
    return 0;
}
