#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'Spider for Qiushibaike'

__author__ = 'INNO'

import urllib.request
import urllib
import re

page = 1
url = 'http://www.qiushibaike.com/hot/page/' + str(page)
user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
headers = {'User-Agent': user_agent}
try:
    request = urllib.request.Request(url, headers=headers)
    response = urllib.request.urlopen(request)
    content = response.read().decode('utf-8')
    pattern = re.compile(
        '<.*?class="author.*?>.*?<a.*?<h2>(.*?)</h2>.*?<div.*?class="content".*?<span>(.*?)</span>(.*?)<div class="stats.*?class="number">(.*?)</i>',
        re.S)
    items = re.findall(pattern, content)
    for item in items:
        if not re.search('img', item[2]):  # 筛选无图的段子输出
            print('\n作者:' + str(item[0]), '\n内容:' + str(item[1]) + '\n点赞人数:' + str(item[3]))

except urllib.error.URLError as e:
    if hasattr(e, "code"):
        print(e.code)
    if hasattr(e, "reason"):
        print(e.reason)
