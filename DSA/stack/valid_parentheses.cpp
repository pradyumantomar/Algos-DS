bool matches(char top, char ch){
    if(ch == ')' and top == '('){
        return true;
    }
     if(ch == '}' and top == '{'){
        return true;
    }
     if(ch == ']' and top == '['){
        return true;
    }

    return false;
}

bool isValidParenthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        // opening bracket
        if(ch == '(' or ch == '{' or ch == '['){
            s.push(ch);
        }
        else{
            // closing bracket

            if(!s.empty()){
                char top = s.top(); 
                if(matches(top,ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
    

}