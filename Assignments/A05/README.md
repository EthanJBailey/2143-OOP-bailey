## Ethan Bailey
### Designing a D&D Game
### Description:

This assignmet covers the creation of a Unified Modeling Language(UML) diagram for a Dungeons and Dragons game.
The first step of the process was identifying all the main components of the game which became classes that would be refined.
Then, based on the usage, a set of attributes and methods were created for each classes.
Finally, the commonailities between classes were noted and classes with repeating elements were split up into its own class
and relationships were formed.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | D&D Game UML | Final version of the UML diagram created.   |
|   2   | images       | The folder where all diagrams are stored.   |

## Initial Classes
- Character
- Inventory
- Item
- Weapon
- Spell
- Equipment
- Player
- Monster
- Encounter
- Map

## Initial diagram:
<img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/A05/images/Initial%20UML%20Diagram.jpg" width="1000">

## Breakdown / Thought-Process
After building out classes and drawing up some diagrams, the relationships, usage and gameplay was the next steps.
First off the Character class was created since Players and Monsters were pretty much identical. This can now be worded as
a Player "is a" Character and a Monster is a "Character". Inheritance is appropriate here because each subclass shares many of the same properties and methods as the superclass, but also has its own unique behaviors from them as seen below:

<img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/A05/images/Character-Player-Monsters.png" width="350">

Each Character in the D&D world needs something to survive combat and life. Thus, every character needs items such as weapons,
spells, armor and other equipment. Since these are all items or a weapon "is a" item then Inheritance can be appropriate again to 
prevent the reuse of code since they are all similar.
An Inventory "has a" items or is comprised of a list of 0 to multiple items. Next, each Charachter "has a" or has an Inventory.
Thus, Composition is appropriate where each item can be added to a list in the inventory of each charachter.
These can all be seen in the diagrams:

<img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/A05/images/Items.png" width="350"> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/A05/images/Character-Inventory%20.png" width="550">



