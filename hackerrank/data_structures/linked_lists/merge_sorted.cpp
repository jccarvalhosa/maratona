/*
   Merge two sorted lists A and B as one linked list
   Node is defined as 
   struct Node
   {
   int data;
   struct Node *next;
   }
 */
Node* MergeLists(Node *headA, Node* headB)
{
	if(headA == NULL) return headB;
	if(headB == NULL) return headA;
	if(headA->data < headB->data) {
		headA->next = MergeLists(headA->next, headB);
		return headA;
	}
	headB->next = MergeLists(headA, headB->next);
	return headB;
	// This is a "method-only" submission. 
	// You only need to complete this method 
}
