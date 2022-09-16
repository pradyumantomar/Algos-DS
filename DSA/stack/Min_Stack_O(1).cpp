//Tc - O(N) 
// SC - O(1)

// if s.top() < minElement  this is an indication for operations
// pushed Element = 2 * ele  - minElement  =>  update this as minElement
//  minElement  = 2 * minElement  - Stacktop => s.pop()


class Solution{
    private:
        stack<int> s;
    public:
        int minElement = -1;
       // getting minimum element
       int getMin(){
           if(!s.empty()){
             return minElement;
           } 
           else
             return -1;
       }


       int pop(){
           if(s.empty()){
            return -1;
           }
           else{
            if(s.top() >= minElement){
                s.pop();
            }
            else{
                minElement = 2 * minElement - s.top();

            }
           }

       }

       void push(int x){
           
           if(s.empty()){
            s.push(x);
            x = minElement;
           }
           else{
            if( x < minElement  ){
                s.push( 2 * minElement - x );
                minElement = x;
            }
           }

       }

       };