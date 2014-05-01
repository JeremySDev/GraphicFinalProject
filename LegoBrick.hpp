/**
 * LegoBrick.hpp - This header defines the LegoBrick class and its methods
 *
 * Author: Wes Johnson
 * Author: Jeremy Stilwell
 * Date:   4/21/14
 *
 * 
 */
#ifndef LEGOBRICK_H
#define LEGOBRICK_H

#include<GL/glut.h>

#define HEIGHT 2
#define STUD_WIDTH 1

//an enumeration for the size of the bricks.
enum BrickType {
    x11 = 1, x21 = 2, x22 = 4, x42 = 8
};

class LegoBrick {
    //the length of the brick
    GLfloat length;
    //the width of the brick
    GLfloat width;
    //the current x position of the brick
    GLfloat curX;
    //the current y position of the brick
    GLfloat curY;
    //the current z position of the brick
    GLfloat curZ;
    int curColor;
    //brick type x11, x21, x22, x42
    int brickType;
public:
    //Constructor 
    LegoBrick(BrickType type);
    //draws the brick
    void DrawBrick();
    //changes the color of the brick
    void ChangeColor();
    //change the x position of the brick
    void ChangeX(GLfloat offset);
    //change the y position of the brick
    void ChangeY(GLfloat offset);
    //change the z position of the brick
    void ChangeZ(GLfloat offset);
    //get what type of brick
    int GetBrickType();
};

#endif
