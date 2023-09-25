#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node()
    {
        // this->data = 0;
        this->next = NULL;
    }
    Node(T x)
    {
        this->data = x;
        this->next = NULL;
    }
};

template <typename T>
class list
{
    Node<T> *head;
    int length;

public:
    list()
    {
        head = NULL;
        length = 0;
    }
    void push_back(T value)
    {
        Node<T> *node = new Node(value);
        if (head == NULL)
        {
            head = node;
            length++;
            return;
        }
        Node<T> *ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
        length++;
        return;
    }
    void push_front(T value)
    {
        Node<T> *node = new Node(value);
        node->next = head;
        head = node;
        length++;
        return;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty!!!";
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        free(temp);
        length--;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty!!!";
            return;
        }
        if (head->next == NULL)
        {
            head = NULL;
            length--;
            return;
        }
        Node<T> *ptr = head;
        while (ptr->next->next)
        {
            ptr = ptr->next;
        }
        Node<T> *temp = ptr->next->next;
        ptr->next = NULL;
        free(temp);
        length--;
        return;
    }
    // delete all elements with value 20
    void remove(T x)
    {
        return;
    }
    Node<T> *front()
    {
        return head;
    }
    Node<T> *back()
    {
        // FIXME
        return head;
    }
    int size()
    {
        return length;
    }
    Node<T> *begin()
    {
        return head;
    }
    Node<T> *end()
    {
        // FIXME
        return head;
    }
    void print()
    {
        Node<T> *ptr = head;
        while (ptr)
        {
            cout << " " << ptr->data << "->";
            ptr = ptr->next;
        }
        return;
    }
};

int main()
{
    list<int> li;
    li.push_back(1);
    li.push_back(3);
    li.print();

    list<char> li1;
    li1.push_back(1);
    li1.push_back(2);
    li1.push_back(3);
    li1.push_back(4);
    li1.push_back(97);
    li1.push_back(65);
    li1.print();

    return 0;
}
