/**
 * LegoBrick.h
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

class LegoBrick 
{
    enum BrickType { x11 = 1, x21 = 2, x22 = 4, x44 = 8 };
    GLfloat length;
    GLfloat width;
    public:
        void LegoBrickConstr(BrickType type);
        void DrawBrick();
        void ChangeColor();
};

#endif
