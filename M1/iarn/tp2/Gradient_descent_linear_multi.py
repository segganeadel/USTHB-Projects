# matplotlib inline
import numpy as np
import matplotlib.pyplot as plt
import math
import pandas as pd

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
print(data)


def train_test_split(data):
    train_data = data.sample(frac=0.5, random_state=23)
    # Return a random sample of items from an axis of object
    test_data = data.drop(train_data.index).sample(frac=1.0)
    # Drop specified labels from rows or columns.
    x_train = np.array(train_data['X']).reshape(-1, 1)
    y_train = np.array(train_data['Y']).reshape(-1, 1)
    x_test = np.array(test_data['X']).reshape(-1, 1)
    y_test = np.array(test_data['Y']).reshape(-1, 1)
    return x_train, y_train, x_test, y_test


x_train, y_train, x_test, y_test = train_test_split(data)
# print(x_train)


# -------------------

def forward_1(x):
    return np.polyval(weight[::-1], x)
# -----------------------------------------

def loss(y, y_pred):
    loss = np.sqrt(np.mean((y_pred-y)**2))
    return loss
# ------------------------------------------

def gradient_1(i, x, y, y_pred):
    m = x.shape[0]
    # gradient of loss w.r.t  bias
    return (2/m)*np.sum(np.dot((x.T)**i, (y_pred - y)))

alpha = 0.01
# Degree 0 means y=b i.e there is only bias
weight = [0,0,0,0,0,0]
iterations = 100000
# -------------------------------------------------------------------
# Training loop


y_pred = forward_1(x_train)
for epoch in range(iterations):
    losses = []
    # -----------------------------------------
    for i in range(len(weight)): 
        grad = gradient_1(i, x_train, y_train, y_pred)
        weight[i]= weight[i] - alpha * grad  
    # ----------------------
    y_pred = forward_1(x_train)

    l = loss(y_train, y_pred)
    losses.append(l)
    #if(epoch % 10 == 0 or epoch == 99):
        #print("progress:", epoch, "w=", weight, "loss=", np.mean(losses))



#y_pred = forward_1(data['X'].array.reshape(-1, 1))
fig = plt.figure(figsize=(8, 6))

plt.plot(data['X'], data['Y'], 'yo-')

#plt.plot(x_train, y_train, 'yo-')
#plt.plot(x_test, y_test, 'bo-')
x1 = data['X']
y1 = forward_1(x1)
plt.plot(x1, y1,'o-',color='r')

plt.legend(["Data", f"Degree={len(weight)-1}"])
plt.xlabel('X - Input')
plt.ylabel('y - target / true')
plt.title('Polynomial Regression')
plt.show()
