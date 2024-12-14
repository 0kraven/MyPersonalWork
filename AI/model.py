import panda as pd
import numpy as np
import warnings
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score


heart = pd.read_csv('/path/to/file.csv')

heart.head()
heart.tail()
heart.shape
heart.info()
heart.isnull()
heart.describe()
heart['target'].value_counts()


