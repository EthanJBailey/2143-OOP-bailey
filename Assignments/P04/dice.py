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
import sys
import random

"""
"Class: Die
"
" Description:
"      This class creates a die that can be rolled to find the random values
" 
" Methods:
"      - def __init__(self, sides)   # Function to set the constructor parameters
"      - def roll(self)              # Function that rolls the die
"      - def __str__(self)           # Function to format the printed result for object
"
" Usage:
"      - Can be used to create and roll a die to play board games or 
"        various scenarios
"""
class Die(object):
  # Function that serves as the Overloaded Constructor with parameters
  def __init__(self, sides=6):
    if not isinstance(sides, int):
      print("Error: sides is not an integer!")
      sys.exit()
    self.sides = sides
    
  # Function to set the roll the die created
  def roll(self):
    values = [x for x in range(self.sides)]
    random.shuffle(values)
    return values[0] + 1
    
  # Function to format the printed result for object
  def __str__(self):
    return f"[{self.sides}]"
    
"""
"Class: Dice
"
" Description:
"      This class createsa die that can be rolled to find the random values
" 
" Methods:
"      - def __init__(self, sides, num_dice, strng) # Sets constructor parameters
"      - def roll(self)      # Function that rolls the dice based on the type
"      - def sum(self)       # Function to compute the summation of the dice rolled
"      - def min(self)       # Function to compute the minimum valued dice rolled
"      - def max(self)       # Function to compute the maximum valued dice rolled
"      - def avg(self)       # Function to compute the average of all the dice rolled
"      - def __str__(self)   # Function to format the printed result for object
"
" Usage:
"      - Can be used to create and roll many dice to play board games or 
"        various scenarios and compute overall states of the dice rolled
"""
class Dice:
  def __init__(self, sides=6, num_dice=1, strng=""):
    # Error checking, if no sides are entered
    if not isinstance(sides, int):
        print("Error: sides is not an integer!")
        sys.exit()

    # Error checking, if no sides are entered
    if not isinstance(num_dice, int):
        print("Error: value for the number of dice is not an integer!")
        sys.exit()
      
    # Creates a empty list
    self.dice = []

    # Adds dice in to the list
    for die in range(num_dice):
      self.dice.append(Die(sides))

    if strng:
     # Splits string into pieces
      res = strng.split('.')      
      
      # Takes the 1st and third values of the list
      n = int(res[0])
      s = int(res[2])

      # Empties the list
      self.dice = []

      # Adds the dice to the list
      for die in range(n):
        self.dice.append(Die(s))
        
  # Function that rolls the dice based on the type 
  def roll(self,rollType=None):      
    if rollType =='max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else: 
      return self.sum()
  # Function to compute the summation of the dice rolled
  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()
    return total
  # Function to compute the minimum valued dice rolled
  def min(self):
    dmax = min(d.roll() for d in self.dice)
    return dmax
 # Function to compute the maximum valued dice rolled
  def max(self):
    dmax = max(d.roll() for d in self.dice)
    return dmax
  # Function to compute the average of all the dice rolled
  def avg(self):
    avg = (sum(d.roll() for d in self.dice)/len(self.dice))
    return avg
  # Function to format the printed result for object
  def __str__(self):
    s = "[\n"
    for d in self.dice:
      s = s + f"   [{d.sides}]\n"
    s = s+"]\n"
    return s

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
  d3 = Dice(10,5)
  print('Five, 10-sided dice:')
  print(d3)

  # Creates a die using game syntax (4, 12-sided dice)
  d4 = Dice(strng="4.d.12")
  print('A die using game syntax (4.d.12):')
  print(d4)

  # Computes the sum of all the dice
  print(f"Sum of all dies: {d4.roll()}")
  
  # Computes the min roll of all the dice
  print(f"Minimum roll: {d4.roll('min')}")
  
  # Computes the max roll of all the dice
  print(f"Maximum roll: {d4.roll('max')}")

  # Computes the max roll of all the dice
  print(f"Average: {d4.roll('avg')}")
  