"""
14. subplot 分格显示
"""
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec


# method 1: subplot2grid
########################
plt.figure()
# 3行３列的子图，图从０,0开始，列跨度为３默认为１
ax1 = plt.subplot2grid((3,3), (0,0),colspan=3, rowspan=1)
ax1.plot([1,2],[1,2])
ax1.set_title('ax1_title')
ax2 = plt.subplot2grid((3,3), (1,0),colspan=2, rowspan=1)
ax3 = plt.subplot2grid((3,3), (1,2),colspan=1, rowspan=2)
ax4 = plt.subplot2grid((3,3), (2,0),colspan=1, rowspan=1)
ax5 = plt.subplot2grid((3,3), (2,1),colspan=1, rowspan=1)

# method 2: gridspec
#######################
fig = plt.figure()
gs = gridspec.GridSpec(3,3)
ax1 = plt.subplot(gs[0,:])
ax2 = plt.subplot(gs[1,:2])
ax3 = plt.subplot(gs[1:,2])
ax4 = plt.subplot(gs[-1,0])
ax5 = plt.subplot(gs[-1,-2])


# method 3: easy to define structure
#######################
# sharex是否共享ｘ轴 sharey是否共享ｙ轴，subplots返回一个figure和对应位置的ax
f, ((ax11,ax12),(ax21,ax22)) = plt.subplots(2,2,sharex=True,sharey=True)
ax11.scatter([1,2],[1,2])

plt.tight_layout()
plt.show()
