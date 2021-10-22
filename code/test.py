import torch
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import torch.utils.data as Data
import torch.nn as nn
import torch.optim as optim
from torch.nn import init

df =  pd.read_csv("./advertising.csv")

def graph1( data ):
    TV = data.TV
    Radio = data.Radio
    Newspaper = data.Newspaper
    Sales = data.Sales
 
    plt.scatter(TV, Sales,  c='r',marker='o',label='TV')
    plt.scatter(Radio, Sales,  c='b', marker='x', label='Radio')
    plt.scatter(Newspaper, Sales,  c='y', marker='d', label='Newspaper')
    plt.legend()
    plt.ylabel("销售额",fontproperties='SimHei')
    plt.xlabel('广告花费',fontproperties='SimHei')
    plt.grid(linestyle='-.')
    plt.show()
    
graph1(df)

def graph2(data):
    TV = data.TV
    Radio = data.Radio
    Newspaper = data.Newspaper
    Sales = data.Sales
    plt.ylabel("销售额", fontproperties='SimHei')
    #plt.figure()
    plt.subplot(311)
    plt.scatter(TV, Sales,  c='r',marker='o')
    plt.grid(linestyle='-.')
    plt.subplot(312)
    plt.scatter(Radio, Sales,  c='b', marker='x')
    plt.grid(linestyle='-.')
    plt.subplot(313)
    plt.scatter(Newspaper, Sales,  c='y', marker='d')
    plt.xlabel('广告花费', fontproperties='SimHei')
    plt.grid(linestyle='-.')
    plt.show()
    
graph2(df)

data=df.values
features=data[:,:3]
labels=data[:,3]
train_data,train_label,test_data,test_label=features[:160],labels[:160],features[160:],labels[160:]

train_data,train_label,test_data,test_label = torch.as_tensor(torch.from_numpy(train_data), dtype=torch.float32),\
torch.as_tensor(torch.from_numpy(train_label), dtype=torch.float32),\
torch.as_tensor(torch.from_numpy(test_data), dtype=torch.float32),\
torch.as_tensor(torch.from_numpy(test_label), dtype=torch.float32)

num_puts=3
batch_size = 32
lr=0.01
weight_decay=0.0001
num_epochs = 10

train_dataset = Data.TensorDataset(train_data, train_label)
data_iter_train = Data.DataLoader(train_dataset, batch_size, shuffle=True)

net = nn.Sequential(nn.Linear(num_puts, 1))
init.normal_(net[0].weight, mean=0, std=0.01)
init.constant_(net[0].bias, val=0)
loss = nn.MSELoss()
optimizer = optim.Adam(params=net.parameters(),lr=lr, weight_decay=weight_decay) 

process=[]

for epoch in range(1, num_epochs + 1):
    for x, y in data_iter_train:
        output = net(x)
        l = loss(output, y.view(-1, 1))
        optimizer.zero_grad()
        l.backward()
        optimizer.step()
        process.append(l.item())
    if epoch%2==0:
        print('epoch %d, train loss: %f' % (epoch, l.item()))
        
print('test loss: %f' % (loss(net(test_data), test_label.view(-1, 1)).item()))

print(net[0].weight)
print(net[0].bias)

plt.plot(process)
plt.ylabel('loss')
plt.xlabel('times')
plt.show()

import seaborn as sns

plt.figure(figsize=(10,8))
sns.heatmap(np.corrcoef(features,rowvar=False),linewidths = 0.05, cmap='rainbow', annot=True)
plt.title('Correlation coefficient')
plt.show()