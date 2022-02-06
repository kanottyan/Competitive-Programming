#include<bits/stdc++.h>

using namespace std;

const int QUEUE_SIZE = 10;
const bool SUCCESS = true;
const bool FAILURE = false;

typedef int data_t;

struct ringbuffer
{
    public:
    /* data */
    data_t queue_data[QUEUE_SIZE];
    int queue_head;
    int queue_num;

    ringbuffer():queue_head(0), queue_num(0){}

    bool enqueue(data_t enq_data){
        if(queue_num < QUEUE_SIZE){
            queue_data[(queue_head + queue_num) % QUEUE_SIZE] = enq_data;
            queue_num++;
            return SUCCESS;
        }else{
            return FAILURE;
        }
    }

    bool dequeue(data_t &deq_data){
        if(queue_num > 0){
            deq_data = queue_data[queue_head];
            queue_head = (queue_head + 1)%QUEUE_SIZE;
            queue_num --;
            return SUCCESS;
        }else{
            return FAILURE;
        }
    }

    void queuePrint(){
        int i;
        printf("queue [");
        for(int i=0; i<QUEUE_SIZE; ++i){
            if( (queue_head + queue_num <= QUEUE_SIZE && queue_head <= i && i < queue_head + queue_num ) ||
                (queue_head + queue_num > QUEUE_SIZE && (queue_head <= i || i < (queue_head+queue_num)%QUEUE_SIZE))
            ){
                printf("%3d", queue_data[i]);
            }else{
                printf("%3c", '.');
            }
        }
        printf("]\n");
    }
};


int main(){
    int i;
    data_t d;

    ringbuffer r;

    for(int i=1; i<=7; ++i){
        printf("Enqueue%3d :", i);
        r.enqueue(i);
        r.queuePrint();
    }

    for(int i=1; i<=4; ++i){
        r.dequeue(d);
        printf("Dequeue%3d :", d);
        r.queuePrint();
    }

    for(int i=8; i<=15; ++i){
        printf("Enqueue%3d :", i);
        if(r.enqueue(i) == SUCCESS) r.queuePrint();
        else printf("FUll queue\n");
        
    }

    while(r.queue_num > 0){
        r.dequeue(d);
        printf("Dequeue%3d :", d);
        r.queuePrint();
    }
}