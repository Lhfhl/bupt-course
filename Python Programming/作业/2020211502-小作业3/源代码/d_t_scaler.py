import matplotlib
import pandas as pd
from matplotlib import pyplot as plt
from pandas import Series
from sklearn.preprocessing import MinMaxScaler, StandardScaler

plt.rcParams['axes.unicode_minus'] = False
matplotlib.rcParams['font.sans-serif'] = ['SimHei']
csvfile = pd.read_csv('out.csv')
# 读入demp
dewp = list(csvfile.DEWP)
temp_dewp = Series(dewp)

scaler = MinMaxScaler()

re_dewp = temp_dewp.values.reshape(-1, 1)
# dewp  0-1归一化
dewp_scaler = scaler.fit_transform(re_dewp)

temp = list(csvfile.TEMP)
temp_temp = Series(temp)
re_temp = temp_temp.values.reshape(-1, 1)
# temp  0-1归一化
temp_scaler = scaler.fit_transform(re_temp)

index = list(csvfile.No)
temp_index = Series(index)
re_index = temp_index.values.reshape(-1, 1)
# No 0-1归一化
index_scaler = scaler.fit_transform(re_index)

# dewp  0-1归一化  散点图
plt.scatter(index_scaler, dewp_scaler)
plt.show()
# temp  0-1归一化  散点图
plt.scatter(index_scaler, temp_scaler)
plt.show()

# Z-score归一化
scaler_std = StandardScaler()
# dewp Z-score归一化
zre_dewp = scaler_std.fit_transform(re_dewp)
# temp Z-score归一化
zre_temp = scaler_std.fit_transform(re_temp)
# no Z-score归一化
zre_index = scaler_std.fit_transform(re_index)

# dewp  Z-score归一化  散点图
plt.scatter(zre_index, zre_dewp)
plt.show()
# temp  Z-score归一化  散点图
plt.scatter(zre_index, zre_temp)
plt.show()
