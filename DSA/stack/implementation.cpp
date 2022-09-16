#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int *arr;
        int top ;

        Stack(int size){
            this->size = size;
            arr = new int[size];
            this->top = -1;
        }

        void push(int data){
            if(size - top  > 1){
                top++;
                arr[top] = data;
            }
            else{
                cout<<"Stack overflow\n";
            }
        }

        void pop(){
             if(top >= 0){
                top--;
             }
             else{
                cout<<"Stack Underflow\n";
             }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        int peek(){
            if(top == -1){
                cout<<"UnderFlow\n";
                return -1;
            }
            int data = arr[top];
            top--;
            return data;
        }


};



int main(){
    
    Stack obj = Stack(3);
    obj.push(5);
    obj.push(10);
    obj.push(15);
    obj.push(15);
    obj.pop();
    obj.pop();
    obj.pop();
    obj.push(69);
    cout<<obj.peek()<<endl;
    cout<<obj.isEmpty()<<endl; 
    



    return 0;
}