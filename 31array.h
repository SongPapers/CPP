#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
using namespace std;

class Array
{
private:
    int *arr;     // 存放数组首元素的地址
    int size;     // 大小
    int capacity; // 容量
public:
    Array();
    Array(int capacity);
    Array(const Array &ob);
    ~Array();

    int getCapacity(void);
    int getSize(void);
    void printArray(void);
    // 尾部插入数据
    void pushBack(int elem);
    // 尾部删除元素
    void popBack(void);
    // 查看某个元素
    int &at(int pos);
};

#endif
