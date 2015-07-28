#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}Node;

Node* addElement(Node* list, int val) {
	Node* cp = list;
	Node* newNode;
	if(list == NULL) {
		list = (Node*)malloc(sizeof(Node));
		list->val = val;
		list->next = NULL;
		printf("list->val = %d\n", list->val);
	} else {
		while(cp->next != NULL) cp = cp->next;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->val = val;
		newNode->next = NULL;
		printf("newNode->val = %d\n", newNode->val);
		cp->next = newNode;
	}
	return list;
}

void showList(Node* list) {
	Node* cp = list;
	while(cp != NULL) {
		printf("%d\t", cp->val);
		cp = cp->next;
	}
	printf("\n");
}

Node* removeElements(struct ListNode* head, int val) {
	Node* cp = head;
	Node* prev = head;
    while(cp != NULL) {
      if(head->val == val) {
    	  head = head->next;
    	  cp = head;
    	  prev = head;
      } else {
    	  if(cp->val != val) {
    		  prev = cp;
    		  cp = cp->next;
    	  } else {
    		  prev->next = cp->next;
    		  cp = cp->next;
    	  }
      }
    }
    return head;
}

int main() {
	Node* list = NULL;
	list = addElement(list, 6);
	list = addElement(list, 6);
	list = addElement(list, 6);
	list = addElement(list, 6);
	list = addElement(list, 6);
	list = addElement(list, 6);
	list = addElement(list, 5);
	showList(list);
	list = removeElements(list, 6);
	showList(list);
	return 0;
}
