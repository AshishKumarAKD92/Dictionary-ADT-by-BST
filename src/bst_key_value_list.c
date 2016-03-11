


#include "bst.h"
#include <list.h>
#include <queue.h>







int bst_keys(const BST *tree, List *keyList) {
	
	ListElem *n;
	BNode *node;
	Queue nodeQ;
	
	queue_init(&nodeQ, 0);
	list_init(keyList, 0);
	n = list_head(keyList);
	
	/* Use Inorder algorithm to get a Sorted Key sequence (might be convenient) */
	bst_inorder(tree, bst_root(tree), &nodeQ);
	
	while (queue_size(&nodeQ) > 0) {
		
		queue_dequeue(&nodeQ, (void **) &node);
		
		if (bst_isInternal(node)) {
			
			list_ins_next(keyList, n, (const void *) node->key);
			n = list_tail(keyList);
		}
	}
	
	queue_destroy(&nodeQ);
	return 0;
}




int bst_elements(const BST *tree, List *elementList) {
	
	ListElem *n;
	BNode *node;
	Queue nodeQ;
	
	queue_init(&nodeQ, 0);
	list_init(elementList, 0);
	n = list_tail(elementList);
	
	/* Use Inorder algorithm to get a Sorted Element sequence (According to Keys) */
	bst_inorder(tree, bst_root(tree), &nodeQ);
	
	while (queue_size(&nodeQ) > 0) {
		
		queue_dequeue(&nodeQ, (void **) &node);
		
		if (bst_isInternal(node)) {
			
			list_ins_next(elementList, n, (const void *) node->element);
			n = list_tail(elementList);
		}
	}
	
	queue_destroy(&nodeQ);
	return 0;
}