import matplotlib.pyplot as plt
import math

f = open("generated_data.txt", "r")
n = list(map(float, f.readline().split()))
pi = list(map(float, f.readline().split()))
e = list(map(float, f.readline().split()))
f.close()

f, (ax1, ax2) = plt.subplots(1, 2)
ax1.set_title('PI absolute')
line1, = ax1.plot(n, pi)
line2, = ax1.plot(n, [math.pi for i in range(100, 5001, 100)])
ax1.legend([line1, line2], ['Prediction', 'Actual'])
ax1.set_xlabel('N')
ax1.set_ylabel('PI')
ax1.grid()

ax2.set_title('PI in %')
line1, = ax2.plot(n, e)
line2, = ax2.plot(n, [0 for i in range(100, 5001, 100)])
ax2.legend([line1, line2], ['Prediction', 'Actual'])
ax2.set_xlabel('N')
ax2.set_ylabel('epsilon PI')
ax2.grid()
plt.tight_layout()
plt.show()