%运行脚本
%初始值
B=[0.9 1.8 2.3 1.2 2.1 2.8];
x0=[70000 70000 70000 70000 70000 25000];

%产生线性不等式系数矩阵A和向量b：Ax<b
A=zeros(2,6);
for ii=1:6
    A(1,ii)=-1/(16*pi*B(ii)^2);
end
for ii=1:6
    A(2,ii)=1/(16*pi*B(ii)^2);
end
ii=0;
b=[-600*37.5;900*37.5];

%线性等式约束
Aeq=[1 1 1 1 1 1];
Beq=375000;

%范围
Lb=[0 0 0 0 0 0];
Ub=[375000 375000 375000 375000 375000 375000];

%求解
options=optimset('LargeScale','off','Display','final');
[x,fval,exitflag,output]=fmincon('fun1',x0,A,b,Aeq,Beq,Lb,Ub,'fun2',options)