/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
   int data;
   Node* next;
   }
 */
int FindMergeNode(Node *headA, Node *headB)
{
	int nA=0, nB=0;
	for(Node *temp=headA;temp!=NULL;temp=temp->next) nA++;
	for(Node *temp=headB;temp!=NULL;temp=temp->next) nB++;
	while(nA > nB) headA = headA->next, nA--;
	while(nB > nA) headB = headB->next, nB--;
	while(headA != NULL) {
		if(headA == headB) return headA->data;
		headA = headA->next;
		headB = headB->next;
	}
	// Complete this function
	// Do not write the main method. 
}
