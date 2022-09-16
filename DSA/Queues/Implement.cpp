class Queue {

    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {

        size =  100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {

        if(qfront == rear){
            return true;
        }

        return false;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {

        if(rear != size){
            arr[rear] = data;
            rear++;
        }
        // Implement the enqueue() function
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront == rear){
            rear = 0;
            qfront = 0;
        }
        return ans;
        // Implement the dequeue() function
    }

    int front() {
        if(qfront == rear){
            return -1;
        }

        return arr[qfront];
        // Implement the front() function
    }
};