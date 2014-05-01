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
LegoBrick legoBrickG;

float rotateX = 0.0f;
float rotateY = 0.0f;
float rotateZ = 0.0f;
/**
 * Draws the wall of cubes in the scene by using a DrawShape object
 */
void drawBrick(LegoBrick legoBrick)
{
    //BrickType bType = x11;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-12.0, 12.0, -12, 12, -12.0, 12.0);

    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);
    glRotatef(rotateZ, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    //glRotatef(55.0, 0.0, 0.0, 1.0);
    legoBrickG = legoBrick;
    legoBrick.LegoBrickConstr();
    //legoBrick.ChangeColor();
    legoBrick.DrawBrick();


}

void render()
{
    LegoBrick legoBrick;
    drawBrick(legoBrick);
    glFlush();
    glutSwapBuffers();
}

/**
 * Keyboard function that handles moving and rotating the cube 
 * based on input from the keyboard.
 */
void keyboardFunc(unsigned char key, int x, int y)
{
    float angle = 90.0f;
    switch (key) {
        case 'w':
            rotateX = rotateX + angle;
            glutPostRedisplay();
            break;
        case 's':
            rotateY = rotateY + angle;
            glutPostRedisplay();
            break;
        case 'a':
            rotateZ = rotateZ + angle;
            glutPostRedisplay();
            break;
        case 'd':            
            glutPostRedisplay();
            break;
        case 'r':
            legoBrickG.ChangeColor();
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
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_LIGHT1);
    glOrtho(-12.0, 12.0, -12, 12, -12.0, 12.0);
}

/* helps change the geometry to match any changes for window resizing 
void reshape(int w, int h)
{
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}*/

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
