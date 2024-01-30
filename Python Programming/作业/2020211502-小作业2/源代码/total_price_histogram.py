import pandas as pd
from matplotlib import pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 添加对中文字体的支持

csvfile = pd.read_csv('new_house.csv')

x = csvfile.building_location.unique()

lis = []
y = []
wide = []
for i in range(len(x)):
    lis = list(csvfile.loc[csvfile.building_location == x[i]]['total_price 单位：万/套'])
    sum_price = 0
    j = 0
    for j in range(len(lis)):
        sum_price += int(lis[j])
    wide.append(j+1)
    y.append(round(sum_price/wide[i]))
    wide[i] = wide[i]/10

plt.bar(x, y, width=wide)
for a, b in zip(x, y):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各行政区楼盘总价直方图，单位：万/套')
plt.show()
