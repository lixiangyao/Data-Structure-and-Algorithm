/*
* Writen By 李相垚
* Email：lixiangyao@outlook.com 
* 仅供参考和学习 
* License：AL2.0 
*/ 


#include <stdio.h>
#include <windows.h>

void hanoi(int n, char start, char middle, char target);
void move(int n, char start, char target);

int cnt = 0;

int main(void)
{
	int n = 0;
	
	printf("请输入汉诺塔层数：");
	scanf("%d",&n);
	printf("\n");
	
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	hanoi(n, ch1, ch2, ch3); 
	return 0;
}

void hanoi(int n, char start, char middle, char target)
{
	if(1 == n)
		move(n, start, target);    //如果n = 1，就直接将层从起始柱移到目标柱 
	else
	{
		hanoi(n-1, start, target, middle);  //将上面n-1层从起始柱经过目标柱移动到中间柱
		move(n, start, target);  //第n层移动到目标柱，完成
		hanoi(n-1, middle, start, target);  //递归将剩下的n-1层从中间柱移动到目标柱 
	}
	
	return;
}

void move(int n, char start, char target)
{
	cnt++;  //用全局变量记录移动次数 
	//printf("  %d:将第%d层从%c--->%c\n\n",cnt,n,start,target);  //这里的移动是移动一层 
	if(start == 'A' && target == 'B')
		printf("    第%d步:将第%d层\n      -------->\n     *         *         *\n     *         *         *\n     *         *         *\n     *         *         *\n   *****     *****     *****\n     A         B         C\n\n",cnt,n);
	else if(start == 'A'  && target == 'C')
		printf("    第%d步:将第%d层\n     ------------------->\n     *         *         *\n     *         *         *\n     *         *         *\n     *         *         *\n   *****     *****     *****\n     A         B         C\n\n",cnt,n);
	else if(start == 'B' && target == 'C')
		printf("    第%d步:将第%d层\n                -------->\n     *         *         *\n     *         *         *\n     *         *         *\n     *         *         *\n   *****     *****     *****\n     A         B         C\n\n",cnt,n);
	else if(start == 'C' && target == 'A')
		printf("    第%d步:将第%d层\n      <------------------\n     *         *         *\n     *         *         *\n     *         *         *\n     *         *         *\n   *****     *****     *****\n     A         B         C\n\n",cnt,n);
	else if(start == 'C' && target == 'B')
		printf("    第%d步:将第%d层\n                <--------\n     *         *         *\n     *         *         *\n     *         *         *\n     *         *         *\n   *****     *****     *****\n     A         B         C\n\n",cnt,n);
	else if(start == 'B' && target == 'A')	
		printf("    第%d步:将第%d层\n      <--------\n     *         *         *\n     *         *         *\n     *         *         *\n     *         *         *\n   *****     *****     *****\n     A         B         C\n\n",cnt,n);
	//为了好看^_^，将打印的信息用符号编辑为汉诺塔的形状，并指示从哪根柱子移动到哪根 
	
	return;
}

