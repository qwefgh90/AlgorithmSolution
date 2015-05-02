

/*
https://code.google.com/codejam/contest/4224486/dashboard#s=p1

Problem B. Haircut
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
11 points
Solve B-small
Large input
22 points
Solve B-large
Problem

You are waiting in a long line to get a haircut at a trendy barber shop. The shop has B barbers on duty, and they are numbered 1 through B. It always takes the kth barber exactly Mk minutes to cut a customer's hair, and a barber can only cut one customer's hair at a time. Once a barber finishes cutting hair, he is immediately free to help another customer.

While the shop is open, the customer at the head of the queue always goes to the lowest-numbered barber who is available. When no barber is available, that customer waits until at least one becomes available.

You are the Nth person in line, and the shop has just opened. Which barber will cut your hair?

Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of two lines. The first contains two space-separated integers B and N -- the number of barbers and your place in line. The customer at the head of the line is number 1, the next one is number 2, and so on. The second line contains M1, M2, ..., MB.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the number of the barber who will cut your hair.

Limits

1 �� T �� 100.
1 �� N �� 109.
Small dataset

1 �� B �� 5.
1 �� Mk �� 25.
Large dataset

1 �� B �� 1000.
1 �� Mk �� 100000.
Sample


Input

Output

3
2 4
10 5
3 12
7 7 7
3 8
4 2 1

Case #1: 1
Case #2: 3
Case #3: 1

In Case #1, you are the fourth person in line, and barbers 1 and 2 take 10 and 5 minutes, respectively, to cut hair. When the shop opens, the first customer immediately has the choice of barbers 1 and 2, and she will choose the lowest-numbered barber, 1. The second customer will immediately be served by barber 2. The third customer will wait since there are no more free barbers. After 5 minutes, barber 2 will finish cutting the second customer's hair, and will serve the third customer. After 10 minutes, both barbers 1 and 2 will finish; you are next in line, and you will have the choice of barbers 1 and 2, and will choose 1.
*/