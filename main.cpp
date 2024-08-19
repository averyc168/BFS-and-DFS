/**
 * Name: Avery Chan
 * Project: PrgAsst2
 * File: main.cpp
 * Content: main function that allows users to upload a maze and the program will
 *          find the answer to the maze
 */

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main() {
    // Initial code to read input from cin.
    // You shouldn't need to modify this portion of code
    cout << "Welcome to The A-Maze-ing Race." << endl;
    string map; // name of the map file
    cout << "where is your maze file? ";
    cin >> map;

    string search;  // option to choose what kind of search
    cout << "Which search algorithm to use (BFS or DFS)? ";
    cin >> search;

    Maze *maze = loadMap(map); // maze object from loading the map
    vector<Position*> PathAnswer;   // vector that holds the answer

    // if breadth-first search
    if (search == "BFS") {
        PathAnswer = maze->solveBreadthFirst();
    }
    // if depth-first search
    else if (search == "DFS"){
        PathAnswer = maze->solveDepthFirst();
    }
    // if neither then error
    else {
        cerr << "NOT A VALID OPTION";
    }

    string outputFileName;  // name of the output file
    cout << "What is the name of the output file?";
    cin >> outputFileName;
    cin.get();

    ofstream outFP;   // ostream object that writes it to new file
    outFP.open(outputFileName);
    outFP << renderAnswer(maze, PathAnswer);
    outFP.close();

    return 0;
}
