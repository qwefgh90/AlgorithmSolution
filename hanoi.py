from Queue import Queue

count = int(raw_input())
class Stack(Queue):
    def _get(self):
        item = self.queue[-1]
        del self.queue[-1]
        return item
a = Stack();
b = Stack();
c = Stack();
k=[a,b,c]
def move(src,dest):
	k[dest-1].put(k[src-1].get())
	if(count<=20):
		print src,dest
def other(h1,h2):
	temp=[1,2,3]
	temp.remove(h1)
	temp.remove(h2)
	return temp[0]
def hanoi(src,dest,length): #5 4 3 2 1
	if length==1:
		move(src,dest)
		return
	hanoi(src,other(src,dest),length-1)
	hanoi(src,dest,1)
	hanoi(other(src,dest),dest,length-1)

for i in range(count):
	a.put(count-i)

print pow(2,count)-1
hanoi(1,3,a.qsize())

#for i in range(c.qsize()):
#	print c.get()
