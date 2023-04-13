#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

template <class T>
class Array
{
private:
    T *arr;
    int size;

public:
    Array(int size)
    {
        this->size = size;
        arr = new T[size];
    }

    T &operator[](int index)
    {
        return arr[index];
    }

    int GetSize()
    {
        return size;
    }
};

template <class T>
class Iterator
{
private:
    Array<T> *arr;
    int index;
    int size;

public:
    Iterator(Array<T> *arr, int size)
    {
        this->arr = arr;
        this->size = size;
        index = 0;
    }

    T &operator*()
    {
        return (*arr)[index];
    }

    void operator++()
    {
        index++;
    }

    bool operator!=(const Iterator<T> &other) const
    {
        return index != other.index || arr != other.arr;
    }

    bool operator!=(int size) const
    {
        return index != size;
    }

    bool operator==(const Iterator<T> &other) const
    {
        return index == other.index && arr == other.arr;
    }

    int GetSize()
    {
        return size;
    }
};

int main()
{
    Array<int> arr(5);
    for (int i = 0; i < arr.GetSize(); i++)
    {
        arr[i] = i;
        cout << "Added element: " << arr[i] << endl;
    }

    cout << "While loop:" << endl;
    Iterator<int> it(&arr, arr.GetSize());
    while (it != it.GetSize())
    {
        cout << "Iteration at index: " << *it << endl;
        ++it;
    }

    cout << "For loop:" << endl;
    for (Iterator<int> it(&arr, arr.GetSize()); it != it.GetSize(); ++it)
    {
        cout << "Iteration at index: " << *it << endl;
    }

    return 0;
}
