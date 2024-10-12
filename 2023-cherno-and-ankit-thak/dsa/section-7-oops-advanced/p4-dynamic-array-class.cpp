#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextElement;
    int capacity;

public:
    DynamicArray()
    {
        data = new int[5];
        capacity = 5;
        nextElement = 0;
    }

    DynamicArray(DynamicArray const &d)
    {
        // this->data = d.data; // shallow copy
        // Deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextElement; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextElement = d.nextElement;
        this->capacity = d.capacity;
    }

    void operator=(DynamicArray const &d)
    {
        // this->data = d.data; // shallow copy
        // Deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextElement; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextElement = d.nextElement;
        this->capacity = d.capacity;
    }

    void add(int element)
    {
        if (this->nextElement == this->capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < this->nextElement; i++)
            {
                newData[i] = this->data[i];
            }
            delete[] data;
            data = newData;
            this->capacity = 2 * this->capacity;
            this->data[this->nextElement] = element;
        }
        else
        {
            data[this->nextElement] = element;
        }

        this->nextElement++;
    }

    void add(int element, int index)
    {
        if (index >= 0 && index < this->nextElement)
        {
            this->data[index] = element;
        }
        else if (index == this->nextElement)
        {
            this->add(element);
        }
    }

    int getElement(int i)
    {
        if (i >= 0 && i < this->nextElement)
        {
            return this->data[i];
        }
        else
        {
            return -1;
        }
    }

    int getCapacity()
    {
        return this->capacity;
    }

    void print()
    {
        for (int i = 0; i < this->nextElement; i++)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray d;
    d.add(1);
    d.add(2);
    d.print();
    cout << d.getCapacity() << endl;
    d.add(3);
    d.add(4);
    d.add(5);
    d.print();
    cout << d.getCapacity() << endl;
    d.add(6);
    d.print();
    cout << d.getCapacity() << endl;
    cout << "0th element is : " << d.getElement(0) << endl;

    DynamicArray d2 = d;
    d.add(100, 0);
    d2.print();
    d.print();
}