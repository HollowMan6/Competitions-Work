s = 24; %������24
x = [3;5;5;6;8;7;5;9;11;13;17;21;25;24;23;21;19;16;15;14;16;15;12;9];%��ʼ���ݵ�¼��
%x=[8;11;12;15;11;9;9;7;7;6;9;16;15;15;14;13;11;8;7;6;4;4;5;7];
a=0.4;
b=0.2;
n = 24; %Ԥ���ĸ���
m1 = length(x); %ԭʼ�����ݵĸ���
for i = s+1:m1;
    y(i-s) = x(i) - x(i-s);%�������ڲ�ֱ任
end
w = diff(y); %���������ԵĲ������
ToEstMd = arima('ARLags',1:3,'MALags',1:3,'Constant',0);%ָ��ģ�͵Ľṹ
[EstMdl,EstParamCov,LogL,info] = estimate(ToEstMd,w);%ģ����� 
w_Forecast = forecast(EstMdl,n,'Y0',w);
yhat = y(end) + cumsum(w_Forecast); %һ�ײ�ֵĻ�ԭֵ
for j = 1:n
    x(m1 + j) = yhat(j) + x(m1+j-s);%x��Ԥ��ֵ
end
x(m1+1:end)/60;
x(m1+1:m1+7)*a/60
x(m1+8:end)*b/60