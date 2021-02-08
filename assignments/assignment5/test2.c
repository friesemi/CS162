/*********************************************************************
 * ** Program Filename: Definitions.c
 * ** Author: Ryan Kennedy
 * ** Date: 05/30/2018
 * ** Description: Definitions for the assignment 5 functions
 * ** Input: Input from the main
 * ** Output: Outputs responses to CL or to be interpreted in the main
 * *********************************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
 * ** Function: length
 * ** Description: returns how many items are in a linked list of node pointers
 * ** Parameters: node pointer of head node
 * ** Pre-Conditions: need to know how many nodes are in the linked list after a certain node
 * ** Post-Conditions: the value is returned
 * *********************************************************************/ 
int length(struct node * here){
	if(here == NULL){return 0;}
	if(here->next != NULL){return length(here->next) + 1;}
	return 1;
}

/*********************************************************************
 * ** Function: print
 * ** Description: prints out a certain number of items from a linked list of int nodes
 * ** Parameters:node pointer of head node, number of items to print
 * ** Pre-Conditions:need to print the contents of a list
 * ** Post-Conditions: printed
 * *********************************************************************/ 
void print(struct node * here, int num){
	num=num-1;
	if(num > length(here) || num < 0){printf("out of index\n");}
	if(here == NULL){printf("Doesnt exist"); return;}
	if(num == 0){printf("%d\n", here->val);return;}
	else{printf("%d\n", here->val); print(here->next, num);}	
	return;
}

/*********************************************************************
 * ** Function: push
 * ** Description: adds a value to the front of a linked list
 * ** Parameters: head node of said list, int value to add
 * ** Pre-Conditions: need to put value at front of a linked list
 * ** Post-Conditions: value is set as head of list, list head is returned
 * *********************************************************************/ 
struct node * push(struct node * here, int num){
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->next = here;
	temp->val = num;
	return temp;
}

/*********************************************************************
 * ** Function:append
 * ** Description:adds value to end of linked list
 * ** Parameters:value to add, any node pointer from the linked list
 * ** Pre-Conditions:need to append a value to the list
 * ** Post-Conditions:the value is appended and teh list is returned at the given node
 * *********************************************************************/ 
struct node * append(struct node * here, int num){
	struct node * temp;
	if(here == NULL){
		here = (struct node*)malloc(sizeof(struct node)); 
		here->val = num; here->next = NULL;
		return here;
	}
	if(here->next != NULL){here->next = append(here->next, num);return here;}
	temp = (struct node*)malloc(sizeof(struct node)); 
	temp->next = NULL;
	temp->val = num;
	here->next = temp;
	return here;
}

/*********************************************************************
 * ** Function: clear 
 * ** Description: frees all nodes from the heap and reassigns head node to NULL
 * ** Parameters: node pointer of head of list
 * ** Pre-Conditions: need to remove and free all nodes from the head
 * ** Post-Conditions: nodes are removed and freed
 * *********************************************************************/ 
struct node * clear(struct node * here){
	if(here == NULL){printf("Doesnt exist");return here;}
	if(here->next != NULL){here->next = clear(here->next);}
	free(here);
	here = NULL;
	return here;
}

/*********************************************************************
 * ** Function: remove_node 
 * ** Description: frees a node from the heap and reassigns its previous node to the next node, removing it from the list
 * ** Parameters: indexed location of node to remove, node pointer of head of list
 * ** Pre-Conditions: need to remove and free an individual node
 * ** Post-Conditions: node is removed and freed
 * *********************************************************************/ 
struct node * remove_node(struct node * here, int num){
	struct node* temp;
	if(num < 0 || num >= length(here)){printf("out of index\n"); return here;}
	if(here == NULL){printf("Doesnt exist");return here;}
	if(num == 0){
		temp = here; 
		here = here->next;
		free(temp); 
		return here;
	}
	if(num == 1){
		temp = here->next->next;
		free(here->next); 
		here->next = temp; 
		return here;
	}
	else if(here->next != NULL){
		num -=1; 
		here->next = remove_node(here->next, num);
	}
}

/*********************************************************************
 * ** Function: sort_ascending
 * ** Description: reorders the nodes in a given linked list by ascending int value
 * ** Parameters: head node of list to sort
 * ** Pre-Conditions: linked list of ints that need to be sorted
 * ** Post-Conditions: the list will be sorted and returned by the function in ascending order
 * *********************************************************************/ 
struct node * sort_ascending(struct node * here){
	struct node * temp,* where; int indicator;
	if(here == NULL){printf("Doesnt exist");return here;}
	indicator = 0;
	while(indicator == 0){
		indicator = 1;
		if(here->val > here->next->val){			
			temp = here;
			here = here->next;
			temp->next = here->next;
			here->next = temp;
		}
		where = here;
		while(where->next != NULL){
			if(where->val > where->next->val){indicator = 0;}
			where = where->next;
		}
		if(indicator == 0){here->next = sort_ascending(here->next);}
	}
	return here;
}

/*********************************************************************
 * ** Function: sort_descending
 * ** Description: reorders the nodes in a given linked list by descending int value
 * ** Parameters: head node of list to sort
 * ** Pre-Conditions: linked list of ints that need to be sorted
 * ** Post-Conditions: the list will be sorted and returned by the function in descending order
 * *********************************************************************/ 
struct node * sort_descending(struct node * here){
	struct node * temp,* where; int indicator;
	if(here == NULL){printf("Doesnt exist");return here;}
	indicator = 0;
	while(indicator == 0){  
		indicator = 1;
		if(here->val < here->next->val){			
			temp = here;  
			here = here->next;
			temp->next = here->next;  
			here->next = temp;
		}
		where = here;
		while(where->next != NULL){
			if(where->val < where->next->val){indicator = 0;}
			where = where->next;
		}
		if(indicator == 0){here->next = sort_descending(here->next);}
	}
return here;
}

/*********************************************************************
 * ** Function: insert_middle
 * ** Description: Inserts a value into a linked list of nodes at a certain location
 * ** Parameters: Node to start index from, int value to place in the list, index number of destination
 * ** Pre-Conditions: need to insert value into a list at any given point
 * ** Post-Conditions: the value is placed in the list and returned by the function
 * *********************************************************************/ 
struct node * insert_middle(struct node * here, int value, int num){
	struct node *temp;
	if(num < 0 || num > length(here)){printf("out of index\n"); return here;}
	if(here == NULL){printf("Doesnt exist"); return here;}
	if(num == 0){return push(here, value);}
	else if(num == 1){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->next = here->next;
		temp->val = value;
		here->next = temp;
	}
	else if(here->next != NULL){
		here->next = insert_middle(here->next, value, num-1);
	}
	return here;
}