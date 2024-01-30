# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class MyItem(scrapy.Item):
    # define the fields for your item here like:

    building_name = scrapy.Field()
    building_type = scrapy.Field()
    building_location = scrapy.Field()
    house_type = scrapy.Field()
    house_area = scrapy.Field()
    unit_price = scrapy.Field()
    total_price = scrapy.Field()


class second_hand_item(scrapy.Item):
    name = scrapy.Field()
    location = scrapy.Field()
    type = scrapy.Field()
    unit_price = scrapy.Field()
    total_price = scrapy.Field()
