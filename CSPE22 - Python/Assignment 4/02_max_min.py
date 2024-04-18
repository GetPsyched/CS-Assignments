def main():
    """Question 2

    Write a Python program to find smallest and largest number in a list.
    """
    elements = list(map(int, input('Enter the elements --> ').split()))
    print(f'Smallest = {min(elements)}')
    print(f'Largest = {max(elements)}')

if __name__ == '__main__':
   main()
