import sys 
for line in sys.stdin:

    a = line
    minus = False
    if a[0] == "-":
    	minus = True

    result = ""
    if minus == False:

    	for i in range(len(a)-2, -1, -1):

    		if len(result) == 0 and a[i] == '0':
    			continue

    		result += a[i]
    	print(result)

    else:
    	result += "-"
    	# a = ...\0
    	for i in range(len(a)-2, 0, -1):
    		if len(result) == 1 and a[i] == '0':
    			continue
    		result += a[i]

    	print(result.strip())