import random

data_list = random.sample(range(100), 10)

def qsort(data):
    if len(data) <= 1:
        return data
    
    left, right = list(), list()
    pivot = data[0]

    for index in range(1, len(data)):
        if pivot > data[index]:
            left.append(data[index])
        else:
            right.append(data[index])
    
    return qsort(left) + [pivot] + qsort(right)

print(qsort(data_list))

def qsort2(data):
    if len(data) <= 1:
        return data
    
    pivot = data[0]

    # list comprehension
    left = [ item for item in data[1:] if pivot > item ]            
    right = [ item for item in data[1:] if pivot <= item ]
    
    return qsort(left) + [pivot] + qsort(right)

print(qsort2(data_list))