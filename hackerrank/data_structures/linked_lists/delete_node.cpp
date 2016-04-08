/*
   Delete Node at a given position in a linked list 
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
Node* Delete(Node *head, int position)
{
	if(position == 0) return head->next;
	Node* temp = head;
	for(int i=0;i<position-1;i++) temp = temp->next;
	temp->next = temp->next->next;
	return head;

	// Complete this method
}
