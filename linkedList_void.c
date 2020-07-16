#include <stdlib.h>
#include <stdio.h>
#include "linkedList_void.h"

Status is_greater(Element num1, Element num2) {
  return *(int *)num1 > *(int *)num2;
};

Element save_num(int value) {
  int *result = malloc(sizeof(int));
  *result = value;
  return result;
};

Node_ptr create_node(Element element){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->element = element;
  new_node->next = NULL;
  return new_node;
};

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
};

void display_list(List_ptr list){
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d\n",*(int *)p_walk->element);
    p_walk = p_walk->next;
  }
};

Status add_to_list( List_ptr list, Element element) {
  Node_ptr new_node = create_node(element);
  if(list->first == NULL) list->first = new_node;
  else list->last->next = new_node;
  list->last = new_node;
  list->length++;
  return Success;
}

void swap(Element *value1, Element *value2){
  Element *temp = *value1;
  *value1 = *value2;
  *value2 = temp;
};

void selection_sort(List_ptr list, Matcher matcher) {
  Node_ptr max_p_walk = list->first,p_walk;
  while (max_p_walk != NULL) {
    p_walk = max_p_walk;
    while (p_walk != NULL) {
      if((*matcher)(max_p_walk->element, p_walk->element)) swap(max_p_walk->element,p_walk->element);
      p_walk = p_walk->next;
    }
    max_p_walk = max_p_walk->next;
  }
};

void bubble_sort(List_ptr src, Matcher matcher){
  Node_ptr p_walk = src->first, next_p_walk = p_walk->next;
  for(size_t i = 0; i < src->length; i++) {
    while(next_p_walk != NULL) {
      if((*matcher)(p_walk->element,next_p_walk->element)) swap(p_walk->element,next_p_walk->element);
      p_walk = next_p_walk;
      next_p_walk = next_p_walk->next;
    }
  }
};

void arrange(List_ptr src, int to, int from) {
  Node_ptr p_walk = src->first;
  for(size_t i = 0; i < from; i++)
   p_walk = p_walk->next;
  for(size_t j = from; j < to; j++)
   swap(p_walk->element,p_walk->next->element);
};

void insertion_sort(List_ptr src, Matcher matcher) {
  Node_ptr initial_p_walk = src->first,p_walk;
  for(size_t i = 0; i < src->length; i++) {
    p_walk = src->first;
    for(size_t j = 0; j <= i; j++) {
      if((*matcher)(p_walk->element,initial_p_walk->element)) {
        arrange(src,i,j);
        break;
      }
      p_walk = p_walk->next;
    }
    initial_p_walk = initial_p_walk->next;
  }
};