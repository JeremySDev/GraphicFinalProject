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

LegoBrick legoBrick(x42);
LegoBrick legoBrick2(x11);
float rotateX = 0.0f;
float rotateY = 0.0f;
float rotateZ = 0.0f;
float xOffset = 0.0f;
float yOffset = 0.0f;
float zOffset = 0.0f;

float xOffset2 = 0.0f;
float yOffset2 = 0.0f;
float zOffset2 = 0.0f;

int chosenKey = 0;
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    legoBrick.DrawBrick();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, 10.0, 0.0);
    legoBrick2.DrawBrick();
    glPopMatrix();
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
            if(chosenKey == 0) {
                legoBrick.ChangeZ(-offset);
            } else {
                legoBrick2.ChangeZ(-offset);
            }
            glutPostRedisplay();
            break;
        case 's':
            //rotateY = rotateY + angle;
            if(chosenKey == 0) {
                legoBrick.ChangeZ(offset);
            } else {
                legoBrick2.ChangeZ(offset);
            }
            glutPostRedisplay();
            break;
        case 'a':
            //rotateZ = rotateZ + angle;
            if(chosenKey == 0) {
                legoBrick.ChangeX(-offset);
            } else {
                legoBrick2.ChangeX(-offset);
            }
            glutPostRedisplay();
            break;
        case 'd':
            if(chosenKey == 0) {
                legoBrick.ChangeX(offset);
            } else {
                legoBrick2.ChangeX(offset);
            }
            glutPostRedisplay();
            break;
        case 'r':
            if(chosenKey == 0) {
                chosenKey = 1;
            } else {
                chosenKey = 0;
            }
            //legoBrickG.ChangeColor();
            //glutPostRedisplay();
            break;
        case 'q':
            if(chosenKey == 0) {
                legoBrick.ChangeColor();
            } else {
                legoBrick2.ChangeColor();
            }
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
    glOrtho(-50.0, 50.0, -50, 50, -50.0, 50.0);
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
