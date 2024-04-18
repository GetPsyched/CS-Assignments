def main():
    """Question 4

    Use of eval(), int(), and float() in a single program.
    """
    x = 5
    y = 5.00

    print(f'{float(x)} {float(y)}')

    print(f'{int(x)} {int(y)}')

    print(f'{eval(str(x))} {eval(str(y))}')

if __name__ == '__main__':
    main()
