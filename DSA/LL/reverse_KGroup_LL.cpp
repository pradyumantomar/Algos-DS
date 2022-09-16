/****************************************************************
    Following is the Linked List node structure

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


Node* kReverse(Node* head, int k) {
    
    if(head == NULL){
        return NULL;
    }

    // step 1 -> create node 

    Node * forward  = NULL;
    Node * prev = NULL;
    Node * curr = head;
    int count = 0;

    // loop for k
    while(curr != NULL  && count < k ){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = kReverse(forward,k);
    }

    return prev;


}