import scrapy


class bei_jing_item(scrapy.Item):
    # define the fields for your item here like:
    title = scrapy.Field()          # 名称字段
    location = scrapy.Field()       # 地点字段
    area = scrapy.Field()           # 面积字段
    direction = scrapy.Field()      # 朝向字段
    type = scrapy.Field()           # 房型字段
    description = scrapy.Field()    # data-house_code
    price = scrapy.Field()          # 价格字段
