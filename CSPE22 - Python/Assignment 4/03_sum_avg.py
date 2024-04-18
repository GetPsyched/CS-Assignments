def main():
    """Question 3

    Write a Python program to find the sum and average of the list.
    """
    elements = list(map(int, input('Enter the elements --> ').split()))
    total = sum(elements)
    print(f'Sum = {total}')
    print(f'Average = {total / len(elements)}')

if __name__ == '__main__':
   main()
