import matplotlib
from matplotlib import pyplot as plt

matplotlib.rcParams['font.sans-serif'] = ['SimHei']

x = ["北京", "上海", "广州", "深圳", "合肥"]
unit_price_mean = [100.2, 104.98, 53.12, 95.29, 28.89]  # 一个月的  单位：元/平方米
year_unit_price_mean = []   # 一年的   单位：元/平方米 [1202.4, 1259.76, 637.44, 1143.48, 346.68]
for i in range(len(unit_price_mean)):
    year_unit_price_mean.append(round(unit_price_mean[i]*12, 2))

gdp_p = []      # [0.654, 0.725, 0.422, 0.655, 0.285]
salary_p = []   # [0.618, 0.921, 0.415, 0.792, 0.331]
gdp = [18.39, 17.38, 15.12, 17.46, 12.18]   # 单位：万人民币
salary = [194651, 136757, 153471, 144288, 104729]   # 单位：元

for i in range(len(year_unit_price_mean)):
    gdp_p.append(year_unit_price_mean[i]/(gdp[i]*10000)*100)
    salary_p.append(year_unit_price_mean[i]/salary[i]*100)
    gdp_p[i] = round(gdp_p[i], 3)
    salary_p[i] = round(salary_p[i], 3)

plt.bar(x, gdp_p)
for a, b in zip(x, gdp_p):
    plt.text(a, b+0.008, b, ha='center', va='bottom')
plt.title('各城市人均GDP和单位面积租房租金比例直方图，单位：%')
plt.show()

plt.bar(x, salary_p)
for a, b in zip(x, salary_p):
    plt.text(a, b+0.008, b, ha='center', va='bottom')
plt.title('各城市人均工资和单位面积租房租金比例直方图，单位：%')
plt.show()
