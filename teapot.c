#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>
static int window;
static int menu_id;
int diag=1;
static int value = 1;
int c_r=1,c_g=0,c_b=0;

void menu_f(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else if(1<=num&&num<=4){
    value = num;
  }
  else
  {
  	c_r=0;
  	c_g=0;
  	c_b=0;
  	switch(num)
  	{
  		case 8:
  			c_r=1;
  			break;
  		case 5:
  			c_g=1;
  			break;
  		case 6:
  			c_b=1;
  			break;
  		case 7:
  			c_r=1;
  			c_g=1;
  			c_b=1;
  			break;
  		default:
  			c_g=1;
  			c_b=1;
  	}
  }
  glutPostRedisplay();
} 
void createMenu(void){     

	int submenu_id = glutCreateMenu(menu_f);
    
    glutAddMenuEntry("RED", 8);
    glutAddMenuEntry("GREEN", 5);
    glutAddMenuEntry("BLUE", 6);
    glutAddMenuEntry("WHITE", 7);
	
	menu_id = glutCreateMenu(menu_f);
	glutAddMenuEntry("Solid",1);
	glutAddMenuEntry("Wired",2);
	glutAddMenuEntry("Diag. Wired",4);
	glutAddMenuEntry("reset",3);
	glutAddSubMenu("COLOR",submenu_id);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
 
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
} 
 
static void display(void)
{ 
	if(diag=1)
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(c_r,c_g,c_b); 
 	
 	if(value==1)
 	{
 		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    	glPushMatrix();
        glTranslated(0.0, 0.0, -3);
        //glRotated(30, 0.0, -1.0, 0.0);
        glutSolidTeapot(1);
    	glPopMatrix(); 
 	}
 	else if(value==2)
 	{
    	glPushMatrix();
        glTranslated(0.0, 0.0, -3);
        //glRotated(30, 0.0, -1.0, 0.0);
        glutWireTeapot(1);
    	glPopMatrix();
    }
    else if(value==4)
    {
 	if(diag=1)
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    	glPushMatrix();
        glTranslated(0.0, 0.0, -3);
        //glRotated(30, 0.0, -1.0, 0.0);
        glutSolidTeapot(1);
    	glPopMatrix();
    }
    glutSwapBuffers();
} 
 
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
 
/* Program entry point */
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    window=glutCreateWindow("Programming Techniques - 3D Teapots"); 
 
    glutReshapeFunc(resize);
    glutDisplayFunc(display); 
 
    glClearColor(0,0,0,0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 	
 	createMenu();
 	
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
 
    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}
