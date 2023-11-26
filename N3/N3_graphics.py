import matplotlib.pyplot as plt
import math

f = open("generated_data_quick.txt", "r")
n = list(map(int, f.readline().split()))
random = list(map(float, f.readline().split()))
reverse = list(map(float, f.readline().split()))
almost = list(map(float, f.readline().split()))
f.close()

f, ax1 = plt.subplots(1)
ax1.set_title('RANDOM DATA')
line1, = ax1.plot(n, random)
ax1.legend([line1], ['Time (microsec)'])
ax1.set_xlabel('Size of data')
ax1.set_ylabel('Time (microsec)')
ax1.grid()

f, ax2 = plt.subplots(1)
ax2.set_title('REVERSED DATA')
line1, = ax2.plot(n, reverse)
ax2.legend([line1], ['Time (microsec)'])
ax2.set_xlabel('Size of data')
ax2.set_ylabel('Time (microsec)')
ax2.grid()

f, ax3 = plt.subplots(1)
ax3.set_title('ALMOST SORTED DATA')
line1, = ax3.plot(n, almost)
ax3.legend([line1], ['Time (microsec)'])
ax3.set_xlabel('Size of data')
ax3.set_ylabel('Time (microsec)')
ax3.grid()



f = open("generated_data_hybrid.txt", "r")
n = list(map(int, f.readline().split()))
random5 = list(map(float, f.readline().split()))
random10 = list(map(float, f.readline().split()))
random20 = list(map(float, f.readline().split()))
random50 = list(map(float, f.readline().split()))
reverse5 = list(map(float, f.readline().split()))
reverse10 = list(map(float, f.readline().split()))
reverse20 = list(map(float, f.readline().split()))
reverse50 = list(map(float, f.readline().split()))
almost5 = list(map(float, f.readline().split()))
almost10 = list(map(float, f.readline().split()))
almost20 = list(map(float, f.readline().split()))
almost50 = list(map(float, f.readline().split()))
f.close()

f, ax4 = plt.subplots(1)
ax4.set_title('RANDOM DATA')
line5, = ax4.plot(n, random5)
line10, = ax4.plot(n, random10)
line20, = ax4.plot(n, random20)
line50, = ax4.plot(n, random50)
ax4.legend([line5, line10, line20, line50], ['limit = 5', 'limit = 10', 'limit = 20', 'limit = 50'])
ax4.set_xlabel('Size of data')
ax4.set_ylabel('Time (microsec)')
ax4.grid()

f, ax5 = plt.subplots(1)
ax5.set_title('REVERSED DATA')
line5, = ax5.plot(n, reverse5)
line10, = ax5.plot(n, reverse10)
line20, = ax5.plot(n, reverse20)
line50, = ax5.plot(n, reverse50)
ax5.legend([line5, line10, line20, line50], ['limit = 5', 'limit = 10', 'limit = 20', 'limit = 50'])
ax5.set_xlabel('Size of data')
ax5.set_ylabel('Time (microsec)')
ax5.grid()

f, ax6 = plt.subplots(1)
ax6.set_title('ALMOST SORTED DATA')
line5, = ax6.plot(n, almost5)
line10, = ax6.plot(n, almost10)
line20, = ax6.plot(n, almost20)
line50, = ax6.plot(n, almost50)
ax6.legend([line5, line10, line20, line50], ['limit = 5', 'limit = 10', 'limit = 20', 'limit = 50'])
ax6.set_xlabel('Size of data')
ax6.set_ylabel('Time (microsec)')
ax6.grid()




plt.show()