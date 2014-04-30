/**
 * LegoBrick.cpp
 *
 * Author: Wes Johnson
 * Author: Jeremy Stilwell
 * Date:   4/1/14
 *
 * This program implements the object logic and draw function for various shapes of lego brick.
 */
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "LegoBrick.hpp"
using namespace std;

GLfloat colors[4][3] = {
    {1.0, 0.0, 0.0}, //Red
    {0.0, 1.0, 0.0}, //Green
    {0.0, 0.0, 1.0}, //Blue
    {0.0, 0.5, 0.5}  //Yellow
};

int currColor = 0;

void LegoBrick::LegoBrickConstr(BrickType type) {
    switch(type) {
        case x11:
            length = 1 * STUD_WIDTH;
            width  = 1 * STUD_WIDTH;
            break;
        case x21:
            length = 1 * STUD_WIDTH;
            width  = 2 * STUD_WIDTH;
            break;
        case x22:
            length = 2 * STUD_WIDTH;
            width  = 2 * STUD_WIDTH;
            break;
        case x42:
            length = 4 * STUD_WIDTH;
            width  = 2 * STUD_WIDTH;
            break;
    }
}

/**
 * Draw a brick
 *
 * @param BrickType Shape of brick to be drawn
 */
void LegoBrick::DrawBrick() {
    glBegin(GL_QUADS);
        glColor3f(colors[currColor][0],
                  colors[currColor][1],
                  colors[currColor][2]);
        
        //Front Face
        glVertex3f(0.0 + (width / 2), 0.0 + (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 + (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 - (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 - (HEIGHT / 2), 0.0 + (length / 2));

        //Back Face
        glVertex3f(0.0 + (width / 2), 0.0 - (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 - (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 + (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 + (HEIGHT / 2), 0.0 - (length / 2));

        //Top Face
        glVertex3f(0.0 + (width / 2), 0.0 + (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 + (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 + (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 + (HEIGHT / 2), 0.0 + (length / 2));

        //Bottom Face
        glVertex3f(0.0 + (width / 2), 0.0 - (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 - (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 - (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 - (HEIGHT / 2), 0.0 - (length / 2));

        //Left Face
        glVertex3f(0.0 - (width / 2), 0.0 + (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 + (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 - (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 - (width / 2), 0.0 - (HEIGHT / 2), 0.0 + (length / 2));

        //Right Face
        glVertex3f(0.0 + (width / 2), 0.0 + (HEIGHT / 2), 0.0 - (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 + (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 - (HEIGHT / 2), 0.0 + (length / 2));
        glVertex3f(0.0 + (width / 2), 0.0 - (HEIGHT / 2), 0.0 - (length / 2));
    glEnd();
}

void LegoBrick::ChangeColor() {
    if(currColor < 3) {
        currColor++;
    } else {
        currColor = 0;
    }
    DrawBrick();
}
