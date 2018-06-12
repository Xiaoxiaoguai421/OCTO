## 实验六 ##

实验目的与要求：掌握动态规划方法的基本思想与设计策略。

1. 最长公共子序列问题
【问题描述】
- 给定两个字符串X和Y，设计一个动态规划算法，求出这两个字符串的最长公共子序列，并输出该子序列。

设L[i][j]表示x[1...i]与y[1...j]的最长公共子序列长度，则DP递推式:

<a href="https://www.codecogs.com/eqnedit.php?latex=L(i,j)=\left\{\begin{matrix}&space;&&space;1&plus;L(i-1,j-1),x[i]=y[j]\\&space;&&space;max(L(i-1,j),L(i,j-1)),x[i]\neq&space;y[j]\\&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?L(i,j)=\left\{\begin{matrix}&space;&&space;1&plus;L(i-1,j-1),x[i]=y[j]\\&space;&&space;max(L(i-1,j),L(i,j-1)),x[i]\neq&space;y[j]\\&space;\end{matrix}\right." title="L(i,j)=\left\{\begin{matrix} & 1+L(i-1,j-1),x[i]=y[j]\\ & max(L(i-1,j),L(i,j-1)),x[i]\neq y[j]\\ \end{matrix}\right." /></a>

若需要输出最长公共子序列，可用表D[][]记录每次选择，递归输出最长公共子序列

- 若仅要求求出两个字符串的最长公共子序列的长度值，为节省存储空间，采用“滚动数组”方式实现动态规划算法。

表L[][]保存了所有情况，若只需要求最长公共子序列的长度，则计算第i行时只要用到上一行即可，所以可以用二维数组滚动数组L[2][]记录当前行和上一行的情况.
index\_pre即i-1，index\_now即i

2. 0-1背包问题
【问题描述】
给定n种物品和一背包。物品i的重量是wi，其价值为vi，背包的容量为W（假定物品重量与背包容量值均为整数），应如何选择装入背包中的物品，使得装入背包中物品的总价值最大？设计一个动态规划算法，求解背包问题。

设L(w,i)表示背包容量w,物品1...i的最大总价值，则DP方程为:
<a href="https://www.codecogs.com/eqnedit.php?latex=L(w,i)=\left\{\begin{matrix}&space;&&space;0,i=0&space;\&space;or&space;\&space;w=0\\&space;&&space;L(w,i-1),w_{i}>w\\&space;&&space;max(&space;L(w,i-1),L(w-w_{i},i-1)&plus;p_{i}),otherwise\\&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?L(w,i)=\left\{\begin{matrix}&space;&&space;0,i=0&space;\&space;or&space;\&space;w=0\\&space;&&space;L(w,i-1),w_{i}>w\\&space;&&space;max(&space;L(w,i-1),L(w-w_{i},i-1)&plus;p_{i}),otherwise\\&space;\end{matrix}\right." title="L(w,i)=\left\{\begin{matrix} & 0,i=0 \ or \ w=0\\ & L(w,i-1),w_{i}>w\\ & max( L(w,i-1),L(w-w_{i},i-1)+p_{i}),otherwise\\ \end{matrix}\right." /></a>

~~~
//base case
for (int i = 0; i < w + 1; i++)
    a[i][0] = 0;
for (int i = 0; i < n + 1; i++)
    a[0][i] = 0;
//for
for (int i = 1; i < w + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
        if (i < weight[j - 1]) //当前背包重量小于物品，不装
        {
            a[i][j] = a[i][j - 1];
        } else {
            if (a[i][j - 1] <= a[i - weight[j - 1]][j - 1] + price[j - 1]) {
                a[i][j] = a[i - weight[j - 1]][j - 1] + price[j - 1];
            } else
                a[i][j] = a[i][j - 1];
          }
     }
}
~~~
