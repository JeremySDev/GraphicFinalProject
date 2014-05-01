/** 
 * LegoBuilder.cpp - handles the window building and user interface of the 
 * project pressing 1 gives you 1x1, 2 a 1x2, 3 a 2x2, 4 a 2x4, sized brick.
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

//the value of the current window
int window;

//a vector that holds all previously created & commited bricks 
std::vector<LegoBrick> bricks;
//amounts to rotate on given axis by 
float rotateX = 0.0f;
float rotateY = 0.0f;
float rotateZ = 0.0f;

int curBrick = 0;

/* Creates the scene and draws the bricks*/
void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //go through and redraw all the bricks
    for(int i = 0; i < bricks.size(); i++) {
        bricks.at(i).DrawBrick();
    }
    glutSwapBuffers();
}

/**
 * Keyboard function that handles moving and rotating the cube 
 * based on input from the keyboard.
 */
void keyboardFunc(unsigned char key, int x, int y)
{
    float offset = 1;
    float angle = 90.0f;
    switch (key) {
        //1x1 brick
        case '1':
            bricks.push_back(LegoBrick(x11));
            curBrick = bricks.size() - 1;
            break;
        //2x1 brick
        case '2':
            bricks.push_back(LegoBrick(x21));
            curBrick = bricks.size() - 1;
            break;
        //2x2 brick
        case '3':
            bricks.push_back(LegoBrick(x22));
            curBrick = bricks.size() - 1;
            break;
        //2x4 brick
        case '4':
            bricks.push_back(LegoBrick(x42));
            curBrick = bricks.size() - 1;
            break;
        //changes the position in relation to the z axis. 
        case 'w':
            bricks.at(curBrick).ChangeZ(-offset);
            glutPostRedisplay();
            break;
        case 's':
            bricks.at(curBrick).ChangeZ(offset);
            glutPostRedisplay();
            break;
        //changes the position in relation to the x axis.
        case 'a':
            bricks.at(curBrick).ChangeX(-offset);
            glutPostRedisplay();
            break;
        case 'd':
            bricks.at(curBrick).ChangeX(offset);
            glutPostRedisplay();
            break;
            //change the position in relation to the y axis.
        case 'q':
            bricks.at(curBrick).ChangeY(offset);
            glutPostRedisplay();
            break;
        case 'e':
            bricks.at(curBrick).ChangeY(-offset);
            glutPostRedisplay();
            break;
        //cycles through the possible choices for the brick color.
        case 'c':
            bricks.at(curBrick).ChangeColor();
            glutPostRedisplay();
            break;
		//rotates the current brick
        case 'r':
            bricks.at(curBrick).Rotate();
            glutPostRedisplay();
            break;
        case 'f':
            if(curBrick < bricks.size() - 1) {
                curBrick++;
            } else {
                curBrick = 0;
            }
            break;
        //kill program
        case 'o':            
            glutDestroyWindow(window);
            break;
    }
}

/* enables certain settings and clears out others before the start of the render*/
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
    glOrtho(-20.0, 20.0, -20, 20, -20.0, 20.0);
}

/* main starts the program */
int main(int argc, char** argv)
{
    //Have to start with a default brick for render() to use, otherwise vector
    //goes out of bounds
    bricks.push_back(LegoBrick(x22));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(1050, 150);
    glutInitWindowSize(800, 600);
    window = glutCreateWindow("Lego Builder");
    init();
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboardFunc);
    glutIdleFunc(render);
    glutMainLoop();
    return 0;
}
