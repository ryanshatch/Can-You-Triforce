#################################################################################
##                                Can You Even Triforce?                       ##
##                         Date of development: July 8th, 2023                 ##
##                          Last modified: July 9th, 2023                      ##
##                               Designed by: Ryan Hatch                       ##
#################################################################################

################################################################################# 
##               This code uses recursion to draw a Triforce shape.            ##
##                                                                             ##
## It starts by drawing the largest equilateral triangle, then recursively     ##
## calls itself to draw smaller Triforce shapes within each larger triangle.   ##
##                                                                             ##
##               The length parameter controls the size of the Triforce shape. ##
## The code positions the turtle at (-300, -300) to ensure the entire shape is ##
##                             visible on the screen.                          ##
#################################################################################

import turtle

def draw_triangle(t, length):
    # Draw an equilateral triangle
    for _ in range(3):
        t.forward(length)
        t.left(120)

def draw_triforce(t, length):
    
    # Base case for recursion
    if length < 10:  
        return
    
    # Draw the current triangle
    draw_triangle(t, length)
    
    # Recursive calls to draw the smaller Triforce shapes
    draw_triforce(t, length/2)
    
    t.forward(length/2)
    draw_triforce(t, length/2)
    t.backward(length/2)
    
    t.left(60)
    t.forward(length/2)
    t.right(60)
    draw_triforce(t, length/2)
    t.left(60)
    t.backward(length/2)
    t.right(60)

# Create a turtle object
t = turtle.Turtle()
t.speed("fast")

# Position the turtle to start drawing the Triforce
t.penup()
t.goto(-300, -300)
t.pendown()

# Draw the Triforce shape
draw_triforce(t, 600)

# Hide the turtle
t.hideturtle()

# Keep the screen open until closed manually
turtle.done()