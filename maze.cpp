/**
 * Name: Avery Chan
 * Project: PrgAsst2
 * File: maze.cpp
 * Content: Implements all the functions of the maze class
 */

#include <stdexcept>

/* STL libraries needed */
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

/* library for reverse function */
#include <algorithm>
/* there is a function called "reverse" in this library that can reverse the elements of a vector
 * call it as follows:
 * reverse(v.begin(), v.end()); // this reverses the order of the elements in vector v
 */

#include "maze.h"

using namespace std;

Maze::Maze(int w, int h) {
    /// sets the data members to the parameters of the DEFAULT CTOR
    width = w;
    height = h;
    /// creates a new double pointer position object by creating a dynamic array
    positions = new Position** [width];

    /// goes through each element of the array to add a new array, creating
    /// the dynamic 2D array
    for (int i = 0; i < width; i++) {
        positions[i] = new Position* [height];
    }

    /// puts each position object into each element of the dynamic 2D array
    /// double for-loop allows us to access each member of the 2D array
    for (int j = 0; j < width; j ++) {
        for (int k = 0; k < height; k++) {
            positions[j][k] = new Position(j,k);
        }
    }
}

Maze::~Maze() {
    /// double for-loop that allows us to go through each element of the 2D array
    /// and delete the position object from that element
    for (int i = 0; i < width; i++) {
        for (int j =0; j < height; j++) {
            delete positions[i][j];
        }
    }

    /// for-loop that goes through each element in the array to delete that position object
    for (int k = 0; k < width; k++) {
        delete [] positions[k];
    }
    /// deletes the last remaining position pointer
    delete [] positions;
}

int Maze::getWidth() {
    return width;
}

int Maze::getHeight() {
    return height;
}

bool Maze::isWall(int x, int y) {
    return positions[x][y]->isWall();
}

void Maze::setWall(int x, int y) {
    positions[x][y]->setWall();
}

vector<Position*> Maze::solveBreadthFirst() {
    /* you will need an unordered_map to store the previous of each position */
    /* the keys for this map are the to_string of a position object
     * the associated value should be a pointer to the Position from which
     * you saw the key
     */
    /**
     * creates two vectors, one that contains a path and answer of the maze (path),
     * while the other is an empty vector that would be returned if no answer is found (emptyNoPathVect)
     * visited queue that holds all the current position pointers of the positions that have been
     * visited by traversing the 2D array/maze.
     * visitedMap is an unordered map that holds onto the previous of the coordinates based off the key
     * coordinate
     * neighborVect is a vector that holds all the valid neighbors of current
     */
    vector<Position*> path;
    vector<Position*> emptyNoPathVect;
    queue<Position*> visited;
    unordered_map<string, Position*> visitedMap;
    vector<Position*> neighborVect;

    Position *start = positions[0][0];  // start of the maze
    Position *destination = positions[width-1][height-1]; // end point of the maze

    visited.push(start);
    visitedMap[start->to_string()] = nullptr;

    // while loop goes through until the queue visited is empty, updates current
    // and adds and pops it off of the queue
    while (!visited.empty()) {
        Position *current = visited.front();
        visited.pop();
        // checking to see if the current is the end point of the maze
        if (current == destination) {
            // if so it will go back traverse backward using the unordered map to
            // create the path of maze answer
            while (current != nullptr){
                path.push_back(current);
                current = visitedMap[current->to_string()];
            }
            // reverses it because destination would be at the front of the vector
            // and the start would be at the end
            // gives a vector from start to finish answer
            reverse(path.begin(), path.end());
            return path;
        }

        // if it does not reach the end point of the maze
        else {
            neighborVect = getNeighbors(current);
            // iterates through the neighbor vector and sees if the neighbors have been visited
            for (int i =0; i < neighborVect.size(); i++) {
                // checks to see if the neighbor is found in the unordered map of visited previously
                // if not in the unordered map, then it adds it to the unordered map and pushes
                // neighbor onto queue
                if (visitedMap.find(neighborVect[i]->to_string()) == visitedMap.end()) {
                   visitedMap[neighborVect[i]->to_string()] = current;
                   visited.push(neighborVect[i]);
                } // if
            } // for statement
        } // else
    } // endwhile

    return emptyNoPathVect;
}

vector<Position*> Maze::solveDepthFirst() {
    /* you will need an unordered_map to store the previous of each position */
    /* the keys for this map are the to_string of a position object
     * the associated value should be a pointer to the Position from which
     * you saw the key
     */
    /**
     * creates two vectors, one that contains a path and answer of the maze (path),
     * while the other is an empty vector that would be returned if no answer is found (emptyNoPathVect)
     * visited stack that holds all the current position pointers of the positions that have been
     * visited by traversing the 2D array/maze.
     * visitedMap is an unordered map that holds onto the previous of the coordinates based off the key
     * coordinate
     * neighborVect is a vector that holds all the valid neighbors of current
     */
    vector<Position*> path;
    vector<Position*> emptyNoPathVect;
    stack<Position*> visited;
    unordered_map<string, Position*> visitedMap;
    vector<Position*> neighborVect;

    Position *start = positions[0][0];  // start point of the maze
    Position *destination = positions[width-1][height-1];  // end point of the maze

    visited.push(start);
    visitedMap[start->to_string()] = nullptr;

    // while loop goes through until the stack visited is empty, updates current
    // and adds and pops it off of the stack
    while (!visited.empty()) {
        Position *current = visited.top();
        visited.pop();
        // checking to see if the current is the end point of the maze
        if (current == destination) {
            // if so it will go back traverse backward using the unordered map to
            // create the path of maze answer
            while (current != nullptr){
                path.push_back(current);
                current = visitedMap[current->to_string()];
            }
            // reverses it because destination would be at the front of the vector
            // and the start would be at the end
            // gives a vector from start to finish answer
            reverse(path.begin(), path.end());
            return path;
        } // if

        // if it does not reach the end point of the maze
        else {
            neighborVect = getNeighbors(current);
            // iterates through the neighbor vector and sees if it the neighbors have been visited
            for (int i =0; i < neighborVect.size(); i++) {
                // checks to see if the neighbor is found in the unordered map of visited previously
                // if not in the unordered map, then it adds it to the unordered map and pushes
                // neighbor onto queue
                if (visitedMap.find(neighborVect[i]->to_string()) == visitedMap.end()) {
                    visitedMap[neighborVect[i]->to_string()] = current;
                    visited.push(neighborVect[i]);
                } // if
            } // for statement
        } // else
    } // endwhile

    return emptyNoPathVect;
}

vector<Position*> Maze::getNeighbors(Position* position) {
    int xPosition = position->getX();  // creating object to hold x coordinate of position
    int yPosition = position->getY();  // creating object to hold y coordinate of position

    vector<Position*> neighborVect;    // vector that holds all the neighbors of the position object
    Position *up, *left, *right, *down; // position object neighbors

    // checks to see if the up neighbor is a valid neighbor of current
    if (checkSpot(xPosition, yPosition - 1)) {
        up = positions[xPosition][yPosition - 1];
        neighborVect.push_back(up);
    }

    // checks to see if the left neighbor is a valid neighbor of current
    if (checkSpot(xPosition - 1, yPosition)) {
          left = positions[xPosition - 1][yPosition];
          neighborVect.push_back(left);
    }

    // checks to see if the right neighbor is a valid neighbor of current
    if (checkSpot(xPosition + 1, yPosition)) {
          right = positions[xPosition + 1][yPosition];
          neighborVect.push_back(right);
    }

    // checks to see if the down neighbor is a valid neighbor of current
    if (checkSpot(xPosition, yPosition + 1)) {
          down = positions[xPosition][yPosition + 1];
          neighborVect.push_back(down);
    }

    return neighborVect;
}

bool Maze ::checkSpot(int x, int y) {
    // checks to see if the neighbors are out of bounds of the 2D array or is a wall
    if (x < 0 || x >= width || y < 0 || y >= height || positions[x][y]->isWall()) {
        return false;
    }
    return true;
}
