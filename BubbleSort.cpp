#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int * arr, int n);

int main(void)
{
	int n = 100000;
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
	BubbleSort(arr, n);
/*	
	printf("排序后数据：\n");  //因为打印到控制台太费时间，所以暂时注释掉 
	for(int i = 0; i < n; ++i)
		printf("%d ",arr[i]); 
*/	
	return 0;	
} 

void BubbleSort(int * arr, int n)
{
	int i,j,t;
	
	for(i = 0; i < n; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;		
			}
		}
	}
	return;
}
