/*
   Reverse a linked list and return pointer to the head
   The input list will have at least one element  
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
Node* Reverse(Node *head)
{
	Node* temp = head->next;
	head->next = NULL;
	while(temp != NULL) {
		Node *aux = temp->next;
		temp->next = head;
		head = temp;
		temp = aux;
	}
	return head;

	// Complete this method
}
