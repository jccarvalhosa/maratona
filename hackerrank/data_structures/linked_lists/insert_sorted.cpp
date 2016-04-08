/*
   Insert Node in a doubly sorted linked list 
   After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
   int data;
   Node *next;
   Node *prev
   }
 */
Node* SortedInsert(Node *head,int data)
{
	Node* nNode = new Node();
	nNode->data = data;
	if(head == NULL) return nNode;
	if(head->data > data) {
		nNode->next = head;
		head->prev = nNode;
		return nNode;
	}
	Node* temp = head;
	while(1) {
		if(temp->next == NULL) {
			temp->next = nNode;
			nNode->prev = temp;
			return head;
		}
		if(temp->next->data > data) {
			nNode->next = temp->next;
			temp->next->prev = nNode;
			temp->next = nNode;
			nNode->prev = temp;
			return head;
		}
		temp = temp->next;
	}
	// Complete this function
	// Do not write the main method. 
}
