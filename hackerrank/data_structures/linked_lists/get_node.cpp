/*
   Get Nth element from the end in a linked list of integers
   Number of elements in the list will always be greater than N.
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
int GetNode(Node *head,int positionFromTail)
{
	int n=0;
	Node *temp = head;
	while(temp != NULL) temp=temp->next, n++;
	int positionFromHead = n - 1 - positionFromTail;
	temp = head;
	for(int i=0;i<positionFromHead;i++) temp = temp->next;
	return temp->data;
	// This is a "method-only" submission. 
	// You only need to complete this method. 
}
