# paste the output of the solutions intro string variable and then run python src/checker.py from the root directory
import os
from pathlib import Path

cwd = os.getcwd()
folder = 'test'
directory = os.path.join(cwd, folder)

for filename in os.listdir(directory):
    f = os.path.join(directory, filename)
    if os.path.isfile(f):
        print(f)
        string = Path(f).read_text()
# string = """((10 + (5 * 5)) - 11)
# (10 + ((5 * 5) - 11))
# (((5 * 5) - 11) + 10)
# ((10 - 11) + (5 * 5))
# (10 - (11 - (5 * 5)))
# ((5 * 5) - (11 - 10))
# (((5 * 5) + 10) - 11)
# ((5 * 5) + (10 - 11))"""
        arr = string.split("\n")
        del arr[-1]
        cnt = 0
        err = []
        for line in arr:
            n = eval(line) == 24
            # print(n)
            if not n:
                cnt += 1
                err.append(line)
        

        set_arr = set(arr)
        print("length of unique strings:", len(set_arr))
        print("length of array of solutions:", len(arr))
        print("number of errors", cnt)

        for i in err:
            print(i)
