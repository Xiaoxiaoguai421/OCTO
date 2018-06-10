% Forest表格
% 数的种类(kind) 胸径(DBH) 株数（num） 受危害株数(num_ill)  幼苗株数(num_new)  
%
%郁闭度Y，乔木层密度p1,更新密度p2，多样性指标mul,病虫危害比率p,火险等级h，土壤有机质含量t
%
%输入数据
area=1000*500/10000;    %公顷
n_kind=input('请输入树种的数目):');
Forest=zeros(n_kind,5);
for ii=1:n_kind
    string=['请输入第' int2str(ii) '种树的[胸径,株数,受危害株数,幼苗株数]:'];
    temp=input(string);
    Forest(ii,1)=ii;
    Forest(ii,2)=temp(1);
    Forest(ii,3)=temp(2);
    Forest(ii,4)=temp(3);
    Forest(ii,5)=temp(4);
end

%计算
sum_n=0;sum_nd2=0;sum_ill=0;sum_new=0;sum_ni=0;
for ii=1:n_kind
   sum_n=sum_n+Forest(ii,3);
   sum_ni=sum_ni+Forest(ii,3)*(Forest(ii,3)-1);
   sum_nd2=sum_nd2+Forest(ii,3)*(Forest(ii,2).^2);
   sum_ill=sum_ill+Forest(ii,4);
   sum_new=sum_new+Forest(ii,5);
end
D_bar=sqrt(sum_nd2/sum_n);
%fprintf('平均胸径(D_bar):%8.4f\n',D_bar);
%乔木密度
p1=sum_n/area;
%fprintf('乔木密度(p1):%8.4f\n',p1);
%更新密度
p2=sum_new/area;
%fprintf('更新密度(p2):%8.4f\n',p2);
%病虫危害比
p=sum_ill/sum_n;
%fprintf('病虫危害比(p):%8.4f\n',p);
%植物多样性指标
mul=sum_ni/(sum_n*(sum_n-1));
%fprintf('植物多样性指标(mul):%8.4f\n',mul);

%林场数据
temp=input('请输入该林场的[郁闭度 群落层次等级 火险等级 土壤有机质含量(g/kg)]：');
Y=temp(1);
com=temp(2);
h=temp(3);
t=temp(4);

%定级，评分
score=zeros(1,9);
%平均胸径得分
if D_bar>=17
    score(1)=3;
elseif D_bar<9
    score(1)=1;
else
    score(1)=2;
end
%郁闭度得分
if Y>=0.5&&Y<=0.7
    score(2)=3;
elseif y<=0.3
    score(2)=1;
else
    score(2)=2;
end
%乔木密度得分
if p1>=600 && p1<=900
    score(3)=3;
elseif p1>900 && p1 <=1200
    score(3)=2;
elseif p1>1200
    score(3)=1;
end
%更新密度得分
if p2>1
    score(4)=3;
elseif p2<0.5
    score(4)=1;
else
    score(4)=2;
end
%群落层次结构得分
if com == 1
    score(5)=3;
elseif com == 2
    score(5)=2;
elseif com == 3
    score(5)=1;
end
%植物多样性得分
if mul<0.3
    score(6)=3;
elseif mul>0.6
    score(6)=1;
else 
    score(6)=2;
end
%病虫危害比得分
if p<0.05
    score(7)=3;
elseif p>0.2
    score(7)=1;
else
    score(7)=2;
end
%火险等级得分
if h<=0.3
    score(8)=3;
elseif h>0.6
    score(8)=1;
else
    score(8)=2;
end
%土壤有机质含量得分
if t>=40
    score(9)=3;
elseif t<20
    score(9)=1;
else
    score(9)=2;
end
%计算森林健康值score
wight=1/9;s=0;
for ii=1:9
    s=s+score(ii)*wight;
end

%fprintf('综合得分(s):%8.f\n',s);

if s>=0&&s<0.8
    disp('该人工林的健康等级为：不健康');
elseif s>=0.8&&s<2.4
    disp('该人工林的健康等级为：亚健康');
elseif s>=2.4&&s<=3.0
    disp('该人工林的健康等级为：健康');
end
