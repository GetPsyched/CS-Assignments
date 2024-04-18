from timeit import timeit

import matplotlib.pyplot as plt

def main():
    x, y = [], []
    for i in range(200):
        x.append(i)
        y.append(timeit(setup='from stack import run_stack', stmt=f'run_stack({i})', number=100))
    
    plt.plot(x, y)
    plt.xlabel('n ➜')
    plt.ylabel('time (seconds) ➜')
    plt.title('Stack Time Complexity Graph')
    plt.show()

if __name__ == '__main__':
    main()
