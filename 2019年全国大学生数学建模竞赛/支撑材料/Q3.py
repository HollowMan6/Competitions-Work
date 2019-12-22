import random # 导入随机数模块
M=int(input("泊位规模：")) # 泊位规模
T=1 # 仿真时间
listp=[0] # 队伍人数
listw=[0] # 在蓄车泊位的车
listg=[]  # 上车点的车
listwg=[] # 等待出发的车
Tvp=0     # 记录上一次车到的时间
Tpp=0     # 记录上一次乘客到的时间
Twp=0     # 记录上一次乘客上车出发的时间
flag=False
tv=random.randint(80,100) # 车到达的间隔
tp=random.randint(80,100) # 人到达的间隔
to=random.randint(5,15)   # 乘客上车出发的间隔
count=0
# 循环
while T<=7200:
    # 判断是否有车到
    if T==Tvp+tv:
        Tvp=T
        tv=random.randint(80,100)
        listw.append(T)
    # 判断是否有人到
    if T==Tpp+tp:
        Tpp=T
        tp=random.randint(80,100)
        listp.append(T)
    # 判断是否有乘客上车出发
    if flag==True and T==Twp+to:
        listwg.pop(0)
        count+=1
        print("第"+str(T)+"秒时有车出发,出发次数共计"+str(count)+"次")
    # 判断乘客是否可以上车
    if listp and listg:
        listp.pop(0)
        listg.pop(0)
        listwg.append(T)
        to=random.randint(5,15)
        Twp=T
        flag=True
    # 判断是否出租车可以从蓄车泊位移动到上车点
    if listw and len(listg)<M:
        listw.pop(0)
        listg.append(T)
    # 仿真时间流逝
    T+=1