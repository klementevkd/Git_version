from inspect import stack
import operator 

OPERATORS = {'+' : operator.add, '-' : operator.sub, '*' : operator.mul, '/' : operator.truediv}

def polska(srt):
    stack = []
    lst = list(srt)
    for i in srt:
        if i.isdigit():
            stack.append(i)
            lst.remove(i)
        else:
            cnt1, cnt2 = stack.pop(), stack.pop()
            stack.append(OPERATORS[i](int(cnt2), int(cnt1)))
            lst.remove(i)
    return stack.pop()

srt = input('Введите формулу ').split()
polska(srt)
