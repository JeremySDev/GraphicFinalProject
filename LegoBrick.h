/**
 * LegoBrick.h
 *
 * Author: Wes Johnson
 * Date:   4/21/14
 *
 * This header defines the LegoBrick class and its methods
 */
#ifndef LEGOBRICK_H
#define LEGOBRICK_H

#include<GL/glut.h>

#define HEIGHT 2
#define STUD_WIDTH 1

class LegoBrick {
    enum BrickType { 1x1 = 1, 1x2 = 2, 2x2 = 4, 2x4 = 8 };
    
    public:
        void LegoBrick(BrickType type);
        void DrawBrick();        
};

#endif
