# Author: WillisChu
# Date:   2017/05/06
import sys

# Redirect STDIN to file
__console__ = sys.stdin
sys.stdin = open('testcase00.in', 'r')
# Coding Start

while True:
    ss = sys.stdin.readline()
    if ss:
      # Body Here
        print ss.strip()
    else:
        break

# Coding End
sys.stdin = __console__


