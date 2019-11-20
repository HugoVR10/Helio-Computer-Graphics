//
// Autor:       
// Creado:      
// Proyecto:    
// Descripción:	
//              
// 
// Controles:    Flecha izquierda: rotar a la izquierda
//               Flecha derecha: rotar a la derecha  
//               Flecha hacia arriba: rotar hacia arriba    
//               Flecha hacia abajo: rotar hacia abajo    

// ----------------------------------------------------------
// Librerías
// ----------------------------------------------------------
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// ----------------------------------------------------------
// Prototipos de función
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Variables globales
// ----------------------------------------------------------
double rotate_y = 0;
double rotate_x = 0;

void illumination() {
	// RGB Luz Halogeno 255, 241, 224
	// RGB Luz Solar 255, 255, 251

	GLfloat diffuseMaterial[4] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

// ----------------------------------------------------------
// Función de retrollamada “display()”
// ----------------------------------------------------------
void display() {

	//  Borrar pantalla y Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Resetear transformaciones
	glLoadIdentity();

	// Rotar cuando el usuario cambie “rotate_x” y “rotate_y”
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// ----------------------------------------------------------
	// Seccion I
	// ----------------------------------------------------------
	//glViewport(0, 200, 400, 200);

	glColorMaterial(GL_FRONT, GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);
	
	glColor3f(1.0, 0.601, 0.153);    glVertex3f( -0.8125, -0.50, -0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f( -0.8125,  0.50, -0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f( -0.9375,  0.50, -0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f( -0.9375, -0.50, -0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.5625,  0.50, -0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.5625,  0.25, -0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.6875,  0.25, -0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.6875,  0.50, -0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.5625, -0.25, 0.0);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.5625,  0.0, 0.0);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.6875,  0.0, 0.0);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.6875, -0.25, 0.0);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.5625, 0.50, 0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.5625, 0.0,  0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.6875, 0.0,  0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.6875, 0.50, 0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.8125, -0.50, -0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.8125, -0.25, -0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.8125, -0.25,  0.0);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.8125, -0.50,  0.0);      
	
	glColor3f(1.0, 0.563, 0.0);   glVertex3f(-0.6875, 0.50, -0.25);
	glColor3f(1.0, 0.390, 0.0);      glVertex3f(-0.6875, 0.25, -0.25);
	glColor3f(1.0, 0.601, 0.153);      glVertex3f(-0.6875, 0.25, 0.0);
	glColor3f(1.0, 0.627, 0.0);      glVertex3f(-0.6875, 0.50, 0.0);
	
	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-1.0, -0.25, -0.125);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-1.0, -0.00, -0.125);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-1.0, -0.00, 0.5);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-1.0, -0.25, 0.5);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.5625, 0.25, -0.25);     
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.5625, 0.00, -0.25);    
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.5625, 0.00, 0.0);       
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.5625, 0.25, 0.0);       

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.5625, 0.50, 0.25);     
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.5625, 0.00, 0.25);    
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.5625, 0.00, 0.375);       
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.5625, 0.50, 0.375);       
	
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.5625, 0.0, 0.0);     
	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.5625, -0.25, 0.0);    
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.5625, -0.25, 0.125);       
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.5625, 0.0, 0.125);       
																         
	glEnd();

	// ----------------------------------------------------------
	// Seccion II
	// ----------------------------------------------------------

	glColorMaterial(GL_FRONT, GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.500,  0.00, -0.125);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.500,  0.25, -0.125);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.375,  0.25, -0.125);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.375,  0.00, -0.125);      

	glColor3f(1.0, 0.563, 0.0);    glVertex3f(-0.500, 0.00, -0.00);      
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.500, 0.25, -0.00);     
	glColor3f(1.0, 0.627, 0.0);    glVertex3f(-0.375, 0.25, -0.00);      
	glColor3f(1.0, 0.601, 0.153);     glVertex3f(-0.375, 0.00, -0.00);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.500, 0.00, -0.125);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.500, 0.25, -0.125);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.500, 0.25, -0.00);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.500, 0.00, -0.00);      

	glColor3f(1.0, 0.563, 0.0);      glVertex3f(-0.375, 0.00, -0.125);      
	glColor3f(1.0, 0.390, 0.0);      glVertex3f(-0.375, 0.25, -0.125);     
	glColor3f(1.0, 0.627, 0.0);      glVertex3f(-0.375, 0.25, -0.00);      
	glColor3f(1.0, 0.601, 0.153);     glVertex3f(-0.375, 0.00, -0.00);      


	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.375, -0.25, -0.0);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.375, -0.50, -0.0);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(-0.250, -0.50, -0.0);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(-0.250, -0.25, -0.0);      

	glColor3f(1.0, 0.563, 0.0);      glVertex3f(-0.375, -0.25,  0.25);      
	glColor3f(1.0, 0.390, 0.0);      glVertex3f(-0.375, -0.50,  0.25);     
	glColor3f(1.0, 0.627, 0.0);      glVertex3f(-0.375, -0.50, -0.00);      
	glColor3f(1.0, 0.601, 0.153);     glVertex3f(-0.375, -0.25, -0.00);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.00, -0.25, 0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.00, -0.50, 0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.25, -0.50, 0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.25, -0.25, 0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(-0.125, 0.00, -0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(-0.125, 0.50, -0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.25,  0.50, -0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.25, 0.00, -0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.125, 0.50, 0.0);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.125, -0.50, 0.0);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.25, -0.50,  0.0);    
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.25, 0.50,  0.0);    

	glColor3f(1.0, 0.563, 0.0);      glVertex3f(0.25, 0.00, -0.00);      
	glColor3f(1.0, 0.390, 0.0);      glVertex3f(0.25, -0.25, -0.00);     
	glColor3f(1.0, 0.627, 0.0);      glVertex3f(0.25, -0.25, 0.25);      
	glColor3f(1.0, 0.601, 0.153);     glVertex3f(0.25, 0.00, 0.25);      

	glColor3f(1.0, 0.563, 0.0);      glVertex3f(-0.25, 0.00, -0.00);      
	glColor3f(1.0, 0.390, 0.0);      glVertex3f(-0.25, -0.25, -0.00);     
	glColor3f(1.0, 0.627, 0.0);      glVertex3f(-0.25, -0.25, -0.25);      
	glColor3f(1.0, 0.601, 0.153);     glVertex3f(-0.25, 0.00, -0.25);      
											 

	glEnd();

	// ----------------------------------------------------------
	// Seccion III
	// ----------------------------------------------------------

	glColorMaterial(GL_FRONT, GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.9375, -0.50, -0.5);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.9375, -0.25, -0.5);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.9375, -0.25,  0.125);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.9375, -0.50,  0.125);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.9375, -0.25, 0.125);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.9375, -0.00, 0.125);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.9375, -0.00, 0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.9375, -0.25, 0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.9375, -0.25,  -0.5);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.9375, -0.00, -0.5);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.9375, -0.00, -0.375);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.9375, -0.25, -0.375);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.5, -0.50, -0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.5, -0.25, -0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.5, -0.25,  0.0);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.5, -0.50,  0.0);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.5, -0.25, -0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.5, -0.00, -0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.5, -0.00, -0.125);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.5, -0.25, -0.125);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.5, 0.0,  -0.5);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.5, 0.25, -0.5);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.5, 0.25,  0.125);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.5, 0.0,   0.125);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.5, -0.25, 0.0);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.5, -0.00, 0.0);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.5, -0.00, 0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.5, -0.25, 0.25);      

	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.8125, -0.50, 0.25);      
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.8125, -0.00,  0.25);     
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.9375, -0.00,  0.25);      
	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.9375, -0.50, 0.25);      

	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.8125, -0.50, 0.125);      
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.8125, -0.00, 0.125);     
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.9375, -0.00, 0.125);      
	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.9375, -0.50, 0.125);      

	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.8125, -0.25, -0.5);      
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.8125, -0.00, -0.5);     
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.9375, -0.00, -0.5);      
	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.9375, -0.25, -0.5);      

	glColor3f(1.0, 0.563, 0.0);     glVertex3f(0.5, 0.00, -0.5);      
	glColor3f(1.0, 0.390, 0.0);     glVertex3f(0.5, 0.25, -0.5);     
	glColor3f(1.0, 0.627, 0.0);     glVertex3f(0.8125, 0.25, -0.5);      
	glColor3f(1.0, 0.601, 0.153);    glVertex3f(0.8125, 0.00, -0.5);      

	glEnd();


	


	// ----------------------------------------------------------
	// Bases
	// ----------------------------------------------------------

	glColorMaterial(GL_FRONT, GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);

	// PISO
	glColor3f(1.0, 0.0, 0.0);

	glVertex3f( 0.5, -0.70, -0.75);
	glVertex3f( 0.5, -0.70, -0.25);
	glVertex3f(-1.0 , -0.70, -0.25);
	glVertex3f(-1.0 , -0.70, -0.75);

	glVertex3f(1.0, -0.70, -0.75);
	glVertex3f(1.0, -0.70, -0.50);
	glVertex3f(0.5, -0.70, -0.50);
	glVertex3f(0.5, -0.70, -0.75);

	glVertex3f(-1.0, -0.70, 0.75);
	glVertex3f(-1.0, -0.70, 0.50);
	glVertex3f(-0.5, -0.70, 0.50);
	glVertex3f(-0.5, -0.70, 0.75);

	glVertex3f(-0.5, -0.70,  0.75);
	glVertex3f(-0.5, -0.70,  0.25);
	glVertex3f(1.0, -0.70, 0.25);
	glVertex3f(1.0, -0.70, 0.75);

	glVertex3f(-1.0, -0.70,  0.75);
	glVertex3f(-1.0, -0.70, -0.75);
	glVertex3f(-1.25, -0.70,-0.75);
	glVertex3f(-1.25, -0.70, 0.75);

	glVertex3f(1.0, -0.70, 0.75);
	glVertex3f(1.0, -0.70, -0.75);
	glVertex3f(1.25, -0.70, -0.75);
	glVertex3f(1.25, -0.70, 0.75);

	//SECCION 1
	glColor3f(0.354, 1.0, 0.109);
	glVertex3f(-1.0,  -0.75, -0.25);
	glVertex3f(-1.0,  -0.75,  0.5 );
	glVertex3f(-0.5,  -0.75,  0.5 );
	glVertex3f(-0.5,  -0.75, -0.25);

	//SECCION 2
	glColor3f(0.354, 1.0, 0.109);
	glVertex3f(1.0, -0.75, -0.5);
	glVertex3f(1.0, -0.75,  0.25);
	glVertex3f(0.5, -0.75,  0.25);
	glVertex3f(0.5, -0.75, -0.5);

	//SECCION 3
	glColor3f(0.354, 1.0, 0.109);
	glVertex3f(-0.5, -0.75, -0.25);
	glVertex3f(-0.5, -0.75, 0.25);
	glVertex3f(0.5,  -0.75, 0.25);
	glVertex3f(0.5,  -0.75, -0.25);

	// ----------------------------------------------------------
	// Seccion I
	// ----------------------------------------------------------
	glColor3f(0.354, 0.229, 0.109); //139,90,43

	glVertex3f(-1.0, -0.75, -0.25);
	glVertex3f(-1.0, -0.75,  0.50);
	glVertex3f(-1.0, -0.70, 0.50);
	glVertex3f(-1.0, -0.70, -0.25);

	glVertex3f(-0.5, -0.75, 0.25);
	glVertex3f(-0.5, -0.75, 0.50);
	glVertex3f(-0.5, -0.70, 0.50);
	glVertex3f(-0.5, -0.70, 0.25);

	glVertex3f(-0.5, -0.75, 0.50);
	glVertex3f(-1.0, -0.75, 0.50);
	glVertex3f(-1.0, -0.70, 0.50);
	glVertex3f(-0.5, -0.70, 0.50);

	glVertex3f(0.5, -0.75,  -0.25);
	glVertex3f(-1.0, -0.75, -0.25);
	glVertex3f(-1.0, -0.70, -0.25);
	glVertex3f(0.5, -0.70,  -0.25);

	glVertex3f(1.0, -0.75,  0.25);
	glVertex3f(-0.5, -0.75, 0.25);
	glVertex3f(-0.5, -0.70, 0.25);
	glVertex3f(1.0, -0.70,  0.25);

	glVertex3f(1.0, -0.75, -0.50);
	glVertex3f(1.0, -0.75,  0.25);
	glVertex3f(1.0, -0.70,  0.25);
	glVertex3f(1.0, -0.70, -0.50);

	glVertex3f(0.5, -0.75, -0.50);
	glVertex3f(0.5, -0.75, -0.25);
	glVertex3f(0.5, -0.70, -0.25);
	glVertex3f(0.5, -0.70, -0.50);

	glVertex3f(1.0, -0.75,  -0.50);
	glVertex3f(0.5, -0.75, -0.50);
	glVertex3f(0.5, -0.70, -0.50);
	glVertex3f(1.0, -0.70,  -0.50);

	glEnd();

	//glViewport(0, 0, 400, 200);

	// Cubo Rectangular transparente
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(-0.125, -0.25, 0.0);
	glColor4f(1.0, 1.0, 1.0, 0.4);
	glutSolidCube(0.25);
	glDisable(GL_BLEND);



	glFlush();
	glutSwapBuffers();

}

// ----------------------------------------------------------
// Función de retrollamada “specialKeys()” 
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {

	//  Flecha derecha: aumentar rotación 5 grados
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
		

	//  Flecha izquierda: disminuir rotación 5 grados
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	//  Solicitar actualización de visualización
	glutPostRedisplay();

}

// ----------------------------------------------------------
// Función “main()”
// ----------------------------------------------------------
int main(int argc, char* argv[]) {

	//  Inicializar los parámetros GLUT y de usuario proceso
	glutInit(&argc, argv);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, 1200, 600, 0.0f, 0.0f, 1.0f);

	//  Solicitar ventana con color real y doble buffer con Z-buffer 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Crear ventana
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Helio Oiticica");
	
	// Habilita la iluminación en la escena
	illumination();

	//  Habilitar la prueba de profundidad de Z-buffer
	glEnable(GL_DEPTH_TEST);

	// Funciones de retrollamada
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	//  Pasar el control de eventos a GLUT
	glutMainLoop();

	//  Regresar al sistema operativo
	return 0;

}