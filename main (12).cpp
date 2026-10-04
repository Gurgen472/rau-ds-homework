#include <iostream>
#include <cstring>
/*template <typename T>//1
void print(T value) {
	std::cout<<value<<std::endl;
}
template <>
void print<bool>(bool value) {
	if(value) {
		std::cout<<"True"<<std::endl;
	} else {
		std::cout<<"False"<<std::endl;
	}
}
template<>
void print<char*>(char* value) {
	std::cout << "\"" << value << "\"" << std::endl;
}

template <typename T>
bool isEqual(T a,T b) {

	return a==b;
}
template<>
bool isEqual<char*>(char* a,char* b) {
	return strcmp(a,b)==0;
}*/\
template <typename T>
T copyValue(T value) {
	return value;
}
template <typename T>
T* copyValue(T* value) {
	return new T(*value);
}




int main()
{
	/*print(10);//1
	print(3.14);
	print(true);
	print(false);
	char text[] = "Barev";
	print(text);

	std::cout<<isEqual(5,10)<<std::endl;//2
	std::cout<<isEqual(5,5)<<std::endl;
	std::cout<<isEqual(5.25,5.25)<<std::endl;
	char a[] = "Barev";
	char b[] = "Barev";
	char c[] = "Hajox";
	std::cout << isEqual(a, b) << std::endl;
	std::cout << isEqual(a, c) << std::endl;*/

	int a = 10;
	int b = copyValue(a);
	int* p = &a;
	int* q = copyValue(p);
	std::cout << b << std::endl;
	std::cout << *q << std::endl;

	delete q;
	return 0;
}