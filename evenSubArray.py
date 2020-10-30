def Reverse(lst): 
    return [ele for ele in reversed(lst)] 

def listToString(s):  
        
    # initialize an empty string 
    str1 = ""     
    for ele in s:  
        str1 += ele   
    return str1  


class stack:
    def __init__(self):
        self.items = []
    def isEmpty(self):
        return self.items == []
    def push(self, item):
        self.items.append(item)
    def pop_stack(self):
        self.items.pop()    
    def peek(self):
        if len(self.items) == 0:
            return -1
        else :
            return self.items[len(self.items) - 1]
    def size(self):
        return len(self.items)

import fileinput 
a = []
print_list = []
a = ['2','10001','000111']
#a.pop()
#print(a)
s = stack()
for i in range(1, len(a)):
    #print(a[i])
    #print(a[i][1])
    s.push(a[i][0]) #Pushing first element of i'th bitstring
    #print(s.peek())
    #print(len(a[i]))
    for j in range(1, len(a[i])):
        if a[i][j] == s.peek():
            s.pop_stack()
        else :
            s.push(a[i][j])
    if s.isEmpty() == True:
        print("Empty")
        #print("\n")
    else :
        while s.isEmpty() == False:
            print_list.append(s.peek())
            s.pop_stack()
        l = Reverse(print_list)
        print(listToString(l))
        print_list.clear()