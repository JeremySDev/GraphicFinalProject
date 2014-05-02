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
            length = 1 * SEGMENT_WIDTH;
            width = 1 * SEGMENT_WIDTH;
            break;
        case x21:
            length = 1 * SEGMENT_WIDTH;
            width = 2 * SEGMENT_WIDTH;
            break;
        case x22:
            length = 2 * SEGMENT_WIDTH;
            width = 2 * SEGMENT_WIDTH;
            break;
        case x42:
            length = 2 * SEGMENT_WIDTH;
            width = 4 * SEGMENT_WIDTH;
            break;
    }
    curX = 0.0f;
    curY = 0.0f;
    curZ = 0.0f;
    curColor = 0;
    brickType = type;
    rotated = false;
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

    switch(brickType) {
        case 1:
            DrawStud(curX, curY + (HEIGHT / 2), curZ);
            break;
        case 2:
            if(!rotated) {
                DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2), curZ);
                DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2), curZ);
            } else {
                DrawStud(curX, curY + (HEIGHT / 2), curZ - (0.25 * length));
                DrawStud(curX, curY + (HEIGHT / 2), curZ + (0.25 * length));
            }
            break;
        case 4:
            DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2),
                     curZ - (0.25 * length));
            DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2),
                     curZ - (0.25 * length));
            DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2),
                     curZ + (0.25 * length));
            DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2),
                     curZ + (0.25 * length));
            break;
        case 8:
            if(!rotated) {
                DrawStud(curX - (0.375 * width), curY + (HEIGHT / 2),
                         curZ - (0.25 * length));
                DrawStud(curX - (0.125 * width), curY + (HEIGHT / 2),
                         curZ - (0.25 * length));
                DrawStud(curX + (0.375 * width), curY + (HEIGHT / 2),
                         curZ - (0.25 * length));
                DrawStud(curX + (0.125 * width), curY + (HEIGHT / 2),
                         curZ - (0.25 * length));
                DrawStud(curX - (0.375 * width), curY + (HEIGHT / 2),
                         curZ + (0.25 * length));
                DrawStud(curX - (0.125 * width), curY + (HEIGHT / 2),
                         curZ + (0.25 * length));
                DrawStud(curX + (0.375 * width), curY + (HEIGHT / 2),
                         curZ + (0.25 * length));
                DrawStud(curX + (0.125 * width), curY + (HEIGHT / 2),
                         curZ + (0.25 * length));
            } else {
                DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2),
                         curZ - (0.375 * length));
                DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2),
                         curZ - (0.125 * length));
                DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2),
                         curZ - (0.375 * length));
                DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2),
                         curZ - (0.125 * length));
                DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2),
                         curZ + (0.375 * length));
                DrawStud(curX - (0.25 * width), curY + (HEIGHT / 2),
                         curZ + (0.125 * length));
                DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2),
                         curZ + (0.375 * length));
                DrawStud(curX + (0.25 * width), curY + (HEIGHT / 2),
                         curZ + (0.125 * length));
            }
            break;
    }
}

/**
 * DrawStuds places and draws studs depending on the type of brick being drawn
 */
void LegoBrick::DrawStud(GLfloat baseX, GLfloat baseY, GLfloat baseZ) {
    for(GLfloat i = 0.0f; i < STUD_HEIGHT; i += 0.05f) {
        glBegin(GL_LINE_LOOP);
        for(int j = 0; j < 20; j++) {
            GLfloat degree = j * (360.0/20);
            GLfloat radian = degree * M_PI / 180;

            GLfloat z = STUD_RAD * sinf(radian);
            GLfloat x = STUD_RAD * cosf(radian);
            glVertex3f(baseX + x, baseY + i, baseZ + z);
        }
        glEnd();
    }
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

/**
 * Rotate rotates the brick by 90 degrees
 */
void LegoBrick::Rotate() {
    GLfloat temp = length;
    length = width;
    width = temp;
    if(!rotated) {
        rotated = true;
    } else {
        rotated = false;
    }
    DrawBrick();
}

/**
 * ChangeX moves the brick in the X direction
 *
 * @param distance to move the brick
 */
void LegoBrick::ChangeX(GLfloat offset) {
    curX += offset;
}

/**
 * ChangeY moves the brick in the Y direction
 *
 * @param distance to move the brick
 */
void LegoBrick::ChangeY(GLfloat offset)
{
    curY += offset;
}

/**
 * ChangeZ moves the brick in the Z direction
 *
 * @param distance to move the brick
 */
void LegoBrick::ChangeZ(GLfloat offset)
{
    curZ += offset;
}

/**
 * GetBrickType returns what type of brick the current brick is i.e. 1x1, 1x2, 
 * 2x2, 2x4
 *
 * @return the type of the brick 
 */
int LegoBrick::GetBrickType()
{
    return brickType;
}
