// Створити параметризованную циклічну чергу.

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

template <class T>
class Queue
{
private:
    T *arr;
    int size;
    int head;
    int tail;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new T[size];
        head = 0;
        tail = 0;
    }

    void push(T value)
    {
        if (tail == size)
        {
            tail = 0;
        }
        arr[tail] = value;
        tail++;
    }

    T pop()
    {
        if (head == size)
        {
            head = 0;
        }
        T temp = arr[head];
        head++;
        return temp;
    }

    void print()
    {
        cout << "Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void GetSize()
    {
        cout << size << endl;
    }
};

int main()
{
    Queue<int> queue(5);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.print();
    cout << "Size of the queue is: ";
    queue.GetSize();
    cout << "Deleting element: " << queue.pop() << endl;
    cout << "Deleting element: " << queue.pop() << endl;
    cout << "Deleting element: " << queue.pop() << endl;
    cout << "Deleting element: " << queue.pop() << endl;
    cout << "Deleting element: " << queue.pop() << endl;
    return 0;
}