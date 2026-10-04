#include <iostream>
#include <vector>

/*template <typename T1,typename T2>//1
class Pair {
public:
	T1 arajin;
	T2 erkrord;
public:
	void print() {
		std::cout<<arajin<<" "<<erkrord<<" "<<std::endl;
	}
};
template <typename T,int N>//2
class FixedArray {
private:
	T arr[N];
public:
	void set(int index,T value) {
		arr[index]=value;
	}
	T get(int index) {
		return arr[index];
	}
	int size() {
		return N;
	}

};*/
template <typename T,int N,int M>
class Matrix {
private:
	T arr[N][M];
public:
	void set(int row,int col,T value) {
		arr[row][col]=value;
	}
	T get(int row,int col) {
		return arr[row][col];
	}
	void print() {
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				std::cout<<arr[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	Matrix<T,N,M> operator+(Matrix<T,N,M>other) {
		Matrix<T,N,M> result;
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				result.set(i,j,arr[i][j]+other.get(i,j));
			}

		}
		return result;
	}

    };
    template <typename T>
    class Range{
        private:
        T start;
        T end;
        public:
        Range(T s,T e):start(s),end(e){}
       void contains(const T& value) {
    if (value >= start && value <= end) {
        std::cout << "Contains" << std::endl;
    } else {
        std::cout << "Does not contain" << std::endl;
    }
}
        T length(){
            return end-start;
        }
        void print(){
            std::cout<<"["<<start<<";"<<end<<"]"<<std::endl;
        }
        
    };
int main()
{
	/*Pair<int,double> p;//1
	p.arajin=5;
	p.erkrord=3.4;
	p.print();

	FixedArray<int,5>a;//2
	a.set(0,5);
	std::cout<<a.get(0)<<std::endl;
	std::cout<<a.size()<<std::endl;
	FixedArray<double,3>b;
	b.set(2, 5.3);
	std::cout<<b.get(2)<<std::endl;
	std::cout<<b.size()<<std::endl;

	Matrix<int,2,3> a;//3
	Matrix<int,2,3> b;
	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(0, 2, 3);
	a.set(1, 0, 4);
	a.set(1, 1, 5);
	a.set(1, 2, 6);

	b.set(0, 0, 10);
	b.set(0, 1, 20);
	b.set(0, 2, 30);
	b.set(1, 0, 40);
	b.set(1, 1, 50);
	b.set(1, 2, 60);
	std::cout<<"Matrix: A"<<std::endl;
	a.print();
	Matrix<int,2,3>c=a+b;
	std::cout<<"A+B: "<<std::endl;
	c.print();*/
	Range<int> a(3,10);
	a.print();
	a.contains(5);;
	std::cout<<a.length()<<std::endl;
	
	Range<double> b(3.4,10.4);
	b.print();
	b.contains(5.4);
	std::cout<<b.length()<<std::endl;

    Range<char> c('a', 'd');
    c.print();
    c.contains('c');
    c.contains('z');
    std::cout << c.length() << std::endl;


	return 0;
}