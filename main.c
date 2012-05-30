/* Nama kelompok:
        Elvack Riansyah  10108460
        Rikha Syafitri   10108435
        Anggi Agustina   10108454
        Wildan Ahmad     10108446
*/

#include <stdio.h>
#include <windows.h>	   
#include <GL/gl.h>	
#include <GL/glut.h>

#define KEY_ESCAPE 27

typedef struct {
    int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;
glutWindow win;
float Rotation;

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();
	gluLookAt( 10,3,0, 0,0,0, 0,1,0);

	
	glPushMatrix();	
		glColor3f(0.5,0.3,0);
		glTranslatef(0,0,-3);
		glRotatef(Rotation,0,1,0);
		glRotatef(90,0,1,0);
	    glutWireTeapot(1);
	glPopMatrix();

	glPushMatrix();		
		glColor3f(0.5,0.2,0);
		glTranslatef(0,0,2);
		glRotatef(Rotation,0,1,0);
		glRotatef(90,0,1,0);
	    glutSolidTeapot(2);
	glPopMatrix();	
	
	Rotation++;

	glutSwapBuffers();
}


void initialize () 
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, win.width, win.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat aspect = (GLfloat) win.width / win.height;
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);	
    glMatrixMode(GL_MODELVIEW);	
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );	
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );	

	GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1 };
    GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
    glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
    glEnable( GL_LIGHT0 );
    glEnable( GL_COLOR_MATERIAL );
    glShadeModel( GL_SMOOTH );
    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
    glDepthFunc( GL_LEQUAL );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); 
	glClearColor(0.2, 0, 0.1, 0.4);

}


void keyboard ( unsigned char key, int mousePositionX, int mousePositionY )		
{ 
  switch ( key ) 
  {
    case KEY_ESCAPE:        
      exit ( 0 );   
      break;      

    default:      
      break;
  }
}

int main(int argc, char **argv) 
{
	win.width = 640;
	win.height = 480;
	win.title = "OpenGL/GLUT Window.";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	glutInit(&argc, argv);    
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); 
	glutInitWindowSize(win.width,win.height);	
	glutCreateWindow(win.title);	
	glutDisplayFunc(display);
	glutIdleFunc( display );	
    glutKeyboardFunc( keyboard );
	initialize();
	glutMainLoop();	
	return 0;
}
