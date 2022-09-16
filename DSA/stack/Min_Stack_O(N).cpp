//Tc - O(N) 
// SC - O(N)


class Solution{
    private:

        // initialaize a stack for min element
        stack<int> minStack;

        // initialaize a stack for functioning for stack such as push , pop , top
        stack<int> s;

    public:
      
       // getting minimum element
       int getMin(){
            // if minStack is not empty return minStack top
            if(!minStack.empty()){
                return minStack.top();
            }
            else// else retrun -1;
                return -1;

       }


       int pop(){
           int ele = -1;
           
           // if s not empty return top of s
           if(!s.empty()){
                ele = s.top();
                s.pop();

                // if minsTack not empty check if minStack top greater than stack top 
                if(!minStack.empty()){
                    if(ele <= minStack.top())
                        minStack.pop();
                }
           }
           return ele;

       }

       void push(int x){
            s.push(x);

            // if minStack is empty push it into minStack
            if( minStack.empty() ){
                minStack.push(x);
            } // else its top greater
            else if(x <= minStack.top())
            {
                minStack.push(x);
            }
       }

       };