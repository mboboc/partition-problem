#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <stdlib.h>
/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------
/**
 *  Linked list representation -- R2 Curs2 (Slide 8)
 */
typedef int Item;
typedef struct ListNode{
	Item elem; // Stored node value
	struct ListNode* next; // link to next node
	struct ListNode* prev; // link to prev node
} ListNode;

/**
 *  Double linked list representation -- desen Curs 3 (Slide 19)
 */
typedef struct List{
	ListNode* first; // link to the first node
	ListNode* last; // link to the last node
}List;
// -----------------------------------------------------------------------------

/**
 * Create a new (empty)  list  -- Silde-urile 13/14 Curs 2
 *  [input]: None
 *  [output]: List*
 */
List* createList(void){
	List* NewList = NULL;
	NewList = (List* )malloc(sizeof(List));
	NewList->first = NULL;
	NewList->last = NULL;

	return NewList;
}
// -----------------------------------------------------------------------------


/**
 * Determines if the list is empty
 *  [input]: List*
 *  [output]: 1 - empty/ 0 - not empty
 */
int isEmpty(List *list){
	if(list->first == NULL && list->last == NULL)
		return 1;
	else 
		return 0;
}
// -----------------------------------------------------------------------------


/**
 * Determines if a list contains a specified element
 *  [input]: List*, Item
 *  [output]: int (1 - contains/ 0 - not contains)
 */
int contains(List *list, Item elem){
	ListNode* current;
	current = list->first;

	if(isEmpty(list) == 1)
		return 0;
	while(current != NULL) {
		if(current->elem == elem)
			return 1;
	}

	return 0;
}
// -----------------------------------------------------------------------------



/**
 * Insert a new element in the list at the specified position.
 * Note: Position numbering starts with the position at index zero
 *  [input]: List*, Item, int
 *  [output]: void
 */
int length(List *list) {
	// Guard against young player errors
	if(list == NULL) return 0;

	ListNode *current = list->first;
	int count = 0;

	while(current != NULL){
		count = count + 1;
		current = current->next;
	}

	return count;
}
void insertAt(List* list, Item elem, int pos) {

	// Guard against young player errors
	if(list == NULL) {
		printf("Lista e nula\n");
		return;
	}
	if( pos < 0 || pos > length(list))
		return;

	ListNode *newNode;
	newNode =(ListNode *)malloc(sizeof(ListNode));
	newNode->elem = elem;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(pos == 0) {
		if(isEmpty(list)) {
			list->first = newNode;
			list->last = newNode;
		} else {
			newNode->next = list->first;
			list->first->prev = newNode;
			list->first = newNode;
		}
	} else {
		int i;
		ListNode *current = list->first;
		for(i = 0; i < pos; i++) {
			current = current->next;
		}

		if(current == NULL) {
			newNode->prev = list->last;
			list->last->next = newNode;
			list->last = newNode;
		} else {
			newNode->next = current;
			newNode->prev = current->prev;

			current->prev->next = newNode;
			current->prev = newNode; 
		}
	}
}
// -----------------------------------------------------------------------------


/**
 * Delete the first element instance from a list.
 *  [input]: List*, Item
 *  [output]: void
 */
void deleteOnce(List *list, Item elem){
	// Guard against young player errors
	if(list == NULL) return;
	if(isEmpty(list)) return;
	ListNode *current = list->first;
	
	if(list->first->elem == elem) {
		if(list->first == list->last) {
			free(list->first);
			list->first = list->last = NULL; 
		} else {
			list->first = list->first->next;
			free(list->first->prev);
			list->first->prev = NULL;
		}
	} else {
		while(current != NULL) {
			if(current->elem == elem) break;
			current = current->next;
		}
		if(current == NULL) return;
		if(current->next == NULL){
			list->last = list->last->prev;
			list->last->next = NULL;
			free(current);
		}
		current->next->prev = current->prev;
		current->prev->next = current->next;
		free(current);
	}
}
// -----------------------------------------------------------------------------


/**
 * Compute list length
 *  [input]: List*
 *  [output]: int
 */
// -----------------------------------------------------------------------------



/**
 * Destroy a list.
 *  [input]: List*
 *  [output]: void
 */
void destroyList(List* list){
	// Guard against young player errors
	if(list == NULL) return;
	ListNode *p = list->first;
	ListNode *aux;
	while(p != NULL) {
		aux = p;
		p = p->next;
		free(aux);
	}
	free(list);
	list = NULL;
}
// -----------------------------------------------------------------------------


#endif //_DOUBLE_LINKED_LIST_H_
