%draw
x=0:0.1:60;
y=1.8403 .*(x.^(0.7212));
plot(x,y)
xlabel('平均胸径DBH/cm')
ylabel('树高height/m')
grid on