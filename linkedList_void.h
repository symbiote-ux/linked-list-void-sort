#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  Failure,
  Success
} Status;

typedef void *Element;

typedef struct node
{
  Element element;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct linklist
{
  Node *first;
  Node *last;
  int length;
} LinkedList;
  
typedef LinkedList *List_ptr;

typedef Status (*Matcher)(Element, Element);

Node_ptr create_node(Element element);
List_ptr create_list(void);
Element save_num(int value);
Status is_greater(Element num1, Element num2);

Status add_to_list(List_ptr, Element);

void swap(Element *, Element *);
void arrange(List_ptr src, int to, int from);
void selection_sort(List_ptr, Matcher);
void bubble_sort(List_ptr, Matcher);
void insertion_sort(List_ptr, Matcher);
void display_list(List_ptr);
#endif