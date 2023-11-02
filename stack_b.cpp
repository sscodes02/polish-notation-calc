#include <iostream>
#include "stack_b.h"
#include <stdexcept>

using namespace std;

Stack_B::Stack_B()
{
    try
    {
        capacity = 1024;
        stk = new int[capacity];
        size = -1;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

Stack_B::~Stack_B()
{
    delete[] stk;
}

void Stack_B::push(int data)
{
    try
    {
        if (size >= capacity)
        {
            int *temp = new int[capacity * 2];
            for (int i = 0; i <= size; i++)
            {
                temp[i] = stk[i];
            }
            delete stk;
            stk = temp;
            capacity *= 2;
        }
        stk[++size] = data;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::pop()
{
    try
    {
        if (size == -1)
        {
            throw runtime_error("Empty Stack");
        }
        else
        {
            if ((size <= capacity / 2) && (capacity >= 2048))
            {
                int *temp = new int[capacity/2];
                for (int i = 0; i <= size; i++)
                {
                    temp[i] = stk[i];
                }
                delete stk;
                stk = temp;
                capacity /= 2;
            }
            int r = stk[size];
            size--;
            return r;
        }
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::get_element_from_top(int idx)
{
    if (size == -1)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[size - idx];
    }
}

int Stack_B::get_element_from_bottom(int idx)
{
    if (size == -1)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[idx];
    }
}

void Stack_B::print_stack(bool top_or_bottom)
{
    if (top_or_bottom)
    {
        for (int i = 0; i <= size; i++)
        {
            cout << stk[size - i] << endl;
        }
    }
    else
    {
        for (int j = 0; j <= size; j++)
        {
            cout << stk[j] << endl;
        }
    }
    return;
}

int Stack_B::add()
{
    if (size < 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int m = pop();
        int n = pop();
        int p = m + n;
        stk[++size] = p;
        return p;
    }
}

int Stack_B::subtract()
{
    if (size < 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int m = pop();
        int n = pop();
        int p = n - m;
        stk[++size] = p;
        return p;
    }
}

int Stack_B::multiply()
{
    if (size < 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int m = pop();
        int n = pop();
        int p = m * n;
        stk[++size] = p;
        return p;
    }
}

int Stack_B::divide()
{
    int q;
    if (size < 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {

        int m = pop();
        if (m == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            int n = pop();
            q = (n / m);
            if (n * m < 0 && n%m!=0)
            {
                q = q - 1;
            }
            stk[++size] = q;
            return q;
        }
    }
}

int *Stack_B::get_stack()
{
    return stk;
}
int Stack_B::get_size() 
{
    return size + 1;
}
