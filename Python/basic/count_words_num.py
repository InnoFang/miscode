# -*- coding: utf-8 -*-
from collections import Counter

def count_words(path):
	words = Counter()
	with open(path) as f:
		for line in f:
			for word in line.strip().split():
				words[word] += 1

	for word, count in words.most_common(10):
		print("%s x%d" % (word, count))


count_words("E:\\hello.txt")