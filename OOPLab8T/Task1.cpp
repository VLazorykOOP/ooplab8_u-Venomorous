// Написати функцію-шаблон, що обчислює середнє значення в масиві. Написати специфікацію функції-шаблон для типу char*.
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <array>

using namespace std;

template <class T>
T average(T *arr, int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

template <>
char *average(char **arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += atoi(arr[i]);
    }
    string result = to_string(sum / size);
    char *str = new char[result.length() + 1];

    strcpy(str, result.c_str());

    return str;
}

int main()
{
    double arr1[] = {1, 2, 3, 4, 5, 6};
    cout << "Average of arr1:" << endl;
    cout << average(arr1, 6) << endl;

    char *arr2[] = {"1", "2", "3", "4", "5"};
    cout << "Average of arr2:" << endl;
    cout << average(arr2, 5) << endl;

    return 0;
}

/*#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

template <class T>
double average(T *arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

template <>
double average(char **arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += atof(arr[i]);
    }
    return sum / size;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    cout << "Average of arr1:" << endl;
    cout << average(arr1, 6) << endl;

    char *arr2[] = {"1", "2", "3", "4", "5"};
    cout << "Average of arr2:" << endl;
    cout << average(arr2, 5) << endl;

    return 0;
}
*/