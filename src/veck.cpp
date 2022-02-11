#include <veck.hpp>

Vector::Vector()
{
	vec_size = 0;
	vec_capacity = 8;
	array = new int[vec_capacity];
}

Vector::~Vector()
{
	delete[] array;
}

Vector::Vector(const std::initializer_list<int> &list)
{
	vec_size = 0;
	vec_capacity = vec_size * 2;
	array = new int[vec_capacity];

	for (int i : list)
	{
		push(i);
	}
}

void Vector::push(int val)
{
	if (vec_size < vec_capacity)
	{
		array[vec_size] = val;
		++vec_size;
	}
	else
	{
		vec_capacity *= 2;
		int *newarray = new int[vec_capacity];
		for (int i = 0; i < vec_size; i++)
		{
			newarray[i] = array[i];
		}
		newarray[vec_size] = val;
		++vec_size;
		delete[] array;
		this->array = newarray;
	}
}

bool Vector::empty() const
{
	return vec_size == 0;
}

int Vector::size() const
{
	return this->vec_size;
}

int Vector::capacity() const
{
	return this->vec_capacity;
}

bool Vector::operator==(const Vector &rhs)
{
	if (this->size() != rhs.size())
	{
		return false;
	}

	for (int i = 0; i < size(); i++)
	{
		if (array[i] != rhs.array[i])
		{
			return false;
		}
	}

	return true;
}

bool Vector::operator!=(const Vector &rhs)
{
	// invert the output of the == operator
	return !(*this == rhs);
}

Vector::Vector(const Vector &rhs)
{
	vec_size = rhs.size();
	vec_capacity = rhs.capacity();
	array = new int[vec_capacity];

	for (int i = 0; i < rhs.size(); i++)
	{
		array[i] = rhs.array[i];
	}
}

Vector::Vector(int elements, int value)
{
	vec_size = elements;
	vec_capacity = elements * 2;
	array = new int[vec_capacity];

	for (int i = 0; i < elements; i++)
	{
		array[i] = value;
	}
}

std::ostream &operator<<(std::ostream &ostr, const Vector &rhs)
{
	for (int i = 0; i < rhs.vec_size; i++)
	{
		ostr << rhs.array[i];
		if (i + 1 != rhs.vec_size)
		{
			ostr << ", ";
		}
	}

	return ostr;
}

void Vector::pop()
{
	if (vec_size == 0)
	{
		throw std::exception();
	}
	--vec_size;
}

Vector &Vector::operator=(const Vector &rhs)
{
	if (rhs.vec_size > vec_size)
	{
		delete[] array;
		vec_capacity = rhs.vec_capacity * 2;
		array = new int[rhs.vec_capacity];
	}

	for (int i = 0; i < rhs.vec_size; i++)
	{
		array[i] = rhs.array[i];
	}

	vec_size = rhs.vec_size;
	return *this;
}

int &Vector::operator[](int index)
{
	return array[index];
}

int &Vector::at(int index)
{
	if ((index < 0) || index > vec_size)
	{
		throw std::exception();
	}
	return array[index];
}

int &Vector::front()
{
	return array[0];
}

int &Vector::back()
{
	return array[vec_size - 1];
}

void Vector::insert(int index, int value)
{
	// The code below is really ugly and inefficient
	// I am writing this code at 2 in the morning
	// forgive me for my sins
	if ((index < 0) || index >= vec_size)
	{
		throw std::out_of_range("insert :: Index out of range");
	}
	if (vec_size != vec_capacity)
	{
		for (int i = vec_size - 1; i >= index; i++)
		{
			array[i + 1] = array[i];
		}
		array[index] = value;
		++vec_size;
	}
	else
	{
		vec_capacity *= 2;
		int *newarray = new int[vec_capacity];
		for (int i = 0; i < vec_size; i++)
		{
			newarray[i] = array[i];
		}
		delete[] array;
		array = newarray;
		insert(index, value);
	}
}

void Vector::erase(int index)
{
	if (index < 0 || index >= vec_size)
	{
		throw std::out_of_range("Index out of range");
	}

	for (int i = index; i < vec_size - 1; i++)
	{
		array[i] = array[i + 1];
	}

	--vec_size;
}

void Vector::clear()
{
	vec_size = 0;
}