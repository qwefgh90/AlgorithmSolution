def sort(_list):
	for i in range(len(_list)):
		target = _list[i]
		for k in range(len(_list)):
			if( (k+1) != len(_list)):
				if (_list[k] > _list[k+1]):
					swap(_list,k,k+1)
				else :
					k+=1

def printMax(_list):
	temp = 0
	for i in _list:
		if i>temp:
			temp = i

	print '%.1f'%(temp)
def swap(_list,sindex,dindex):
	temp = _list[sindex]
	_list[sindex] = _list[dindex]
	_list[dindex] = temp
			

count = int(raw_input())
case_list = []
for i in range(count):
	case_count = int(raw_input())
	case_item = raw_input()
	case_item = (int(item) for item in case_item.split(' '))
	case_item = list(case_item)
	case_list.append((case_count, case_item))

result = []
for i in range(count):
	sort(case_list[i][1])
	_list = []
	
	for k in range(len(case_list[i][1])/2):
		avg = (case_list[i][1][k] + case_list[i][1][len(case_list[i][1])-k-1]) /2.0
		_list.append(avg)
	if(len(case_list[i][1]))%2 == 1:
		_list.append(case_list[i][1][len(case_list[i][1])/2])
	sort(_list)
	result.append(_list)

for i in result:
	printMax(i)
