__author__ = 'changwoncheo'
a0=(0,'zero')
a1=(1,'one')
a2=(2,'two')
a3=(3,'three')
a4=(4,'four')
a5=(5,'five')
a6=(6,'six')
a7=(7,'seven')
a8=(8,'eight')
a9=(9,'nine')
alist = [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9]
biglist =[];
def compareNum(string):
    for i in alist:
        temp = ''
        com = i[1]
        l = list(com)
        for k in range(len(l)):
            if l[k] in string:
                pass
            else:
                break
            if k == len(l)-1:
                return i[0]

exlist=['+','-','*']
exexex = ''


def result(exp):
    index = -1;
    for i in exlist:
        index = exp.find(i)
        if(index != -1):
            exexex = i
            break
    startrange = [0,index-1]

    index = -1;
    for i in ['=']:
        index = exp.find(i)
        if(index != -1):
            break
    endrange = [startrange[1]+3,index-1]
    answerrange = [index+2,-1]

    a= compareNum(exp[startrange[0]:startrange[1]])
    b= compareNum(exp[endrange[0]:endrange[1]])
    c= compareNum(exp[answerrange[0]:])

    if exexex=='+':

        if (a+b) ==c:
           print 'Yes'
        else:
            print 'No'
    if exexex=='-':
        if (a-b) ==c:
           print 'Yes'
        else:
            print 'No'
    if exexex=='*':
        if (a*b) ==c:
           print 'Yes'
        else:
            print 'No'


cnt = raw_input()
for aa in range(int(cnt)):
    exp = raw_input()
    result(exp)



