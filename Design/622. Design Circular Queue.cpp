

// APPROACH 1: USING K SIZED ARRAY
class MyCircularQueue {
private:
vector<int> q;  
int k; 
int front;
int rear; 
int count;
public:
    MyCircularQueue(int k) {
        q=vector<int>(k,-1);
        front=-1;
        rear=-1;
        this->k=k;
        count=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        rear=(rear+1)%k;
        if(front==-1) front=rear; /*first elem*/
        q[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        if(front==rear){
            q[front]=-1;
            front=rear=-1;
        }else{
            q[front]=-1;
            front=(front+1)%k;
        }

        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;

        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;

        return q[rear];
    }
    
    bool isEmpty() {
        if((front==-1 && rear==-1) || count==0) return true;

        return false;
    }
    
    bool isFull() {
        if(count==k) return true;

        return false;
    }
};


 
