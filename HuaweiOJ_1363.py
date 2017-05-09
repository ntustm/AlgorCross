'''
功能：交换列表a和b的元素，使a的元素和与b的元素和差值最小
输入：list1, list2
输出：无
返回：经过交换后的list1和list2
'''

def iter_tool(list_it, r):
	pool = tuple(list_it)
	n = len(pool)
	if r > n:
		return
	ind = list(range(r))
	yield tuple(pool[i] for i in ind)
	while True:
		for i in reversed(range(r)):
			if ind[i] != i + n - r:
				break
			else:
				return
		ind[i] += 1
		for j in range(i+1, r):
			ind[j] = ind[j-1] + 1
		yield tuple(pool[i] for i in ind)

class Demo:

	def demo(self, list1, list2):
		l_merg = list1 + list2
		t_sum = sum(l_merg)
		a = min(iter_tool(l_merg, len(list1)), key=lambda x:abs(t_sum-2*sum(x)))
		for digit in a:
			l_merg.remove(digit)
		return list(a), l_merg
