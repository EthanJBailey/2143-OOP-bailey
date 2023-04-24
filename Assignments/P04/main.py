"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"  Email:            businessjoebailey@gmail.com
"  Label:            P04
"  Title:            Roll them Bones!
"  Course:           CMPS 2143
"  Semester:         Spring 2023
"
"  Description:
"    This program implements a Die and Dice classes in Python, using an outlined 
"    c++ code as a template. The Die class can be used to create a die that can 
"    be rolled to find the random values. The Dice class can be to create dice by
"    entering the no and type of die using a normal or a preformatted game format
"
"  Usage:
"        - This program can be used to generate different sizes of die and dices 
"        - that can be rolled in games or different scenarios
"        - Run the main.cpp or envoke the dice.py file directly using the shell
"
"  Files:
"        dice.py  :  driver program
"        main.py  :  tester file
"
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
from dice import Die   # imports the Die class from the dice.py file
from dice import Dice  # imports the Dice class from the dice.py file

# Tests to see if the implementations works after only importing the classes
if __name__=='__main__':
  # Prints heading of program
  print('Ethan Bailey')
  print('Program 4 - Roll them Bones!')
  print()
  
  # Creates a standard 6-sided die
  d1 = Die()
  
  # Creates a 10-sided die
  d2 = Die(10)

  # Prints out the standard die
  print('A standard 6-sided die: ',end="")
  print(d1)

  print('A standard 10-sided die: ',end="")
  print(d2)
  
  # Prints the value of a rolled dice
  print('The value of a rolled 10-sided die: ',end="")
  print(d2.roll())

  # Creates 5, 10-sided dice
  d3 = Dice(6,3)
  print('Three, 6-sided dice:')
  print(d3)

  # Creates a die using game syntax (4, 12-sided dice)
  d4 = Dice(strng="5.d.9")
  print('A die using game syntax (5.d.9):')
  print(d4)

  # Computes the sum of all the dice
  print(f"Sum of all dies: {d4.roll()}")
  
  # Computes the min roll of all the dice
  print(f"Minimum roll: {d4.roll('min')}")
  
  # Computes the max roll of all the dice
  print(f"Maximum roll: {d4.roll('max')}")

  # Computes the max roll of all the dice
  print(f"Average: {d4.roll('avg')}")