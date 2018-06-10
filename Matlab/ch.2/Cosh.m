x = 10:0.1:10;
y = (exp(x)+exp(-x))/2;
plot(x,y)
title('Plot of cosh x=(e^x+e^-x)/2');
[minvalue,index]=min(y)