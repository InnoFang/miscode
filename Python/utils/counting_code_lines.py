import os
import re
import time
from collections import defaultdict

lines = 0
pattern = re.compile('.*\.(py|java||c|cpp|js|pde|kt|dart)$')
file_dict = defaultdict(int)


def countFileLines(filename):
    count = 0
    with open(filename, 'rb') as handle:
        for _ in handle:
            count += 1
    return count


def listDir(path):
    global lines, pattern, file_dict
    files = os.listdir(path)
    for file in files:
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            listDir(file_path)
        elif os.path:
            try:
                res = re.match(pattern, file)
                if res:
                    line = countFileLines(file_path)
                    file_type = os.path.splitext(file)[1][1:]
                    file_dict[file_type] += 1
                    print('File name: ', file_path, ' , file type: ', file_type, ' , code line: ', line)
                    lines += line
            except AttributeError as e:
                print(e)


def main():
    global lines

    filepath = './filelist.txt'

    if not os.path.exists(filepath):
        print('{} is not exist, please create it and add some file path you want to count.'.format(filepath))
        exit(0)
 
    with open(filepath) as file:
        time_start = time.time()
        print('--- searching and counting ---')
        for line in file.readlines():
            line = line.strip()
            if os.path.exists(line):
                listDir(line)
            else:
                print('{} is not a validate path.'.format(line))
        time_end = time.time()
    
    print('Total number of lines of code: ', lines)
 
    totally = 0

    # py|java||c|cpp|js|pde|kt|dart
    for _, count in file_dict.items():
        totally += count
    for tp, count in file_dict.items():
        print('The number of ', tp, ' file: ', count, ' , ratio is %.2f%%' % (count / totally * 100))
    print('Totally cost: ', time_end - time_start, 's')


if __name__ == '__main__':
    main()
    """
    Total number of lines of code:  181840
    The number of  c  file:  29  , ratio is 1.26%
    The number of  cpp  file:  129  , ratio is 5.61%
    The number of  java  file:  1409  , ratio is 61.31%
    The number of  js  file:  83  , ratio is 3.61%
    The number of  kt  file:  289  , ratio is 12.58%
    The number of  py  file:  263  , ratio is 11.44%
    The number of  pde  file:  85  , ratio is 3.70%
    The number of  dart  file:  11  , ratio is 0.48%
    Totally cost:  3.1801540851593018 s
    """
