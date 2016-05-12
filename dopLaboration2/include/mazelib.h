/*
 * File: mazelib.h
 * ---------------
 * This interface provides a library of primitive operations
 * to simplify the solution to the maze problem.  Note that we
 * have added two functions to the interface.  AdjacentPoint
 * is given in the text, and we have added it to mazelib to
 * make it readily available.  We have also added a function
 * SetPauseTime that will let you control the speed of the
 * search by causing a pause before each mark is drawn.
 */

#ifndef _mazelib_h
#define _mazelib_h

#include "genlib.h"

/*
 * Type: pointT
 * ------------
 * The type pointT is used to encapsulate a pair of integer
 * coordinates into a single value with x and y components.
 */

typedef struct {
    int x, y;
} pointT;

/*
 * Type: directionT
 * ----------------
 * This type is used to represent the four compass directions.
 */

typedef enum { North, East, South, West } directionT;

/*
 * Function: ReadMazeMap
 * Usage: ReadMazeMap(filename);
 * -----------------------------
 * This function reads in a map of the maze from the specified
 * file and stores it in private data structures maintained by
 * this module.  In the data file, the characters '+', '-', and
 * '|' represent corners, horizontal walls, and vertical walls,
 * respectively; spaces represent open passageway squares.  The
 * starting position is indicated by the character 'S'.  For
 * example, the following data file defines a simple maze:
 *
 *       +-+-+-+-+-+
 *       |     |
 *       + +-+ + +-+
 *       |S  |     |
 *       +-+-+-+-+-+
 *
 * Coordinates are numbered starting at (0,0) in the lower left.
 */

void ReadMazeMap(string filename);

/*
 * Function: GetStartPosition
 * Usage: pt = GetStartPosition();
 * -------------------------------
 * This function returns a pointT indicating the coordinates of
 * the start square.
 */

pointT GetStartPosition(void);

/*
 * Function: OutsideMaze
 * Usage: if (OutsideMaze(pt)) . . .
 * ---------------------------------
 * This function returns TRUE if the specified point is outside
 * the boundary of the maze.
 */

bool OutsideMaze(pointT pt);

/*
 * Function: WallExists
 * Usage: if (WallExists(pt, dir)) . . .
 * -------------------------------------
 * This function returns TRUE if there is a wall in the indicated
 * direction from the square at position pt.
 */

bool WallExists(pointT pt, directionT dir);

/*
 * Functions: MarkSquare, UnmarkSquare, IsMarked
 * Usage: MarkSquare(pt);
 *        UnmarkSquare(pt);
 *        if (IsMarked(pt)) . . .
 * ------------------------------
 * These functions mark, unmark, and test the status of the
 * square specified by the coordinates pt.
 */

void MarkSquare(pointT pt);
void UnmarkSquare(pointT pt);
bool IsMarked(pointT pt);

/*
 * Function: AdjacentPoint
 * Usage: newpt = AdjacentPoint(pt, dir);
 * --------------------------------------
 * This function returns the pointT that results from moving
 * one square from pt in the direction specified by dir.  For
 * example, if pt is the point (1,1), AdjacentPoint(pt, East)
 * would return the point (2,1).
 */

pointT AdjacentPoint(pointT pt, directionT dir);

/*
 * Function: SetPauseTime
 * Usage: SetPauseTime(0.1);
 * -------------------------
 * This functions sets the amount of  time that the library pauses
 * each time it draws a mark in a square.
 */

void SetPauseTime(double seconds);

#endif
