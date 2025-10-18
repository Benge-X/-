import torch
import torch.nn as nn
import pandas as pd
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']


# 1. 加载数据
data = pd.read_csv('D:/archive/day.csv')
X_df = data['temp']
y_df = data['cnt']


# 2. 转换为PyTorch张量
X_tensor = torch.tensor(X_df.values, dtype=torch.float32)
y_tensor = torch.tensor(y_df.values, dtype=torch.float32)


# 重塑张量维度为 (样本数, 1)
X_tensor = X_tensor.view(-1, 1)
y_tensor = y_tensor.view(-1, 1)

print(f"数据形状: X_tensor: {X_tensor.shape}, y_tensor: {y_tensor.shape}")

# 绘制原始数据的散点图
plt.figure(figsize=(12, 4))

plt.subplot(1, 3, 1)
plt.scatter(X_tensor.numpy(), y_tensor.numpy(), alpha=0.5)
plt.xlabel('温度')
plt.ylabel('租车率')
plt.title('原始数据散点图')


# 线性回归模型
class LinearRegressionModel(nn.Module):
    def __init__(self):
        super(LinearRegressionModel, self).__init__()
        self.linear = nn.Linear(1, 1)

    def forward(self, x):
        return self.linear(x)


# 实例化模型、损失函数和优化器
model = LinearRegressionModel()
criterion = nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)

print("模型结构:")
print(model)


# 训练次数
num_epochs = 1000
losses = []  # 用于存储每个epoch的损失

for epoch in range(num_epochs):
    # 前向传播
    outputs = model(X_tensor)
    loss = criterion(outputs, y_tensor)

    # 反向传播和优化
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    # 记录损失
    losses.append(loss.item())

    # 每隔100轮打印损失
    if (epoch + 1) % 100 == 0:
        print(f'Epoch [{epoch + 1}/{num_epochs}], Loss: {loss.item():.4f}')

# 可视化
# 提取学习到的参数
weight = model.linear.weight.item()
bias = model.linear.bias.item()
print(f"\n训练结果:")
print(f"学习到的权重 (w): {weight:.4f}")
print(f"学习到的偏置 (b): {bias:.4f}")
print(f"回归方程: y = {weight:.4f} x + {bias:.4f}")

# 计算预测值
with torch.no_grad():
    predicted = model(X_tensor).detach().numpy()


# 绘制拟合直线
plt.subplot(1, 3, 2)
plt.scatter(X_tensor.numpy(), y_tensor.numpy(), alpha=0.5, label='原始数据')
plt.plot(X_tensor.numpy(), predicted, color='green', linewidth=1.5, label='拟合直线')
plt.xlabel('温度')
plt.ylabel('租车率')
plt.title('线性回归拟合结果')
plt.legend()
plt.grid(True, alpha=0.3)

# 绘制损失曲线
plt.subplot(1, 3, 3)
plt.plot(range(num_epochs), losses)
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.title('训练损失曲线')
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()




