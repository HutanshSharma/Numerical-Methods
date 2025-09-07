import numpy as np
import matplotlib.pyplot as plt

x = np.logspace(-6, 6, 500)

A = np.sqrt(x + 1) - np.sqrt(x)
B = 1 / (np.sqrt(x + 1) + np.sqrt(x))

denom = 0.5 * (np.abs(A) + np.abs(B))
eps = np.finfo(float).eps
rel_diff = np.abs(A - B) / np.abs(B)

plt.figure(figsize=(8,5))
plt.loglog(x, rel_diff)
plt.xlabel("x")
plt.ylabel("Relative difference")
plt.title("Relative difference between √(x+1)−√x and 1/(√(x+1)+√x)")
plt.grid(True, which="both")
plt.show()
