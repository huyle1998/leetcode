#include <iostream>
#include <string>

void* operator new(size_t size)
{
	return malloc(size);
}

struct Object
{
	int x, y, z;
};
 
int main(int argc, char** argv)
{
	std::string str = "HuyLe";
	Object* obj = new Object;
	return 0;
}