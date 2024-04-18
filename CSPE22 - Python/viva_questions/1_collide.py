import math
from dataclasses import dataclass

@dataclass
class Ball:
    x: int
    y: int
    radius: int

def will_collide(ball1: Ball, ball2: Ball) -> bool:
    """Return a boolean stating if the 2 balls are colliding or not"""
    # Calculating the distance between the centers
    # Formula used: distance = square_root[(x1 - x2)² + (y1 - y2)²]
    distance = math.sqrt((ball1.x - ball2.x) ** 2 + (ball1.y - ball2.y) ** 2)

    # Calculating the sum of the radii
    radii_sum = ball1.radius + ball2.radius

    # Return a boolean of the comparison between the 2 variables
    return distance <= radii_sum

def main():
    """Question 1

    WAF wall_collide(ball1, ball2) -> bool that computes if they are colliding or not.
    A ball is represented by x, y, r (here, r is the radius of the ball and x, y are the co-ordinates of the ball)
    If the distance between the balls' center is >= the sum of their radii, then they are colliding.
    """
    # Inputting the details of the balls and creating an object of Ball type
    ball1 = Ball(
        int(input('Enter the x co-ordinate of ball 1 --> ')),
        int(input('Enter the y co-ordinate of ball 1 --> ')),
        int(input('Enter the radius of ball 1 --> ')),
    )

    # Print a newline for distinction between the 2 inputs
    print()

    ball2 = Ball(
        int(input('Enter the x co-ordinate of ball 1 --> ')),
        int(input('Enter the y co-ordinate of ball 1 --> ')),
        int(input('Enter the radius of ball 1 --> ')),
    )

    # Check if the balls are colliding
    if will_collide(ball1, ball2):
        print('The balls are colliding!')
    else:
        print('The balls are NOT colliding!')

# Run the main function if this file is directly executed (i.e., not imported)
if __name__ == '__main__':
    main()
