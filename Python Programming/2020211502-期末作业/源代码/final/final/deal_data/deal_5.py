import matplotlib
import pandas as pd
from matplotlib import pyplot as plt
from pandas import Series
from pandas.core.frame import DataFrame

matplotlib.rcParams['font.sans-serif'] = ['SimHei']

# 第五问
bj_block = []
bj_block_price = []

sh_block = []
sh_block_price = []

gz_block = []
gz_block_price = []

sz_block = []
sz_block_price = []

hf_block = []
hf_block_price = []

# SECTION:定义文件读取
csvfile_bj = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\bei_jing.csv')
csvfile_sh = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\shang_hai.csv')
csvfile_gz = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\guang_zhou.csv')
csvfile_sz = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\shen_zhen.csv')
csvfile_hf = pd.read_csv('D:\\桌面\\final\\final\\convert_data\\he_fei.csv')


# SECTION:数据处理函数
def deal_5(csvfile, block, block_price):
    # SECTION:第五问使用的数据结构
    loc = []
    price = []
    description = csvfile.description.unique()
    # 去重并提取数据
    for i in range(len(description)):
        temp = csvfile.loc[csvfile.description == description[i], ['building_location1', 'price']]

        lis = list(temp.loc[:, 'building_location1'])
        lis2 = list(temp.loc[:, 'price'])

        loc.append(lis[0])
        price.append(lis2[0])
    # 把板块和价格转换为dataframe
    dic = {"loca": loc, "price": price}
    loc_price = DataFrame(dic)
    # 按照板块来划分数据
    building_location1 = Series(loc_price.loca).unique()
    # 保存去重后的板块到传入的参数中
    for i in range(len(list(building_location1))):
        block.append(list(building_location1)[i])
    # 计算每个板块的均价
    for i in range(len(building_location1)):
        temp = loc_price.loc[loc_price.loca == building_location1[i], ['price']]
        lis = list(temp.loc[:, 'price'])
        total = 0
        for j in range(len(lis)):
            total += int(lis[j])
        # print(total)
        # print(total/len(lis))
        block_price.append(round(total/len(lis)/100, 2))


deal_5(csvfile_bj, bj_block, bj_block_price)
deal_5(csvfile_sh, sh_block, sh_block_price)
deal_5(csvfile_gz, gz_block, gz_block_price)
deal_5(csvfile_sz, sz_block, sz_block_price)
deal_5(csvfile_hf, hf_block, hf_block_price)
# print(bj_block)
# print(bj_block_price)

# print(sh_block)
# print(sh_block_price)
#
# print(gz_block)
# print(gz_block_price)
#
# print(sz_block)
# print(sz_block_price)
#
# print(hf_block)
# print(hf_block_price)

# 画布大小参数-figsize
plt.figure(figsize=(15, 100))
plt.hlines(y=bj_block, xmin=0, xmax=bj_block_price, color='skyblue')
plt.plot(bj_block_price, bj_block, "D")
plt.yticks(fontsize=10)
plt.savefig("bei_jing_block.png", dpi=300)
plt.gca()

# 画布大小参数-figsize
plt.figure(figsize=(15, 100))
plt.hlines(y=sh_block, xmin=0, xmax=sh_block_price, color='skyblue')
plt.plot(sh_block_price, sh_block, "D")
plt.yticks(fontsize=10)
plt.savefig("shang_hai_block.png", dpi=300)
plt.gca()

# 画布大小参数-figsize
plt.figure(figsize=(15, 100))
plt.hlines(y=gz_block, xmin=0, xmax=gz_block_price, color='skyblue')
plt.plot(gz_block_price, gz_block, "D")
plt.yticks(fontsize=10)
plt.savefig("guang_zhou_block.png", dpi=300)
plt.gca()

# 画布大小参数-figsize
plt.figure(figsize=(15, 100))
plt.hlines(y=sz_block, xmin=0, xmax=sz_block_price, color='skyblue')
plt.plot(sz_block_price, sz_block, "D")
plt.yticks(fontsize=10)
plt.savefig("shen_zhen_block.png", dpi=300)
plt.gca()

# 画布大小参数-figsize
plt.figure(figsize=(15, 100))
plt.hlines(y=hf_block, xmin=0, xmax=hf_block_price, color='skyblue')
plt.plot(hf_block_price, hf_block, "D")
plt.yticks(fontsize=10)
plt.savefig("he_fei_block.png", dpi=300)
plt.gca()

