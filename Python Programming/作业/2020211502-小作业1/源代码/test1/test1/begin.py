from scrapy import cmdline
from scrapy.crawler import CrawlerRunner
from scrapy.utils.log import configure_logging
from twisted.internet import reactor

from test1.spiders.spider import mySpider, second_hand

# cmdline.execute("scrapy crawl new_house".split())
# bupt为爬虫的名字，在spider.py中定义

configure_logging()
runner = CrawlerRunner()
runner.crawl(mySpider)
runner.crawl(second_hand)
d = runner.join()
d.addBoth(lambda _: reactor.stop())

reactor.run()

