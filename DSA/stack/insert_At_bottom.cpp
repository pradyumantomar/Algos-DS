void solve(stcak<int> myStack , int x){
     if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int data = myStack.top();
    myStack.pop();
    solve(myStack, x);

    myStack.push(x);

    return myStack;
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
   solve(myStack,x);
   return myStack;
}
