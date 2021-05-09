#include <iostream>
#include <fstream>
#include "data_structs.h"

using namespace std;

int main(){
    Queue queue;
    queue.init();

    ifstream input;
    input.open("data.txt");

    while(!input.eof()){
        Process* process= new Process;

        input>>process->name;
        input>>process->priority;
        input>>process->arrival_time;
        input>>process->task_count;

        process->task_stack.init();

        process->deadline=process->arrival_time;

        Subtask* subtask_new;
        for(int i=0; i<process->task_count;i++){
            subtask_new=new Subtask;
            input>>subtask_new->name;
            input>>subtask_new->duration;

            process->task_stack.push(subtask_new);
            process->deadline=process->deadline+subtask_new->duration;

        }

        queue.queue(process);
    }


    int current_time=0;
    int priority2_count=0;
    int lateness=0;
    MultiQueue multiqueue;
    multiqueue.init();

    while((!queue.isEmpty())||(!multiqueue.isEmpty(1))||(!multiqueue.isEmpty(2))||(!multiqueue.isEmpty(3))){

        for(Process*p=queue.head; p; p=p->next){
            if(p->arrival_time<=current_time){
                Process* temp=new Process;
                temp=queue.dequeue();
                multiqueue.queue(temp);
            }
        }

            Subtask* temp=new Subtask;
            string temp_name;
            if(!multiqueue.isEmpty(1)){
                temp_name=multiqueue.queues[0].head->name;
                temp=multiqueue.queues[0].head->task_stack.pop();
            }

            else{
                if(priority2_count==2){
                    if(!multiqueue.isEmpty(3)){
                        temp_name=multiqueue.queues[2].head->name;
                        temp=multiqueue.queues[2].head->task_stack.pop();
                    }
                    else{
                        temp_name=multiqueue.queues[1].head->name;
                        temp=multiqueue.queues[1].head->task_stack.pop();
                    }
                    priority2_count=0;
                }
                else if(!multiqueue.isEmpty(2)){
                    temp_name=multiqueue.queues[1].head->name;
                    temp=multiqueue.queues[1].head->task_stack.pop();
                    priority2_count++;
                }
                else{
                    temp_name=multiqueue.queues[2].head->name;
                    temp=multiqueue.queues[2].head->task_stack.pop();
                    priority2_count=0;
                }
            }

            current_time=current_time+temp->duration;
            cout<<"temp_name"<<" "<<temp->name<<endl;

            for(int i=1;i<4;i++){
                if(multiqueue.queues[i].isEmpty()){
                    lateness=lateness + current_time - multiqueue.queues[i].head->deadline;
                    multiqueue.queues[i].dequeue();
                }
            }
            delete temp;


    }

    cout<<"Cumulative Lateness: "<<lateness<<endl;

    system("pause");
    return EXIT_SUCCESS;
}