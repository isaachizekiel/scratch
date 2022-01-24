#include <stdio.h>
#include <stdlib.h>
/* Two Sum */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

  int size = 2;

  int *array = NULL;
  
  *returnSize = size;


  for (int i = 0; i  < numsSize; i++)
    {
      for (int j = 0; j < numsSize; j++)
	{

	  if (i == j) continue;

	  if (nums[i] + nums[j] == target)
	    {		  
	      array = (int *)malloc(sizeof(int) * size);
	      array[0] = i;
	      array[1] = j;
	      return array;		  
	    }	    

	}
    }
  
  
  return array;
}


int
main ()
{

  int retsize;
  int *ret;

  //int a [] = {2, 7, 11, 15};
  int a [] = {3, 2, 4};
  int numsize = sizeof(a)/sizeof(a[0]);
  //int target = 9;
  int target = 6;
  
  ret = twoSum(a, numsize, target, &retsize);

  if (ret == NULL)
    {
      printf("no index\n");
      return 0;
    }
  
  for (int i = 0; i < retsize; i ++)
    {
      printf("%d\n", ret[i]);
    }


}
