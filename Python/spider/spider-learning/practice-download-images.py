# -*- coding:utf-8 -*-

from bs4 import BeautifulSoup
import requests
import os

URL = 'http://bing.plmeizi.com/?page=%d'

def downlaod_bing_wallpaper(page):
    for i in range(1, page + 1):
        print('========= Page %d =========' % i)

        html = requests.get(URL % i).text
        soup = BeautifulSoup(html, features='lxml')
        img_a = soup.find_all('a', {'class': 'item'})

        for a in img_a:
            url = a.find('div').find('img')['src']
            r = requests.get(url, stream=True)
            image_name = url.split('/')[-1].replace('jpg-listpic', 'jpg')
            
            with open('E:/bing/%s' % image_name, 'wb') as f:
                for chunk in r.iter_content(chunk_size=32):
                    f.write(chunk)
            print('Saved {}'.format(image_name))


if __name__ == '__main__':
    page = int(input('How many page do you need? (9pics/page): '))
    os.makedirs('E:/bing/', exist_ok=True)
    downlaod_bing_wallpaper(page)
