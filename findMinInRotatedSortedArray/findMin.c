#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize) {
    int minIndex = 0;
    int maxIndex = numsSize - 1;
    int midIndex = 0;

    if (nums[0] < nums[numsSize - 1])
    	return nums[0];

    while (minIndex < maxIndex - 1)
    {
    	midIndex = minIndex + ((maxIndex - minIndex) >> 1);

   		if (nums[midIndex] > nums[minIndex])
   		{
    		minIndex = midIndex;
    	}
    	else
    	{
    		maxIndex = midIndex;
    	}
    }
    
    return (nums[minIndex] < nums[maxIndex]) ? nums[minIndex] : nums[maxIndex];
}

int main(int argc, char *argv[])
{
	//int testcase[] = {9,0,1,2,3,4,5,6,7,8};
	//int testcase[] = {3,4,5,6,7,8,9,0,1,2};
	int testcase[] = {};
	printf("min: %d\n", findMin(testcase, sizeof(testcase)));

	return 0;
}


