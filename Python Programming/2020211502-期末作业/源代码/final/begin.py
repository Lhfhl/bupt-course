from scrapy import cmdline
from scrapy.crawler import CrawlerRunner
from scrapy.utils.log import configure_logging
from twisted.internet import reactor
from final.spiders.spider import bei_jing, shang_hai, guang_zhou, shen_zhen, he_fei

configure_logging()
runner = CrawlerRunner()
# runner.crawl(bei_jing)
# runner.crawl(shang_hai)
# runner.crawl(guang_zhou)
# runner.crawl(shen_zhen)
runner.crawl(he_fei)
d = runner.join()
d.addBoth(lambda _: reactor.stop())

reactor.run()
