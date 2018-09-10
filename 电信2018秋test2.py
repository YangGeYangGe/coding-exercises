l = []
for a in range(0,10):
	for b in range(0,10):
		for c in range(0,10):
			for d in range(0,10):
				abcd = a*1000+b*100+c*10+d
				bcda = b*1000+c*100+d*10+a
				if abcd+bcda == 8888:
					l.append(abcd)

for i in l:
    a = -1 
    b = -1 
    c = -1 
    d = -1

    x = str(i)

    
    if len(x) == 4:
        a = x[0]
        b = x[1]
    
        c = x[2]
        d = x[-1]
    if len(x) == 3:
        a = 0
        b = x[0]
    
        c = x[1]
        d = x[-1]
        
    if len(x) == 2:
        a = 0
        b = 0
    
        c = x[0]
        d = x[-1]
    if len(x) == 1:
        a = 0
        b = 0
    
        c = 0
        d = x[-1]
    print(a,b,c,d)