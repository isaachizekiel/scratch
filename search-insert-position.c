#include <stdio.h>


int
searchInsert(int* nums, int numsSize, int target)
{

  int index = -1, left = 0, right = 0, limit = numsSize - 1;
  
  for (int i = 0; i < numsSize; i++)
    {
      left = i == 0 ? 0 : i - 1;
      
      right = i == (limit) ? limit : i + 1;

     
      if (nums[i] == target)
	{
	  index = i;
	}
    }

  return index;
}

int
main()
{


  int nums[6] = {1, 3, 6, 9, 12, 100};  
  int target = -1;
  
  
  int res = searchInsert(nums, 6, target);

  printf("%d\n", res);
  
}
