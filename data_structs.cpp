/* @Author
Student Name: <Ekin Tasyurek>
Student ID : <150190108>
Date: <13.01.2021> */

#include <iostream>
#include "data_structs.h"

using namespace std;

Subtask *temp1;
Process *temp2;

void Stack::init(){
    head=0;
}

void Stack::close(){
    Subtask *p;
    while(head){
        p = head;
        head= head->next;
        delete p;
    }
}

void Stack::push(Subtask* in){
    Subtask *newnode = new Subtask;
    newnode =in;
    newnode->next = head;
    head = newnode;
}

bool Stack::isEmpty(){
    return head == NULL;
}

Subtask *Stack::pop(){
    Subtask *topstack;
    topstack=head;
    head=head->next;
    temp1=topstack;
    delete topstack;
    return temp1;
}                         

void Queue::init(){
    head=0;
    tail=0;
}

void Queue::close(){
    Process *p;
    while(head){
        p=head;
        head=head->next;
        delete p;
    }
}

void Queue::queue(Process *in){
    Process *new_process=new Process;

    new_process=in;

    new_process->next=NULL;

    if(isEmpty()){
        tail=new_process;
        head=tail;
    }
    else{
        tail->next=new_process;
        tail=new_process;
    }
}

Process * Queue::dequeue(){
    Process *top;

    top=head;
    head=head->next;
    temp2=top;
    delete top;
    return temp2;
}

bool Queue::isEmpty(){
    return head==NULL;
}

Process * Queue::front(){
    return head;
}

void MultiQueue::init(){
    for( int i = 0; i < 3; i++){
        queues[i].head = NULL;
        queues[i].tail = NULL;
    }
}

void MultiQueue::close(){
    Process *p;
    for(int i = 0; i < 3; i++)  {
        while(queues[i].head) {
            p = queues[i].head;
            queues[i].head = queues[i].head->next;
            delete p;
        }
    }
}

void MultiQueue::queue(Process* in){ 

    queues[in->priority-1].queue(in);
}

Process * MultiQueue::dequeue(int priority){
    Process* top;
    top=queues[priority-1].head;
    queues[priority-1].head=queues[priority-1].head->next;
    temp2=top;
    delete top;
    return temp2;
}

bool MultiQueue::isEmpty(int priority){
    if(queues[priority-1].head = NULL){
        return 1;
    }
    else{return 0;}
}

Process * MultiQueue::front(int priority){
    return queues[priority-1].head;
}
