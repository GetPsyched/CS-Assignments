def get_category(bmi: float) -> str:
    """Return the BMI category of the given BMI"""
    if 0 <= bmi < 18.5:
        return 'underweight'
    if 18.5 <= bmi < 25:
        return 'healthy'
    if 25 <= bmi < 30:
        return 'overweight'
    if 30 <= bmi:
        return 'obese'
    return 'invalid'

def main():
    """Question 4

    Write a Python program that prompts the user to enter a weight in pounds and height in inches and then display the BMI.
    """
    height = float(input('Enter the height in inches --> '))
    weight = float(input('Enter the weight in pounds --> '))

    # Calculating the BMI
    bmi = (weight * 0.45359237) / ((height * 0.0254) ** 2)

    print(f'The BMI is {bmi:.2f} and the category is {get_category(bmi)}')

if __name__ == '__main__':
    main()
