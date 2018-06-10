function [ave,std]=runstats(x)
%定义静态变量
persistent n
persistent sum_x
persistent sum_x2
%检查有效性
if x=='r'
    n=0;
    sum_x=0;
    sum_x2=0;
else
    n=n+1;
    sum_x=sum_x+x;
    sum_x2=sum_x2+x^2;
end
%计算平均值
if n==0
    ave=0;
    std=0;
elseif n==1
    ave=x;
    std=0;
else
    ave=sum_x/n;
    std=sqrt((n*sum_x2-sum_x^2)/(n*(n-1)));
end

