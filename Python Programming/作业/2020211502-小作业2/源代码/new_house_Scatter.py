import matplotlib
import pandas as pd
import matplotlib.pyplot as plt

matplotlib.rcParams['font.sans-serif'] = ['SimHei']

csvfile = pd.read_csv('new_house.csv')
colors = ['r', 'y', 'b', 'k', 'g']  # 定义五种散点的颜色
label = csvfile.building_type.unique()
for i in range(len(label)):
    plt.scatter(csvfile.loc[csvfile.building_type == label[i]]['total_price 单位：万/套'],
                csvfile.loc[csvfile.building_type == label[i]]['unit_price 单位：元/㎡'],
                s=35, c=colors[i], label=label[i])

# 添加轴标签和标题
plt.title('总价x单价')
plt.xlabel('total_price 单位：万/套')
plt.ylabel('unit_price 单位：元/㎡')
plt.grid(True, linestyle='--', alpha=0.8)  # 设置网格线
plt.legend(loc='lower right')  # 添加图例
plt.show()
