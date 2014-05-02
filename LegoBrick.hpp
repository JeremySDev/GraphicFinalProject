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
#define SEGMENT_WIDTH 1
#define STUD_HEIGHT 0.25
#define STUD_RAD 0.4

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
    //Draw the studs on the brick
    void DrawStud(GLfloat baseX, GLfloat baseY, GLfloat baseZ);
    //changes the color of the brick
    void ChangeColor();
    //Rotate the current brick
    void Rotate();
    //Move the brick along the X-axis
    void ChangeX(GLfloat offset);
    //Move the brick along the Y-axis
    void ChangeY(GLfloat offset);
    //Move the brick along the Z-axis
    void ChangeZ(GLfloat offset);
    //get what type of brick
    int GetBrickType();
};

#endif
