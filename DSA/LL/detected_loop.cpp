#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

bool detectCycle(Node *head)
{
	if(head == NULL){
        return false;
    }
    
    map<Node * , bool> visited;
    Node * temp = head;
    
    while(temp != nullptr){
        if(visited[temp] == true){
            return true;
        }
        
        visited[temp]=true;
        temp = temp->next;
        
    }
    return false;
    
    
}