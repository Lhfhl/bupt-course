import scrapy
from test1.items import MyItem, second_hand_item  # 从items.py中引入MyItem对象


class mySpider(scrapy.spiders.Spider):
    name = "new_house"  # 爬虫的名字是bupt
    # allowed_domains = ["bj.fang.lianjia.com/"]  # 允许爬取的网站域名
    start_urls = ["https://bj.fang.lianjia.com/loupan/pg3/"]
    custom_settings = {
        'ITEM_PIPELINES': {'test1.pipelines.MyPipeline': 300},
    }

    # 初始URL，即爬虫爬取的第一个URL
    def parse(self, response):
        # 解析爬取的内容
        item = MyItem()  # 生成一个在items.py中定义好的Myitem对象,用于接收爬取的数据
        # /html/body/div[2]/div[2]/div[2]/div/ul/li[1]/div/ul/li[7]/a
        for each in response.xpath("/html/body/div[3]/ul[2]/li[*]/div[@class='resblock-desc-wrapper']"):
            # 用xpath来解析html，div标签中的数据，就是我们需要的数据。
            item['building_name'] = each.xpath("div[@class='resblock-name']/a/text()").extract()  # 学院名称在text中
            item['building_type'] = each.xpath(
                "div[@class='resblock-name']/span[@class='resblock-type']/text()").extract()  # 学院链接在href中
            item['building_location'] = each.xpath(
                "div[@class='resblock-location']/span/text()|div[@class='resblock-location']/a/text()").extract()
            item['house_type'] = each.xpath("a[@class='resblock-room']/span/text()").extract()
            item['house_area'] = each.xpath("div[@class='resblock-area']/span/text()").extract()
            item['unit_price'] = each.xpath(
                "div[@class='resblock-price']/div[@class='main-price']/span/text()").extract()
            item['unit_price'][1] = item['unit_price'][1].strip()
            item['total_price'] = each.xpath("div[@class='resblock-price']/div[@class='second']/text()").extract()
            # if item['building_name'] and item['building_type'] and item['building_location'] \
            #         and item['house_type'] and item['house_area'] and item['unit_price'] and item[
            #     'total_price']:  # 去掉值为空的数据
            yield item  # 返回item数据给到pipelines模块
        yield scrapy.Request("https://bj.fang.lianjia.com/loupan/pg4/")
        yield scrapy.Request("https://bj.fang.lianjia.com/loupan/pg5/")
        yield scrapy.Request("https://bj.fang.lianjia.com/loupan/pg6/")
        yield scrapy.Request("https://bj.fang.lianjia.com/loupan/pg7/")


# /html/body/div[2]/div[2]/div[2]/div/ul/li[1]/div/ul/li[1]/a
# /html/body/div[*]/ul[*]/li[*]/div[@class='resblock-desc-wrapper']
# /html/body/div[3]/ul[2]/li[1]/div
# /html/body/div[3]/ul[2]/li[1]/div
# /html/body/div[3]/ul[2]/li[2]/div

class second_hand(scrapy.spiders.Spider):
    name = 'second_hand'
    start_urls = ["https://bj.lianjia.com/ershoufang/pg3/"]
    custom_settings = {
        'ITEM_PIPELINES': {'test1.pipelines.MyPipeline2': 400},
    }

    def parse(self, response):
        item = second_hand_item()
        for each in response.xpath("//*[@id='content']/div[1]/ul/li[*]/div[1]"):
            item['name'] = each.xpath("div[1]/a/text()").extract()
            item['location'] = each.xpath("div[2]/div/a/text()").extract()
            item['type'] = each.xpath("div[3]/div/text()").extract()
            item['unit_price'] = each.xpath("div[6]/div[2]/span/text()").extract()
            item['total_price'] = each.xpath("div[6]/div[1]/span/text()|div[6]/div[1]/i[2]/text()").extract()
            yield item  # 返回item数据给到pipelines模块
        yield scrapy.Request("https://bj.lianjia.com/ershoufang/pg4/")
        yield scrapy.Request("https://bj.lianjia.com/ershoufang/pg5/")
        yield scrapy.Request("https://bj.lianjia.com/ershoufang/pg6/")
        yield scrapy.Request("https://bj.lianjia.com/ershoufang/pg7/")
