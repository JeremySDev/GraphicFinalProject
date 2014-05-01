/** 
 * LegoBuilder.cpp
 * 
 * Author: Wes Johnson
 * Author: Jeremy Stilwell
 * Date:   4/21/14
 */
#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "LegoBrick.hpp"
using namespace std;

int window;

std::vector<LegoBrick> bricks;
float rotateX = 0.0f;
float rotateY = 0.0f;
float rotateZ = 0.0f;

int curBrick = 0;
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
    //glPushMatrix();
    for(int i = 0; i < bricks.size(); i++) {
        bricks.at(i).DrawBrick();
    }
    //glTranslatef(0.0, 0.0, 0.0);
    //legoBrick.DrawBrick();
    //glPopMatrix();
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
        case '1':
            bricks.push_back(LegoBrick(x11));
            curBrick++;
            break;
        case '2':
            bricks.push_back(LegoBrick(x21));
            curBrick++;
            break;
        case '3':
            bricks.push_back(LegoBrick(x22));
            curBrick++;
            break;
        case '4':
            bricks.push_back(LegoBrick(x42));
            curBrick++;
            break;
        case 'w':
            bricks.at(curBrick).ChangeZ(-offset);
            //rotateX = rotateX + angle;
            /*if(chosenKey == 0) {
                legoBrick.ChangeZ(-offset);
            } else {
                legoBrick2.ChangeZ(-offset);
            }*/
            glutPostRedisplay();
            break;
        case 's':
            bricks.at(curBrick).ChangeZ(offset);
            //rotateY = rotateY + angle;
            /*if(chosenKey == 0) {
                legoBrick.ChangeZ(offset);
            } else {
                legoBrick2.ChangeZ(offset);
            }*/
            glutPostRedisplay();
            break;
        case 'a':
            bricks.at(curBrick).ChangeX(-offset);
            //rotateZ = rotateZ + angle;
            /*if(chosenKey == 0) {
                legoBrick.ChangeX(-offset);
            } else {
                legoBrick2.ChangeX(-offset);
            }*/
            glutPostRedisplay();
            break;
        case 'd':
            bricks.at(curBrick).ChangeX(offset);
            /*if(chosenKey == 0) {
                legoBrick.ChangeX(offset);
            } else {
                legoBrick2.ChangeX(offset);
            }*/
            glutPostRedisplay();
            break;
        case 'r':
            if(curBrick < bricks.size()) {
                curBrick++;
            } else {
                curBrick = 0;
            }
            /*if(chosenKey == 0) {
                chosenKey = 1;
            } else {
                chosenKey = 0;
            }*/
            //legoBrickG.ChangeColor();
            //glutPostRedisplay();
            break;
        case 'q':
            /*if(chosenKey == 0) {
                legoBrick.ChangeColor();
            } else {
                legoBrick2.ChangeColor();
            }*/
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
    glOrtho(-20.0, 20.0, -20, 20, -20.0, 20.0);
}

/* main starts the program */
int main(int argc, char** argv)
{
    //bricks.push_back(LegoBrick(x11));
    //cout << bricks.at(0).GetBrickType() << endl;
    bricks.push_back(LegoBrick(x22));
    //cout << bricks.at(1).GetBrickType() << endl;
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
