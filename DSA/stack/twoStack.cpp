class TwoStack {

public:

    int *arr;
    int size;
    int top1;
    int top2;

    // Initialize TwoStack.
    TwoStack(int s) {

        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
        // Write your code here.
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
        // Write your code here.
    }

    // Push in stack 2.
    void push2(int num) {

        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }

        // Write your code here.
    }

    // Pop from stack 1 and return popped element.
    int pop1() {

        if(top1 >= 0){
            int data = arr[top1];
            top1--;
            return data;
        }
        return -1;
        // Write your code here.
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        
        
        if(top2 < size){
        int data = arr[top2];
        top2++;
        return data;
        // Write your code here.
    }
    return -1;
    }
};
