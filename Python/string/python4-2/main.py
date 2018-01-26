import os  # 系统权限相关
import stat  # 文件状态相关

files = os.listdir(r'F:\PyCharm Project\PythonTrain\python4\python4-2\test')
print(files)


f = [name for name in os.listdir(r'F:\PyCharm Project\PythonTrain\python4\python4-2\test') if name.endswith(('.sh', '.py'))]
print(f)

print(os.stat('readme.txt'))