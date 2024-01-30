# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


import json


class bei_jing_Pipeline(object):
    def open_spider(self, spider):
        try:  # 打开json文件
            self.file = open('bei_jing.json', "w", encoding="utf-8")
        except Exception as err:
            print(err)

    def process_item(self, item, spider):
        dict_item = dict(item)  # 生成字典对象
        json_str = json.dumps(dict_item, ensure_ascii=False) + "\n"  # 生成json串
        self.file.write(json_str)  # 将json串写入到文件中

        return item

    def close_spider(self, spider):
        self.file.close()  # 关闭文件


class shang_hai_Pipeline(object):
    def open_spider(self, spider):
        try:  # 打开json文件
            self.file = open('shang_hai.json', "w", encoding="utf-8")
        except Exception as err:
            print(err)

    def process_item(self, item, spider):
        dict_item = dict(item)  # 生成字典对象
        json_str = json.dumps(dict_item, ensure_ascii=False) + "\n"  # 生成json串
        self.file.write(json_str)  # 将json串写入到文件中

        return item

    def close_spider(self, spider):
        self.file.close()  # 关闭文件


class guang_zhou_Pipeline(object):
    def open_spider(self, spider):
        try:  # 打开json文件
            self.file = open('guang_zhou.json', "w", encoding="utf-8")
        except Exception as err:
            print(err)

    def process_item(self, item, spider):
        dict_item = dict(item)  # 生成字典对象
        json_str = json.dumps(dict_item, ensure_ascii=False) + "\n"  # 生成json串
        self.file.write(json_str)  # 将json串写入到文件中

        return item

    def close_spider(self, spider):
        self.file.close()  # 关闭文件


class shen_zhen_Pipeline(object):
    def open_spider(self, spider):
        try:  # 打开json文件
            self.file = open('shen_zhen.json', "w", encoding="utf-8")
        except Exception as err:
            print(err)

    def process_item(self, item, spider):
        dict_item = dict(item)  # 生成字典对象
        json_str = json.dumps(dict_item, ensure_ascii=False) + "\n"  # 生成json串
        self.file.write(json_str)  # 将json串写入到文件中

        return item

    def close_spider(self, spider):
        self.file.close()  # 关闭文件


class he_fei_Pipeline(object):
    def open_spider(self, spider):
        try:  # 打开json文件
            self.file = open('he_fei.json', "w", encoding="utf-8")
        except Exception as err:
            print(err)

    def process_item(self, item, spider):
        dict_item = dict(item)  # 生成字典对象
        json_str = json.dumps(dict_item, ensure_ascii=False) + "\n"  # 生成json串
        self.file.write(json_str)  # 将json串写入到文件中

        return item

    def close_spider(self, spider):
        self.file.close()  # 关闭文件