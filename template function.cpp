#include <iostream>
#include <vector>

template <typename T> //1
void printElement(T value) {
	std::cout<<"Value: "<<value<<std::endl;
}
template <typename T>//2
void mySwap(T a,T b) {
	T temp;
	temp=a;
	a=b;
	b=temp;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
}
template <typename T>//3
T sumArray(T* arr,int size) {
	T sum=T();
	for(int i=0; i<size; ++i) {
		sum+=arr[i];
	}
	return sum;
}
template <typename T>//5
int  LinearSearch(const std::vector<T>& arr,T target){
    for(int i=0;i<arr.size();++i){
        if(target==arr[i]){
            return i;
        }
    }
    return -1;

}

int main()
{
	printElement(5.25); //1
	printElement(5);
	printElement(std::string("Barev"));

	mySwap(5.6,5.25);//2
	mySwap(std::string("Barev"),std::string("Hajox"));

	int arr1[] = {1, 2, 3, 4};//3
	double arr2[] = {1.5, 2.5, 3.5};
	std::cout << sumArray(arr1,4) << std::endl;
	std::cout << sumArray(arr2,3) << std::endl;
	std::string arr[] = {"Barev", " ", "Hajox"};
	std::cout << sumArray(arr,3) << std::endl;
	
	std::vector<int> tver={1,2,3,4,5};
	std::cout<<LinearSearch(tver,3)<<std::endl;
	
	std::vector<double> ketov={2.2,2.6,2.3};
	std::cout<<LinearSearch(ketov,2.6)<<std::endl;
	
	std::vector<std::string> barer={"barev","hajox","kjogenq"};
	std::cout<<LinearSearch(barer,std::string("kjogenq"))<<std::endl;
	
	
	
	return 0;
}