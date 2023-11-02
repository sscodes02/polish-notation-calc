#include <iostream>
#include "stack_c.h"
#include <stdexcept>

using namespace std;
Stack_C::Stack_C()
{

    try
    {
        stk = new List;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}
Stack_C::~Stack_C()
{
    delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);
}

int Stack_C::pop()
{

    int q = stk->delete_tail();
    return q;
}

int Stack_C::get_element_from_top(int idx)
{
    int k = stk->get_size();
    if (idx >= k)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        Node *temp = stk->get_head();
        for (int i=0; i<k-idx ; i++)
        {
            temp = temp->next;
        }
        int r = temp->get_value();
        return r;
    }
}

int Stack_C::get_element_from_bottom(int idx)
{
    int k = stk->get_size();
    if (idx >= k)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        Node *temp = stk->get_head();
        for (int i = 0; i <= idx; i++)
        {
            temp = temp->next;
        }
        int r = temp->get_value();
        return r;
    }
}

void Stack_C::print_stack(bool top_or_bottom)
{
    int k=stk->get_size();
    if (k==0)
    {
        return;
    }
    else
    {
        if (top_or_bottom)
        {
            Node *temp = stk->get_head();
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp=temp->prev;
            while(temp->prev!=NULL)
            {
                cout << temp->get_value() << endl;
                temp = temp->prev;
            }
        }
        else
        {
            Node *temp = (stk->get_head())->next;
            while (temp->next !=NULL)
            {
                cout << temp->get_value() << endl;
                temp = temp->next;
            }
        }
        return;
    }
}
int Stack_C::add()
{
    int k=stk->get_size();
    if (k <2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int m = stk->delete_tail();
        int n = stk->delete_tail();
        int p = m + n;
        stk->insert(p);
        return p;
    }
}

int Stack_C::subtract()
{
    int k=stk->get_size();
    if (k < 2)
    {
        throw runtime_error("Not Enough Arguments");
        int m = stk->delete_tail();
        int n = stk->delete_tail();

        int p = n-m;
        stk->insert(p);

        return p;
    }
    else
    {
        int m = stk->delete_tail();
        int n = stk->delete_tail();

        int p = n-m;
        stk->insert(p);

        return p;
    }
}

int Stack_C::multiply()
{
    int k=stk->get_size();
    if (k >= 2)
    {
        int m = stk->delete_tail();
        int n = stk->delete_tail();

        int p = m * n;
        stk->insert(p);

        return p;
    }
    else
    {
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_C::divide()
{
    int k=stk->get_size();
    if (k >= 2)
    {
        int m = stk->delete_tail();
        int n = stk->delete_tail();
        if (m == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {

            int p = n / m;
            if (n * m < 0 && n%m!=0)
            {
                p = p - 1;
            }

            stk->insert(p);
            return p;
        }
    }
    else
    {
        throw runtime_error("Not Enough Arguments");
    }
}

List *Stack_C::get_stack()
{
    return stk;
}

int Stack_C::get_size()
{
    int i = stk->get_size();
    return i;
}