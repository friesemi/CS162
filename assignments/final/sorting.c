#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *);
void add_num(int **, int *, int);

int main(){
   int *nums=NULL;
   int size=0;
   time stop, start;

   fill_array(&nums, &size);
   print_array(nums, size);

   //Time the function here
   gettimeofday(&start, NULL);
   
   //bubble_sort(nums, size);
   //insertion_sort(nums, size);
   //merge_sort(nums, 0, size-1);
   selection_sort(nums, size);

   gettimeofday(&stop, NULL);

   printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
   //printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

   print_array(nums, size);
   free(nums);

   return 0;
}

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of 
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
   int i;

   printf("The array elements are:\n");
   for(i=0; i<size; i++)
      printf("%d\t", nums[i]);
   printf("\n\n");
}

/***********************************************************************
* Description: Sorts the sections of the list that are partitioned by merge_sort and combines them with other sorted sections
* Parameters: the lsit of numbers, and the left, middle, and right partition sizes
* Returns: a sorted list is returned
* Pre-Conditions: the list must be furnished and the sides and middle are determined in merge_sort
* Post-Conditions: each partition is sorted and combines with the next partition and sorted
***********************************************************************/
void merge(int *nums, int left, int mid, int right){
   int i, j, lower_half, upper_half;
   int temp[(right-left)+1];

   lower_half=left;  //What is this for?
                     //This gives a variable to check the ever-shrinking size of the partitions of the left side of data
   upper_half=mid+1;  //What is this for?
                      //This gives a variable to check the ever_shrinking size of the partitions of the right side of the data
   
   //What does this loop do?
   //This loop makes sure that every partition is sorted, from when they are a single element, all the way to when they are sorted completely
   for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
      //What does this condition do?
      //This will comapare two number from the right and left partitions and stores the left value in a temp to be swapped and sorted
      if(nums[lower_half]<=nums[upper_half]){
    temp[i]=nums[lower_half];
    lower_half++;
      }
      //What does this condition do?
      //This stores the value of the right partition in a temp to be swapped later
      else{
    temp[i]=nums[upper_half];
    upper_half++;
      }
   }

   //What does this condition and loop do?
   //This will insert the temporary values to be sorted from the lower partition and places them in the upper partition
   if(lower_half>mid)
      for(j=upper_half;j<=right;j++, i++)
    temp[i]=nums[j];
   //What does this else and loop do?
   //This will do the opposite of the previous condition and place the temp values into the lower partition from the upper partition
   else
      for(j=lower_half;j<=mid;j++, i++)
    temp[i]=nums[j];

   //What does this loop do?
   //This will combine the left and right partitions after they are sorted to begin sorting again on larger partitions
   for(j=0,i=left;i<=right;i++,j++)
      nums[i]=temp[j];
}

/***********************************************************************
* Description: splits the list into partitions and individually sorts the decreasing sized partitions with recursion
* Parameters: the original list of numbers, and two sets of the list consisting of the middle, left and right pieces of the list
* Returns: the sorted list is returned after all the recursive calls have finished
* Pre-Conditions: the list ust be furnished, and the left and right must be initialized
* Post-Conditions: the list is sorted and returned
***********************************************************************/
void merge_sort(int *nums, int left, int right) {
   int mid; 
   if(left<right) {
      mid=(right+left)/2;
      merge_sort(nums, left, mid);  //what does this call do?
      //This will half the left half of the list until it is 1 element on each side to split the list up
      merge_sort(nums, mid+1, right); //what does this call do?
      //This will do the same as the previous call, but make another set of divided elements to sort
      merge(nums, left, mid, right);  //what does this call do?
      //This will call the sorting function that will sort each side of the list and work back up the ladder recursively, combining each side
      //as it goes up
   }
}

/***********************************************************************
* Description: Takes the first element and compares to each element to put the smallest element in front, then repeats the process with the
*              second element and so on
* Parameters: the list of numbers and the size of the list
* Returns: the sorted list is returned
* Pre-Conditions: the list is furnished  and the size is determined
* Post-Conditions: the elements are compared and swapped until the list is sorted
***********************************************************************/
void selection_sort(int *nums, int size) {
   int i, j;
   int temp, min;

   //What does this loop do?
   //This loop repeats the process of finding smallest element after each pass finishes to find the smallest element following the previous
   //smallest element
   for(i=0; i<size-1; i++) {
      min=i;
      //What does this loop do?
      //This loop runs through each element, looking for the smallest element in the still unsorted list and adds it to the left most position,
      //moving right after each pass
      for(j=i; j<size; j++)
    if(nums[j]<nums[min]) 
       min=j;
      //What elements are being swaped?
      //The smallest element that is found in the list is swapped with whichever the element to the left most is to get it to the front(left)
      //of the list
      temp=nums[i];
      nums[i]=nums[min];
      nums[min]=temp;
   }
}

/***********************************************************************
* Description: Sorts the list by creating a partition at the first element and comparing the first two elements, then move the partiton right one
*              and compare the two separated elements, moving as necessary
* Parameters: the list of numbers and the size of the list
* Returns: the sorted list is returned
* Pre-Conditions: the list is furnished and the size is determined
* Post-Conditions: the list is sorted and printed
***********************************************************************/
void insertion_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   //This loop will move the partition one to the right until the end of the list where it should be sorted
   for(i=0; i<size; i++) {
      temp=nums[i]; 
      //What does this loop do?
      //This loop compares the element to the right of the partition to the element to the left and the next elements if it is still
      //smaller than the other elements
      for(j=i; j>0 && nums[j-1]>temp; j--) 
    nums[j]=nums[j-1];
      //What does this statment do?
      //This statement will swap the elements that are being compared by moving it to the right and placing the lower element on the left
      nums[j]=temp;
   }
}

/***********************************************************************
* Description: sorts the list by comparing two adjacent elements, swapping if necessary, then moving to the next two elements
* Parameters: a list of numbers and the size of the numbers
* Returns: a sorted list of numbers from smallest to largest
* Pre-Conditions: the list must be filled and the size determined
* Post-Conditions: the list is sorted
***********************************************************************/
void bubble_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   //This loop starts at the first elements and runs through the list an amount equal to the size times to ensure the list is sorted
   for(i=0; i<size; i++) {
      //What does this loop do?
      //This loop compares two adjacent elements and flips them if necessary and then compares the next element with the second previous element
      for(j=0; j<size-i-1; j++) {
    if(nums[j]>nums[j+1]) {
       temp=nums[j];
       nums[j]=nums[j+1];
       nums[j+1]=temp;
    }
      }
   }
}

/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num){
   int *old_nums, i;

   *size+=1;
   old_nums=*nums;
   *nums=(int *) malloc(sizeof(int)*(*size));

   for(i=0; i<*size-1; i++)
      (*nums)[i]=old_nums[i];
   (*nums)[*size-1]=num;

   free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
   FILE *fptr;
   char filename[20], num[10];

   //printf("Enter the filename: ");
   //scanf("%s",filename); 
   fptr=fopen("lists.txt","r");

   while(fscanf(fptr,"%s", num)!=EOF){
      add_num(nums, size, atoi(num));
   }

   fclose(fptr);
}