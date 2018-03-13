#include "../headers/global_variables.h"
#include "../headers/keyboard.h"
#include "../headers/camera.h"

void keyboardFunc(unsigned char key, GLint x, GLint y)
{
	switch (key)
	{
		case 'w':	gCameraPitch += gRotationSensitivity;
					break;

		case 's':	gCameraPitch -= gRotationSensitivity;
					break;

		case 'a':	gCameraYaw -= gRotationSensitivity;
					break;

		case 'd':	gCameraYaw += gRotationSensitivity;
					break;

		case 'r':	resetCamera();
					break;
	}
	updateCamera();
}

void specialFunc(GLint key, GLint x, GLint y)
{
	switch (key)
	{
	case GLUT_KEY_UP: gMoveForward += gMovementSensitivity;
		break;

	case GLUT_KEY_DOWN: gMoveForward -= gMovementSensitivity;
		break;

	case GLUT_KEY_LEFT: gMoveRightward -= gMovementSensitivity;
		break;

	case GLUT_KEY_RIGHT: gMoveRightward += gMovementSensitivity;
		break;
	}

	updateCamera();
}
