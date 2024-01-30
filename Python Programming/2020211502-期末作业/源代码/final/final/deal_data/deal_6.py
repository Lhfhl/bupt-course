import matplotlib
import pandas as pd
from matplotlib import pyplot as plt
from pandas import Series
from pandas.core.frame import DataFrame

matplotlib.rcParams['font.sans-serif'] = ['SimHei']

bj_point = []  # ['东南', '南', '东', '东北', '西南', '北', '西', '西北']
bj_point_price = []  # [104.37, 95.28, 109.46, 105.67, 101.71, 93.07, 107.26, 110.77]

sh_point = []  # ['南', '北', '西', '东南', '东', '西北', '西南', '东北']
sh_point_price = []  # [102.61, 96.41, 134.55, 126.02, 129.22, 136.79, 129.11, 142.89]

gz_point = []  # ['南', '西南', '东北', '东', '北', '东南', '西', '西北']
gz_point_price = []  # [50.12, 56.46, 49.42, 62.46, 52.63, 52.3, 65.06, 56.84]

sz_point = []  # ['南', '西北', '东南', '西南', '北', '东北', '东', '西']
sz_point_price = []  # [93.03, 93.78, 89.77, 96.5, 97.63, 98.05, 110.43, 111.85]

hf_point = []  # ['南', '东南', '北', '西南', '东', '西北', '东北', '西']
hf_point_price = []  # [27.23, 29.45, 27.97, 34.23, 40.13, 37.12, 38.69, 45.55]

# SECTION:定义文件读取
csvfile_bj = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\bei_jing.csv')
csvfile_sh = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\shang_hai.csv')
csvfile_gz = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\guang_zhou.csv')
csvfile_sz = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\shen_zhen.csv')
csvfile_hf = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\he_fei.csv')


def deal_6(csvfile, point, point_price):
    # SECTION:第六问使用的数据结构
    area = []
    dire = []
    price = []
    description = csvfile.description.unique()
    # SECTION:去重并获取需要的数据
    for i in range(len(description)):
        temp = csvfile.loc[csvfile.description == description[i], ['area', 'direction', 'price']]

        lis = list(temp.loc[:, 'area'])
        lis2 = list(temp.loc[:, 'direction'])
        lis3 = list(temp.loc[:, 'price'])

        area.append(lis[0])
        dire.append(lis2[0])
        price.append(lis3[0])
        # temp_lis_price = Series(lis_price)
    # 转换成DataFrame
    dic = {"area": area, "dire": dire, "price": price}
    dire_price = DataFrame(dic)
    del_dire = []
    lis = []
    are = []
    pri = []
    for i in range(len(dire_price)):
        if len(dire_price.loc[i, 'dire']) > 2:
            # 切割不只一个朝向的房子，获取全部朝向，并保存
            lis.extend(list(str(dire_price.loc[i, 'dire']).split()))
            # 保存这些不止一个朝向的房子的下标，为后续删除这些数据做准备
            del_dire.append(i)
            # 为这些切割出来的朝向保存对应的面积和price，注意循环的长度为切割出来的朝向的数量
            for j in range(len(list(str(dire_price.loc[i, 'dire']).split()))):
                # print(str(dire_price.loc[i, 'area']))
                # print(str(dire_price.loc[i, 'price']))
                are.append(dire_price.loc[i, 'area'])
                pri.append(dire_price.loc[i, 'price'])

    # print(len(del_dire))
    # print(len(dire_price))
    # print(del_dire)
    # print(dire_price)
    # print()
    # 删除不只一个朝向的数据并重新分配下标
    dire_price.drop(del_dire, axis=0, inplace=True)
    dire_price = dire_price.reset_index(drop=True)
    # print(len(dire_price))
    # print(dire_price)
    # print()
    # 将切割出来的数据加上对应的面积和价格，在存到dataframe中
    len_dire_price = len(dire_price)
    for i in range(len(lis)):
        tem = [are[i], lis[i], pri[i]]
        dire_price.loc[i+len_dire_price] = tem
    # print(len(dire_price))
    # print(len(lis))
    # print(len(are))
    # print(len(pri))
    # print()
    # print(dire_price)
    # print(lis)
    # print(are)
    # print(pri)
    # 计算单位面积的价格
    dire_price['divide'] = dire_price['price'] / dire_price['area']
    # print(round(dire_price.loc[:, 'divide'].mean(), 2))
    # 按朝向分类
    direction = Series(dire_price.dire).unique()
    # print(direction)
    # 按朝向计算并保存数据
    for i in range(len(list(direction))):
        point.append(list(direction)[i])
    for i in range(len(direction)):
        temp = dire_price.loc[dire_price.dire == direction[i], ['divide']]
        point_price.append(round(temp.loc[:, 'divide'].mean(), 2))


deal_6(csvfile_bj, bj_point, bj_point_price)
# print(bj_point)
# print(bj_point_price)
# print()
deal_6(csvfile_sh, sh_point, sh_point_price)
# print(sh_point)
# print(sh_point_price)
# print()
deal_6(csvfile_gz, gz_point, gz_point_price)
# print(gz_point)
# print(gz_point_price)
# print()
deal_6(csvfile_sz, sz_point, sz_point_price)
# print(sz_point)
# print(sz_point_price)
# print()
deal_6(csvfile_hf, hf_point, hf_point_price)
# print(hf_point)
# print(hf_point_price)

plt.bar(bj_point, bj_point_price)
for a, b in zip(bj_point, bj_point_price):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('北京市各朝向租房单位面积租金直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(sh_point, sh_point_price)
for a, b in zip(sh_point, sh_point_price):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('上海市各朝向租房单位面积租金直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(gz_point, gz_point_price)
for a, b in zip(gz_point, gz_point_price):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('广州市各朝向租房单位面积租金直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(sz_point, sz_point_price)
for a, b in zip(sz_point, sz_point_price):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('深圳市各朝向租房单位面积租金直方图，单位：月租金（元）/㎡')
plt.show()

plt.bar(hf_point, hf_point_price)
for a, b in zip(hf_point, hf_point_price):
    plt.text(a, b+1, b, ha='center', va='bottom')
plt.title('合肥市各朝向租房单位面积租金直方图，单位：月租金（元）/㎡')
plt.show()
