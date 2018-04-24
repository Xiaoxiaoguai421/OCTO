## 实验五 ##

实验目的与要求：掌握动态规划方法的基本思想与设计策略。

1. 最长递增子序列问题
【问题描述】
给定一个整数数组，设计一个动态规划算法求出该数组中的最长递增子序列。

设L(i)表示a[1...i]的最长递增子序列长度，则DP递推式：

<a href="https://www.codecogs.com/eqnedit.php?latex=L(i)=\left\{\begin{matrix}&space;&&space;max(L(j)&plus;1),a[j]<a[i]\\&space;&&space;1,a[j]\geqslant&space;a[i]\\&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?L(i)=\left\{\begin{matrix}&space;&&space;max(L(j)&plus;1),a[j]<a[i]\\&space;&&space;1,a[j]\geqslant&space;a[i]\\&space;\end{matrix}\right." title="L(i)=\left\{\begin{matrix} & max(L(j)+1),a[j]<a[i]\\ & 1,a[j]\geqslant a[i]\\ \end{matrix}\right." /></a>

若要输出最长递增子序列，可增加一维用于记录前驱结点

~~~
设L(i)表示以i为结点的最长递增子序列的长度，L(0)=1
for k=0 to i-1
	if	a[k] < a[i]:	L(i)=max(L[k]+1);
if all a[k] > a[i]:	L[i]=1;
~~~
时间复杂度为O(n^2),若输出最长子序列，可用prev[]记录前驱结点，找到最长递增子序列的终点i，然后回溯输出最长递增子序列。

2. 矩阵连乘问题
【问题描述】
给定n个矩阵{A1，A2，…,An},其中AiAi+1是可乘的，i=1，2，…，n-1,考察这n个矩阵的连乘积A1A2…An，设计一个动态规划算法，求出这个矩阵连乘积问题的最优计算顺序。
实现要求：随机生成n个合法的可连乘的矩阵，以完全加括号的方式输出其最优计算顺序。

