# -*- encoding: utf-8 -*-
import timeit
from changext import fibonachi

def pyFibonachi(index) :
	prepreValue = 1
	preValue = 1
	offset = 2
	if(index < 1) :
		print 'invalid parameter'
		return 0;
	if(index == 1) :
		return prepreValue
	elif(index == 2):
		return preValue
	else :
		while(offset < index):
			temp = prepreValue + preValue
			prepreValue = preValue
			preValue = temp
			offset += 1
		return preValue

def test():
	loopCount = 10000;
	pyresult = timeit.timeit('pyFibonachi(40)' , setup = "from fibonachi import pyFibonachi",number=loopCount)
	cresult = timeit.timeit('fibonachi(40)' , setup = "from changext import fibonachi",number=loopCount)

	fastResult = 'Python'
	slowResult = 'C Language'
	if(cresult < pyresult):
		fastResult = 'C Language'
		slowResult = 'Python'

	maxValue = max(pyresult*(10^7),cresult*(10^7))
	minValue = min(pyresult*(10^7),cresult*(10^7))

	print 'Loop Count- %d' %(loopCount)
	print slowResult + '- Value %f second' %(maxValue)
	print fastResult + '- Value %f second' %(minValue)
	print 'diff %f percent' %(maxValue/minValue)


if '__main__' == __name__ :
	print pyFibonachi(40)
	print fibonachi(40)
	test()