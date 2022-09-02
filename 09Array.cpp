#include<iostream>
#include<bitset>
using namespace std;

void array(){
    // int arr[5](int, int);
    int arr[5];
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    // 初始化
    int a[5] = {1,2,3,4,5};
    int b[] = {10,20,30,40,50,60};
    // 部分初始化,自动补零
    int c[5] = {1,2,3};
    int d[5] = {0};
    // 下标初始化
    // int e[5] = {[2]=10, [3]=50};
}
void array1(){
    // int arr[5](int, int);
    int arr[5]={0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    cout<<arr[2]+1<<endl;
}  
void forprint(int arr[][4]){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
void array2(){
    // int arr[5](int, int);
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12,}};
    int arr1[][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr2[3][4] = {{1,2,},{5,6},{9,10,11}};
    int arr3[3][4] = {1,2,5,6,10,11};

    forprint(arr);
    forprint(arr1);
    forprint(arr2);
    forprint(arr3);
}  
void CharArray(){
    char arr[6] = "hello";
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    cout<<endl;
    char arr1[] = "hello wa";
    cout<<"arr1="<<arr1<<endl;

    char arr2[] = "hel\0lo";
    cout<<arr2<<endl;

    char str[16] = "";
    cout<<"Input a string:"<<endl;
    cin.getline(str, sizeof(str));
    int i=0;
    while(str[i]!='\0'){
        cout<<str[i];
        i++;
    }
}
void CharArray2(){
    char arr[5][128] = {"hello","world","hehehe","xixix","lalalala"};
    int row = sizeof(arr)/sizeof(arr[0]);

    int i ;
    for(i=0;i<row;i++){
        cout<<arr[i]<<endl;
    }

    char arr1[5][128] = {""};
    row = sizeof(arr1)/sizeof(arr1[0]);
    for(i=0;i<row;i++){
        cout<<arr1[i]<<endl;
    }
}
int main(){
    array();
    array1();
    array2();
    CharArray();
    CharArray2();
    return 0;
}
