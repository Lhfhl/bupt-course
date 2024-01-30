# -*- coding: utf-8 -*-
import json
import csv
import re
# 将北京的数据转换为csv文件格式
csvfile = open('bei_jing.csv', 'w', newline='', encoding='utf-8-sig')
writer = csv.writer(csvfile, delimiter=',')

with open('D:\\桌面\\final\\bei_jing.json', 'r', encoding='UTF-8') as f:
    flag = True
    for line in f:
        dic = json.loads(line)
        if flag:
            # 获取属性列表
            keys = list(dic.keys())
            keys.insert(2, 'building_location2')
            keys.insert(2, 'building_location1')
            print(keys)
            writer.writerow(keys)  # 将属性列表写入csv中
            flag = False
        # 读取json数据的每一行，将values数据一次一行的写入csv中
        val = list(dic.values())
        # 提取名字并改为字符串
        temp_name = val[0]
        del val[0]
        name = temp_name[0].split(" ", 1)
        # print(name[0][3:])
        val.insert(0, name[0][3:])

        # 将地理位置拆分成三个
        local = val[1]
        del val[1]
        val.insert(1, local[2])
        val.insert(1, local[1])
        val.insert(1, local[0])
        # 面积
        Area = 1    # 定义变量保存一个整型的面积值
        are = val[4]
        del val[4]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(4, number[0])
            Area = int(number[0])
        else:
            val.insert(4, [])

        # 提取朝向并改为字符串
        temp_dire = val[5]
        del val[5]
        val.insert(5, temp_dire[0])

        # 提取房型并改为字符串
        temp_type = val[6]
        del val[6]
        val.insert(6, temp_type[0])

        # 提取房子号码并改为字符串
        temp_type = val[7]
        del val[7]
        val.insert(7, temp_type[0])

        # 价格
        price = 1  # 定义变量保存一个整型的面积值
        are = val[8]
        del val[8]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(8, number[0])
            price = int(number[0])
        else:
            val.insert(8, [])
        writer.writerow(val)
    f.close()
    csvfile.close()

# 将上海的数据转换为csv文件格式
csvfile = open('shang_hai.csv', 'w', newline='', encoding='utf-8-sig')
writer = csv.writer(csvfile, delimiter=',')

with open('D:\\桌面\\final\\shang_hai.json', 'r', encoding='UTF-8') as f:
    flag = True
    for line in f:
        dic = json.loads(line)
        if flag:
            # 获取属性列表
            keys = list(dic.keys())
            keys.insert(2, 'building_location2')
            keys.insert(2, 'building_location1')
            print(keys)
            writer.writerow(keys)  # 将属性列表写入csv中
            flag = False
        # 读取json数据的每一行，将values数据一次一行的写入csv中
        val = list(dic.values())
        # 提取名字并改为字符串
        temp_name = val[0]
        del val[0]
        name = temp_name[0].split(" ", 1)
        # print(name[0][3:])
        val.insert(0, name[0][3:])

        # 将地理位置拆分成三个
        local = val[1]
        del val[1]
        val.insert(1, local[2])
        val.insert(1, local[1])
        val.insert(1, local[0])
        # 面积
        Area = 1    # 定义变量保存一个整型的面积值
        are = val[4]
        del val[4]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(4, number[0])
            Area = int(number[0])
        else:
            val.insert(4, [])

        # 提取朝向并改为字符串
        temp_dire = val[5]
        del val[5]
        val.insert(5, temp_dire[0])

        # 提取房型并改为字符串
        temp_type = val[6]
        del val[6]
        val.insert(6, temp_type[0])

        # 提取房子号码并改为字符串
        temp_type = val[7]
        del val[7]
        val.insert(7, temp_type[0])

        # 价格
        price = 1  # 定义变量保存一个整型的面积值
        are = val[8]
        del val[8]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(8, number[0])
            price = int(number[0])
        else:
            val.insert(8, [])
        writer.writerow(val)
    f.close()
    csvfile.close()

# 将广州的数据转换为csv文件格式
csvfile = open('guang_zhou.csv', 'w', newline='', encoding='utf-8-sig')
writer = csv.writer(csvfile, delimiter=',')

with open('D:\\桌面\\final\\guang_zhou.json', 'r', encoding='UTF-8') as f:
    flag = True
    for line in f:
        dic = json.loads(line)
        if flag:
            # 获取属性列表
            keys = list(dic.keys())
            keys.insert(2, 'building_location2')
            keys.insert(2, 'building_location1')
            print(keys)
            writer.writerow(keys)  # 将属性列表写入csv中
            flag = False
        # 读取json数据的每一行，将values数据一次一行的写入csv中
        val = list(dic.values())
        # 提取名字并改为字符串
        temp_name = val[0]
        del val[0]
        name = temp_name[0].split(" ", 1)
        # print(name[0][3:])
        val.insert(0, name[0][3:])

        # 将地理位置拆分成三个
        local = val[1]
        del val[1]
        if len(local) < 3:
            val.insert(1, "")
            val.insert(1, local[1])
            val.insert(1, local[0])
        else:
            val.insert(1, local[2])
            val.insert(1, local[1])
            val.insert(1, local[0])
        # 面积
        Area = 1    # 定义变量保存一个整型的面积值
        are = val[4]
        del val[4]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(4, number[0])
            Area = int(number[0])
        else:
            val.insert(4, [])

        # 提取朝向并改为字符串
        temp_dire = val[5]
        del val[5]
        val.insert(5, temp_dire[0])

        # 提取房型并改为字符串
        temp_type = val[6]
        del val[6]
        val.insert(6, temp_type[0])

        # 提取房子号码并改为字符串
        temp_type = val[7]
        del val[7]
        val.insert(7, temp_type[0])

        # 价格
        price = 1  # 定义变量保存一个整型的面积值
        are = val[8]
        del val[8]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(8, number[0])
            price = int(number[0])
        else:
            val.insert(8, [])
        writer.writerow(val)
    f.close()
    csvfile.close()

# 将深圳的数据转换为csv文件格式
csvfile = open('shen_zhen.csv', 'w', newline='', encoding='utf-8-sig')
writer = csv.writer(csvfile, delimiter=',')

with open('D:\\桌面\\final\\shen_zhen.json', 'r', encoding='UTF-8') as f:
    flag = True
    for line in f:
        dic = json.loads(line)
        if flag:
            # 获取属性列表
            keys = list(dic.keys())
            keys.insert(2, 'building_location2')
            keys.insert(2, 'building_location1')
            print(keys)
            writer.writerow(keys)  # 将属性列表写入csv中
            flag = False
        # 读取json数据的每一行，将values数据一次一行的写入csv中
        val = list(dic.values())
        # 提取名字并改为字符串
        temp_name = val[0]
        del val[0]
        name = temp_name[0].split(" ", 1)
        # print(name[0][3:])
        val.insert(0, name[0][3:])

        # 将地理位置拆分成三个
        local = val[1]
        del val[1]
        val.insert(1, local[2])
        val.insert(1, local[1])
        val.insert(1, local[0])
        # 面积
        Area = 1    # 定义变量保存一个整型的面积值
        are = val[4]
        del val[4]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(4, number[0])
            Area = int(number[0])
        else:
            val.insert(4, [])

        # 提取朝向并改为字符串
        temp_dire = val[5]
        del val[5]
        val.insert(5, temp_dire[0])

        # 提取房型并改为字符串
        temp_type = val[6]
        del val[6]
        val.insert(6, temp_type[0])

        # 提取房子号码并改为字符串
        temp_type = val[7]
        del val[7]
        val.insert(7, temp_type[0])

        # 价格
        price = 1  # 定义变量保存一个整型的面积值
        are = val[8]
        del val[8]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(8, number[0])
            price = int(number[0])
        else:
            val.insert(8, [])
        writer.writerow(val)
    f.close()
    csvfile.close()

# 将合肥的数据转换为csv文件格式
csvfile = open('he_fei.csv', 'w', newline='', encoding='utf-8-sig')
writer = csv.writer(csvfile, delimiter=',')

with open('D:\\桌面\\final\\he_fei.json', 'r', encoding='UTF-8') as f:
    flag = True
    for line in f:
        dic = json.loads(line)
        if flag:
            # 获取属性列表
            keys = list(dic.keys())
            keys.insert(2, 'building_location2')
            keys.insert(2, 'building_location1')
            print(keys)
            writer.writerow(keys)  # 将属性列表写入csv中
            flag = False
        # 读取json数据的每一行，将values数据一次一行的写入csv中
        val = list(dic.values())
        # 提取名字并改为字符串
        temp_name = val[0]
        del val[0]
        name = temp_name[0].split(" ", 1)
        # print(name[0][3:])
        val.insert(0, name[0][3:])

        # 将地理位置拆分成三个
        local = val[1]
        del val[1]
        if len(local) < 3:
            val.insert(1, "")
            val.insert(1, local[1])
            val.insert(1, local[0])
        else:
            val.insert(1, local[2])
            val.insert(1, local[1])
            val.insert(1, local[0])
        # 面积
        Area = 1    # 定义变量保存一个整型的面积值
        are = val[4]
        del val[4]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(4, number[0])
            Area = int(number[0])
        else:
            val.insert(4, [])

        # 提取朝向并改为字符串
        temp_dire = val[5]
        del val[5]
        val.insert(5, temp_dire[0])

        # 提取房型并改为字符串
        temp_type = val[6]
        del val[6]
        val.insert(6, temp_type[0])

        # 提取房子号码并改为字符串
        temp_type = val[7]
        del val[7]
        val.insert(7, temp_type[0])

        # 价格
        price = 1  # 定义变量保存一个整型的面积值
        are = val[8]
        del val[8]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(8, number[0])
            price = int(number[0])
        else:
            val.insert(8, [])
        writer.writerow(val)
    f.close()
    csvfile.close()
