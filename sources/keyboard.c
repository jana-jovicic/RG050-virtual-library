#include "../headers/global_variables.h"
#include "../headers/keyboard.h"
#include "../headers/camera.h"
#include "../headers/bookcase.h"

extern GLFWwindow* bookWindow;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

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
                                        
                case 'o':       if(gCameraPosition[0] > books[0].x+27 && gCameraPosition[0] < books[0].x+33
                                    && gCameraPosition[2] > books[0].z-26 &&  gCameraPosition[2] < books[0].z+13){
                                    // printf("!!!!!\n");
                                        
                                        glfwSetErrorCallback(error_callback);

                                        if (!glfwInit()) {
                                            exit(EXIT_FAILURE);
                                        }
                                        
                                        bookWindow = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "George Orwell, 1984", NULL, NULL);
                                        
                                        if(!bookWindow){
                                            glfwTerminate();
                                            exit(EXIT_FAILURE);
                                        }
                                        
                                        while(!glfwWindowShouldClose(bookWindow)){
                                            displayBook(books[0].title);
                                            glfwPollEvents();
                                        }

                                        glfwDestroyWindow(bookWindow);
                                        glfwTerminate();
                                }
                                
                

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
