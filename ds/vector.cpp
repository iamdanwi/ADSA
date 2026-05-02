#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyVector
{
private:
    int cap;
    T *data;
    int size;

public:
    MyVector(int cap)
    {
        this->cap = cap;
        this->size = 0;
        this->data = new T[cap];
    }

    MyVector() {}

    ~MyVector()
    {
        delete[] data;
    }

    void push_back(T value)
    {
        if (size == cap)
        {
            int new_cap = (cap == 0) ? 1 : cap * 2;

            T *new_data = new T[new_cap];

            for (int i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
            cap = new_cap;
        }
        data[size] = value;
        size++;
    }

    void pop_back()
    {
        if (size == 0)
        {
            return;
        }

        size--;
    }

    int get_size() const
    {
        return size;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("index out of range");
        }
        return data[index];
    }
};

int main()
{
    MyVector<int> vec(5);

    for (size_t i = 0; i < vec.get_size(); i++)
    {
        vec.push_back(i);
    }

    cout << vec[4] << endl;

    return 0;
}
