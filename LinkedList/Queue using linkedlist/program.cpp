#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:
    Node* head;
    int length;
    Stack(){
        this->head = NULL;
        this->length = 0;
    }
    void enqueue(int data){
        
    }
    int dequeue(){

    }
    int rear(){

    }
    int front(){

    }
};




int main(){







    return 0;
}
