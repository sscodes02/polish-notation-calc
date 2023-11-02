
#include <iostream>
#include "stack_a.h"
#include <stdexcept>

using namespace std;

Stack_A::Stack_A()
{
    size = -1;
}

void Stack_A::push(int data)
{
    if (size >= 1023)
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[++size] = data;
    }
}
int Stack_A::pop()
{
    if (size == -1)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        return stk[size--];
    }
}

int Stack_A::get_element_from_top(int idx)
{
    if (size == -1)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[size-idx];
    }
}
int Stack_A::get_element_from_bottom(int idx)
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
void Stack_A::print_stack(bool top_or_bottom)
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
}

int Stack_A::add()
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

int Stack_A::subtract()
{
    if (size < 1)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int m = pop();
        int n = pop();
        int p = n-m;
        stk[++size] = p;
        return p;
    }
}

int Stack_A::multiply()
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

int Stack_A::divide()
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
            int n=pop();
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

int *Stack_A::get_stack()
{
    return stk;
}
int Stack_A::get_size()
{
    return size+1;
}
