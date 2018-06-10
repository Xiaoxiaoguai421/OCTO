%排除噪声干扰的曲线回归
%最小二乘法

%输入数据
n_points=input('Enter number of[x y]pairs:');
%读取数据
for ii=1:n_points
    temp=input('Enter [x y]pairs:');
    x(ii)=temp(1);
    y(ii)=temp(2);
end
%计算
sum_x=0;sum_y=0;sum_x2=0;sum_xy=0;
for ii=1:n_points
    sum_x=sum_x+x(ii);
    sum_y=sum_y+y(ii);
    sum_x2=sum_x2+x(ii)^2;
    sum_xy=sum_xy+x(ii)*y(ii);
end
%计算截距b和斜率m
x_bar=sum_x/n_points;
y_bar=sum_y/n_points;
slope=(sum_xy-sum_x*y_bar)/(sum_x2-sum_x*x_bar);
y_int=y_bar-slope*x_bar;
%显示计算结果
disp('Regression coefficients for the least-square lines:');
fprintf('Slope(m)=%8.3f\n',slope);
fprintf('Intercept(b)=%8.3f\n',y_int);
fprintf('No of points=%8d\n',n_points);
%绘制数据点
figure(1);
plot(x,y,'ro');
hold on
xmin=min(x);
ymin=slope*xmin+y_int;
xmax=max(x);
ymax=slope*xmax+y_int;
plot([xmin xmax],[ymin ymax],'r-','linewidth',2);
title('\bfleast-square Fit');
xlabel('\bf\itx');
ylabel('\bf\ity');
grid on