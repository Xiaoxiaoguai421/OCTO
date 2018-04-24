## 实验六 ##

实验目的与要求：掌握动态规划方法的基本思想与设计策略。

1. 最长公共子序列问题
【问题描述】
- 给定两个字符串X和Y，设计一个动态规划算法，求出这两个字符串的最长公共子序列，并输出该子序列。

设L[i][j]表示x[1...i]与y[1...j]的最长公共子序列长度，则DP递推式:

<a href="https://www.codecogs.com/eqnedit.php?latex=L(i,j)=\left\{\begin{matrix}&space;&&space;1&plus;L(i-1,j-1),x[i]=y[j]\\&space;&&space;max(L(i-1,j),L(i,j-1)),x[i]\not\equiv&space;y[j]\\&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?L(i,j)=\left\{\begin{matrix}&space;&&space;1&plus;L(i-1,j-1),x[i]=y[j]\\&space;&&space;max(L(i-1,j),L(i,j-1)),x[i]\not\equiv&space;y[j]\\&space;\end{matrix}\right." title="L(i,j)=\left\{\begin{matrix} & 1+L(i-1,j-1),x[i]=y[j]\\ & max(L(i-1,j),L(i,j-1)),x[i]\not\equiv y[j]\\ \end{matrix}\right." /></a>

若需要输出最长公共子序列，可用表D[][]记录每次选择，递归输出最长公共子序列

- 若仅要求求出两个字符串的最长公共子序列的长度值，为节省存储空间，采用“滚动数组”方式实现动态规划算法。

表L[][]保存了所有情况，若只需要求最长公共子序列的长度，则计算第i行时只要用到上一行即可，所以可以用二维数组滚动数组L[2][]记录当前行和上一行的情况.
index\_pre即i-1，index\_now即i

2. 0-1背包问题
【问题描述】
给定n种物品和一背包。物品i的重量是wi，其价值为vi，背包的容量为W（假定物品重量与背包容量值均为整数），应如何选择装入背包中的物品，使得装入背包中物品的总价值最大？设计一个动态规划算法，求解背包问题。

