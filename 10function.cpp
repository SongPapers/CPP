#include<iostream>
using namespace std;

void inputIntArray(int arr[], int n);
void sortIntArray(int arr[], int n);
void printIntArray(int arr[], int n);
void IntArrayfunc(){
    int arr[5]={0};
    int n = sizeof(arr)/sizeof(arr[0]);
    // 获取键盘输入
    inputIntArray(arr, n);

    // 对数组排序
    sortIntArray(arr, n);

    // 遍历
    printIntArray(arr, n);
}

void inputIntArray(int arr[], int n){
    cout<<"请输入"<<n<<"个int数据："<<endl;
    int i=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
    } 
    return ;
}

void sortIntArray(int arr[], int n){
    int i=0;
    for(i=0;i<n;i++){
        int j=0;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return ;
}

void printIntArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

void myGetString(char str[], int n);
int myStrlen(char str[]);

void CharArrayfunc(){
    char str[128] = "";
    // 键盘获取字符串
    myGetString(str, sizeof(str));
    // 测量字符串长度
    cout<<"长度："<<myStrlen(str)<<endl;
}

void myGetString(char str[], int n){
    cout<<"请输入一个字符串";
    cin.getline(str, n);
}

int myStrlen(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
int main(int argc, char*argv[]){
    IntArrayfunc();
    CharArrayfunc();
    return 0;
}
