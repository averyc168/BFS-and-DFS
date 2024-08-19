# BFS and DFS Search

### Purpose:
The user enters a text file of a map first with two numbers on top (number of columns and number of rows) and the map
terrain coded as '.' (open space) and a '#' (closed space, wall). The map is created using a dynamically  
allocated 2D array. Each element within the 2D array is a position or coordinate and that is also dynamically allocated.
The user then chooses what type of search, breadth first search (BFS) or depth first search (DFS), they want the rover 
to conduct. The BFS algorithm uses a _queue data structure_ to keep track of the positions to find the next available
space for its path while the DFS algorithm uses a _stack data structure_. The program uses the queue and stack library
available in the STL library. 

The rover's path is held in a _vector data structure_ and the spaces around where the rover is currently are held in an 
_unordered map data structure_ (both from the STL library). Once completed, a new text file is created with the rover's 
path through the map. The user has the option to edit the map by adding walls at certain positions.

### Input:
On the console the user first types in a valid text file, and then chooses which search algorithm they would like the 
rover to conduct.

### Output:
A text file with the rover's path.

### Note:
All the test files can be found in the _cmake-build-debug_ directory.
