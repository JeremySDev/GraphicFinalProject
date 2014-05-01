/** 
 * LegoBuilder.cpp
 * 
 * Author: Wes Johnson
 * Author: Jeremy Stilwell
 * Date:   4/21/14
 */
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include "LegoBrick.hpp"
using namespace std;
int window;

float rotateX = 0.0f;
float rotateY = 0.0f;
float rotateZ = 0.0f;
float xOffset = 0.0f;
float yOffset = 0.0f;
float zOffset = 0.0f;
/**
 * Draws the wall of cubes in the scene by using a DrawShape object
 */
/*void drawBrick(LegoBrick legoBrick)
{
    //BrickType bType = x11;

    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);
    glRotatef(rotateZ, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
}*/

void render()
{
    LegoBrick legoBrick(x42);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    glTranslatef(0.0 + xOffset, 0.0 + yOffset, 0.0 + zOffset);
    legoBrick.DrawBrick();
    glPopMatrix();
    //glFlush();
    glutSwapBuffers();
}

/**
 * Keyboard function that handles moving and rotating the cube 
 * based on input from the keyboard.
 */
void keyboardFunc(unsigned char key, int x, int y)
{
    float offset = 2;
    float angle = 90.0f;
    switch (key) {
        case 'w':
            //rotateX = rotateX + angle;
            zOffset += offset;
            glutPostRedisplay();
            break;
        case 's':
            //rotateY = rotateY + angle;
            zOffset -= offset;
            glutPostRedisplay();
            break;
        case 'a':
            //rotateZ = rotateZ + angle;
            xOffset -= offset;
            glutPostRedisplay();
            break;
        case 'd':
            xOffset += offset;
            glutPostRedisplay();
            break;
        case 'r':
            //legoBrickG.ChangeColor();
            glutPostRedisplay();
            break;
        case 'o':            
            glutDestroyWindow(window);
            break;
    }
}

/* enables certain settings and clears out others before the start of the render*/
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_COLOR_MATERIAL);
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_LIGHT1);
    glLoadIdentity();
    glOrtho(-12.0, 12.0, -12, 12, -12.0, 12.0);
}

/* main starts the program */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(800, 150);
    glutInitWindowSize(800, 600);
    window = glutCreateWindow("Lego Builder");
    init();
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboardFunc);
    glutIdleFunc(render);
    glutMainLoop();
    return 0;
}
