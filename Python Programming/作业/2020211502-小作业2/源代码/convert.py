# -*- coding: utf-8 -*-
import json
import csv
import re

csvfile = open('new_house.csv', 'w', newline='', encoding='utf-8-sig')
writer = csv.writer(csvfile, delimiter=',')

with open('new_house.json', 'r', encoding='UTF-8') as f:
    # 解析一个有效的JSON字符串并将其转换为Python字典
    flag = True
    for line in f:
        dic = json.loads(line)
        if flag:
            # 获取属性列表
            keys = list(dic.keys())
            keys.insert(3, 'building_location2')
            keys.insert(3, 'building_location1')
            # 为索引面积，单价，总价增加单位
            temp_str = keys[6]+" 单位：㎡"
            del keys[6]
            keys.insert(6, temp_str)
            temp_str = keys[7] + " 单位：元/㎡"
            del keys[7]
            keys.insert(7, temp_str)
            temp_str = keys[8] + " 单位：万/套"
            del keys[8]

            keys.insert(8, temp_str)
            print(keys)
            writer.writerow(keys)  # 将属性列表写入csv中
            flag = False
            # 读取json数据的每一行，将values数据一次一行的写入csv中
        val = list(dic.values())
        # 将名字和类型改为字符串
        temp_name = val[0]
        del val[0]
        val.insert(0, temp_name[0])

        temp_type = val[1]
        del val[1]
        val.insert(1, temp_type[0])
        # 将地理位置拆分成三个
        local = val[2]
        del val[2]
        val.insert(2, local[2])
        val.insert(2, local[1])
        val.insert(2, local[0])

        # 保留最小房型
        typ = val[5]
        del val[5]
        if typ:
            val.insert(5, typ[0])
        else:
            val.insert(5, [])
        # 保留最小建面
        Area = 1
        are = val[6]
        del val[6]
        if are:
            number = re.findall("\\d+", are[0])
            val.insert(6, number[0])
            Area = int(number[0])
        else:
            val.insert(6, [])
        # 价格处理
        total_Price = 0
        unit_Price = 0
        unit = val[7]
        total = val[8]
        del val[7]
        del val[7]
        for i in unit:
            if "总价" in i:
                number = re.findall("\\d+", unit[0])
                total_Price = int(number[0])
            else:
                number = re.findall("\\d+", unit[0])
                unit_Price = int(number[0])

        if total:
            number = re.findall("\\d+", total[0])
            total_Price = int(number[0])
        else:
            unit_Price = round(total_Price*10000/Area)

        val.insert(7, total_Price)
        val.insert(7, unit_Price)
        writer.writerow(val)
    f.close()
    csvfile.close()
