#include <stdio.h>
#include <stdlib.h>

//how_many algorithm
int comp_up(const void *a , const void *b)
{
	return *(int *)a - *(int *)b;
}

int binary_find(int *array , int key , int low , int high)
{
	int middle;
	
	while(low <= high)
	{
		middle = (low + high) / 2;
		
		if(array[middle]>key)
		{
			high = middle - 1;
		}
		else if(array[middle] < key)
		{
			low = middle + 1;
		}
		else
			return middle;
	}
	
	return -1;
}

//internet
//http://blog.csdn.net/jeanphorn/article/details/46351475
int binary_find_(int *a , int len , int num, int isLeft)
{
    int left = 0, right = len -1;
	
    int pos,mid;
	
    while(left <= right)
    {
        mid = (left + right)/2;
		
        if( a[mid] < num )
        {
            left = mid +1;
        }
        else if(a[mid] > num)
        {
            right = mid -1;
        }
        else
        {
            pos = mid;
			
            if(isLeft)//查找最左值 指定key的最左边出现的位置
            {
                right = mid -1;
            }
            else//查找最右值 指定key的最右边出现的位置
            {
                left = mid +1;
            }
        }
    }
    return pos;//返回最终查找到的位置 最左或最右
}
/*
int main()
{
int a[10] = { 1,2,3,4,4,4,4,6,8,9};

  int left , right, dst = 4;
  
    left = FindCntofNum(a,10,4,true);
    right = FindCntofNum(a,10,4,false);
	
	  printf("count of number %d : %d\n",dst,right - left+1);
	  
		return 0;
		}
*/
//end
//http://blog.csdn.net/jeanphorn/article/details/46351475

int main(void)
{
	int min_pos;
	int max_pos;
	
	int array[10] = {1,1,2,3,4,5,6,8,8,8};
	
	int key = 2;
	
	max_pos = min_pos = binary_find(array , key , 0 , 9);
	
	if(min_pos == -1)
	{
		puts("no");
		return 1;
	}
	
	//forward
	for(; min_pos ; min_pos --)
	{
		if(array[min_pos] == key)
			continue ;
		else
		{
			min_pos ++;
			break;
		}
	}
	
	for( ; max_pos<10 ; max_pos ++)
	{
		if(array[max_pos] == key)
			continue ;
		else
		{
			max_pos --;
			break;
		}
	}
	if(max_pos == 10)
		max_pos = 9;
	
	printf("%d\n", max_pos - min_pos + 1);
	
	return 0;
}