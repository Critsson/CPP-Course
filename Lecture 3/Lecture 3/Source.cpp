#include <iostream>
#include <memory>

void pp(int & a) {
	std::cout << &a << " " << a << " " << sizeof(a) << std::endl;
}

template <typename T>
class DynamicArray {

	size_t m_size;
	T* m_array;

public:

	DynamicArray(size_t size) : m_size(size), m_array(new T[size]) {

		std::cout << "Array Constructed\n";

	}

	~DynamicArray() {
		delete[] m_array;
		std::cout << "Array Destructed\n";
	}

	T get(size_t index) const {
		return m_array[index];
	}

	void set(size_t index, T value) {
		m_array[index] = value;
	}

	void print() const {
		for (size_t i = 0; i < m_size; i++) {
			std::cout << i << " " << m_array[i] << std::endl;
		}
	}

	size_t length() const {
		return m_size;
	}

	const T& operator [] (size_t index) const {
		return m_array[index];
	}

	T& operator [] (size_t index) {
		return m_array[index];
	}
};

int main(int argc, char* argv[]) {

	DynamicArray<float> myArray(10);

	for (size_t i = 0; i < myArray.length(); i++) {
		myArray.set(i, i * 10.3f);
	}

	myArray[3] = 3.1415;

	std::cout << myArray[3] << "\n";

	return 0;
}