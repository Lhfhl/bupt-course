import scrapy

from final.items import bei_jing_item


class bei_jing(scrapy.spiders.Spider):
    name = "bei_jing"
    start_urls = ["https://bj.lianjia.com/zufang/brp0erp3500/"]
    custom_settings = {
        'ITEM_PIPELINES': {'final.pipelines.bei_jing_Pipeline': 300},
    }

    def parse(self, response):
        item = bei_jing_item()

        for each in response.xpath("/html/body/div[3]/div[1]/div[5]/div[1]/div[1]/div[*]"):
            strf = int(each.xpath("normalize-space(@data-ad_code)")[0].extract())
            if strf != 0:
                continue
            strf = str(each.xpath("normalize-space(div/p[1]/a/text())")[0].extract())
            strf = str(strf[0:2])
            if strf == "独栋" or strf == "合租":
                continue
            item['title'] = each.xpath("normalize-space(div/p[1]/a/text())").extract()
            item['location'] = each.xpath("div/p[2]/a[1]/text()|div/p[2]/a[2]/text()|div/p[2]/a[3]/text()").extract()
            item['area'] = each.xpath("normalize-space(div/p[2]/text()[5])").extract()
            item['direction'] = each.xpath("normalize-space(div/p[2]/text()[6])").extract()
            item['type'] = each.xpath("normalize-space(div/p[2]/text()[7])").extract()
            item['description'] = each.xpath("normalize-space(@data-house_code)").extract()
            item['price'] = each.xpath("div/span/em/text()|div/span/text()").extract()

            yield item  # 返回item数据给到pipelines模块

        for i in range(71):
            j = str(i + 2)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "erp3500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(63):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp3501erp4000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(84):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp4001erp4500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp4501erp5000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp5001erp5500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(92):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp5501erp5900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(97):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp5901erp6300/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(90):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp6301erp6700/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(92):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp6701erp7200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(95):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp7201erp7800/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(91):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp7801erp8600/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(96):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp8601erp10500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(98):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp10501erp14000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(95):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp14001erp26000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(42):
            j = str(i + 1)
            next_url = "https://bj.lianjia.com/zufang/pg" + j + "brp26001/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)


class shang_hai(scrapy.spiders.Spider):
    name = "shang_hai"
    start_urls = ["https://sh.lianjia.com/zufang/erp3500/"]
    custom_settings = {
        'ITEM_PIPELINES': {'final.pipelines.shang_hai_Pipeline': 400},
    }

    def parse(self, response):
        item = bei_jing_item()

        for each in response.xpath("/html/body/div[3]/div[1]/div[5]/div[1]/div[1]/div[*]"):
            strf = int(each.xpath("normalize-space(@data-ad_code)")[0].extract())
            if strf != 0:
                continue
            strf = str(each.xpath("normalize-space(div/p[1]/a/text())")[0].extract())
            strf = str(strf[0:2])
            if strf == "独栋" or strf == "合租":
                continue
            item['title'] = each.xpath("normalize-space(div/p[1]/a/text())").extract()
            item['location'] = each.xpath("div/p[2]/a[1]/text()|div/p[2]/a[2]/text()|div/p[2]/a[3]/text()").extract()
            item['area'] = each.xpath("normalize-space(div/p[2]/text()[5])").extract()
            item['direction'] = each.xpath("normalize-space(div/p[2]/text()[6])").extract()
            item['type'] = each.xpath("normalize-space(div/p[2]/text()[7])").extract()
            item['description'] = each.xpath("normalize-space(@data-house_code)").extract()
            item['price'] = each.xpath("div/span/em/text()|div/span/text()").extract()

            yield item  # 返回item数据给到pipelines模块

        for i in range(92):
            j = str(i + 2)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "erp3500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(96):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp3501erp4200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(86):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp4201erp4700/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(76):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp4701erp5100/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp5101erp5500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(85):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp5501erp6000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp6001erp6800/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(92):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp6801erp7900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(89):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp7901erp9500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(84):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp9501erp13000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(71):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp13001erp20000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(53):
            j = str(i + 1)
            next_url = "https://sh.lianjia.com/zufang/pg" + j + "brp20001/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)


class guang_zhou(scrapy.spiders.Spider):
    name = "guang_zhou"
    start_urls = ["https://gz.lianjia.com/zufang/erp1100/"]
    custom_settings = {
        'ITEM_PIPELINES': {'final.pipelines.guang_zhou_Pipeline': 500},
    }

    def parse(self, response):
        item = bei_jing_item()

        for each in response.xpath("/html/body/div[3]/div[1]/div[5]/div[1]/div[1]/div[*]"):
            strf = int(each.xpath("normalize-space(@data-ad_code)")[0].extract())
            if strf != 0:
                continue
            strf = str(each.xpath("normalize-space(div/p[1]/a/text())")[0].extract())
            strf = str(strf[0:2])
            if strf == "独栋" or strf == "合租":
                continue
            item['title'] = each.xpath("normalize-space(div/p[1]/a/text())").extract()
            item['location'] = each.xpath("div/p[2]/a[1]/text()|div/p[2]/a[2]/text()|div/p[2]/a[3]/text()").extract()
            item['area'] = each.xpath("normalize-space(div/p[2]/text()[5])").extract()
            item['direction'] = each.xpath("normalize-space(div/p[2]/text()[6])").extract()
            item['type'] = each.xpath("normalize-space(div/p[2]/text()[7])").extract()
            item['description'] = each.xpath("normalize-space(@data-house_code)").extract()
            item['price'] = each.xpath("div/span/em/text()|div/span/text()").extract()

            yield item  # 返回item数据给到pipelines模块

        for i in range(79):
            j = str(i + 2)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "erp1100/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(90):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1101erp1300/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(61):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1301erp1490/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(90):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1491erp1590/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(78):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1591erp1690/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(59):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1691erp1790/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1791erp1880/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(52):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp1881erp1990/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(47):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0brp1991erp2000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(35):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l1brp1991erp2000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(38):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp1991erp2000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(5):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l3brp1991erp2000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(62):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp2001erp2190/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(99):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp2191erp2290/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp2291erp2320/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(62):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp2321erp2490/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(38):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0brp2491erp2500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(47):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l1brp2491erp2500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(58):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp2491erp2500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(9):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l3brp2491erp2500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(91):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp2501erp2600/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(56):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp2601erp2790/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(99):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l1l3brp2791erp2900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(54):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp2791erp2900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(82):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l3brp2901erp3200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(86):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l1brp2901erp3200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(93):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp2901erp3200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(91):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp3201erp3400/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(89):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l3l2brp3401erp3500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(42):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l1brp3401erp3500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(84):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp3501erp3790/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp3791erp3890/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(75):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l1l3brp3891erp4000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(40):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp3891erp4000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(69):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp4001erp4290/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l1l3brp4291erp4590/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(65):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp4291erp4590/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(99):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp4591erp4990/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(81):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp4991erp5100/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(83):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l1l3brp5101erp5900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(82):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2brp5101erp5900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(93):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2l0brp5901erp7000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(74):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l1l3brp5901erp7000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(86):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l2l1brp7001erp11000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(67):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "l0l3brp7001erp11000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(68):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp11001erp20000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(35):
            j = str(i + 1)
            next_url = "https://gz.lianjia.com/zufang/pg" + j + "brp20001/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)


class shen_zhen(scrapy.spiders.Spider):
    name = "shen_zhen"
    start_urls = ["https://sz.lianjia.com/zufang/erp1300/"]
    custom_settings = {
        'ITEM_PIPELINES': {'final.pipelines.shen_zhen_Pipeline': 200},
    }
    i = 0

    def parse(self, response):
        item = bei_jing_item()

        for each in response.xpath("/html/body/div[3]/div[1]/div[5]/div[1]/div[1]/div[*]"):
            strf = int(each.xpath("normalize-space(@data-ad_code)")[0].extract())
            if strf != 0:
                shen_zhen.i += 1
                continue
            strf = str(each.xpath("normalize-space(div/p[1]/a/text())")[0].extract())
            strf = str(strf[0:2])
            if strf == "独栋" or strf == "合租":
                shen_zhen.i += 1
                continue
            item['title'] = each.xpath("normalize-space(div/p[1]/a/text())").extract()
            item['location'] = each.xpath("div/p[2]/a[1]/text()|div/p[2]/a[2]/text()|div/p[2]/a[3]/text()").extract()
            item['area'] = each.xpath("normalize-space(div/p[2]/text()[5])").extract()
            item['direction'] = each.xpath("normalize-space(div/p[2]/text()[6])").extract()
            item['type'] = each.xpath("normalize-space(div/p[2]/text()[7])").extract()
            item['description'] = each.xpath("normalize-space(@data-house_code)").extract()
            item['price'] = each.xpath("div/span/em/text()|div/span/text()").extract()

            yield item  # 返回item数据给到pipelines模块

        for i in range(69):
            j = str(i + 2)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "erp1300/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(24):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1301erp1350/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1351erp1400/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1401erp1500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(98):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1501erp1600/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(66):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1601erp1700/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1701erp1900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(86):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp1901erp2000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(99):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp2001erp2200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(81):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp2201erp2400/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(94):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp2401erp2600/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(91):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp2601erp2900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(93):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp2901erp3200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(86):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp3201erp3500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp3501erp3900/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(85):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp3901erp4200/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp4201erp4700/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(85):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp4701erp5100/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(96):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp5101erp5500/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp5501erp6000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(96):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp6001erp6700/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(88):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp6701erp7400/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(89):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp7401erp8000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(99):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp8001erp9700/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp9701erp13000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(71):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp13001erp20000/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(58):
            j = str(i + 1)
            next_url = "https://sz.lianjia.com/zufang/pg" + j + "brp20001/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)
        print(shen_zhen.i)


class he_fei(scrapy.spiders.Spider):
    name = "he_fei"
    start_urls = ["https://hf.lianjia.com/zufang/erp1100/"]
    custom_settings = {
        'ITEM_PIPELINES': {'final.pipelines.he_fei_Pipeline': 100},
    }
    i = 0

    def parse(self, response):
        item = bei_jing_item()

        for each in response.xpath("/html/body/div[3]/div[1]/div[5]/div[1]/div[1]/div[*]"):
            strf = int(each.xpath("normalize-space(@data-ad_code)")[0].extract())
            if strf != 0:
                he_fei.i += 1
                continue
            strf = str(each.xpath("normalize-space(div/p[1]/a/text())")[0].extract())
            strf = str(strf[0:2])
            if strf == "独栋" or strf == "合租":
                he_fei.i += 1
                continue
            item['title'] = each.xpath("normalize-space(div/p[1]/a/text())").extract()
            item['location'] = each.xpath("div/p[2]/a[1]/text()|div/p[2]/a[2]/text()|div/p[2]/a[3]/text()").extract()
            item['area'] = each.xpath("normalize-space(div/p[2]/text()[5])").extract()
            item['direction'] = each.xpath("normalize-space(div/p[2]/text()[6])").extract()
            item['type'] = each.xpath("normalize-space(div/p[2]/text()[7])").extract()
            item['description'] = each.xpath("normalize-space(@data-house_code)").extract()
            item['price'] = each.xpath("div/span/em/text()|div/span/text()").extract()

            yield item  # 返回item数据给到pipelines模块

        for i in range(89):
            j = str(i + 2)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "erp1100/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(83):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp1101erp1400/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(68):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp1401erp1590/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(90):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp1591erp1790/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(77):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp1791erp1990/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(82):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp1991erp2190/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(89):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp2191erp2490/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(100):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp2491erp2890/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(91):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp2891erp3990/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(74):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp3991erp20990/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)

        for i in range(79):
            j = str(i + 1)
            next_url = "https://hf.lianjia.com/zufang/pg" + j + "brp3991/#contentList"
            yield scrapy.Request(next_url, callback=self.parse)
        print(he_fei.i)
