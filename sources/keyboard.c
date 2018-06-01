#include "../headers/global_variables.h"
#include "../headers/keyboard.h"
#include "../headers/camera.h"

extern GLFWwindow* bookWindow;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

void keyboardFunc(unsigned char key, GLint x, GLint y)
{
        /* Ovom funkcijom se realizuje:
           - rotacija kamere pomocu tastera 'w', 's', 'a', 'd'
           - otvaranje knjige pomocu tastera 'o'  
        */
    
        int i;
	switch (key)
	{
		case 'w':
                case 'W':       gCameraPitch += gRotationSensitivity;
					break;

		case 's':	
                case 'S':       gCameraPitch -= gRotationSensitivity;
					break;

		case 'a':	
                case 'A':       gCameraYaw -= gRotationSensitivity;
					break;

		case 'd':	
                case 'D':       gCameraYaw += gRotationSensitivity;
					break;

		case 'r':	
                case 'R':       resetCamera();
					break;
                                
                case 'o':                        
                case 'O':   
                            /* Kada korisnik pritisne taster 'o', proveravam da li se on nalazi u blizini neke od knjiga. 
                             * Ukoliko se nalazi, kreira se novi prozor u kome ce biti ispisan tekst iz te knjige. */
                            for(i = 0; i < NUM_OF_BOOKS; i++){
                              /*  
                                printf("------------------------------\n");
                                printf("Book coord: x=%f y=%f z=%f  %s\n", books[i].x, books[i].y, books[i].z, books[i].title);
                                printf("Camera pos: x=%f y=%f z=%f\n", gCameraPosition[0], gCameraPosition[1], gCameraPosition[2]);
                                */    
                                if(i == 0){
                                    /* books[0] razmatram posebno zbog toga sto se nalazi na stolu */
                                    if(gCameraPosition[0] > books[i].x+27 && gCameraPosition[0] < books[i].x+33
                                        && gCameraPosition[2] > books[i].z-26 &&  gCameraPosition[2] < books[i].z+13){
                                        createNewWindow(books[i]);
                                    }
                                }
                                else{
                                    if(gCameraPosition[0] > books[i].x-5 && gCameraPosition[0] < books[i].x+25
                                        && gCameraPosition[2] > books[i].z &&  gCameraPosition[2] < books[i].z+33
                                        && gCameraPosition[1] > books[i].y-35 && gCameraPosition[1] < books[i].y+35){
                                        createNewWindow(books[i]);
                                    }
                                }
                

                            }
                            break;
        }
	updateCamera();
}

void createNewWindow(Book book)
{ 
        /* Ovom funkcijom se kreira novi prozor, u event petlji se poziva funkcija displayBook kojom ce 
           biti ispisan tekst iz knjige ciji se naslov prosledjuje kao argument, i na kraju se zatvara taj prozor. */
    
        glfwSetErrorCallback(error_callback);

        if (!glfwInit()) {
            exit(EXIT_FAILURE);
        }
        
        bookWindow = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, book.title, NULL, NULL);
        
        if(!bookWindow){
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        
        while(!glfwWindowShouldClose(bookWindow)){
            displayBook(book.title);
            glfwPollEvents();
        }

        glfwDestroyWindow(bookWindow);
        glfwTerminate();
                                
}

void specialFunc(GLint key, GLint x, GLint y)
{
        /* Ovom funkcijom je realizovano kretanje po prostoriji pomocu strelica */
    
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
