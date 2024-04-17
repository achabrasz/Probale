import random

def random_on_interval(a, b):
    return a+(b-a)*random.random()

def adjust_probability(probability):
    for i in range(1, len(probability)):
        probability[i] += probability[i-1]
    return probability

def biased_random_on_interval(interval, probability):
    r = random.random()
    probability = adjust_probability(probability)
    for i in range(len(probability)):
        if r < probability[i]:
            return interval[i]

def main():
    a = 50
    b = 150
    interval = [1, 2, 3, 4]
    probability = [0.3, 0.2, 0.4, 0.1]
    print(random_on_interval(a, b))
    print(biased_random_on_interval(interval, probability))

if __name__ == "__main__":
    main()