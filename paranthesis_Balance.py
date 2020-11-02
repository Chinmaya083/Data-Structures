
class stack:
    def __init__(self):
         self.items = []
    def push(self, item):
        self.items.append(item)
    def pop(self):
        self.items.pop()
    def peek(self):
        if len(self.items) == 0:
            return -1
        else:
            return self.items[len(self.items) - 1]
    def isEmpty(self):
        return self.items == []
    def size(self):
        return len(self.items)



def isBalanced(str):
    s = stack()
    s.push(str[0])
    length = len(str)
    for i in range(1, length) :
        if s.peek() == "(" and str[i] == ")":
            s.pop()
        elif s.peek() == "[" and str[i] == "]":
            s.pop()
        elif s.peek() == "{" and str[i] == "}":
            s.pop()
        else :
            s.push(str[i])
    if s.isEmpty() == True:
        return "YES"
    else :
        return "NO"

s = "[]]]]]]]]]]()[]"

print(isBalanced(s))


