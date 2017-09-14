# Author: chutengwei
# Date : 2017/09/13
# Description: Generate Fft output order.

import sys

def bit_revers(num, width):
    return int('{:0{width}b}'.format(num, width=width)[::-1], 2)

for num_in in range(5):
    infile = open(str(128<<num_in)+"FFTOutOrder.txt", "w")
    list = [bit_revers(x, num_in+7) for x in range(128<<num_in)]
    for dig in list:
        bin_num = "{:0{width}b}".format(dig, width=num_in+7)
        infile.write("%s %s \n" % (bin_num, str(dig)))
