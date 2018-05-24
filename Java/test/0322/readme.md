1. 完全数

2. 泰勒展开式

~~~
double para=1.0, sum=1.0;
for(int i=2; ;i++){
    n=2*(i-1);
    para *= x*x/(n*(n-1));
    if(para<0.000001)   break;
    if( i%2 == 0){
        sum -= para;
    }else
        sum += para;
}
~~~
