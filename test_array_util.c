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

void test_for_finding_index_of_the_value_if_it_is_in_the_array(){
  ArrayUtil arr_util=create(4,5);
  ((int *)arr_util.base)[3]=5;
  int ele = 5;
  assert(findIndex(arr_util,&ele)==3);
  printf("✓ test_for_finding_index_of_the_value_if_it_is_in_the_array\n\n");
};

void test_for_finding_index_of_the_value_which_is_not_in_the_array(){
  ArrayUtil arr_util=create(4,5);
  ((int *)arr_util.base)[3]=4;
  int ele = 5;
  assert(findIndex(arr_util,&ele)== -1);
  printf("✓ test_for_finding_index_of_the_value_which_is_not_in_the_array\n\n");
};

void test_for_dispose(){
  ArrayUtil arr_util=create(4,5);
  dispose(arr_util);
  printf("✓ test_for_dispose\n\n");
};

void insertElements(ArrayUtil *list, void *array) {
	char *arrayByBit = array;
	char *baseByBit = list->base;
	for(int i=0; i<(list->length)*(list->type_size); i++){
			baseByBit[i]=arrayByBit[i];
	}
};

int isEven(void* hint, void* item){
  int *value = item;
  if((*value)%2 == 0) return 1;
  return 0;
};

int isDivisible(void* hint, void* item){
  int *dividend = item;
  int *devisor = hint;
  if((*dividend)%(*devisor)==0) return 1;
  return 0;
};

void test_findfirst_gives_the_first_element_that_matches_the_critiria() {
  ArrayUtil arr_util = create(4,5);
  int array[] = {1,2,3,4};
  MatchFunc *f = &isEven;
  insertElements(&arr_util,array);
  int *element = findFirst(arr_util,f,NULL);
  assert(*element==2);
  printf("✓ test_findfirst_gives_the_first_element_that_matches_the_critiria\n\n");
};

void test_findfirst_gives_null_when_does_not_match_the_critiria() {
  ArrayUtil arr_util = create(4,5);
  int array[] = {1,2,3,4};
  int ele = 5;
  MatchFunc *f = &isDivisible;
  insertElements(&arr_util,array);
  void *element = findFirst(arr_util,f,&ele);
  assert(element==NULL);
  printf("✓ test_findfirst_gives_null_when_does_not_match_the_critiria\n\n");
};

void test_findLast_returns_pointer_of_the_first_element_from_last_that_matches_criteria_for_isDivisible() {
  ArrayUtil arr_util = create(4, 5);
	int array[] = {1,2,3,4,5};
	int ele = 5;
	int *element;
	insertElements(&arr_util, array);
	element = findLast(arr_util, isDivisible, &ele);
	assert(*element==5);
	dispose(arr_util);
  printf("✓ test_findLast_returns_pointer_of_the_first_element_from_last_that_matches_criteria_for_isDivisible\n\n");
};

void test_findLast_returns_NULL_if_none_of_the_elements_matches_criteria_for_isDivisible () {
  ArrayUtil arr_util = create(4, 5);
	int array[] = {1,2,3,4,5};
  int ele = 7;
	int *element;
	insertElements(&arr_util, array);
	element = findLast(arr_util, isDivisible, &ele);
	assert(element==NULL);
	dispose(arr_util);
  printf("✓ test_findLast_returns_NULL_if_none_of_the_elements_matches_criteria_for_isDivisible\n\n");
};


void test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria() {
  ArrayUtil arr_util = create(4, 5);
	int array[] = {1,2,3,4,5};
	int element;
	insertElements(&arr_util, array);
	element = count(arr_util, isEven, NULL);
	assert(element==2);
	dispose(arr_util);
  printf("✓ test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria\n\n");

};

void test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria_for_isDivisible() {
  ArrayUtil arr_util = create(4, 5);
	int array[] = {1,2,3,4,5};
	int element;
	int ele = 2;
	insertElements(&arr_util, array);
	element = count(arr_util, isDivisible, &ele);
	assert(element==2);
	dispose(arr_util);
  printf("✓ test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria_for_isDivisible\n\n");
};

void test_count_returns_ZERO_if_none_of_the_elements_matches_given_criteria() {
	int array[] = {1,3,5,7,9};
	int element;
	ArrayUtil arr_util = create(4, 5);
	insertElements(&arr_util, array);
	element = count(arr_util, isEven, NULL);
	assert(element==0);
	dispose(arr_util);
  printf("✓ test_count_returns_ZERO_if_none_of_the_elements_matches_given_criteria\n\n");
};

void test_for_filter_which_provide_filtered_array_and_length_of_elements(){
  ArrayUtil arr_util = create(4,5);
  int array[] ={2,3,4,5,9};
  insertElements(&arr_util,array);
  ArrayUtil is_even = create(4,2);
  int matching_elements = filter(arr_util,isEven,NULL,is_even.base,is_even.length);
  assert(matching_elements == 2);
  int*ptr =is_even.base;
  printf("✓ test_for_filter_which_provide_filtered_array_and_length_of_elements\n\n");
};

void test_filter_gives_the_filtered_array_and_returns_length_0_when_no_item_found(){
  ArrayUtil arr_util = create(4,5);
  int array[] ={2,3,4,5,9};
  int ele = 7;
  insertElements(&arr_util,array);
  ArrayUtil is_divisible_by_7 = create(4,2);
  int matching_elements = filter(arr_util,isDivisible,&ele,is_divisible_by_7.base,is_divisible_by_7.length);
  assert(matching_elements == 0);
  printf("✓ test_filter_gives_the_filtered_array_and_returns_length_0_when_no_item_found\n\n");
};

void convert_to_even(void* hint, void* sourceItem, void* destinationItem){
  if(*(int*)sourceItem %2 ==0)
    *(int *)destinationItem = *(int *)sourceItem;
  else
    *(int*)destinationItem = (*(int*)sourceItem)+1;
};

void test_map_by_using_a_converting_function_and_formed_an_destination_array_after_convertion(){
  ArrayUtil arr_util_source = create(4,5);
  ArrayUtil arr_util_destination = create(4,5);
  ArrayUtil expected_array = create(4,5);
  int array[] ={4,6,8,6,4};
  insertElements(&expected_array,array);
  int elements[] ={3,5,7,6,4};
  insertElements(&arr_util_source,elements);
  map(arr_util_source,arr_util_destination,convert_to_even,NULL);
  int *dest = arr_util_destination.base;
  int *expect = expected_array.base;
  assert(areEqual(expected_array,arr_util_destination)==1);
  printf("✓ test_map_by_using_a_converting_function_and_formed_an_destination_array_after_convertion\n\n");

};

void pdt_of_two(void* hint, void* item){
  *(int*)item = (*(int*)item)*2;
};


void test_forEach_performs_operation_on_each_item_in_the_array(){
  ArrayUtil arr_util_source = create(4,5);
  int elements[] ={1,2,3,4,5};
  insertElements(&arr_util_source,elements);
  ArrayUtil expected_array = create(4,5);
  int array[] ={2,4,6,8,10};
  insertElements(&expected_array,array);

  forEach(arr_util_source,pdt_of_two,NULL);
  int *dest = arr_util_source.base;
  int *expect = expected_array.base;
  assert(areEqual(expected_array,arr_util_source)==1);
  printf("✓ test_forEach_performs_operation_on_each_item_in_the_array\n\n");
};

  void divide_by_hint(void* hint, void* item){
  *(int*)item = (*(int*)item)/(*(int*)hint);
};

void test_forEach_performs_operation_on_each_item_divide_by_hint_on_the_array(){
  ArrayUtil arr_util_source = create(4,5);
  int elements[] ={10,20,30,40,50};
  insertElements(&arr_util_source,elements);
  ArrayUtil expected_array = create(4,5);
  int array[] ={2,4,6,8,10};
  insertElements(&expected_array,array);
  int num = 5;
  forEach(arr_util_source,divide_by_hint,&num);
  int *dest = arr_util_source.base;
  int *expect = expected_array.base;
  assert(areEqual(expected_array,arr_util_source)==1);
  printf("✓ test_forEach_performs_operation_on_each_item_divide_by_hint_on_the_array\n\n");
};

int main (void){
  test_create_returns_new_array_utils();
  test_create_wheather_the_values_are_0_after_allocating_memmory();
  test_areEqual_returns_1_when_both_are_equal();
  test_areEqual_returns_0_when_their_type_size_is_different();
  test_areEqual_returns_0_when_their_length_is_different();
  test_for_resize_array_to_add_more_length_of_the_array();
  test_for_resize_array_to_reduce_length_of_the_array();
  test_for_finding_index_of_the_value_if_it_is_in_the_array();
  test_for_finding_index_of_the_value_which_is_not_in_the_array();
  test_for_dispose();
  test_findfirst_gives_the_first_element_that_matches_the_critiria();
  test_findfirst_gives_null_when_does_not_match_the_critiria();
  test_findLast_returns_pointer_of_the_first_element_from_last_that_matches_criteria_for_isDivisible();
  test_findLast_returns_NULL_if_none_of_the_elements_matches_criteria_for_isDivisible();
  test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria();
  test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria_for_isDivisible();
  test_count_returns_ZERO_if_none_of_the_elements_matches_given_criteria();
  test_for_filter_which_provide_filtered_array_and_length_of_elements();
  test_filter_gives_the_filtered_array_and_returns_length_0_when_no_item_found();
  test_map_by_using_a_converting_function_and_formed_an_destination_array_after_convertion();
  test_forEach_performs_operation_on_each_item_in_the_array();
  test_forEach_performs_operation_on_each_item_divide_by_hint_on_the_array();
  return 0;
};
