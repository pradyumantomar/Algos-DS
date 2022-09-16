void solve(stack<int>&inputStack, int counter, int N){
    
    int size = N/2;
    if (counter  == size){
        inputStack.pop();
        return;
    }
    
    int data = inputStack.top();
    inputStack.pop();
    counter++;
    solve(inputStack , counter, N);
    
    inputStack.push(data);
    
}


void deleteMiddle(stack<int>&inputStack, int N){
	
    int counter = 0;
    solve(inputStack , counter, N);
}