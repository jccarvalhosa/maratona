/*
   Insert Node at a given position in a linked list 
   The linked list will not be empty and position will always be valid
   First element in the linked list is at position 0
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
Node* InsertNth(Node *head, int data, int position)
{
	Node* nNode = new Node();
	nNode->data = data;
	if(position == 0) {
		nNode->next = head;
		return nNode;
	}
	Node* temp = head;
	for(int i=0;i<position-1;i++) temp = temp->next;
	nNode->next = temp->next;
	temp->next = nNode;
	return head;
	// Complete this method only
	// Do not write main function. 
}
