import pandas as pd

# read data
data = pd.read_csv('data/student.csv')
print(data)

# write to pickle
data.to_pickle('data/student.pickle')