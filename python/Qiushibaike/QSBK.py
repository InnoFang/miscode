#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'Spider for Qiushibaike'

__author__ = 'INNO'

import urllib.request
import urllib
import re


class QSBK:
    def __init__(self):
        self.pageIndex = 1
        self.user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
        # 初始化headers
        self.headers = {'User-Agent': self.user_agent}
        # 存放段子的变量，每一个元素是每一页的段子
        self.stories = []
        # 存放程序是否继续运行的变量
        self.enable = False

    # 传入某一页的索引获得页面代码
    def get_page(self, page_index):
        try:
            url = 'http://www.qiushibaike.com/hot/page/' + str(page_index)
            request = urllib.request.Request(url, headers=self.headers)
            response = urllib.request.urlopen(request)
            page_code = response.read().decode('utf-8')
            return page_code
        except urllib.error.URLError as e:
            if hasattr(e, "code"):
                print(e.error)
            if hasattr(e, "reason"):
                print(e.reason)

    # 传入某一页代码，返回本页不带图片的段子列表
    def get_page_items(self, page_index):
        page_code = self.get_page(page_index)
        if not page_code:
            print("error!")
            return None
        pattern = re.compile(
            '<.*?class="author.*?>.*?<a.*?<h2>(.*?)</h2>.*?<div.*?class="content".*?<span>(.*?)</span>(.*?)<div class="stats.*?class="number">(.*?)</i>',
            re.S)
        items = re.findall(pattern, page_code)
        page_stories = []
        for item in items:
            # 是否含有图片
            have_img = re.search("img", item[3])
            # 如果不含有图片，把它加入list中
            if not have_img:
                # item[0]是一个段子的发布者，item[1]是内容,item[2]是图片，item[4]是点赞数
                if not re.search('img', item[2]):  # 筛选无图的段子输出
                    page_stories.append([item[0].strip(), item[1].strip(), item[3].strip()])

        return page_stories

    # 加载并提取页面的内容，加入到列表中
    def load_page(self):
        if self.enable:
            if len(self.stories) < 2:
                # 获取新一页
                page_stories = self.get_page_items(self.pageIndex)
                # 将该页的段子存放到全局list中
                if page_stories:
                    self.stories.append(page_stories)
                    # 获取完之后页码索引加一，表示下次读取下一页
                    self.pageIndex += 1

    # 调用该方法，每次敲回车打印输出一个段子
    def get_one_story(self, page_stories, page):  # 遍历一页的段子
        for story in page_stories:
            keyboard = input()
            self.load_page()
            if keyboard == 'Q':
                self.enable = False
                return
            print(u'\n作者:' + story[0],
                  '\n内容:' + re.sub('<br/>', '', story[1]) + '\n点赞人数:' + str(story[2]))
            # print(u"第%d页\t发布人:%s\t发布时间:%s\n%s\n赞:%s\n" % (page, story[0], story[1], story[2], story[3]))


    # 开始方法
    def start(self):
        print(u"正在读取糗事百科,按回车查看新段子，Q退出")
        # 使变量为True，程序可以正常运行
        self.enable = True
        # 先加载一页内容
        self.load_page()
        # 局部变量，控制当前读到了第几页
        now_page = 0
        while self.enable:
            if len(self.stories) > 0:
                # 从全局list中获取一页的段子
                page_stories = self.stories[0]
                # 当前读到的页数加一
                now_page += 1
                # 将全局list中第一个元素删除，因为已经取出
                del self.stories[0]
                # 输出该页的段子
                self.get_one_story(page_stories, now_page)


if __name__ == '__main__':
    spider = QSBK()
    spider.start()
