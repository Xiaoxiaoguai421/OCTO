%抛物线最远距离和最佳角度
%初始角度theta

%定义常数和初始值
conv=pi/180;g=-9.81;v0=20;
range=zeros(1,91);

for ii=1:91
    theta=ii-1;
    vx0=v0*cos(theta*conv);
    vy0=v0*sin(theta*conv);
    max_time=-2*vy0/g;
    range(ii)=vx0*max_time;
end

% fprintf('Range versus angle theta:\n');
% for ii=1:91
%     theta=ii-1;
%     fprintf('%2d %8.4f\n',theta,range(ii));
% end

%最大距离和角度
[maxrange,index]=max(range);
maxangle=index-1;
fprintf('\nMax rang is %8.4f at %2d degrees.\n',maxrange,maxangle);

% %绘制抛物线
% for ii=5:10:85
%     theta=ii;
%     vx0=v0*cos(theta*conv);
%     vy0=v0*sin(theta*conv);
%     max_time=-2*vy0/g;
%     x=zeros(1,21);
%     y=zeros(1,21);
%     for jj=1:21
%         time=(jj-1)*max_time/20;
%         x(jj)=vx0*time;
%         y(jj)=vy0*time+0.5*g*time^2;
%     end
%     plot(x,y,'b');
%     hold on
% end
% grid on

%绘制最优抛物线
vx0=v0*cos(maxangle*conv);
vy0=v0*sin(maxangle*conv);
max_time=-2*vy0/g;
%计算（x,y）坐标
x=zeros(1,21);
y=zeros(1,21);
for jj=1:21
    time=(jj-1)*max_time/20;
    x(jj)=vx0*time;
    y(jj)=vy0*time+0.5*g*time^2;
end
plot(x,y,'r','linewidth',3.0);
hold off