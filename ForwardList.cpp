#include <iostream>
#include <cassert>
#ifndef FORWARDLIST_H
#define FORWARDLIST_H
template <typename T>
class ForwardList {
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& d) : data(d), next(nullptr) {}
	};
	Node* _head;
	int _size;
public:
	ForwardList():_head(nullptr),_size(0) {}
	~ForwardList() {
		clear();
	}
	ForwardList(const ForwardList& other):_head(nullptr),_size(0) {
		Node* current=other._head;
		Node* tail = nullptr;
		while(current!=nullptr) {
			Node* newNode=new Node(current->data);
			if(_head==nullptr) {
				_head=newNode;
			} else {
				tail->next=newNode;
			}
			tail=newNode;
			++_size;
			current=current->next;
		}
	}
	ForwardList& operator=(const ForwardList& other) {
		if(this==&other) {
			return *this;
		}
		clear();
		Node* current=other._head;
		Node* tail=nullptr;
		while(current!=nullptr) {
			Node* newNode=new Node(current->data);
			if(_head==nullptr) {
				_head=newNode;
			} else {
				tail->next=newNode;
			}
			tail=newNode;
			++_size;
			current=current->next;
		}
		return *this;
	}
    void push_front(const T& x){
        Node* newNode=new Node(x);
        newNode->next=_head;
        _head=newNode;
        ++_size;
    }
    void pop_front(){
        if(_head==nullptr){
            return;
        }
        Node* temp=_head;
        _head=_head->next;
        delete temp;
        --_size;
    }
    T& front(){
        return _head->data;
    }
    const T& front() const{
        return _head->data;
    }
     void insert_after(Node* node, const T& value){
        Node* newNode=new Node(value);
        newNode->next=node->next;
        node->next=newNode;
        ++_size;
     }
     void erase_after(Node* node){
         if(node==nullptr || node->next==nullptr){
             return;
         }
         Node* temp=node->next;
         node->next=temp->next;
         delete temp;
         --_size;
         
     }
     void clear(){
         while(_head!=nullptr){
             pop_front();
         }
     }
     void reverse(){
         Node* prev=nullptr;
         Node* current=_head;
         Node* next=nullptr;
         while(current!=nullptr){
             next=current->next;
             current->next=prev;
             prev=current;
             current=next;
         }
         _head=prev;
     }
     int size() const {
    return _size;
  }
  bool empty() const {
    return _head == nullptr;
  }
  Node* begin(){
      return _head;
  }
    Node* begin() const{
        return _head;
    }
};
//tests 
//1
void test_constructor() {
    ForwardList<int> fl;
    assert(fl.size() == 0);
    assert(fl.empty());
    std::cout << "test_constructor passed\n";
}
//2
void test_destructor() {
    {
        ForwardList<int> fl;
        fl.push_front(1);
        fl.push_front(2);
        fl.push_front(3);
        assert(fl.size() == 3);
    } 
    std::cout << "test_destructor passed" << std::endl;
}
//3 
void test_copy_constructor() {
    ForwardList<int> fl;
    fl.push_front(2);
    fl.push_front(1);

    ForwardList<int> copy(fl);

    assert(copy.size() == 2);
    assert(copy.front() == 1);

    copy.pop_front();
    assert(copy.front() == 2);
    assert(fl.front() == 1);

    std::cout << "test_copy_constructor passed\n";
}
//4 
void test_assignment_operator() {
    ForwardList<int> fl;
    fl.push_front(2);
    fl.push_front(1);

    ForwardList<int> copy;
    copy.push_front(100);
    copy = fl;

    assert(copy.size() == 2);
    assert(copy.front() == 1);

    copy = copy;
    assert(copy.size() == 2);

    std::cout << "test_assignment_operator passed\n";
}

//5
void test_push_front() {
    ForwardList<int> list;
    
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);
    
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    
    std::cout << "test_push_front passed" << std::endl;
}
//6
void test_pop_front() {
    ForwardList<int> fl;

    fl.push_front(1);
    fl.push_front(2);
    fl.push_front(3);

    fl.pop_front();
    assert(fl.front() == 2);
    assert(fl.size() == 2);

    fl.pop_front();
    fl.pop_front();

    assert(fl.empty());

    std::cout << "test_pop_front passed\n";
}
//7 
void test_front() {
    ForwardList<int> fl;

    fl.push_front(10);
    assert(fl.front() == 10);

    fl.front() = 20;
    assert(fl.front() == 20);

    std::cout << "test_front passed\n";
}
//8
void test_insert_after() {
    ForwardList<int> fl;
    fl.push_front(2);
    fl.push_front(1);

    auto node = fl.begin();
    fl.insert_after(node, 10);

    assert(fl.size() == 3);
    assert(node->next->data == 10);
    assert(node->next->next->data == 2);

    std::cout << "test_insert_after passed\n";
}
//9
void test_erase_after() {
    ForwardList<int> fl;
    fl.push_front(3);
    fl.push_front(2);
    fl.push_front(1);

    auto node = fl.begin();
    fl.erase_after(node);

    assert(fl.size() == 2);
    assert(node->next->data == 3);

    std::cout << "test_erase_after passed\n";
}
//10
void test_clear() {
    ForwardList<int> fl;
    fl.push_front(1);
    fl.push_front(2);

    fl.clear();

    assert(fl.size() == 0);
    assert(fl.empty());

    std::cout << "test_clear passed\n";
}
//11
void test_reverse() {
    ForwardList<int> fl;
    fl.push_front(3);
    fl.push_front(2);
    fl.push_front(1);

    fl.reverse();

    assert(fl.front() == 3);
    assert(fl.size() == 3);
    assert(fl.begin()->next->data == 2);
    assert(fl.begin()->next->next->data == 1);

    std::cout << "test_reverse passed\n";
}
//12,13
void test_size_and_empty() {
    ForwardList<int> fl;

    assert(fl.size() == 0);
    assert(fl.empty());

    fl.push_front(5);

    assert(fl.size() == 1);
    assert(!fl.empty());

    std::cout << "test_size_and_empty passed\n";
}
//14
void test_begin() {
    ForwardList<int> fl;
    fl.push_front(20);
    fl.push_front(10);

    assert(fl.begin() != nullptr);
    assert(fl.begin()->data == 10);
    assert(fl.begin()->next->data == 20);

    std::cout << "test_begin passed\n";
}



#endif
int main()
{
    std::cout << "Running ForwardList tests" << std::endl;
    test_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size_and_empty();
    test_begin();
    
    std::cout << "All tests passed" << std::endl;


	return 0;
}