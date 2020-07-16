#include "linkedList_void.h"

int main(void) {
  List_ptr list = create_list();
  Element num1 = save_num(3);
  add_to_list(list, num1);
  Element num2 = save_num(1);
  add_to_list(list, num2);
  Element num3 = save_num(2);
  add_to_list(list, num3);
  selection_sort(list, &is_greater);
  bubble_sort(list, &is_greater);
  insertion_sort(list, &is_greater);
  display_list(list);
  return 0;
}