#include<iostream>
#include<string.h>
using namespace std;
void test1(){
    size_t strlen(const char*s);
    // 测量字符串函数
    char str1[128] = "hello";
    cout<<strlen(str1)<<endl;
    char str2[128] = "he\0llo";
    cout<<strlen(str2)<<endl;
    // 字符串拷贝
    // strcpy,strncpy
    char dst[128]="";
    char src[]="hello\0world";
    strcpy(dst,src);
    cout<<dst<<endl;
    
    char dst1[]="";     // dst1只有1字节，当src1拷贝到dst1中，造成溢出
    char src1[]="helloworld";
    strcpy(dst1,src1);  // 污染内存
    cout<<dst1<<endl;
}

void test2(){
    // 字符串拼接
    char dst[128]="hello ";     // dst1只有1字节，当src1拷贝到dst1中，造成溢出
    char src[]="world";
    strcat(dst,src);  // 污染内存
    cout<<dst<<endl;
}
void test3(){
    // 字符串比较
    char str1[128] = "";
    char str2[128] = "";
    cout<<"请输入第一个字符串";
    cin>>str1;
    cout<<"请输入第二个字符串";
    cin>>str2;
    if(strcmp(str1,str2)>0){
        cout<<str1<<"大于"<<str2<<endl;
    }
    else if (strcmp(str1,str2)<0) {
        cout<<str1<<"小于"<<str2<<endl;
    }
    else if(strcmp(str1,str2)==0){
        cout<<str1<<"等于"<<str2<<endl;
    }
}
int main(int argc, char *argv[]){
    test1();
    test2();
    test3();
    return 0;
}
