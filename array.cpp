#include "array.h"
#include <string.h>

Array::Array()
{
    capacity = 5;
    size = 0;
    arr = new int[capacity];
    // 空间清零
    memset(arr, 0, sizeof(int) * capacity);
}

Array::Array(int capacity)
{
    this->capacity = capacity;
    size = 0;
    arr = new int[capacity];
    // 空间清零
    memset(arr, 0, sizeof(int) * capacity);
}

Array::Array(const Array &ob)
{
    capacity = ob.capacity;
    size = ob.size;

    // 深拷贝
    arr = new int[capacity];
    memcpy(arr, ob.arr, sizeof(int) * capacity);
}

Array::~Array()
{
    if (arr != NULL)
    {
        delete[] arr;
        arr = NULL;
    }
}

int Array::getCapacity(void)
{
    return capacity;
}

int Array::getSize(void)
{
    return size;
}

void Array::printArray(void)
{
    int i = 0;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 尾部插入数据
void Array::pushBack(int elem)
{
    // 判断容器是否满
    if (size == capacity)
    {
        // 申请空间，另辟空间，不要后面追加，因为不知道后面够不够
        int *tmp = new int[2 * capacity];
        memset(tmp, 0, sizeof(int) * 2 * capacity);
        // 将旧空间内容 拷贝到新空间中
        memcpy(tmp, arr, size * sizeof(int));
        // 释放旧空间
        delete[] arr;
        // 让arr指向新空间
        arr = tmp;
        // 更新容量
        capacity = 2 * capacity;
    }
    arr[size] = elem;
    size++;
}
// 尾部删除元素
void Array::popBack(void)
{
    if (size == 0)
    {
        cout << "容器为空" << endl;
    }
    else
    {

        size--;
        arr[size] = 0;
    }
}
// 查看某个元素
int &Array::at(int pos)
{
    if (pos < 0 || pos >= size)
    {
        cout << "位置无效" << endl;
        exit(-1);
    }
    return arr[pos];
}