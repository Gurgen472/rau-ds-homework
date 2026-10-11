#include <iostream>
#include <stdexcept>
#include <cassert>
#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {
private:
	T* _data;
	size_t _size;
	size_t _capacity;

	void _resize_capacity(size_t new_capacity) {
		T* arr = new T[new_capacity];

		for (size_t i = 0; i < _size; ++i) {
			arr[i] = _data[i];
		}

		delete[] _data;

		_data = arr;
		_capacity = new_capacity;
	}

public:
	Vector()
		: _size(0), _capacity(0), _data(nullptr) {}

	Vector(size_t initial_size) {
		_data = new T[initial_size];
		_size = initial_size;
		_capacity = initial_size;
	}

	~Vector() {
		delete[] _data;
	}

	Vector(const Vector& other) {
		_size = other._size;
		_capacity = other._capacity;
		_data = new T[_capacity];

		for (size_t i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}

	Vector& operator=(const Vector& other) {
		if (this != &other) {
			delete[] _data;

			_size = other._size;
			_capacity = other._capacity;
			_data = new T[_capacity];

			for (size_t i = 0; i < _size; ++i) {
				_data[i] = other._data[i];
			}
		}

		return *this;
	}

	void push_back(const T& value) {
		if (_size == _capacity) {
			if (_capacity == 0) {
				_resize_capacity(1);
			} else {
				_resize_capacity(_capacity * 2);
			}
		}

		_data[_size] = value;
		_size++;
	}

	void pop_back() {
		if (_size > 0) {
			_size--;
		}
	}

	T& operator[](size_t index) {
		return _data[index];
	}

	const T& operator[](size_t index) const {
		return _data[index];
	}

	T& at(size_t index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}

		return _data[index];
	}

	const T& at(size_t index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}

		return _data[index];
	}

	T& front() {
		return _data[0];
	}

	const T& front() const {
		return _data[0];
	}

	T& back() {
		return _data[_size - 1];
	}

	const T& back() const {
		return _data[_size - 1];
	}
	void resize(size_t new_size) {
		if (new_size > _capacity) {
			_resize_capacity(new_size);
		}

		_size = new_size;
	}

	void insert(size_t pos, const T& value) {
    if (pos > _size) {
        throw std::out_of_range("Index out of range");
    }

    if (_size == _capacity) {
        if (_capacity == 0) {
            _resize_capacity(1);
        } else {
            _resize_capacity(_capacity * 2);
        }
    }

    for (size_t i = _size; i > pos; --i) {
        _data[i] = _data[i - 1];
    }

    _data[pos] = value;
    ++_size;
}
	void erase(int pos) {
		if(pos>=_size) {
			throw std::out_of_range("Index out of range");
		}
		if(pos==_size-1) {
			pop_back();
			return;

		} else {
			for(size_t i=pos; i<_size-1; ++i) {
				_data[i]=_data[i+1];
			}
		}
		--_size;
	}
	void swap(Vector& other) {
		T* temp_data=_data;
		_data=other._data;
		other._data=temp_data;

		size_t temp_size=_size;
		_size=other._size;
		other._size=temp_size;

		size_t temp_capacity=_capacity;
		_capacity=other._capacity;
		other._capacity=temp_capacity;
	}


	size_t size() const {
		return _size;
	}

	size_t capacity() const {
		return _capacity;
	}

	bool empty() const {
		return _size == 0;
	}

	void clear() {
		_size = 0;
	}

	T* begin() {
		return _data;
	}

	const T* begin() const {
		return _data;
	}

	T* end() {
		return &_data[_size];
	}

	const T* end() const {
		return &_data[_size];
	}
};
void test_push_back() {
	Vector<int> v;
	v.push_back(5);
	assert(v.size() == 1);
	assert(v[0] == 5);
	v.push_back(10);
	v.push_back(15);
	assert(v.size() == 3);
	assert(v.back() == 15);
	std::cout << "test_push_back passed" << std::endl;
}
void test_pop_back() {
	Vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v.pop_back();

	assert(v.size() == 2);
	assert(v[0] == 10);
	assert(v[1] == 20);

	std::cout << "test_pop_back passed" << std::endl;
}
void test_operator_brackets() {
	Vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	assert(v[0] == 10);
	assert(v[1] == 20);
	assert(v[2] == 30);

	v[1] = 50;

	assert(v[1] == 50);

	std::cout << "test_operator_brackets passed" << std::endl;
}
void test_back() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	assert(v.back()==30);
	std::cout << "test_back passed" << std::endl;

}
void test_front() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	assert(v.front()==10);
	std::cout << "test_front passed" << std::endl;

}
void test_insert() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(1,10);
	assert(v.size()==4);
	assert(v[0] == 10);
	assert(v[1] == 10);
	assert(v[2] == 20);
	assert(v[3] == 30);
	std::cout << "test_insert passed" << std::endl;
}
void test_erase() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.erase(1);
	assert(v.size()==2);
	assert(v[0]==10);
	assert(v[1]==30);
	std::cout<<"test_erase passed"<<std::endl;
}
void test_swap() {
	Vector<int> v1;
	Vector<int> v2;

	v1.push_back(10);
	v1.push_back(20);

	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	v1.swap(v2);

	assert(v1.size() == 3);
	assert(v1[0] == 30);
	assert(v1[1] == 40);
	assert(v1[2] == 50);

	assert(v2.size() == 2);
	assert(v2[0] == 10);
	assert(v2[1] == 20);

	std::cout << "test_swap passed" << std::endl;
}
void test_clear() {
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.clear();
	assert(v.size()==0);
}
void test_resize() {
	Vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v.resize(5);

	assert(v.size() == 5);

	v.resize(2);

	assert(v.size() == 2);
	assert(v[0] == 10);
	assert(v[1] == 20);

	std::cout << "test_resize passed" << std::endl;
}
void test_copy_constructor() {
	Vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	Vector<int> v2(v1);

	assert(v2.size() == 3);
	assert(v2[0] == 10);
	assert(v2[1] == 20);
	assert(v2[2] == 30);

	std::cout << "test_copy_constructor passed" << std::endl;
}
void test_assignment_operator() {
	Vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	Vector<int> v2;

	v2 = v1;

	assert(v2.size() == 3);
	assert(v2[0] == 10);
	assert(v2[1] == 20);
	assert(v2[2] == 30);

	std::cout << "test_assignment_operator passed" << std::endl;
}

#endif

int main() {
	test_pop_back();
	test_operator_brackets();
	test_back();
	test_front();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_resize();
	test_copy_constructor();
	test_assignment_operator();




	return 0;
}