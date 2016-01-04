#include <stdio.h>
#include <assert.h>
#include "array_util.h"

void test_create_returns_new_array_utils(){
  ArrayUtil arr_util =create(4,2);
  assert(arr_util.length ==2);
  assert(arr_util.type_size ==4);
  printf("\n✓ test_create_returns_new_array_utils\n\n");
};

void test_create_wheather_the_values_are_0_after_allocating_memmory(){
  ArrayUtil arr_util = create(4,2);
  assert(((int *)arr_util.base)[0]==0);
  assert(((int *)arr_util.base)[1]==0);
  printf("✓ test_create_wheather_the_values_are_0_after_allocating_memmory\n\n");
}
void test_areEqual_returns_1_when_both_are_equal(){
  ArrayUtil arr1 = create(4,9);
  ArrayUtil arr2 = create(4,9);
  assert(areEqual(arr1,arr2)==1);
  printf("✓ test_areEqual_returns_1_when_both_are_equal\n\n");
};

void test_areEqual_returns_0_when_their_type_size_is_different(){
  ArrayUtil arr1 = create(8,3);
  ArrayUtil arr2 = create(4,3);
  assert(areEqual(arr1,arr2)==0);
  printf("✓ test_areEqual_returns_0_when_their_type_size_is_different\n\n");
};

void test_areEqual_returns_0_when_their_length_is_different(){
  ArrayUtil arr1 = create(4,4);
  ArrayUtil arr2 = create(4,5);
  assert(areEqual(arr1,arr2)==0);
  printf("✓ test_areEqual_returns_0_when_their_length_is_different\n\n");
};

void test_for_resize_array_to_add_more_length_of_the_array(){
  ArrayUtil arr_util = create(4,5);
  printf("Collected :type_size = %d , length = %d , base = %p\n",arr_util.type_size,arr_util.length,arr_util.base);
  ArrayUtil new_arr_util = resize(arr_util,6);
  printf("Expected :type_size = %d , length = %d , base = %p\n",4,6,arr_util.base);
  assert(new_arr_util.base == arr_util.base);
  assert(new_arr_util.length == 6);
  assert(arr_util.type_size == 4);
  printf("✓ test_for_resize_array_to_add_more_length_of_the_array\n\n");
};
void test_for_resize_array_to_reduce_length_of_the_array(){
  ArrayUtil arr_util = create(4,5);
  printf("Collected :type_size = %d , length = %d , base = %p\n",arr_util.type_size,arr_util.length,arr_util.base);
  ArrayUtil new_arr_util = resize(arr_util,3);
  printf("Expected :type_size = %d , length = %d , base = %p\n",4,3,arr_util.base);
  assert(new_arr_util.base == arr_util.base);
  assert(new_arr_util.length == 3);
  assert(arr_util.type_size == 4);
  printf("✓ test_for_resize_array_to_reduce_length_of_the_array\n\n");
};

int main (void){
  test_create_returns_new_array_utils();
  test_create_wheather_the_values_are_0_after_allocating_memmory();
  test_areEqual_returns_1_when_both_are_equal();
  test_areEqual_returns_0_when_their_type_size_is_different();
  test_areEqual_returns_0_when_their_length_is_different();
  test_for_resize_array_to_add_more_length_of_the_array();
  test_for_resize_array_to_reduce_length_of_the_array();
  return 0;
};
