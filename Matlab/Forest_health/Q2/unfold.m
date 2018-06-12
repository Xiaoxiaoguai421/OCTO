%等式、不等式符号表示 
%用于展开，求c(1) c(2)
syms x1 x2 x3 x4 x5 x6 B1 B2 B3 B4 B5 B6 n1 n2 n3 n4 n5 n6
x=[x1,x2,x3,x4,x5,x6];
n=[n1,n2,n3,n4,n5,n6];
B=[B1,B2,B3,B4,B5,B6];
syms sum_N sum_xB sum_ni
sum_N=sum_N-sum_N;
sum_xB=sum_xB-sum_xB;
sum_ni=sum_ni-sum_ni;
num=6;
for ii=1:num
    n(ii)=x(ii)/(16*pi*B(ii)^2);
    sum_N=sum_N+n(ii);
    sum_xB=sum_xB+x(ii)/(16*pi);
    sum_ni=sum_ni+n(ii)*(n(ii)-1);
end
g(1)=sum_ni/(sum_N*(sum_N-1));
g(2)=( 10*(n(1)+n(4)) + 20*(n(2)+n(5)) + 30*(n(3)+n(6)) )/sum_N;
g(3)=sqrt(sum_xB/sum_N);
g(4)=(10*n(1)+20*n(2)+30*n(3)+36*n(4)+30*n(5)+30*n(6) )/sum_N;