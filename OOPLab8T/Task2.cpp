// Написати функцію-шаблон функцію впорядкування методом «Вилучення». Написати специфікацію функції-шаблон для типу char*.

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

template <class T>
void sort(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

template <>
void sort(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (atof(arr[j]) < atof(arr[min]))
            {
                min = j;
            }
        }
        char *temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr1[] = {1, 2, 32, 41, 55, 6321};
    cout << "Sorted arr1:" << endl;
    sort(arr1, 6);
    for (auto el : arr1)
    {
        cout << el << " ";
    }

    cout << endl;
    char *arr2[] = {"15", "12", "53", "4", "235"};
    cout << "Sorted arr2:" << endl;
    sort(arr2, 5);
    for (auto el : arr2)
    {
        cout << el << " ";
    }

    return 0;
}