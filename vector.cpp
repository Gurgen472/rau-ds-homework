#include <iostream>
#include <vector>


/*void createAndFillVector(int n) {
	std::vector<int> vec(n);
	std::cout<<"Elements: ";
	for(int i=0; i<n; ++i) {
		vec[i]=i+1;

	}
	for(int i=0; i<n; ++i) {
		std::cout<<vec[i]<<" ";
	}
	std::cout<<"\nsize="<<vec.size()<<std::endl;
	std::cout<<"capacity="<<vec.capacity()<<std::endl;
}
void workWithEmptyVector() {
	std::vector<int> vec;
	for(int i=0; i<=10; ++i) {
		vec.push_back(i);
		std::cout<<"After push_back: "<<"size "<<vec.size()<<","<<"capacity "<<vec.capacity()<<std::endl;
	}
	std::cout<<"size "<<vec.size()<<","<<"capacity "<<vec.capacity()<<std::endl;
	std::cout<<"Elements: ";
	for(int i=0; i<=vec.size(); ++i) {
		std::cout<<vec[i]<<" ";

	}
}
void createVectorFromInput() {
	std::vector<int> vec;
	while(true) {
		int a;
		std::cin>>a;
		if(a==0) {
			break;
		}
		vec.push_back(a);
	}

}
int removeElementsGreaterThan(std::vector<int>& vec, int max) {
	int count=0;
	while(vec.back()>max) {
		vec.pop_back();
		count++;

	}
	return count;
}
void manageCapacity(std::vector<int>& vec) {
	std::cout<<"Size: "<<vec.size()<<std::endl;
	std::cout<<"Capacity: "<<vec.capacity()<<std::endl;
	vec.reserve(vec.size()+500);
	for(int i=0; i<500; ++i) {
		vec.push_back(i);
	}
	std::cout << "After push_back:"<<std::endl;
	std::cout << "Size: " << vec.size() <<std::endl;
	std::cout << "Capacity: " << vec.capacity() <<std::endl;

}
template <typename T>
void resizeVector(std::vector<T>& vec,int newSize,T value) {
	std::cout<<"Before resize: ";
	for(int i=0; i<vec.size(); ++i) {
		std::cout<<vec[i]<<" ";
	}
	std::cout<<"\n";
	vec.resize(newSize,value);
	std::cout<<"After resize: ";
	for(int i=0; i<vec.size(); ++i) {
		std::cout<<vec[i]<<" ";
	}

}
std::vector<int> mergeSortedVectors(std::vector<int>&a,std::vector<int>& b) {
	std::vector<int> result;
	int i=0;
	int j=0;
	while(i<a.size() && j<b.size()) {
		if(a[i]<b[j]) {
			result.push_back(a[i]);
			++i;
		}
		else {
			result.push_back(b[j]);
			++j;
		}

	}


	while(i<a.size()) {
		result.push_back(a[i]);
		++i;
	}
	while(j<b.size()) {
		result.push_back(b[j]);
		++j;
	}
	return result;
}
int findSubsequence(std::vector<int> main_vec,std::vector<int>& sub_vec) {
	for(int i=0; i<main_vec.size(); ++i) {
		if(main_vec[i]==sub_vec[0]) {

			bool found=true;
			for(int j=0; j<sub_vec.size(); ++j) {
				if(main_vec[i+j]!=sub_vec[j]) {
					found=false;
					break;
				}

			}
			if(found) {
				return i;
			}
		}
	}
	return -1;
}


std::vector<std::vector<int>> groupAdjacent(std::vector<int>& vec) {
	std::vector<std::vector<int>> result;

	if(vec.empty()) {
		return result;
	}
	std::vector<int> group;
	group.push_back(vec[0]);
	for(int i=1; i<vec.size(); ++i) {
		if(vec[i]==vec[i-1]) {
			group.push_back(vec[i]);
		} else {
			result.push_back(group);
			group.clear();
			group.push_back(vec[i]);
		}
	}
	result.push_back(group);
	return result;


}*/
// 1,1,2,2,2,3,1,1
std::vector<int> findIntersection(std::vector<int> a,std::vector<int> b) {
	std::vector<int> result;
	for(int i=0; i<a.size(); ++i) {
		for(int j=0; j<b.size(); ++j) {
			if(a[i]==b[i]) {
              int k=0;
              for(int k=0;k<a.size();++k){
                  if(result[k]==a[i]){
                      break;
                  }
              }
              if(k==result.size()){
                  result.push_back(a[i]);
              }
              break;
			}
		}

	}
for(int i=0;i<result.size();++i){
    for(int j=i+1;j<result.size();++j){
        if(result[i]>result[j]){
            int temp=result[i];
            result[i]=result[j];
            result[j]=temp;
        }
    }
}

return result;
}
int main()
{
	/*	createAndFillVector(5);// 1
		workWithEmptyVector();//2
		createVectorFromInput();//3

		std::vector<int> vec = {1, 3, 5, 7, 10, 15, 20};//4
		int removed = removeElementsGreaterThan(vec, 10);
		std::cout << "Removed: " << removed << std::endl;

		manageCapacity(vec);//5

		std::vector<int> v = {1, 2, 3};//6
		resizeVector(v, 5, 42);

		std::vector<int> a = {1, 3, 5, 7};//7
		std::vector<int> b = {2, 4, 6, 8, 9};
		std::vector<int> merged = mergeSortedVectors(a, b);
		std::cout << "Sorted Vectors: ";
		for (int x : merged)
		{
			std::cout << x << " ";
		}
	std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};//8
	std::vector<int> sub_vec = {3, 4, 5};
	int index = findSubsequence(main_vec, sub_vec);
	std::cout<<index;
	std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};//9
	std::vector<std::vector<int>> groups = groupAdjacent(vec);
	// groups содержит: {{1, 1}, {2, 2, 2}, {3}, {1, 1}}
	for (std::vector<int> group : groups) {
	std::cout << "{";

	for (int x : group) {
	    std::cout << x << " ";
	}

	std::cout << "}" << std::endl;
	}*/
	std::vector<int> a = {1, 2, 3, 4};//12
	std::vector<int> b = {3, 4, 5, 6};

	std::vector<int> inter = findIntersection(a, b);

	   for (int i = 0; i < inter.size(); ++i) {
        std::cout << inter[i] << " ";
    }

	return 0;
}