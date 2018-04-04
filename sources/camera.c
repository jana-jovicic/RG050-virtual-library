/*
Kretanje kamere sam napravila na osnovu koda sa sledeceg linka:
http://www.lighthouse3d.com/tutorials/glut-tutorial/keyboard-example-moving-around-the-world/

Odnosno, odatle sam iskoristila formule za kretanje i ideju kako da ih povezem sa funkcijama iz keyboard.c.
Obradu kolizija na ovako glup nacin sam sama radila. Prvo sam pokusala nekako bolje da uradim, ali onda se sve poremetilo i u nekim pravcima uopste nije moglo da se krece. Zato sam ostavila ovako.
*/
        
#include "../headers/global_variables.h"
#include "../headers/camera.h"
#include "../headers/bookcase.h"

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

        
        /* Obrada kolizije sa prednjom desnom policom za knjige (koja je druga u nizu bookcases[]) */
        if(gCameraPosition[0] > 0 && gCameraPosition[2] > 0)
        {
            /* ako smo sa prednje strane ormana */
            if(gCameraPosition[2] > bookcases[2].z)
            {
                if(gCameraPosition[2] < bookcases[2].z + 20 && gCameraPosition[0] > bookcases[2].x - 65)
                    gCameraPosition[2] = bookcases[2].z + 20;
                else
                    gCameraPosition[2] -= cos(DEG2RAD(gCameraYaw)) * (gMoveForward * 2);
            }
            /* ako smo sa zadnje strane ormana */
            else if(gCameraPosition[2] < bookcases[2].z) 
            {
                if(gCameraPosition[2] > bookcases[2].z - 20  && gCameraPosition[0] > bookcases[2].x - 65)
                    gCameraPosition[2] = bookcases[2].z - 20;
                else
                    gCameraPosition[2] += -cos(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);
            }
        }
        /* Obrada kolizije sa prednjom levom policom za knjige (koja je treca u nizu bookcases[]) */
        else if(gCameraPosition[0] < 0 && gCameraPosition[2] > 0)
        {
            /* ako smo sa prednje strane ormana */
            if(gCameraPosition[2] > bookcases[3].z)
            {
                if(gCameraPosition[2] < bookcases[3].z + 20 && gCameraPosition[0] < bookcases[3].x + 65)
                    gCameraPosition[2] = bookcases[3].z + 20;
                else
                    gCameraPosition[2] -= cos(DEG2RAD(gCameraYaw)) * (gMoveForward * 2);
            }
            /* ako smo sa zadnje strane ormana */
            else if(gCameraPosition[2] < bookcases[2].z) 
            {
                if(gCameraPosition[2] > bookcases[3].z - 20  && gCameraPosition[0] < bookcases[3].x + 65)
                    gCameraPosition[2] = bookcases[3].z - 20;
                else
                    gCameraPosition[2] += -cos(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);
            }
        }
        /* Obrada kolizije sa zadnjom desnom policom za knjige (koja je nulta u nizu bookcases[]) */
        else if(gCameraPosition[0] > 0 && gCameraPosition[2] < 0)
        {
            /* ako smo sa prednje strane ormana */
            if(gCameraPosition[2] > bookcases[0].z)
            {
                if(gCameraPosition[2] < bookcases[0].z + 20 && gCameraPosition[0] > bookcases[0].x - 65)
                    gCameraPosition[2] = bookcases[0].z + 20;
                else
                    gCameraPosition[2] -= cos(DEG2RAD(gCameraYaw)) * (gMoveForward * 2);
            }
            /* ako smo sa zadnje strane ormana */
            else if(gCameraPosition[2] < bookcases[2].z) 
            {
                if(gCameraPosition[2] > bookcases[0].z - 20  && gCameraPosition[0] > bookcases[0].x - 65)
                    gCameraPosition[2] = bookcases[0].z - 20;
                else
                    gCameraPosition[2] += -cos(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);
            }
        }
        /* Obrada kolizije sa zadnjom levom policom za knjige (koja je prva u nizu bookcases[]) i stolom */
        else if(gCameraPosition[0] < 0 && gCameraPosition[2] < 0)
        {
            /* ako smo sa prednje strane ormana */
            if(gCameraPosition[2] > bookcases[1].z)
            {
                if(gCameraPosition[2] < bookcases[1].z + 20 && gCameraPosition[0] < bookcases[1].x + 65)
                    gCameraPosition[2] = bookcases[1].z + 20;
                else
                    gCameraPosition[2] -= cos(DEG2RAD(gCameraYaw)) * (gMoveForward * 2);
            }
            /* ako smo sa zadnje strane ormana */
            else if(gCameraPosition[2] < bookcases[2].z) 
            {
                if(gCameraPosition[2] > bookcases[1].z - 20  && gCameraPosition[0] < bookcases[1].x + 65)
                    gCameraPosition[2] = bookcases[1].z - 20;
                else
                    gCameraPosition[2] += -cos(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);
                /* kolizija sa stolom */ 
                if(gCameraPosition[0] < -80)
                    gCameraPosition[0] = -80;
            }
        }
        
        /* Obrada kolizija sa zidovima */
        
        // desni zid
        if (gCameraPosition[0] > xRange - 5)
            gCameraPosition[0] = xRange - 5;
        else
            gCameraPosition[0] += sin(DEG2RAD(gCameraYaw)) * (gMoveForward * 2);
       
        // prednji zid
        if (gCameraPosition[2] < -zRange + 5)
            gCameraPosition[2] = -zRange + 5;
        else
            gCameraPosition[2] -= cos(DEG2RAD(gCameraYaw)) * (gMoveForward * 2);

        // levi zid
        if (gCameraPosition[0] < -xRange + 5)
            gCameraPosition[0] = -xRange + 5;
        else
            gCameraPosition[0] += sin(DEG2RAD(gCameraYaw + 90)) * (gMoveRightward * 2);
        
        // zadnji zid
        if (gCameraPosition[2] > zRange - 5)
            gCameraPosition[2] = zRange - 5;
        else
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

