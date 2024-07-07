import matplotlib.pyplot as plt

file_path = 'output.txt'
with open(file_path, 'r') as file:
    data = file.readlines()

x = []
y = []

# Parse the data
for index, line in enumerate(data):
    try:
        y_value = float(line.strip().split()[1])
        x.append(index)
        y.append(y_value)
    except ValueError:
        continue

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(x, y, marker='o', linestyle='-')
plt.grid(True)
plt.show()
