/*********************************************************************
** Program Filename: list
** Author: Michael Friesen
** Date: 6/7/2018
** Description: functions to sort a linked list
** Input: user enters integers
** Output: a sorted linked list
*********************************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*********************************************************************
** Function: length
** Description: gets the length of the list
** Parameters: the list
** Pre-Conditions: the list is taken in
** Post-Conditions: the length of the list is returned
*********************************************************************/ 
int length(struct node *head){
	int count = 0;
	struct node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

/*********************************************************************
** Function: print
** Description: prints the linked list
** Parameters: the list is the only necessary parameter
** Pre-Conditions: the list is taken in
** Post-Conditions: the list is printed
*********************************************************************/ 
void print(struct node *head, int num){
	struct node *current = (struct node *)malloc(sizeof(struct node));
	current = head;
	while(current != NULL){
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
}

/*********************************************************************
** Function: push
** Description: the list has a node added to the front
** Parameters: the list and the desired node
** Pre-Conditions: the parameters are taken in
** Post-Conditions: the list has a node added to the front
*********************************************************************/ 
struct node * push(struct node *head, int num){
	struct node *current = (struct node *)malloc(sizeof(struct node));
	current->val = num;
	current->next = head;
	return current;
}

/*********************************************************************
** Function: append
** Description: the list has a node appended to the back
** Parameters: the list and a node to add
** Pre-Conditions: the parameters are taken in
** Post-Conditions: the node is added to the back of the list
*********************************************************************/ 
struct node * append(struct node *head, int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *current = NULL;

	if(head == NULL){
		head = (struct node *)malloc(sizeof(struct node));
		head->val = num;
		head->next = NULL;
		return head;
	}

	temp->val = num;
	temp->next = NULL;
	current = head;

	while(current->next != NULL){
		current = current->next;	
	}
	current->next = temp;
	return head;
}

/*********************************************************************
** Function: clear
** Description: the list is freed
** Parameters: the head node is taken in
** Pre-Conditions: the head node is taken in
** Post-Conditions: the list is cleared
*********************************************************************/ 
struct node * clear(struct node *head){
	struct node *temp = NULL;
	struct node *current = NULL;

	current = head;
	while(current != NULL){
		temp = current->next;
		free(current);
		current = temp;
	}
	head = NULL;
	current = NULL;
	return head;
}

/*********************************************************************
** Function: remove node
** Description: removes a specified node
** Parameters: the head node and the index of the node to remove
** Pre-Conditions: the parameters are taken in
** Post-Conditions: the specified node is removed
*********************************************************************/ 
struct node * remove_node(struct node *head, int index){
	struct node *current = NULL;
	struct node *prev = head;
	int i = 0;

	if(index > length(head)){
		printf("Remove: Out of Range\n");
	}
	else if(index == 0){
		printf("No node to remove\n");
	}
	else{
		for(i = 0; i < index - 1; i++){
			prev = prev->next;
		}
		if(index == length(head)){
			current = prev->next;
			prev->next = NULL;
		}
		else{
			current = prev->next;
			prev->next = current->next;
		}
		free(current);
	}
	return head;
}

/*********************************************************************
** Function: sort ascending
** Description: sorts the list from smallest to largest
** Parameters: the head node
** Pre-Conditions: the head node is passed in
** Post-Conditions: the list is sorted accordingly
*********************************************************************/ 
struct node * sort_ascending(struct node *head){
	struct node *temp = head;
	struct node *tracker = NULL;
	bool indicator;

	if(length(head) == 1){
		return head;
	}
	indicator = false;
	while(indicator == false){  
		indicator = true;
		if(head->val > head->next->val){			
			temp = head;  
			head = head->next;
			temp->next = head->next;  	
			head->next = temp;
		}
		tracker = head;
		while(tracker->next != NULL){
			if(tracker->val > tracker->next->val){
				indicator = false;
			}
			tracker = tracker->next;
		}
		if(indicator == false){
			head->next = sort_ascending(head->next);
		}
	}
	
	return head;
}

/*********************************************************************
** Function: sort descending
** Description: sorts the list from largest to smallest
** Parameters: the head node
** Pre-Conditions: the head is passed in
** Post-Conditions: the list is sorted accordingly
*********************************************************************/ 
struct node * sort_descending(struct node *head){
	struct node *temp = head;
	struct node *tracker = NULL;
	bool indicator;

	if(length(head) == 1){
		return head;
	}
	indicator = false;
	while(indicator == false){  
		indicator = true;
		if(head->val < head->next->val){			
			temp = head;  
			head = head->next;
			temp->next = head->next;  
			head->next = temp;
		}
		tracker = head;
		while(tracker->next != NULL){
			if(tracker->val < tracker->next->val){
				indicator = false;
			}
			tracker = tracker->next;
		}
		if(indicator == false){
			head->next = sort_descending(head->next);
		}
	}
	return head;
}

/*********************************************************************
** Function: insert middle
** Description: inserts a node into the middle of the list
** Parameters: the head node, a number to insert and the index are input
** Pre-Conditions: the conditions are passed in
** Post-Conditions: the node is added to the list
*********************************************************************/ 
struct node * insert_middle(struct node *head, int num, int index){
	struct node *current = head;
	struct node *prev = head;
	struct node *insert = (struct node*)malloc(sizeof(struct node));
	int i = 0;

	insert->val = num;
	if(index > length(head)){
		printf("Insert: Out of Range\n");
		free(insert);
	}
	else if(index == 0){
		head->next = insert;
		insert->next = NULL;
	}
	else{
		for(i = 0; i < index-1; i++){
			prev = prev->next;
		}
		for(i = 0; i < index; i++){
			current = current->next;
		}
		insert->next = current;
		prev->next = insert;
	}
	return head;
}