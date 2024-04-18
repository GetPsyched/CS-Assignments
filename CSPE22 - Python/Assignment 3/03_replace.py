import re

def main():
    """Question 3

    Write a letter of at least 10 lines and use various methods defined in string class.
    """
    sample_letter = '''Dear <|NAME|>,
    This is with reference to your job requirement on <|portal_name|> for the role of Sales Manager. I truly believe that my qualifications and experience make me a perfect candidate for the job.

    I completed my MBA in Sales and Marketing from <|Institute_Name|>.
    I have worked as an Area Sales Manager and Assistant Marketing Manager at <|Company_Name|>. During my stint as Area Sales Manager, I conceptualized and executed a Customer Engagement Program that resulted in higher sales. As Assistant Marketing Manager, I worked on the planning and execution of a new product launch. With 4 years of experience in B2B sales and marketing, I have an in-depth understanding of the process. I am confident that I will be the right fit for the job.

    I have attached my CV to the email for your reference. Please have a look at it.

    I hope to meet you and discuss this opportunity further. Thank you for considering my application for the role.

    Best regards,
    <|Your_Name|>
    Mob: <|Your _Contact _Number|>
    Email Id: <|Your_ Email _Address|>

    Date: <|DATE|>
    '''
    items = re.findall(r'<\|.+\|>', sample_letter)
    for item in items:
        temp = ' '.join(item[2:-2].replace(' ', '').lower().split('_'))
        sample_letter = sample_letter.replace(
            item,
            input(f'Enter {temp} --> '),
            1
        )
    print(sample_letter)

if __name__ == '__main__':
    main()
