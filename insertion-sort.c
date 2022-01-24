#include <stdio.h>


void
insertion_sort(int *nums, int numsSize)
{

  int key, i, k = 0;  
  
  for (int j = 1; j < numsSize; j++)
    {
      key = nums[j];
      i = j - 1;

      while(i >= 0 && nums[i] > key)
	{
	  nums[i + 1] = nums[i];
	  i = i - 1;
	}

      nums[i + 1] = key;

    }
}



int
main()
{
  //int nums [6] = {8, 2, 4, 9, 3, 6};
  int nums [6] = {9, 8, 6, 4, 3, 2};
  insertion_sort(nums, 6);

  for (int i = 0; i < 6; i++)
    {
      printf("%d%c", nums[i], i == 5 ? '\n' : ' ');
    }



}
