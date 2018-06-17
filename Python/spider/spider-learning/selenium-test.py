import os
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

# 通过设置，不打开浏览器操作
chrome_options = Options()
chrome_options.add_argument('--headless')

os.makedirs('./img/', exist_ok=True)

driver = webdriver.Chrome(chrome_options=chrome_options)
driver.get('https://innofang.github.io')
# driver.find_element_by_link_text('About').click()

html = driver.page_source
driver.get_screenshot_as_file('./img/screenshot.png')
driver.close()
print(html[:200])