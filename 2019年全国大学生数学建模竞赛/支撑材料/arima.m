s = 24; %周期是24
x = [3;5;5;6;8;7;5;9;11;13;17;21;25;24;23;21;19;16;15;14;16;15;12;9];%初始数据的录入
%x=[8;11;12;15;11;9;9;7;7;6;9;16;15;15;14;13;11;8;7;6;4;4;5;7];
a=0.4;
b=0.2;
n = 24; %预报的个数
m1 = length(x); %原始的数据的个数
for i = s+1:m1;
    y(i-s) = x(i) - x(i-s);%进行周期差分变换
end
w = diff(y); %消除趋势性的差分运算
ToEstMd = arima('ARLags',1:3,'MALags',1:3,'Constant',0);%指定模型的结构
[EstMdl,EstParamCov,LogL,info] = estimate(ToEstMd,w);%模型拟合 
w_Forecast = forecast(EstMdl,n,'Y0',w);
yhat = y(end) + cumsum(w_Forecast); %一阶差分的还原值
for j = 1:n
    x(m1 + j) = yhat(j) + x(m1+j-s);%x的预测值
end
x(m1+1:end)/60;
x(m1+1:m1+7)*a/60
x(m1+8:end)*b/60