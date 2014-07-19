cnt = int(raw_input())
rectlst=[]
for i in xrange(cnt):
	tmplst = []
	for k in xrange(3):
		input = raw_input()
		tmplst.append([int(j) for j in input.split()])
	rectlst.append(tmplst)
for i in xrange(cnt):
	coor=rectlst[i]
	result=[]
	center=reduce(lambda a,b:[a[0]+b[0], a[1]+b[1]], coor)
	center=[center[0]/3.0,center[1]/3.0]
	biggerx = [x for x in coor if center[0] < x[0]]
	biggery = [x for x in coor if center[1] < x[1]]
	smallerx = [x for x in coor if center[0] > x[0]]
	smallery = [x for x in coor if center[1] > x[1]]
	xx = biggerx if len(biggerx) < len(smallerx) else smallerx
	yy = biggery if len(biggery) < len(smallery) else smallery
	print xx[0][0], yy[0][1]
