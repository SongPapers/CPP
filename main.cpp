#include <iostream>
#include"array.h"
using namespace std;

int main(int argc, char *argv[])
{
	Array ob;
	cout<<"容量："<<ob.getCapacity()<<",大小："<<ob.getSize()<<endl;
	ob.pushBack(10);
	ob.pushBack(20);
	ob.pushBack(30);
	ob.pushBack(40);
	ob.printArray();
	cout<<"容量："<<ob.getCapacity()<<",大小："<<ob.getSize()<<endl;
	
	ob.pushBack(50);
	ob.pushBack(60);
	ob.printArray();
	cout<<"容量："<<ob.getCapacity()<<",大小："<<ob.getSize()<<endl;

	ob.popBack();
	ob.popBack();
	ob.printArray();
	cout<<"容量："<<ob.getCapacity()<<",大小："<<ob.getSize()<<endl;

	cout<<"ar[2] = "<<ob.at(2)<<endl;
	ob.at(2) = 100;
	ob.printArray();
	return 0;
}