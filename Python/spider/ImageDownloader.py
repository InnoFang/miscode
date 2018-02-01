import urllib.response as response
import requests
import re

def download(url, local):
    res = requests.get(url).text
    # buf = res.decode('utf-8')
    url_list = re.findall(r'//.+?\.jpg*', res)
    # url_list = re.findall(r'src="(.+\.jpg)', buf)
    # url_list = re.findall(r'//.+?\.(jpg|png|gif)', buf)
    if local[-1:] != '/':
        local += '/'
    for url in url_list:
        i = url.rfind('/')
        file_path = local + url[i:]
        print(file_path)
        with open(file_path, 'wb') as f:
            src = requests.get('http:' + url).content
            f.write(src)


if __name__ == '__main__':
    download('http://www.imooc.com/course/list', 'e:/testimg')
