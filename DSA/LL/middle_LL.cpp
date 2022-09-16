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

int getLength(Node* head){
    int len = 0 ;
    while(head != nullptr){
        len++;
        head = head->next;
    }

    return len;
}


Node *findMiddle(Node *head) {
    int len  = getLength(head);

    int mid  = len/2  ;

    Node* temp = head;
    while(mid--){
        temp = temp->next;
    }

    return temp;
} 