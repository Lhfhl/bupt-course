import csv

import matplotlib
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from pandas import Series
from scipy.interpolate import interp1d

matplotlib.rcParams['font.sans-serif'] = ['SimHei']

# SECTION:各城市去重后数据数量：22688,20048,57292,23138,16436
# SECTION:城市横坐标
x = ["北京", "上海", "广州", "深圳", "合肥"]
# 第三问
# SECTION:月租金数据存储定义
price_mean = []  # [8785.8, 8381.59, 4342.54, 8112.17, 2929.4]
price_max = []  # [260000, 600000, 190000, 450000, 594063]
price_min = []  # [1100, 1000, 70, 1250, 500]
price_median = []  # [6500.0, 6000.0, 3300.0, 6000.0, 2000.0]
# SECTION:单位面积租金数据存储定义
unit_price_mean = []  # [100.2, 104.98, 53.12, 95.29, 28.89]
unit_price_max = []  # [1000.0, 687.5, 1300.0, 933.33, 1200.0]
unit_price_min = []  # [11.83, 8.33, 0.99, 5.0, 0.03]
unit_price_median = []  # [96.03, 96.97, 47.62, 88.64, 25.53]
# 第四问
# SECTION:一居室数据存储定义
room1_price_mean = []  # [6447.78, 5366.51, 3335.91, 4816.48, 3760.34]
room1_price_max = []  # [260000, 110000, 175000, 450000, 594063]
room1_price_min = []  # [1100, 1000, 800, 1250, 500]
room1_price_median = []  # [5700.0, 4800.0, 2500.0, 4100.0, 1800.0]
# SECTION:二居室数据存储定义
room2_price_mean = []  # [7065.06, 7178.81, 3654.34, 6487.21, 2282.47]
room2_price_max = []  # [150000, 70000, 120000, 85000, 130000]
room2_price_min = []  # [1100, 1400, 70, 1300, 500]
room2_price_median = []  # [6400.0, 6000.0, 3200.0, 6000.0, 2000.0]
# SECTION:三居室数据存储定义
room3_price_mean = []  # [10799.64, 11145.27, 4363.09, 8306.05, 2429.29]
room3_price_max = []  # [80000, 138000, 190000, 380000, 80000]
room3_price_min = []  # [1500, 1000, 800, 1300, 500]
room3_price_median = []  # [8500.0, 8200.0, 3500.0, 6800.0, 2100.0]

# SECTION:定义文件读取
csvfile_bj = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\bei_jing.csv')
csvfile_sh = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\shang_hai.csv')
csvfile_gz = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\guang_zhou.csv')
csvfile_sz = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\shen_zhen.csv')
csvfile_hf = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\he_fei.csv')


# SECTION:数据处理函数
def deal_3_4(csvfile):
    # SECTION:第三问使用的数据结构
    price = []  # 去重后的总价
    area = []  # 去重后的面积

    description = csvfile.description.unique()
    # SECTION:第三问的准备工作
    for i in range(len(description)):
        lis_price = list(csvfile.loc[csvfile.description == description[i]]['price'])
        price.append(lis_price[0])

        lis_area = list(csvfile.loc[csvfile.description == description[i]]['area'])
        area.append(lis_area[0])
    # print(len(price))
    # print(len(area))
    # SECTION:第四问的准备工作
    csvfile['room_num'] = ""
    for i in range(len(csvfile['type'])):
        strd = csvfile['type'][i][0]
        csvfile.loc[i, 'room_num'] = strd

    room1_price = []
    room2_price = []
    room3_price = []
    for i in range(len(description)):
        lis_no = csvfile.loc[csvfile.description == description[i], ['room_num', 'price']]
        lis = list(lis_no.loc[:, 'room_num'])
        lis2 = list(lis_no.loc[:, 'price'])
        if lis[0] == "1":
            room1_price.append(lis2[0])
        elif lis[0] == "2":
            room2_price.append(lis2[0])
        elif lis[0] == "3":
            room3_price.append(lis2[0])

    # SECTION:Series函数转换数据结构
    # 第三问
    temp_area = Series(area)
    temp_price = Series(price)
    # 第四问
    temp_room1_price = Series(room1_price, dtype='object')
    temp_room2_price = Series(room2_price, dtype='object')
    temp_room3_price = Series(room3_price, dtype='object')
    # 获取单位面积租金，按一个月的租金除以面积
    temp_unit_price = temp_price / temp_area
    for i in range(len(temp_unit_price)):
        temp_unit_price[i] = np.around(temp_unit_price[i], 2)
    # SECTION:第三问的各项数据计算
    # 计算租金的各项数据
    total_price_mean = np.around(temp_price.mean(), 2)
    total_price_min = temp_price.min()
    total_price_max = temp_price.max()
    total_price_median = np.around(temp_price.median(), 2)
    # 计算单位面积租金的各项数据
    temp_unit_price_mean = np.around(temp_unit_price.mean(), 2)
    temp_unit_price_min = temp_unit_price.min()
    temp_unit_price_max = temp_unit_price.max()
    temp_unit_price_median = np.around(temp_unit_price.median(), 2)
    # 把租金的各项数据存入数组
    price_mean.append(total_price_mean)
    price_max.append(total_price_max)
    price_min.append(total_price_min)
    price_median.append(total_price_median)
    # 把单位面积租金的各项数据存入数组
    unit_price_mean.append(temp_unit_price_mean)
    unit_price_max.append(temp_unit_price_max)
    unit_price_min.append(temp_unit_price_min)
    unit_price_median.append(temp_unit_price_median)
    # SECTION:第四问的各项数据计算
    # 计算并存储一居室的各项数据
    room1_price_mean.append(np.around(temp_room1_price.mean(), 2))
    room1_price_max.append(temp_room1_price.max())
    room1_price_min.append(temp_room1_price.min())
    room1_price_median.append(np.around(temp_room1_price.median(), 2))
    # 计算并存储二居室的各项数据
    room2_price_mean.append(np.around(temp_room2_price.mean(), 2))
    room2_price_max.append(temp_room2_price.max())
    room2_price_min.append(temp_room2_price.min())
    room2_price_median.append(np.around(temp_room2_price.median(), 2))
    # 计算并存储三居室的各项数据
    room3_price_mean.append(np.around(temp_room3_price.mean(), 2))
    room3_price_max.append(temp_room3_price.max())
    room3_price_min.append(temp_room3_price.min())
    room3_price_median.append(np.around(temp_room3_price.median(), 2))


# SECTION:数据处理函数调用区
deal_3_4(csvfile_bj)
deal_3_4(csvfile_sh)
deal_3_4(csvfile_gz)
deal_3_4(csvfile_sz)
deal_3_4(csvfile_hf)

# # SECTION:打印测试区
# print(room1_price_mean)
# print(room1_price_max)
# print(room1_price_min)
# print(room1_price_median)
#
# print()
#
# print(room2_price_mean)
# print(room2_price_max)
# print(room2_price_min)
# print(room2_price_median)
# print()
#
# print(room3_price_mean)
# print(room3_price_max)
# print(room3_price_min)
# print(room3_price_median)

# print(unit_price_mean)
# print(unit_price_max)
# print(unit_price_min)
# print(unit_price_median)

# # SECTION:月租金的展示
plt.bar(x, price_mean)
for a, b in zip(x, price_mean):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房租金均价直方图，单位：元/月')
plt.show()

plt.bar(x, price_max)
for a, b in zip(x, price_max):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房租金最高价直方图，单位：元/月')
plt.show()

plt.bar(x, price_min)
for a, b in zip(x, price_min):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房租金最低价价直方图，单位：元/月')
plt.show()

plt.bar(x, price_median)
for a, b in zip(x, price_median):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房租金中位数直方图，单位：元/月')
plt.show()
# SECTION:单位面积租金的展示
plt.bar(x, unit_price_mean)
for a, b in zip(x, unit_price_mean):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房单位面积租金均价直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(x, unit_price_max)
for a, b in zip(x, unit_price_max):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房单位面积租金最高价直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(x, unit_price_min)
for a, b in zip(x, unit_price_min):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房单位面积租金最低价直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(x, unit_price_median)
for a, b in zip(x, unit_price_median):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市租房单位面积租金中位数直方图，单位：月租金（元）/㎡')
plt.show()
# SECTION:展示一居的对比图
plt.bar(x, room1_price_mean)
for a, b in zip(x, room1_price_mean):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市一居租房租金均价直方图，单位：元/月')
plt.show()

plt.bar(x, room1_price_max)
for a, b in zip(x, room1_price_max):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市一居租房租金最高价直方图，单位：元/月')
plt.show()

plt.bar(x, room1_price_min)
for a, b in zip(x, room1_price_min):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市一居租房租金最低价直方图，单位：元/月')
plt.show()

plt.bar(x, room1_price_median)
for a, b in zip(x, room1_price_median):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市一居租房租金中位数直方图，单位：元/月')
plt.show()
# SECTION:展示二居的对比图
plt.bar(x, room2_price_mean)
for a, b in zip(x, room2_price_mean):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市二居租房租金均价直方图，单位：元/月')
plt.show()

plt.bar(x, room2_price_max)
for a, b in zip(x, room2_price_max):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市二居租房租金最高价直方图，单位：元/月')
plt.show()

plt.bar(x, room2_price_min)
for a, b in zip(x, room2_price_min):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市二居租房租金最低价直方图，单位：元/月')
plt.show()

plt.bar(x, room2_price_median)
for a, b in zip(x, room2_price_median):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市二居租房租金中位数价直方图，单位：元/月')
plt.show()
# SECTION:展示三居的对比图
plt.bar(x, room3_price_mean)
for a, b in zip(x, room3_price_mean):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市三居租房租金均价直方图，单位：元/月')
plt.show()

plt.bar(x, room3_price_max)
for a, b in zip(x, room3_price_max):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市三居租房租金最高价直方图，单位：元/月')
plt.show()

plt.bar(x, room3_price_min)
for a, b in zip(x, room3_price_min):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市三居租房租金最低价直方图，单位：元/月')
plt.show()

plt.bar(x, room3_price_median)
for a, b in zip(x, room3_price_median):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('各城市三居租房租金中位数直方图，单位：元/月')
plt.show()
