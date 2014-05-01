/**
 * LegoBrick.cpp
 * sdfs
 * Author: Wes Johnson
 * Author: Jeremy Stilwell
 * Date:   4/1/14
 *
 * This program implements the object logic and draw function for various shapes 
 * of lego brick.
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
    {1.0, 1.0, 0.0} //Yellow
};

/**
 * LegoBrick the constructor for the class the take in a param of brick type
 * and inits all of the fields of the object. Defaults to red for color.
 * @param type what type of brick i.e. 1x1, 1x2, 2x2, 2x4
 */
LegoBrick::LegoBrick(BrickType type)
{
    switch (type) {
        case x11:
            length = 1 * STUD_WIDTH;
            width = 1 * STUD_WIDTH;
            break;
        case x21:
            length = 1 * STUD_WIDTH;
            width = 2 * STUD_WIDTH;
            break;
        case x22:
            length = 2 * STUD_WIDTH;
            width = 2 * STUD_WIDTH;
            break;
        case x42:
            length = 4 * STUD_WIDTH;
            width = 2 * STUD_WIDTH;
            break;
    }
    curX = 0.0f;
    curY = 0.0f;
    curZ = 0.0f;
    curColor = 0;
    brickType = type;
}

/**
 * Draw a brick
 *
 * @param BrickType Shape of brick to be drawn
 */
void LegoBrick::DrawBrick()
{
    glBegin(GL_QUADS);
    glColor3f(colors[curColor][0],
            colors[curColor][1],
            colors[curColor][2]);

    //Front Face
    glNormal3d(0, 0, 1);
    glVertex3f(curX + (width / 2), curY + (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX - (width / 2), curY + (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX - (width / 2), curY - (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX + (width / 2), curY - (HEIGHT / 2), curZ + (length / 2));

    //Back Face
    glNormal3d(0, 0, -1);
    glVertex3f(curX + (width / 2), curY - (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX - (width / 2), curY - (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX - (width / 2), curY + (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX + (width / 2), curY + (HEIGHT / 2), curZ - (length / 2));

    //Top Face
    glNormal3d(0, 1, 0);
    glVertex3f(curX + (width / 2), curY + (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX - (width / 2), curY + (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX - (width / 2), curY + (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX + (width / 2), curY + (HEIGHT / 2), curZ + (length / 2));

    //Bottom Face
    glNormal3d(0, -1, 0);
    glVertex3f(curX + (width / 2), curY - (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX - (width / 2), curY - (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX - (width / 2), curY - (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX + (width / 2), curY - (HEIGHT / 2), curZ - (length / 2));

    //Left Face
    glNormal3d(-1, 0, 0);
    glVertex3f(curX - (width / 2), curY + (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX - (width / 2), curY + (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX - (width / 2), curY - (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX - (width / 2), curY - (HEIGHT / 2), curZ + (length / 2));

    //Right Face
    glNormal3d(1, 0, 0);
    glVertex3f(curX + (width / 2), curY + (HEIGHT / 2), curZ - (length / 2));
    glVertex3f(curX + (width / 2), curY + (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX + (width / 2), curY - (HEIGHT / 2), curZ + (length / 2));
    glVertex3f(curX + (width / 2), curY - (HEIGHT / 2), curZ - (length / 2));
    glEnd();
}

/**
 * ChangeColor alters the color of the brick before it is commited to the scene
 */
void LegoBrick::ChangeColor()
{
    if (curColor < 3)
    {
        curColor++;
    } else
    {
        curColor = 0;
    }
    DrawBrick();
}

void LegoBrick::Rotate() {
    GLfloat temp = length;
    length = width;
    width = temp;
    DrawBrick();
}

void LegoBrick::ChangeX(GLfloat offset) {
    curX += offset;
}

/**
 * ChangeY changes the curY based on the offset passed in.
 * @param offset the amount by which to change curY
 */
void LegoBrick::ChangeY(GLfloat offset)
{
    curY += offset;
}

/**
 * ChangeZ changes the curZ based on the offset passed in.
 * @param offset the amount by which to change curZ
 */
void LegoBrick::ChangeZ(GLfloat offset)
{
    curZ += offset;
}

/**
 * GetBrickType returns what type of brick the current brick is i.e. 1x1, 1x2, 
 * 2x2, 2x4
 * @return the type of the brick 
 */
int LegoBrick::GetBrickType()
{
    return brickType;
}
