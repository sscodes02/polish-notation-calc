#include <iostream>
#include "list.h"
#include <stdexcept>
using namespace std;

List::List()
{
    try
    {
        sentinel_head = new Node(true);
        sentinel_tail = new Node(true);
        sentinel_tail->prev = sentinel_head;
        sentinel_head->next = sentinel_tail;
        sentinel_head->prev = NULL;
        sentinel_tail->next = NULL;
        size=0;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

List::~List()
{
    Node *temp = sentinel_head;
    while (temp->next != NULL)
    {
        Node *v = temp->next;
        v->prev=NULL;
        temp->next=NULL;
        delete temp;
        temp = v;
    }
    delete sentinel_tail;
}
void List::insert(int v)
{
    try
    {
        Node *temp = new Node(v, NULL,NULL);
        sentinel_tail->prev->next=temp;
        temp->prev=sentinel_tail->prev;
        sentinel_tail->prev=temp;
        temp->next=sentinel_tail;
        size++;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}
int List::delete_tail()
{

    if (sentinel_tail->prev == sentinel_head)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        int tail_val = sentinel_tail->prev->get_value();
        Node *actual_tail = sentinel_tail->prev;
        sentinel_tail->prev = actual_tail->prev;
        actual_tail->prev->next = sentinel_tail;
        actual_tail->next = NULL;
        actual_tail->prev = NULL;
        delete actual_tail;
        size--;
        sentinel_tail->prev->next = sentinel_tail;
        return tail_val;
    }
}
int List::get_size()
{
    return size;
}
Node *List::get_head()
{
    return sentinel_head;
}
