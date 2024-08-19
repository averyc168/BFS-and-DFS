/**
 * Name: Avery Chan
 * Project: PrgAsst2
 * File: position.cpp
 * Content: Implements all the methods of the position class declared in position.h
 */

#include "position.h"
#include <stdexcept>
#include <string>

using namespace std;

/**
 * DEFAULT CTOR
 * Default CTOR for the Position class, initializing xPos, yPos, and wall
 * @param x - x coordinate of the Position in the 2D array
 * @param y - y coordinate of teh Position in the 2D array
 * @return N/A, but it should set up a position object in each element in the 2D array
 *         all the elements have no walls
 */
Position::Position(int x, int y) {
    xPos = x;
    yPos = y;
    wall = false;
}

/**
 * getX() method
 * returns the xPosition coordinate from the 2D array
 * @param N/A, but there must be a position object in the 2D array
 * @return the xPos value
 */
int Position::getX()  {
    return xPos;
}

/**
 * getY() method
 * returns the yPosition coordinate from the 2D array
 * @param N/A, but there must be a position object in the 2D array
 * @return the yPos value
 */
int Position::getY() {
    return yPos;
}

/**
 * setWall() method
 * creates a wall in the Position object in the 2D array
 * @param N/A, but there must be a position object in the 2D array
 * @return N/A, but the Position object in the element of the 2D array has a wall
 */
void Position::setWall()  {
    wall = true;
}

/**
 * isWall() method
 * checks to see if the Position object in the 2D array has a wall
 * @param N/A, but there must be a position object in the 2D array
 * @return a bool value saying true if there is a wall and false if there isn't
 */
bool Position::isWall()  {
    return wall;
}

/**
 * to_string() method
 * creates a key for the unordered map using the coordinates of the 2D array
 * @param N/A, but there must be a position object in the 2D array
 * @return s, a string that is the coordinate key to the unordered map
 */
string Position::to_string()  {
    string s;
    s = std::to_string(xPos) + ',' + std::to_string(yPos);
    return s;
}
