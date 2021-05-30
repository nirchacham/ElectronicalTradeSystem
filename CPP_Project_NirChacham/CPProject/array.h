
#ifndef _ARRAY_H
#define _ARRAY_H

template<class T>

class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;
public:
	Array(int size = 1, char delimiter = ' ') :physicalSize(size), logicalSize(0), delimiter(delimiter) { arr = new T[physicalSize]; }
	Array(const Array& other) { *this = other; }
	Array(Array&& other) {
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = other.arr;
		other.arr = nullptr;
	}
	~Array()
	{
		delete []arr;
	}

	const T& operator[](int index);
	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);
	int getSize() { return logicalSize; }const
	int getCapacitySize() { return physicalSize; }const

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; arr.logicalSize; i++) {
			os << arr.arr[i] << arr.delimiter;
		}
		return os;
	}


};

template <class T>
const Array<T>& Array<T>::operator=(const Array<T>&other)
{
	if (this != &other)
	{
		delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	if (logicalSize < physicalSize)
	{
		arr[logicalSize++] = newVal;
	}
	else {
		physicalSize = physicalSize * 2;
		T*newArr = new T[physicalSize];
		memcpy(newArr, arr, sizeof(T)*logicalSize);
		delete[]arr;
		arr = newArr;
		arr[logicalSize++] = newVal;
	}
	return *this;
}

template <class T>
const T& Array<T>::operator[](int index)
{
	return arr[index];
}
#endif // _ARRAY_



