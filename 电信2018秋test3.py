import sys 
for line in sys.stdin:

    a = int(line)


    jiecheng = 1
    for i in range(1, a+1):
        
        jiecheng = i * jiecheng

    temp = str(jiecheng)
    result = 0 
    for idx in range(0, len(temp)):
        t = int(temp[idx])
        result += t
    print(result)