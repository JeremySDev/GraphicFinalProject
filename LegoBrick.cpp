/**
 * LegoBrick.cpp
 *
 * Author: Wes Johnson
 * Date:   4/1/14
 *
 * This program implements the object logic and draw function for various shapes of lego brick.
 */
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "LegoBrick.h"

using namespace std;

void LegoBrick::LegoBrick(BrickType type) {
    

/**
 * Draw a brick
 *
 * @param BrickType Shape of brick to be drawn
 */
void LegoBrick::DrawBrick() {
    glBegin(GL_QUADS);
        //Front/Back Color
        glColor3f(colors[colorChoice][colorFlip][0],
                  colors[colorChoice][colorFlip][1],
                  colors[colorChoice][colorFlip][2]);
        //Front Face
        glVertex3f(centerX + r, centerY + r, centerZ + r);
        glVertex3f(centerX - r, centerY + r, centerZ + r);
        glVertex3f(centerX - r, centerY - r, centerZ + r);
        glVertex3f(centerX + r, centerY - r, centerZ + r);

        //Back Face
        glVertex3f(centerX + r, centerY - r, centerZ - r);
        glVertex3f(centerX - r, centerY - r, centerZ - r);
        glVertex3f(centerX - r, centerY + r, centerZ - r);
        glVertex3f(centerX + r, centerY + r, centerZ - r);

        //Top/Bottom Color
        glColor3f(colors[colorChoice][(colorFlip + 1) % 3][0],
                  colors[colorChoice][(colorFlip + 1) % 3][1],
                  colors[colorChoice][(colorFlip + 1) % 3][2]);
        //Top Face
        glVertex3f(centerX + r, centerY + r, centerZ - r);
        glVertex3f(centerX - r, centerY + r, centerZ - r);
        glVertex3f(centerX - r, centerY + r, centerZ + r);
        glVertex3f(centerX + r, centerY + r, centerZ + r);

        //Bottom Face
        glVertex3f(centerX + r, centerY - r, centerZ + r);
        glVertex3f(centerX - r, centerY - r, centerZ + r);
        glVertex3f(centerX - r, centerY - r, centerZ - r);
        glVertex3f(centerX + r, centerY - r, centerZ - r);

        //Left/Right Color
        glColor3f(colors[colorChoice][(colorFlip + 2) % 3][0],
                  colors[colorChoice][(colorFlip + 2) % 3][1],
                  colors[colorChoice][(colorFlip + 2) % 3][2]);
        //Left Face
        glVertex3f(centerX - r, centerY + r, centerZ + r);
        glVertex3f(centerX - r, centerY + r, centerZ - r);
        glVertex3f(centerX - r, centerY - r, centerZ - r);
        glVertex3f(centerX - r, centerY - r, centerZ + r);

        //Right Face
        glVertex3f(centerX + r, centerY + r, centerZ - r);
        glVertex3f(centerX + r, centerY + r, centerZ + r);
        glVertex3f(centerX + r, centerY - r, centerZ + r);
        glVertex3f(centerX + r, centerY - r, centerZ - r);
    glEnd();
}
