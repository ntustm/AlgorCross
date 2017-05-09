'''
功能：检查圆括号是否平衡
输入：s 输入字符串
输出：无
返回：布尔值，平衡返回true,否则返回False
'''
class Demo:
	def demo(self, s):
		cnt = 0
		if s == '' or s == None:
			return False
		for ch in s:
			if ch == '(':
				cnt+=1
			elif ch == ')':
				cnt-=1
			if cnt<0:
				return False
		if cnt == 0:
			return True
		else:
			return False

