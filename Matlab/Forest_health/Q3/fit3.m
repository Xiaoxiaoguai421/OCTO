% x=[0.9;1.8;2.3;1.2;2.1;2.8];
% y=[7;15;21;11;17;26];

%云南松
x=[0.9;1.8;2.3];
y=[7;15;21];

%冷杉
% x=[1.2;2.1;2.8];
% y=[11;17;26];

p=fittype('1.3+a*(x^b)','independent','x');
opt=fitoptions(p);
opt.StartPoint=[1 1];
[f gof]=fit(x,y,p,opt)
plot(f,x,y)