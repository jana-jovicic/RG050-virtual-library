#include "../headers/global_variables.h"
#include "../headers/camera.h"

void resetCamera()
{
	gCameraPosition[0] = 0.0f;
	gCameraPosition[1] = yRange / 2;
	gCameraPosition[2] = zRange - 2.0f;

	gCameraLookAt[0] = 0.0f;
	gCameraLookAt[1] = yRange / 2;
	gCameraLookAt[2] = 0.0f;

	gCameraUp[0] = 0.0f;
	gCameraUp[1] = 1.0f;
	gCameraUp[2] = 0.0f;

	gCameraPitch = 0.0f;
	gCameraYaw = 0.0f;

	gMoveRightward = 0.0f;
	gMoveUpward = 0.0f;
	gMoveForward = 0.0f;

	cameraUpdated = 1;
}

void updateCamera()
{   
        /* Kamera oko x ose moze da rotira samo u intervalu [-90, 90]  */
	if (gCameraPitch > 90.0f)
		gCameraPitch = 90.0f;
	else if (gCameraPitch < -90.0f)
		gCameraPitch = -90.0f;

        /* Kamera oko y ose moze da napravi pun krug */
	if (gCameraYaw > 360.0f)
		gCameraYaw -= 360.0f;
	else if (gCameraYaw < 0.0f)
		gCameraYaw += 360.0f;

        /*
            Kretanje kamere sam napravila na osnovu koda sa sledeceg linka:
            http://www.lighthouse3d.com/tutorials/glut-tutorial/keyboard-example-moving-around-the-world/
        */
	gCameraPosition[0] += sin(DEG2RAD(gCameraYaw)) * gMoveForward;
	gCameraPosition[2] -= cos(DEG2RAD(gCameraYaw)) * gMoveForward;

	gCameraPosition[0] += sin(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);
	gCameraPosition[2] += -cos(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);

	gCameraPosition[1] += gMoveUpward;

	gCameraLookAt[0] = gCameraPosition[0] + sin(DEG2RAD(gCameraYaw));
	gCameraLookAt[2] = gCameraPosition[2] - cos(DEG2RAD(gCameraYaw));
	gCameraLookAt[1] = gCameraPosition[1] + sin(DEG2RAD(gCameraPitch));

	gMoveRightward = 0;
	gMoveUpward = 0;
	gMoveForward = 0;

	glLoadIdentity();
	gluLookAt(gCameraPosition[0], gCameraPosition[1], gCameraPosition[2],
		gCameraLookAt[0], gCameraLookAt[1], gCameraLookAt[2],
		gCameraUp[0], gCameraUp[1], gCameraUp[2]);


	cameraUpdated = 1;
	glutPostRedisplay();
}

