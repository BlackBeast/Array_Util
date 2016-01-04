#include <stdio.h>
#include <assert.h>
#include "array_util.h"

void test_create_returns_new_array_utils(){
  ArrayUtil arr_util =create(4,2);
  assert(arr_util.length ==2);
  assert(arr_util.type_size ==4);
  printf("✓ test_create_returns_new_array_utils\n");
};

void test_areEqual_returns_1_when_both_are_equal(){
  ArrayUtil arr1 = create(4,9);
  ArrayUtil arr2 = create(4,9);
  assert(areEqual(arr1,arr2)==1);
  printf("✓ test_areEqual_returns_1_when_both_are_equal\n");
};

void test_areEqual_returns_0_when_their_type_size_is_different(){
  ArrayUtil arr1 = create(8,3);
  ArrayUtil arr2 = create(4,3);
  assert(areEqual(arr1,arr2)==0);
  printf("✓ test_areEqual_returns_0_when_their_type_size_is_different\n");
};

void test_areEqual_returns_0_when_their_length_is_different(){
  ArrayUtil arr1 = create(4,4);
  ArrayUtil arr2 = create(4,5);
  assert(areEqual(arr1,arr2)==0);
  printf("✓ test_areEqual_returns_0_when_their_length_is_different\n");
};

int main (void){
  test_create_returns_new_array_utils();
  test_areEqual_returns_1_when_both_are_equal();
  test_areEqual_returns_0_when_their_type_size_is_different();
  test_areEqual_returns_0_when_their_length_is_different();
  return 0;
};
