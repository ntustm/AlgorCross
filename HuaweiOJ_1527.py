#coding:utf-8
'''
дһ���ű������Գɼ�����������ı�׼��������֣�A��90~100   B��80~89  C��70~79 D��60~69 F��<60
Ҫ��1.����һ���ַ��������ַ���ת��Ϊ���֣������Ӧ�ɼ�
2.��������ֻ��߳�����Χ�����˳�����
������
����                  ���
'89'        '89-->B'
'90.5'      '90.5-->A'
'23'        '23-->F'
'62'        '62-->D'
'75'        '75-->C'
'e'         'e-->it is not number'
'-90'       '-90-->Error number'
'999'       '999-->Error number'
'  999 '    '999-->Error number'
'''

grade = [
	{"min": 90, "max": 100, "grade": "A"},
	{"min": 80, "max": 89, "grade": "B"},
	{"min": 70, "max": 79, "grade": "C"},
	{"min": 60, "max": 69, "grade": "D"},
	{"min": 0, "max": 59, "grade": "F"}
]

def msg(num, tip):
	return "{0}-->{1}".format(num, tip)

class Demo:
	def rhomb(self,input):
		try:
			input = input.strip()
			if '.' in input:
				num = float(input)
			else:
				num = int(input)
		except:
			return msg(input, "it is not number")
		if num>100 or num <0:
			return msg(input, "Error number")
		res_str = ''
		for grdInfo in grade:
			if  grdInfo["min"] <= num <= grdInfo["max"]:
				res_str = msg(num, grdInfo["grade"])
				break
		return res_str

