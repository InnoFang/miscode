import requests
import webbrowser

# param = {'wd': '莫烦Python'}
# r = requests.get('http://www.baidu.com/s', params=param)
# print(r.url)
# webbrowser.open(r.url)

# data = {'firstname': 'Inno', 'lastname': 'Fang'}
# r = requests.post('http://pythonscraping.com/pages/files/processing.php', data=data)
# print(r.text)

# file = {'uploadFile': open('E:/Image/umr.jpg', 'rb')}
# r = requests.post('http://pythonscraping.com/pages/files/processing2.php', files=file)
# print(r.text)

payload = {'username': 'hhh', 'password': 'password'}
r = requests.post('http://pythonscraping.com/pages/cookies/welcome.php', data=payload)
print(r.cookies.get_dict())
r = requests.get('http://pythonscraping.com/pages/cookies/profile.php', cookies=r.cookies)
print(r.text)