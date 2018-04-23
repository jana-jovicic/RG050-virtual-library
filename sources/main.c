#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glu.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>

#include "../headers/global_variables.h"
#include "../headers/keyboard.h"
#include "../headers/room.h"
#include "../headers/texture.h"
#include "../headers/bookcase.h"
#include "../headers/books.h"

/*---------------------------- Globalne promenljive ----------------------------*/

/* Pokazivaci na prozore */
GLFWwindow* mainWindow = 0;
GLFWwindow* bookWindow = 0;

/* Dimenzije prozora */
GLint WIN_WIDTH;
GLint WIN_HEIGHT;

//Bookcase bookcases[MAX_BOOKCASES];
//int numOfBookcases = 0;

/* Kamera */
GLfloat gCameraPosition[] = { 0.0f, yRange / 2, zRange - 2 };
GLfloat gCameraLookAt[] = { 0.0f, yRange / 2, 0.0f };
GLfloat gCameraUp[] = { 0.0f, 1.0f, 0.0f };

/* rotacije oko x, y ose redom */
GLfloat gCameraPitch = 0.0f;
GLfloat gCameraYaw = 0.0f;

GLfloat gMoveRightward = 0.0f;
GLfloat gMoveUpward = 0.0f;
GLfloat gMoveForward = 0.0f;

GLfloat gMovementSensitivity = 1;
GLfloat gRotationSensitivity = 2;

int cameraUpdated = 0;  /* indikator */

/* Materijal */
GLfloat gAmbientMaterial[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLint gShininessMaterial = 50;

/* Osvetljenje */
GLfloat gGlobalAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };

GLfloat gToplightAmbient[] = { 0.5, 0.5f, 0.5f, 1.0f };
GLfloat gToplightDiffuse[] = { 1.0f, 0.92f, 0.54f, 1.0f };
GLfloat gToplightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat gToplightPosition[] = { 0.0f, yRange - 10.0f, 0.0f, 1.0f };

GLfloat gBackLeftSpotlightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat gBackLeftSpotlightDiffuse[] = { 0.94f, 0.5f, 0.5f, 1.0f };
GLfloat gBackLeftSpotlightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat gBackLeftSpotlightPosition[] = { -xRange + 2.5f, yRange, -zRange + 2.5f, 1.0f };
GLfloat gBackLeftSpotlightDirection[] = { 0.25, -1.0f, 0.25f };

GLfloat gBackRightSpotlightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat gBackRightSpotlightDiffuse[] = { 0.4f, 0.8f, 0.98f, 1.0f };
GLfloat gBackRightSpotlightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat gBackRightSpotlightPosition[] = { xRange - 2.5f, yRange, -zRange + 2.5f, 1.0f };
GLfloat gBackRightSpotlightDirection[] = { -0.25f, -1.0f, 0.25f };

GLfloat gFrontLeftSpotlightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat gFrontLeftSpotlightDiffuse[] = { 0.94f, 0.5f, 0.5f, 1.0f };
GLfloat gFrontLeftSpotlightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat gFrontLeftSpotlightPosition[] = { -xRange + 2.5f, yRange, zRange - 2.5f, 1.0f };
GLfloat gFrontLeftSpotlightDirection[] = { 0.25, -1.0f, -0.25f };

GLfloat gFrontRightSpotlightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat gFrontRightSpotlightDiffuse[] = { 0.4f, 0.8f, 0.98f, 1.0f };
GLfloat gFrontRightSpotlightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat gFrontRightSpotlightPosition[] = { xRange - 2.5f, yRange, zRange - 2.5f, 1.0f };
GLfloat gFrontRightSpotlightDirection[] = { -0.25, -1.0f, -0.25f };

GLfloat gSkylightAmbient[] = { 0.5f, 0.5f, 0.6f, 1.0f };
GLfloat gSkylightDiffuse[] = { 1.0f, 0.9f, 0.77f, 1.0f };
GLfloat gSkylightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat gSkylightPosition[] = { 0.0f, 100.0f, 0.0f, 1.0f };

/*------------------------------------------------------------------------------*/

/* -------------------------- Deklaracije funkcija --------------------------- */

void init();
void reshape(GLint, GLint);

void drawScene();

static void error_callback(int error, const char* description);
static void draw_debug_coordsys();

/*------------------------------------------------------------------------------*/

/*-------------------------------- Main ----------------------------------------*/

int main(int argc, char ** argv) {
    
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE | GLUT_ACCUM);
        
        glfwSetErrorCallback(error_callback);

        /* Inicijalizacija GLFW */
        if (!glfwInit()) {
            return EXIT_FAILURE;
        }
        
        /* Kreira se prozor dimenzija koje odgovaraju monitoru na kom se program pokrece */
        const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        WIN_WIDTH = mode->width;
        WIN_HEIGHT = mode->height;    
//         mainWindow = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Library", NULL, NULL);
//         if (!mainWindow) {
//             glfwTerminate();
//             return EXIT_FAILURE;
//         }

    
        glutInitWindowPosition(50, 50);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);

	glutCreateWindow("Virtual library");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(drawScene);
       // glutMouseFunc(onMouse);
	glutKeyboardFunc(keyboardFunc);
	glutSpecialFunc(specialFunc);

	glutMainLoop();
        

    return EXIT_SUCCESS;
}

/*------------------------------------------------------------------------------*/

/*------------------------ Definicije funkcija ---------------------------------*/

void init()
{
	glClearColor(0.0, 0.0f, 0.0f, 1.0f);
	glClearAccum(0.0f, 0.0f, 0.0f, 1.0f);
        
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LINE_SMOOTH);
        glEnable(GL_COLOR_MATERIAL);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        
        loadTextures();

	/* Postavljaju se svojstva materijala */
	glMaterialfv(GL_FRONT, GL_AMBIENT, gAmbientMaterial);
	glMateriali(GL_FRONT, GL_SHININESS, gShininessMaterial);

	/* Globalno svetlo je ambijentalno */
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gGlobalAmbient);

	/* Postavlja se gornje osvetljenje */
	glLightfv(GL_LIGHT0, GL_AMBIENT, gToplightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, gToplightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, gToplightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, gToplightPosition);

	/* front left spotlight */
	glLightfv(GL_LIGHT1, GL_AMBIENT, gFrontLeftSpotlightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, gFrontLeftSpotlightDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, gFrontLeftSpotlightSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION, gFrontLeftSpotlightPosition);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0f);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, gFrontLeftSpotlightDirection);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 32.0);

	/* front right spotlight */
	glLightfv(GL_LIGHT2, GL_AMBIENT, gFrontRightSpotlightAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, gFrontRightSpotlightDiffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, gFrontRightSpotlightSpecular);
	glLightfv(GL_LIGHT2, GL_POSITION, gFrontRightSpotlightPosition);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0f);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, gFrontRightSpotlightDirection);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 32.0);

	/* back left spotlight */
	glLightfv(GL_LIGHT3, GL_AMBIENT, gBackLeftSpotlightAmbient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, gBackLeftSpotlightDiffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, gBackLeftSpotlightSpecular);
	glLightfv(GL_LIGHT3, GL_POSITION, gBackLeftSpotlightPosition);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30.0f);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, gBackLeftSpotlightDirection);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 32.0);

	/* back right spotlight */
	glLightfv(GL_LIGHT4, GL_AMBIENT, gBackRightSpotlightAmbient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, gBackRightSpotlightDiffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, gBackRightSpotlightSpecular);
	glLightfv(GL_LIGHT4, GL_POSITION, gBackRightSpotlightPosition);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30.0f);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, gBackRightSpotlightDirection);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 32.0);

	/* Surrounding light */
	glLightfv(GL_LIGHT6, GL_AMBIENT, gSkylightAmbient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, gSkylightDiffuse);
	glLightfv(GL_LIGHT6, GL_SPECULAR, gSkylightSpecular);
	glLightfv(GL_LIGHT6, GL_POSITION, gSkylightPosition);

	/* Ukljucuje se osvetljenje i postavlja se model sencenja */
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

}

void reshape(GLint width, GLint height)
{
	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0f, (GLfloat)width / height, 1.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(gCameraPosition[0],
		gCameraPosition[1],
		gCameraPosition[2],
		gCameraLookAt[0],
		gCameraLookAt[1],
		gCameraLookAt[2],
		gCameraUp[0],
		gCameraUp[1],
		gCameraUp[2]);
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLightfv(GL_LIGHT0, GL_POSITION, gToplightPosition);
	glLightfv(GL_LIGHT1, GL_POSITION, gFrontLeftSpotlightPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, gFrontLeftSpotlightDirection);
	glLightfv(GL_LIGHT2, GL_POSITION, gFrontRightSpotlightPosition);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, gFrontRightSpotlightDirection);
	glLightfv(GL_LIGHT3, GL_POSITION, gBackLeftSpotlightPosition);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, gBackLeftSpotlightDirection);
	glLightfv(GL_LIGHT4, GL_POSITION, gBackRightSpotlightPosition);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, gBackRightSpotlightDirection);
	glLightfv(GL_LIGHT6, GL_POSITION, gSkylightPosition);

	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glDepthMask(GL_TRUE);

	/* Blend in reflection */
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        draw_debug_coordsys();
        
	drawFloor();
	drawRoom();
        drawBookcases();

	glFlush();
	glutSwapBuffers();
}

static void draw_debug_coordsys()
{
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    // x - crvena
    glColor3f (1, 0, 0);
    glVertex3f(150, 0, 0);
    glVertex3f(0, 0, 0);

    // y - zelena
    glColor3f (0, 1, 0);
    glVertex3f(0, 150, 0);
    glVertex3f(0, 0, 0);
    
    // z - plava
    glColor3f (0, 0, 1);
    glVertex3f(0, 0, 150);
    glVertex3f(0, 0, 0);
    glEnd();
    glEnable(GL_LIGHTING);
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

/*------------------------------------------------------------------------------*/