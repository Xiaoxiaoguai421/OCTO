## 实验六 ##
实验要求：
  编写一个三角形类，能根据3个实数构造三角形对象，如果3个实数不满足三角形的条件，则自动构造以最小值为边的等边三角形。输入任意3个数，输出构造的三角形面积.

1. 判断abc能否构成三角形 
  <a href="https://www.codecogs.com/eqnedit.php?latex=\left\{\begin{matrix}&space;&&space;mid&plus;min>max\\&space;&&space;max-mid<min&space;\end{matrix}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?\left\{\begin{matrix}&space;&&space;mid&plus;min>max\\&space;&&space;max-mid<min&space;\end{matrix}\right." title="\left\{\begin{matrix} & mid+min>max\\ & max-mid<min \end{matrix}\right." /></a>

~~~
//排序并判断能否构成三角形
int max,mid,min;
max=(a > b)?a:b;
max=(max > c)?max:c;
if(max==a)
	mid=(b > c)?b:c;
	min=(b > c)?c:b;
else if(max==b)
	mid=(a > c)?a:c;
	min=(a > c)?c:a;
else if(max==c)
	mid=(a > b)?a:b;
	min=(a > b)?b:a;
if( (max<(mid+min)) && (min>(max-mid)) )
	true;
else
	false;

~~~


2. 三角形面积计算公式--海伦公式（设边a,b,c,半周长p）
<a href="https://www.codecogs.com/eqnedit.php?latex=s=\sqrt{p(p-a)(p-b)(p-c))}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?s=\sqrt{p(p-a)(p-b)(p-c))}" title="s=\sqrt{p(p-a)(p-b)(p-c))}" /></a>

