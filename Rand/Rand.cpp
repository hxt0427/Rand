// Rand.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

void Sort(int num[], int n) {
	for (int i = n; i >1; i--) 
		for(int j = 0 ; j < i-1 ; j ++)
			if (num[j] > num[j+1]) {
				int m = num[j+1];
				num[j+1] = num[j];
				num[j] = m;
			}
}

void Print(int num[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", num[i]);
	printf("\n");
}
int main() {
	int i;
	int num1[100000];
	int num2[1000000];
	int *p = num1;
	clock_t c1, c2;
	p = (int *)malloc(sizeof(int) * 100000);
	srand((int)time(0));  // 用time函数取当前时间作为随机数初始化种子
	for (i = 0; i < 100000; i++) {
		num1[i] = rand() % 1000; // 对1000求余数，实际范围0~999
	}
	c1 = clock();
	Sort(num1, 100000);
	c2 = clock();
	printf("100,000个数据排序所需时间:%d ms\n", c2 - c1);

	p = num2;
	p = (int *)malloc(sizeof(int) * 1000000);
	for (i = 0; i < 1000000; i++) {
		num1[i] = rand() % 1000; // 对1000求余数，实际范围0~999
	}
	c1 = clock();
	Sort(num1, 1000000);
	c2 = clock();
	printf("1,000,000个数据排序所需时间:%d ms\n", c2 - c1);
	return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
