import os
from urllib.request import urlretrieve
import requests

os.makedirs('./img/', exist_ok=True)
IMAGE_URL = 'https://morvanzhou.github.io/static/img/description/learning_step_flowchart.png'

# method 1
urlretrieve(IMAGE_URL, './img/image1.png')

# method 2
r = requests.get(IMAGE_URL)
with open('./img/image2.png', 'wb') as f:
    f.write(r.content)

# method 3, more efficient
r = requests.get(IMAGE_URL, stream=True)
with open('./img/image3.png', 'wb') as f:
    for chunk in r.iter_content(chunk_size=32):
        f.write(chunk)