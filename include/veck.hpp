#pragma once

#include <iostream>

class Vector
{
public:
	Vector();
	Vector(const Vector &rhs);
	Vector(int element, int value = 0);
	Vector(const std::initializer_list<int> &list);
	~Vector();

	void push(int value);
	void pop();
	bool empty() const;
	int size() const;
	int capacity() const;
	friend std::ostream &operator<<(std::ostream &ostr, const Vector &rhs);

	bool operator==(const Vector &rhs);
	bool operator!=(const Vector &rhs);

	Vector &operator=(const Vector &rhs);
	int &operator[](int index);
	int &at(int index);
	int &front();
	int &back();
	void insert(int index, int val);
	void erase(int index);
	void clear();

private:
	int *array;
	int vec_size;
	int vec_capacity;
};
