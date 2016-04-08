/*
   Remove all duplicate elements from a sorted linked list
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
Node* RemoveDuplicates(Node *head)
{
	if(head->next == NULL) return head;
	if(head->next->data == head->data) {
		head->next = head->next->next;
		RemoveDuplicates(head);
	}
	else RemoveDuplicates(head->next);
	return head;
	// This is a "method-only" submission. 
	// You only need to complete this method. 
}
