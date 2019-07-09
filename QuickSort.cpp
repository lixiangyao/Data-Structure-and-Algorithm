#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *, int low, int high);
int FindPos(int *, int low, int high);

int main(void)
{
	int n = 100000;  //数组长度，因为用于测试排序速度，设置了千万数据的长度，笔记本i5 8300H平均3.7-3.8s  
/*
	printf("输入数组长度：");    //可以手动输入数组长度 
	scanf("%d",&n);
*/	
	int * arr = (int *)malloc(sizeof(int)*n);  //用malloc()函数动态分配内存 
	//printf("请输入数组的元素：");
	srand(time(NULL));  //根据当前时间生成seed，实现随机数 

	for(int i = 0; i < n; ++i)
		arr[i] = rand();    
		//scanf("%d",&arr[i]);    //可以随机产生数据，也可以手动输入 
/*	
	printf("原始随机数据：\n");  //因为打印到控制台太费时间，所以暂时注释掉 
	for(int i = 0; i < n; ++i)
		printf("%d ",arr[i]); 
*/			
	QuickSort(arr,0,n-1);  //快排函数 
/*	
	printf("\n\n快排后数据：\n");  //因为打印到控制台太费时间，所以暂时注释掉
	for(int i = 0; i < n; ++i)
		printf("%d ",arr[i]); 
*/	
	return 0;
}

void QuickSort(int * arr, int low, int high)
{
	int pos;
	if(low < high)
	{
		pos = FindPos(arr, low, high);
		QuickSort(arr, low, pos-1);
		QuickSort(arr, pos+1, high);
	}
	
	return;
}

int FindPos(int * arr, int low, int high)
{
	int val = arr[low];
	
	while(low < high)
	{
		while(low < high && arr[high] >= val)
			--high;
		arr[low] = arr[high];
		while(low < high && arr[low] <= val)
			++low;
		arr[high] = arr[low];
	}
	
	arr[low] = val;  //此时low已经指向val代表的值该在位置，将该位置赋值为val
	return low;  //则返回此时val的为位置下标 
}


