void insertAtBottom(stack<int> &stack , int ele){

    if(stack.empty()){
        stack.push(ele);
        return;
    }

    int data = stack.top();

    stack.pop();

    insertAtBottom(stack , ele);

    stack.push(data);
}

void reverseStack(stack<int> &stack) {
    
    if(stack.empty()){
        return;
    }

    int data = stack.top();

    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, data);
}