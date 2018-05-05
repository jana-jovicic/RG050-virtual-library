#ifndef _GLOBALVARIABLES_H_
#define _GLOBALVARIABLES_H_

#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>

#define GL_BGR         0x80E0
#define DEG2RAD(a)    (M_PI / 180 * (a))

/* Dimenzije prostorije */
#define xRange (150.0f)
#define yRange (150.0f)
#define zRange (150.0f)

/* Pokazivaci na prozore */
extern GLFWwindow* mainWindow;
extern GLFWwindow* bookWindow;

/* Dimenzije prozora */
extern GLint WIN_WIDTH;
extern GLint WIN_HEIGHT;

/* Kamera */
extern GLfloat gCameraPosition[];
extern GLfloat gCameraLookAt[];
extern GLfloat gCameraUp[];

/* rotacije oko x, y ose redom */
extern GLfloat gCameraPitch;
extern GLfloat gCameraYaw;

extern GLfloat gMoveRightward;
extern GLfloat gMoveUpward;
extern GLfloat gMoveForward;

extern GLfloat gMovementSensitivity;
extern GLfloat gRotationSensitivity;

extern int cameraUpdated;  /* indikator */

/* Materijal */
extern GLfloat gAmbientMaterial[];
extern GLint gShininessMaterial;

/* Osvetljenje */
extern GLfloat gGlobalAmbient[];

extern GLfloat gToplightAmbient[];
extern GLfloat gToplightDiffuse[];
extern GLfloat gToplightSpecular[];
extern GLfloat gToplightPosition[];

extern GLfloat gBackLeftSpotlightAmbient[];
extern GLfloat gBackLeftSpotlightDiffuse[];
extern GLfloat gBackLeftSpotlightSpecular[];
extern GLfloat gBackLeftSpotlightPosition[];
extern GLfloat gBackLeftSpotlightDirection[];

extern GLfloat gBackRightSpotlightAmbient[];
extern GLfloat gBackRightSpotlightDiffuse[];
extern GLfloat gBackRightSpotlightSpecular[];
extern GLfloat gBackRightSpotlightPosition[];
extern GLfloat gBackRightSpotlightDirection[];

extern GLfloat gFrontLeftSpotlightAmbient[];
extern GLfloat gFrontLeftSpotlightDiffuse[];
extern GLfloat gFrontLeftSpotlightSpecular[];
extern GLfloat gFrontLeftSpotlightPosition[];
extern GLfloat gFrontLeftSpotlightDirection[];

extern GLfloat gFrontRightSpotlightAmbient[];
extern GLfloat gFrontRightSpotlightDiffuse[];
extern GLfloat gFrontRightSpotlightSpecular[];
extern GLfloat gFrontRightSpotlightPosition[];
extern GLfloat gFrontRightSpotlightDirection[];

extern GLfloat gSkylightAmbient[];
extern GLfloat gSkylightDiffuse[];
extern GLfloat gSkylightSpecular[];
extern GLfloat gSkylightPosition[];


#endif