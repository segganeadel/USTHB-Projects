# matplotlib inline
import numpy as np
import matplotlib.pyplot as plt
import math
import pandas as pd
from sklearn.model_selection import train_test_split
np.random.seed(23)


def data_gen(n_samples):
    x = np.sort(np.random.uniform(0, 1, n_samples))
    N = np.random.normal(0, 1, n_samples)
    y = np.sin(2*np.pi*x)+0.1*N
    data = pd.DataFrame()  # DataFrame is a structure
    # that contains two-dimensional data and its corresponding labels.
    data['X'] = x
    data['Y'] = y
    return data


data = data_gen(n_samples=20)


weight = np.polyfit(data['X'],data['Y'],3)

print (weight)

fig = plt.figure(figsize=(8, 6))

plt.plot(data['X'], data['Y'], 'yo-')

x1 = data['X']
y1 = np.polyval(weight, x1)

plt.plot(x1, y1,'o-',color='r')

plt.legend(["Data", f"Degree={len(weight)-1}"])
plt.xlabel('X - Input')
plt.ylabel('y - target / true')
plt.title('Polynomial Regression')
plt.show()
