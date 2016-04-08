/*
   Detect loop in a linked list 
   List could be empty also
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
int HasCycle(Node* head)
{
	if(head == NULL || head->next == NULL) return 0;
	Node* tortoise = head->next;
	Node* hare = head->next->next;
	while(1) {
		if(tortoise == hare) return 1;
		if(hare == NULL || hare->next == NULL) return 0;
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	// Complete this function
	// Do not write the main method
}
