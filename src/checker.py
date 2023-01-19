string = """(8 - ((3 - 7) * 4))
(8 + ((7 - 3) * 4))
(((7 - 3) * 4) + 8)
((4 * (7 - 3)) + 8)
(8 + (4 * (7 - 3)))
(8 - (4 * (3 - 7)))"""
arr = string.split("\n")
cnt = 0
err = []
for line in arr:
    n = eval(line) == 24
    print(n)
    if not n:
        cnt += 1
        err.append(line)
        

set_arr = set(arr)
print(len(set_arr), len(arr))
print(cnt)
print(err)
