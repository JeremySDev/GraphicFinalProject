/**
 * LegoBrick.hpp
 *
 * Author: Wes Johnson
 * Author: Jeremy Stilwell
 * Date:   4/21/14
 *
 * This header defines the LegoBrick class and its methods
 */
#ifndef LEGOBRICK_H
#define LEGOBRICK_H

#include<GL/glut.h>

#define HEIGHT 2
#define STUD_WIDTH 1

//an enum for the size of the bricks 
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
    int brickType;
public:
    //void LegoBrickConstr();
    LegoBrick(BrickType type);
    void DrawBrick();
    void ChangeColor();
    void ChangeX(GLfloat offset);
    void ChangeY(GLfloat offset);
    void ChangeZ(GLfloat offset);
    int GetBrickType();
};

#endif
