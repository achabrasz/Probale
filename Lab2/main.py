import matplotlib.pyplot as plt
import statistics
from typing import Tuple, List

class LinearGenerator:
    def __init__(self, a, c, M, seed):
        self.a = a
        self.c = c
        self.M = M
        self.x = seed

    def generate(self):
        self.x = (self.a * self.x + self.c) % self.M
        return self.x / self.M

    def generate_set(self, n):
        return [self.generate() for _ in range(n)]  # Don't index the result of generate()

class ShiftRegisterGenerator:
    def __init__(self, p, q):
        self.p = p
        self.q = q
        self.rand_set = LinearGenerator(69069, 1, 2**32, 2137).generate_set(max(p,q)+1)
    def generate_set(self, n):
        rand_bits = [True if el > 0.5 else False for el in self.rand_set]
        out_bits = []
        for _ in range(n):
            p_bit = rand_bits[self.p]
            q_bit = rand_bits[self.q]
            out_bits.append(rand_bits.pop())
            rand_bits.insert(0, p_bit^q_bit)
        return out_bits

if __name__ == '__main__':
    lfsr_gen = ShiftRegisterGenerator(29,2)
    lcg_gen = LinearGenerator(16807, 0 ,(2**31) - 1, 2137)
    set_of_nums = lcg_gen.generate_set(10000)
    set_of_bits = lfsr_gen.generate_set(10000)
    print(statistics.mean(set_of_nums), statistics.variance(set_of_nums))
    plt.plot(set_of_nums, linewidth=0.1)
    plt.show()
    plt.hist(set_of_nums)
    plt.show()
    print(set_of_bits.count(True)/len(set_of_bits))
