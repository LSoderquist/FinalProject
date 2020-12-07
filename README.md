# FinalProject

Project Summary:

My project is a data structure that represents airports and the different planes stationed at each one. The airports will be represented by vertices on a graph, and each graph will have a linked list attribute that contains a list of all planes currently at that airport. The edges between the vertices of the graph will represent the flights available between the airports and their distances. Additionally, each plane will have a certain amount of fuel that will decrease as it flies between airports. The program runs on user input, presenting the user with a menu they can then use to add to or manipulate the data set. The user can ask the program to calculate various values such as how many planes are at an airport, and the distance of a flight path. The program is also capable of showing the user the shortest path between two destinations based on the relative airport distances and which flights are available. 

How to Run:

The program is run by entering the following commands into the command line:

g++ -std=c++11 -o finalProject FinalProject.cpp Graph.cpp LL.cpp
./finalProject

Once the program is running the user will be presented with a menu with which the user can decide what they want to do with the data set. Additionallly, there are multiple airports, flights, and planes added by default in the driver file 'FinalProject.cpp'. If so desired, the user could alter these default additions to their liking.

Dependencies: None

System Requirements: Program will run on Mac, Windows, or Linux

Team Members: Luke Soderquist

Contributors: Luke Soderquist

Open Issues/Bugs: None



