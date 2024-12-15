import panda as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score


heart = pd.read_csv('/path/to/file.csv')

heart.head()
heart.tail()
heart.shape
heart.info()
heart.isnull()
heart.fillna(heart.median(), inplace = True)
heart.describe()
heart['target'].value_counts()
heart['target'].replace({'yes' : 1, 'no' : 0})
X = heart.drop(columns='target', axis=1)
Y = heart['target']
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=42)
model = LogisticRegression()
model.fit(X_train, Y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(Y_test, y_pred)




