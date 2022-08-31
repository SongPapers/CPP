#include<iostream>
#include<string.h>
using namespace std;

// 静态链表
struct Stu{
    // 数据域
    int mun;
    char name[32];
    // 指针域
    struct Stu *next;
};
void test1(){
    struct Stu node1 = {101, "lucy", NULL};
    struct Stu node2 = {102, "bob", NULL};
    struct Stu node3 = {103, "tom", NULL};
    struct Stu node4 = {104, "德玛", NULL};
    struct Stu node5 = {105, "小法", NULL};
    // 定义链表头
    struct Stu *head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    struct Stu *pb = head;
    while (pb!=NULL) {
        // 访问数据
        cout<<pb->mun<<" "<<pb->name<<endl;
        // 移动到下一个节点
        pb = pb->next;
    }
}

// 动态链表
// 学生管理系统

int main(int argc, char *argv[]){
    test1();
    return 0;
}
