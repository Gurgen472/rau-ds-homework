
#include <iostream>
#ifndef STACK_H
#define STACK_H
#include <cassert>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;

    void expand() {
        int _newcapacity = _capacity * 2;
        T* newData = new T[_newcapacity];

        for (int i = 0; i < _size; ++i) {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = _newcapacity;
    }

public:
    Stack() : _data(new T[3]), _capacity(3), _size(0) {}

    ~Stack() {
        delete[] _data;
    }

    Stack(const Stack& other) {
        _capacity = other._capacity;
        _size = other._size;

        _data = new T[_capacity];

        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if (this == &other) {
            return *this;
        }

        T* newData = new T[other._capacity];

        for (int i = 0; i < other._size; i++) {
            newData[i] = other._data[i];
        }

        delete[] _data;

        _data = newData;
        _capacity = other._capacity;
        _size = other._size;

        return *this;
    }

    void push(const T& x) {
        if (_size == _capacity) {
            expand();
        }

        _data[_size] = x;
        _size++;
    }

    void pop() {
        if (_size == 0) {
            throw std::out_of_range("Stack is empty");
        }

        --_size;
    }

    T& top() {
        if (_size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return _data[_size - 1];
    }

    const T& top() const {
        if (_size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return _data[_size - 1];
    }

    int size() const {
        return _size;
    }

    int capacity() const {
        return _capacity;
    }

    bool is_empty() const {
        if (_size == 0) {
            return true;
        }
        return false;
    }

    void clear() {
        _size = 0;
    }

    T& peek() {
        return top();
    }

    const T& peek() const {
        return top();
    }
};

#endif

void test_constructor() {
    Stack<int> s;
    assert(s.size() == 0);
    assert(s.is_empty());
    assert(s.capacity() > 0);
    std::cout << "test_constructor passed\n";
}

void test_destructor() {
    {
        Stack<int> s;
        s.push(10);
        s.push(20);
    }
    std::cout << "test_destructor passed\n";
}

void test_copy_constructor() {
    Stack<int> a;
    a.push(10);
    a.push(20);

    Stack<int> b(a);

    assert(b.size() == 2);
    assert(b.top() == 20);

    std::cout << "test_copy_constructor passed\n";
}

void test_assignment_operator() {
    Stack<int> a;
    a.push(10);
    a.push(20);

    Stack<int> b;
    b.push(100);

    b = a;

    assert(b.size() == 2);
    assert(b.top() == 20);

    b.pop();
    assert(b.top() == 10);
    assert(a.top() == 20);

    std::cout << "test_assignment_operator passed\n";
}

void test_push() {
    Stack<int> s;

    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.push(10);
    s.push(15);

    assert(s.size() == 3);
    assert(s.top() == 15);

    std::cout << "test_push passed\n";
}

void test_pop() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    assert(s.size() == 2);
    assert(s.top() == 20);

    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 10);

    s.pop();
    assert(s.is_empty());

    std::cout << "test_pop passed\n";
}

void test_top() {
    Stack<int> s;
    s.push(10);
    s.push(20);

    assert(s.top() == 20);

    s.top() = 50;
    assert(s.top() == 50);

    std::cout << "test_top passed\n";
}

void test_size() {
    Stack<int> s;
    s.push(10);
    s.push(20);

    assert(s.size() == 2);
    std::cout << "test_size passed\n";
}

void test_capacity() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    assert(s.capacity() >= 5);

    std::cout << "test_capacity passed\n";
}

void test_is_empty() {
    Stack<int> s;

    assert(s.is_empty());

    s.push(10);
    assert(!s.is_empty());

    s.pop();
    assert(s.is_empty());

    std::cout << "test_is_empty passed\n";
}

void test_clear() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.clear();

    assert(s.size() == 0);
    assert(s.is_empty());

    std::cout << "test_clear passed\n";
}

void test_peek() {
    Stack<int> s;
    s.push(10);
    s.push(20);

    assert(s.peek() == 20);
    assert(s.size() == 2);

    s.peek() = 50;
    assert(s.top() == 50);

    std::cout << "test_peek passed\n";
}

int main() {
    std::cout << "Running Stack tests" << std::endl;

    test_constructor();
    test_destructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push();
    test_pop();
    test_top();
    test_size();
    test_capacity();
    test_is_empty();
    test_clear();
    test_peek();

    std::cout << "All tests passed!\n";

    return 0;
}
