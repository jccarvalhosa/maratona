/*
	Reverse a doubly linked list, input list may also be empty
	Node is defined as
	struct Node
	{
	int data;
	Node *next;
	Node *prev
	}
  */
Node* Reverse(Node* head)
{
	if(head == NULL || head->next == NULL) return head;
	Node* temp = head->next;
	head->next = NULL;
	while (temp != NULL) {
		Node* aux = temp->next;
		temp->next = head;
		head->prev = temp;
		head = temp;
		temp = aux;
	}
	head->prev = NULL;
	return head;
	// Complete this function
	// Do not write the main method. 
}
