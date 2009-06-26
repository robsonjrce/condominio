#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "predio.h"
#define ENTRADA   4
#define ANDAR     2
#define COBERTURA 3
#define PORTA     9

float k, x, y;

typedef GLfloat point3[3];
point3 color[3] = {{0.8,0.5,0.3},{0.6,0.6,0.8},{0.9,0.9,0.9}};

float door = 1.0;

GLfloat emi_normal3[] = {0.0, 0.0, 0.0, 1.0};
GLfloat amb_normal3[] = {0.3, 0.3, 0.3, 1.0};
GLfloat dif_normal3[] = {0.7, 0.7, 0.7, 1.0};
GLfloat spc_normal3[] = {0.5, 0.5, 0.5, 1.0};
GLfloat shi_normal3[] = {60.0};
  
GLfloat emi_branca[] = {0.9, 0.9, 0.9, 0.0};
GLfloat emi_red[]    = {1.0, 0.0, 0.0, 0.0};

void normal(void)
{
   glMaterialfv(GL_FRONT, GL_AMBIENT, amb_normal3);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, dif_normal3);
   glMaterialfv(GL_FRONT, GL_SPECULAR, spc_normal3);
   glMaterialfv(GL_FRONT, GL_SHININESS, shi_normal3);
   glMaterialfv(GL_FRONT, GL_EMISSION, emi_normal3);
}

void luz_branca(void)
{
   glMaterialfv(GL_FRONT, GL_EMISSION, emi_branca);
}

void luz_red(void)
{
   glMaterialfv(GL_FRONT, GL_EMISSION, emi_red);
}

void porta(float a)
{


    glNewList(PORTA, GL_COMPILE);
    glPushMatrix();

    float var1 = 2.5 * a;
    float var2 = 1.25 * a;

        glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(19.5, -1.25, 0.0);
           glVertex3f(19.5, -1.25, 3.0);
           glVertex3f(19.5, -1.25 + var2, 3.0);
           glVertex3f(19.5, -1.25 + var2, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(19.5, -1.25 + var2, 0.0);
           glVertex3f(19.5, -1.25 + var2, 3.0);
           glVertex3f(19.6, -1.25 + var2, 3.0);
           glVertex3f(19.6, -1.25 + var2, 0.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(19.6, -1.25, 0.0);
           glVertex3f(19.6, -1.25, 3.0);
           glVertex3f(19.6, -1.25 + var1, 3.0);
           glVertex3f(19.6, -1.25 + var1, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(19.7, -1.25, 0.0);
           glVertex3f(19.7, -1.25, 3.0);
           glVertex3f(19.7, -1.25 + var1, 3.0);
           glVertex3f(19.7, -1.25 + var1, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(19.6, -1.25 + var1, 0.0);
           glVertex3f(19.6, -1.25 + var1, 3.0);
           glVertex3f(19.7, -1.25 + var1, 3.0);
           glVertex3f(19.7, -1.25 + var1, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(19.8, -1.25, 0.0);
           glVertex3f(19.8, -1.25, 3.0);
           glVertex3f(19.8, -1.25 + var2, 3.0);
           glVertex3f(19.8, -1.25 + var2, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(19.7, -1.25 + var2, 0.0);
           glVertex3f(19.7, -1.25 + var2, 3.0);
           glVertex3f(19.8, -1.25 + var2, 3.0);
           glVertex3f(19.8, -1.25 + var2, 0.0);

        glEnd();

    glPopMatrix();
    glPushMatrix();
    
        glColor3f(0.0,0.0,0.8);

        glTranslatef(19.66, -1.85 + var1, 2.0);        
        glRotatef(90, 0.0, 1.0, 0.0);
        glutSolidTorus(0.05, 0.3, 10, 30);

    glPopMatrix();
    glPushMatrix();
          
        glTranslatef(19.76, -1.85 + var2, 2.0);         
        glRotatef(90, 0.0, 1.0, 0.0);
        glutSolidTorus(0.05, 0.3, 10, 30);
            
    glPopMatrix();
    glEndList();
}

void entrada(int a)
{
    glNewList(ENTRADA, GL_COMPILE);
    glPushMatrix();
    
        glBegin(GL_QUADS);
        glColor3f(0.4,0.0,0.0);

           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);        //PISO
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           
           glColor3f(0.9,0.9,0.9);
           
           glNormal3f(0.0, 0.0, -1.0);
           glVertex3f(35.0, 25.0, 3.8);
           glVertex3f(0.0, 25.0, 3.8);        //TETO
           glVertex3f(0.0, -25.0, 3.8);
           glVertex3f(35.0, -25.0, 3.8);
           
           glColor3f(0.6,0.6,0.6);

           glNormal3f(0.0, 0.0, 1.0);           
           glVertex3f(35.0, 25.0, 4.0);
           glVertex3f(35.0, 21.5, 4.0);
           glVertex3f(37.5, 21.5, 4.0);
           glVertex3f(38.5, 21.5, 4.0);
           
           glNormal3f(0.0, 0.0, 1.0);           
           glVertex3f(35.0, -25.0, 4.0);
           glVertex3f(35.0, -21.5, 4.0);
           glVertex3f(37.5, -21.5, 4.0);
           glVertex3f(38.5, -21.5, 4.0);
        
           glColor3f(1.0,0.8,0.8);
           
           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(20.0, 1.25, 3.0);
           glVertex3f(20.0, 1.25, 4.0);        //PAREDE INTERNA
           glVertex3f(20.0, -1.25, 4.0);
           glVertex3f(20.0, -1.25, 3.0);
           
           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(19.2, 1.25, 3.0);
           glVertex3f(19.2, 1.25, 4.0); 
           glVertex3f(19.2, -1.25, 4.0);
           glVertex3f(19.2, -1.25, 3.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(20.0, 15.0, 0.0);
           glVertex3f(20.0, 15.0, 4.0);
           glVertex3f(20.0, 1.25, 4.0);
           glVertex3f(20.0, 1.25, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(20.0, -15.0, 0.0);
           glVertex3f(20.0, -15.0, 4.0);
           glVertex3f(20.0, -1.25, 4.0);
           glVertex3f(20.0, -1.25, 0.0);
           
           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(19.2, 15.0, 0.0);
           glVertex3f(19.2, 15.0, 4.0);
           glVertex3f(19.2, 1.25, 4.0);
           glVertex3f(19.2, 1.25, 0.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(19.2, -15.0, 0.0);
           glVertex3f(19.2, -15.0, 4.0);
           glVertex3f(19.2, -1.25, 4.0);
           glVertex3f(19.2, -1.25, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(20.0, -1.25, 0.0);
           glVertex3f(20.0, -1.25, 3.0);
           glVertex3f(19.2, -1.25, 3.0);
           glVertex3f(19.2, -1.25, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(20.0, 1.25, 0.0);
           glVertex3f(20.0, 1.25, 3.0);
           glVertex3f(19.2, 1.25, 3.0);
           glVertex3f(19.2, 1.25, 0.0);

           glNormal3f(0.0, 0.0, -1.0);
           glVertex3f(20.0, 1.25, 3.0);
           glVertex3f(20.0, -1.25, 3.0);
           glVertex3f(19.2, -1.25, 3.0);
           glVertex3f(19.2, 1.25, 3.0);
           
           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(2.0, 15.0, 0.0);
           glVertex3f(2.0, 15.0, 4.0);
           glVertex3f(2.0, -15.0, 4.0);
           glVertex3f(2.0, -15.0, 0.0);


           glColor3fv(color[a]);
           
           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);       //LATERAIS E FRENTE COLORIDA
           glVertex3f(0.0, 25.0, 3.9);
           glVertex3f(35.0, 25.0, 3.9);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 3.9);
           glVertex3f(35.0, -25.0, 3.9);
           
           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 4.0);
           glVertex3f(35.0, 15.0, 4.0);
           
           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 4.0);
           glVertex3f(35.0, -15.0, 4.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 3.9);
           glVertex3f(0.0, 25.0, 3.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 3.9);
           glVertex3f(0.0, -25.0, 3.9);
                      
           glNormal3f(1.0, 1.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(35.0, 25.0, 3.9);
           glVertex3f(38.5, 21.5, 3.9);
           glVertex3f(38.5, 21.5, 0.0);

           glNormal3f(1.0, -1.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(35.0, -25.0, 3.9);
           glVertex3f(38.5, -21.5, 3.9);
           glVertex3f(38.5, -21.5, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, 21.5, 0.0);
           glVertex3f(35.0, 21.5, 3.9);
           glVertex3f(38.5, 21.5, 3.9);
           glVertex3f(38.5, 21.5, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, -21.5, 0.0);
           glVertex3f(35.0, -21.5, 3.9);
           glVertex3f(38.5, -21.5, 3.9);
           glVertex3f(38.5, -21.5, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.5, 21.5, 0.0);
           glVertex3f(38.5, 21.5, 3.9);
           glVertex3f(38.5, 15.0, 3.9);
           glVertex3f(38.5, 15.0, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.5, -21.5, 0.0);
           glVertex3f(38.5, -21.5, 3.9);
           glVertex3f(38.5, -15.0, 3.9);
           glVertex3f(38.5, -15.0, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(35.0, 15.0, 3.9);
           glVertex3f(38.5, 15.0, 3.9);
           glVertex3f(38.5, 15.0, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);
           glVertex3f(35.0, -15.0, 3.9);
           glVertex3f(38.5, -15.0, 3.9);
           glVertex3f(38.5, -15.0, 0.0);
           
           glColor3f(0.0,0.0,0.0);

           glNormal3f(0.0, 0.0, 0.0);
           glVertex3f(35.0, 25.0, 3.9);
           glVertex3f(0.0, 25.0, 3.9);           //LINHA PRETA
           glVertex3f(0.0, 25.0, 4.0);
           glVertex3f(35.0, 25.0, 4.0);

           glVertex3f(35.0, -25.0, 3.9);
           glVertex3f(0.0, -25.0, 3.9);
           glVertex3f(0.0, -25.0, 4.0);
           glVertex3f(35.0, -25.0, 4.0);
           
           glVertex3f(35.0, 25.0, 4.0);
           glVertex3f(35.0, 25.0, 3.9);
           glVertex3f(38.5, 21.5, 3.9);
           glVertex3f(38.5, 21.5, 4.0);

           glVertex3f(35.0, -25.0, 4.0);
           glVertex3f(35.0, -25.0, 3.9);
           glVertex3f(38.5, -21.5, 3.9);
           glVertex3f(38.5, -21.5, 4.0);
           
           glVertex3f(0.0, 25.0, 3.9);
           glVertex3f(0.0, -25.0, 3.9);
           glVertex3f(0.0, -25.0, 4.0);
           glVertex3f(0.0, 25.0, 4.0);

           glVertex3f(35.0, 25.0, 3.9);
           glVertex3f(35.0, 24.7, 3.9);
           glVertex3f(35.0, 24.7, 4.0);
           glVertex3f(35.0, 25.0, 4.0);

           glVertex3f(35.0, -25.0, 3.9);
           glVertex3f(35.0, -24.7, 3.9);
           glVertex3f(35.0, -24.7, 4.0);
           glVertex3f(35.0, -25.0, 4.0);

           glVertex3f(35.0, 21.5, 3.9);
           glVertex3f(35.0, 21.5, 4.0);
           glVertex3f(38.5, 21.5, 4.0);
           glVertex3f(38.5, 21.5, 3.9);

           glVertex3f(35.0, -21.5, 3.9);
           glVertex3f(35.0, -21.5, 4.0);
           glVertex3f(38.5, -21.5, 4.0);
           glVertex3f(38.5, -21.5, 3.9);

           glVertex3f(38.5, 21.5, 3.9);
           glVertex3f(38.5, 21.5, 4.0);
           glVertex3f(38.5, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 3.9);

           glVertex3f(38.5, -21.5, 3.9);
           glVertex3f(38.5, -21.5, 4.0);
           glVertex3f(38.5, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 3.9);

           glVertex3f(35.0, 15.0, 3.9);
           glVertex3f(35.0, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 3.9);

           glVertex3f(35.0, -15.0, 3.9);
           glVertex3f(35.0, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 3.9);
           
           glColor3f(0.9,0.9,0.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 5.7, 0.0);
           glVertex3f(0.0, -5.7, 0.0);         //COSTAS
           glVertex3f(0.0, -5.7, 3.9);
           glVertex3f(0.0, 5.7, 3.9);

           glColor3f(0.3,0.3,0.3);
                      
           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 5.7, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 3.9);
           glVertex3f(0.0, 5.7, 3.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, -5.7, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 3.9);
           glVertex3f(0.0, -5.7, 3.9);
           
           glColor3f(0.0,0.0,0.0);

           glVertex3f(-0.04, -0.8, 3.0);
           glVertex3f(-0.04, 0.8, 3.0);        //JANELAS
           glVertex3f(-0.04, 0.8, 3.8);   
           glVertex3f(-0.04, -0.8, 3.8);
           
           glColor3f(0.3,0.3,0.3);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(35.0, 15.0, 3.0);
           glVertex3f(35.0, -15.0, 3.0);       //FRENTE ESCURA
           glVertex3f(35.0, -15.0, 4.0);
           glVertex3f(35.0, 15.0, 4.0);

        
        glEnd();

        luz_branca();
        glColor3f(0.0,0.0,0.0);
        glTranslatef(12.0, 0.0, 3.9);
        glutSolidSphere ( 0.3 , 10 , 10 );
        glTranslatef(13.0, 0.0, 0.0);
        glutSolidSphere ( 0.3 , 10 , 10 );
        normal();

        
    glPopMatrix();
    glPushMatrix();
    
        glColor3f(0.4,0.4,0.4);
        glTranslatef(19.6, 0.0, 3.3);
        glScalef(4.7,1.0,1.0);
        glutSolidCube(0.2);
    
    glPopMatrix();

    porta(door);
    glCallList(PORTA);

    glEndList();
}


void andar(int a, int b)
{
    glNewList(ANDAR, GL_COMPILE);
    glPushMatrix();

        glBegin(GL_QUADS);

           glColor3f(0.8,0.8,0.8);

           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);        //PISO
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);

           glColor3f(0.6,0.6,0.6);

           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);
           glVertex3f(37.5, -15.0, 0.0);
           glVertex3f(37.5, 15.0, 0.0);

           glColor3fv(color[a]);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(20.0, 25.0, 0.0);       //LATERAIS E FRENTE COLORIDA
           glVertex3f(20.0, 25.0, 2.9);
           glVertex3f(35.0, 25.0, 2.9);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(20.0, -25.0, 0.0);
           glVertex3f(20.0, -25.0, 2.9);
           glVertex3f(35.0, -25.0, 2.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 2.9);
           glVertex3f(0.0, 25.0, 2.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 2.9);
           glVertex3f(0.0, -25.0, 2.9);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(35.0, 24.7, 0.0);
           glVertex3f(35.0, 24.7, 2.9);
           glVertex3f(35.0, 25.0, 2.9);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(35.0, -24.7, 0.0);
           glVertex3f(35.0, -24.7, 2.9);
           glVertex3f(35.0, -25.0, 2.9);

           glNormal3f(1.0, 1.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(35.0, 25.0, 1.0);
           glVertex3f(38.5, 21.5, 1.0);
           glVertex3f(38.5, 21.5, 0.0);

           glNormal3f(1.0, -1.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(35.0, -25.0, 1.0);
           glVertex3f(38.5, -21.5, 1.0);
           glVertex3f(38.5, -21.5, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, 21.5, 0.0);
           glVertex3f(35.0, 21.5, 2.9);
           glVertex3f(38.5, 21.5, 2.9);
           glVertex3f(38.5, 21.5, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, -21.5, 0.0);
           glVertex3f(35.0, -21.5, 2.9);
           glVertex3f(38.5, -21.5, 2.9);
           glVertex3f(38.5, -21.5, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.5, 21.5, 0.0);
           glVertex3f(38.5, 21.5, 2.9);
           glVertex3f(38.5, 15.0, 2.9);
           glVertex3f(38.5, 15.0, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.5, -21.5, 0.0);
           glVertex3f(38.5, -21.5, 2.9);
           glVertex3f(38.5, -15.0, 2.9);
           glVertex3f(38.5, -15.0, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(35.0, 15.0, 2.9);
           glVertex3f(38.5, 15.0, 2.9);
           glVertex3f(38.5, 15.0, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);
           glVertex3f(35.0, -15.0, 2.9);
           glVertex3f(38.5, -15.0, 2.9);
           glVertex3f(38.5, -15.0, 0.0);

           glColor3f(0.3,0.3,0.3);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(35.0, 24.7, 0.0);
           glVertex3f(35.0, -24.7, 0.0);          //FRENTE ESCURA
           glVertex3f(35.0, -24.7, 3.0);
           glVertex3f(35.0, 24.7, 3.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(20.0, 25.0, 1.6);          //PARTE ESCURA PERTO DA JANELA
           glVertex3f(0.0, 25.0, 1.6);
           glVertex3f(0.0, 25.0, 2.9);
           glVertex3f(20.0, 25.0, 2.9);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(20.0, -25.0, 1.6);
           glVertex3f(0.0, -25.0, 1.6);
           glVertex3f(0.0, -25.0, 2.9);
           glVertex3f(20.0, -25.0, 2.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 5.7, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 2.9);
           glVertex3f(0.0, 5.7, 2.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, -5.7, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 2.9);
           glVertex3f(0.0, -5.7, 2.9);

           glColor3f(0.2,0.2,0.2);                  //DIVISAO

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, -0.1, 0.0);
           glVertex3f(35.0, -0.1, 3.0);
           glVertex3f(37.45, -0.1, 3.0);
           glVertex3f(37.45, -0.1, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, 0.1, 0.0);
           glVertex3f(35.0, 0.1, 3.0);
           glVertex3f(37.45, 0.1, 3.0);
           glVertex3f(37.45, 0.1, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(37.45, -0.1, 0.0);
           glVertex3f(37.45, -0.1, 3.0);
           glVertex3f(37.45, 0.1, 3.0);
           glVertex3f(37.45, 0.1, 0.0);

           glColor3f(0.0,0.0,0.0);

           glNormal3f(0.0, 0.0, 0.0);
           glVertex3f(35.0, 25.0, 2.9);
           glVertex3f(0.0, 25.0, 2.9);           //LINHA PRETA
           glVertex3f(0.0, 25.0, 3.0);
           glVertex3f(35.0, 25.0, 3.0);

           glVertex3f(35.0, -25.0, 2.9);
           glVertex3f(0.0, -25.0, 2.9);
           glVertex3f(0.0, -25.0, 3.0);
           glVertex3f(35.0, -25.0, 3.0);

           glVertex3f(0.0, 25.0, 2.9);
           glVertex3f(0.0, -25.0, 2.9);
           glVertex3f(0.0, -25.0, 3.0);
           glVertex3f(0.0, 25.0, 3.0);

           glVertex3f(35.0, 25.0, 2.9);
           glVertex3f(35.0, 24.7, 2.9);
           glVertex3f(35.0, 24.7, 3.0);
           glVertex3f(35.0, 25.0, 3.0);

           glVertex3f(35.0, -25.0, 2.9);
           glVertex3f(35.0, -24.7, 2.9);
           glVertex3f(35.0, -24.7, 3.0);
           glVertex3f(35.0, -25.0, 3.0);

           glVertex3f(35.0, 21.5, 2.9);
           glVertex3f(35.0, 21.5, 3.0);
           glVertex3f(38.5, 21.5, 3.0);
           glVertex3f(38.5, 21.5, 2.9);

           glVertex3f(35.0, -21.5, 2.9);
           glVertex3f(35.0, -21.5, 3.0);
           glVertex3f(38.5, -21.5, 3.0);
           glVertex3f(38.5, -21.5, 2.9);

           glVertex3f(38.5, 21.5, 2.9);
           glVertex3f(38.5, 21.5, 3.0);
           glVertex3f(38.5, 15.0, 3.0);
           glVertex3f(38.5, 15.0, 2.9);

           glVertex3f(38.5, -21.5, 2.9);
           glVertex3f(38.5, -21.5, 3.0);
           glVertex3f(38.5, -15.0, 3.0);
           glVertex3f(38.5, -15.0, 2.9);

           glVertex3f(35.0, 15.0, 2.9);
           glVertex3f(35.0, 15.0, 3.0);
           glVertex3f(38.5, 15.0, 3.0);
           glVertex3f(38.5, 15.0, 2.9);

           glVertex3f(35.0, -15.0, 2.9);
           glVertex3f(35.0, -15.0, 3.0);
           glVertex3f(38.5, -15.0, 3.0);
           glVertex3f(38.5, -15.0, 2.9);

           glColor3fv(color[b]);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(20.0, 25.0, 0.0);        //BRANCO EM BAIXO DA JANELA
           glVertex3f(0.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 1.6);
           glVertex3f(20.0, 25.0, 1.6);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(20.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 1.6);
           glVertex3f(20.0, -25.0, 1.6);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(37.5, -15.0, 0.0);
           glVertex3f(37.5, -15.0, 1.0);         //VARANDA
           glVertex3f(37.5, 15.0, 1.0);
           glVertex3f(37.5, 15.0, 0.0);

           glColor3f(0.9,0.9,0.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 5.7, 0.0);
           glVertex3f(0.0, -5.7, 0.0);         //COSTAS
           glVertex3f(0.0, -5.7, 2.9);
           glVertex3f(0.0, 5.7, 2.9);

           glColor3f(0.5,0.5,0.7);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(37.5, -15.0, 1.05);
           glVertex3f(37.5, -15.0, 1.3);      //VIDRO - Varanda
           glVertex3f(37.5, 15.0, 1.3);
           glVertex3f(37.5, 15.0, 1.05);

           glColor3f(0.5,0.5,0.5);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(37.5, -15.0, 1.35);
           glVertex3f(37.5, -15.0, 1.4);
           glVertex3f(37.5, 15.0, 1.4);
           glVertex3f(37.5, 15.0, 1.35);

           glColor3f(0.0,0.0,0.0);

           glNormal3f(0.0, 0.0, 0.0);
           glVertex3f(13.5, 25.04, 1.6);       //JANELAS
           glVertex3f(12.0, 25.04, 1.6);
           glVertex3f(12.0, 25.04, 2.9);
           glVertex3f(13.5, 25.04, 2.9);
           glVertex3f(15.2, 25.04, 1.6);
           glVertex3f(13.6, 25.04, 1.6);
           glVertex3f(13.6, 25.04, 2.9);
           glVertex3f(15.2, 25.04, 2.9);

           glVertex3f(18.0, 25.04, 2.4);
           glVertex3f(17.0, 25.04, 2.4);
           glVertex3f(17.0, 25.04, 2.9);
           glVertex3f(18.0, 25.04, 2.9);
           glVertex3f(19.1, 25.04, 2.4);
           glVertex3f(18.1, 25.04, 2.4);
           glVertex3f(18.1, 25.04, 2.9);
           glVertex3f(19.1, 25.04, 2.9);

           glVertex3f(13.5, -25.04, 1.6);
           glVertex3f(12.0, -25.04, 1.6);
           glVertex3f(12.0, -25.04, 2.9);
           glVertex3f(13.5, -25.04, 2.9);
           glVertex3f(15.2, -25.04, 1.6);
           glVertex3f(13.6, -25.04, 1.6);
           glVertex3f(13.6, -25.04, 2.9);
           glVertex3f(15.2, -25.04, 2.9);

           glVertex3f(18.0, -25.04, 2.4);
           glVertex3f(17.0, -25.04, 2.4);
           glVertex3f(17.0, -25.04, 2.9);
           glVertex3f(18.0, -25.04, 2.9);
           glVertex3f(19.1, -25.04, 2.4);
           glVertex3f(18.1, -25.04, 2.4);
           glVertex3f(18.1, -25.04, 2.9);
           glVertex3f(19.1, -25.04, 2.9);

           glVertex3f(35.04, 24.7, 1.6);
           glVertex3f(35.04, 23.2, 1.6);
           glVertex3f(35.04, 23.2, 2.9);
           glVertex3f(35.04, 24.7, 2.9);
           glVertex3f(35.04, 23.1, 1.6);
           glVertex3f(35.04, 21.6, 1.6);
           glVertex3f(35.04, 21.6, 2.9);
           glVertex3f(35.04, 23.1, 2.9);

           glVertex3f(35.04, -24.7, 1.6);
           glVertex3f(35.04, -23.2, 1.6);
           glVertex3f(35.04, -23.2, 2.9);
           glVertex3f(35.04, -24.7, 2.9);
           glVertex3f(35.04, -23.1, 1.6);
           glVertex3f(35.04, -21.6, 1.6);
           glVertex3f(35.04, -21.6, 2.9);
           glVertex3f(35.04, -23.1, 2.9);

           glVertex3f(35.5, 14.96, 1.6);
           glVertex3f(36.9, 14.96, 1.6);
           glVertex3f(36.9, 14.96, 2.8);
           glVertex3f(35.5, 14.96, 2.8);

           glVertex3f(35.5, -14.96, 1.6);
           glVertex3f(36.9, -14.96, 1.6);
           glVertex3f(36.9, -14.96, 2.8);
           glVertex3f(35.5, -14.96, 2.8);

           glVertex3f(35.04, 2.0, 0.0);
           glVertex3f(35.04, 3.5, 0.0);
           glVertex3f(35.04, 3.5, 2.9);
           glVertex3f(35.04, 2.0, 2.9);
           glVertex3f(35.04, 3.6, 0.0);
           glVertex3f(35.04, 5.1, 0.0);
           glVertex3f(35.04, 5.1, 2.9);
           glVertex3f(35.04, 3.6, 2.9);

           glVertex3f(35.04, 8.0, 1.6);
           glVertex3f(35.04, 10.0, 1.6);
           glVertex3f(35.04, 10.0, 2.9);
           glVertex3f(35.04, 8.0, 2.9);
           glVertex3f(35.04, 10.1, 1.6);
           glVertex3f(35.04, 12.2, 1.6);
           glVertex3f(35.04, 12.2, 2.9);
           glVertex3f(35.04, 10.1, 2.9);

           glVertex3f(35.04, -2.0, 0.0);
           glVertex3f(35.04, -3.5, 0.0);
           glVertex3f(35.04, -3.5, 2.9);
           glVertex3f(35.04, -2.0, 2.9);
           glVertex3f(35.04, -3.6, 0.0);
           glVertex3f(35.04, -5.1, 0.0);
           glVertex3f(35.04, -5.1, 2.9);
           glVertex3f(35.04, -3.6, 2.9);

           glVertex3f(35.04, -8.0, 1.6);
           glVertex3f(35.04, -10.0, 1.6);
           glVertex3f(35.04, -10.0, 2.9);
           glVertex3f(35.04, -8.0, 2.9);
           glVertex3f(35.04, -10.1, 1.6);
           glVertex3f(35.04, -12.2, 1.6);
           glVertex3f(35.04, -12.2, 2.9);
           glVertex3f(35.04, -10.1, 2.9);

           glVertex3f(-0.04, -0.8, 2.0);
           glVertex3f(-0.04, 0.8, 2.0);
           glVertex3f(-0.04, 0.8, 2.8);
           glVertex3f(-0.04, -0.8, 2.8);

           glVertex3f(-0.04, 8.0, 1.6);
           glVertex3f(-0.04, 9.5, 1.6);
           glVertex3f(-0.04, 9.5, 2.2);
           glVertex3f(-0.04, 8.0, 2.2);
           glVertex3f(-0.04, 9.6, 1.6);
           glVertex3f(-0.04, 11.1, 1.6);
           glVertex3f(-0.04, 11.1, 2.2);
           glVertex3f(-0.04, 9.6, 2.2);
           glVertex3f(-0.04, 11.2, 1.6);
           glVertex3f(-0.04, 12.7, 1.6);
           glVertex3f(-0.04, 12.7, 2.2);
           glVertex3f(-0.04, 11.2, 2.2);

           glVertex3f(-0.04, 19.0, 1.6);
           glVertex3f(-0.04, 22.0, 1.6);
           glVertex3f(-0.04, 22.0, 2.9);
           glVertex3f(-0.04, 19.0, 2.9);

           glVertex3f(-0.04, -8.0, 1.6);
           glVertex3f(-0.04, -9.5, 1.6);
           glVertex3f(-0.04, -9.5, 2.2);
           glVertex3f(-0.04, -8.0, 2.2);
           glVertex3f(-0.04, -9.6, 1.6);
           glVertex3f(-0.04, -11.1, 1.6);
           glVertex3f(-0.04, -11.1, 2.2);
           glVertex3f(-0.04, -9.6, 2.2);
           glVertex3f(-0.04, -11.2, 1.6);
           glVertex3f(-0.04, -12.7, 1.6);
           glVertex3f(-0.04, -12.7, 2.2);
           glVertex3f(-0.04, -11.2, 2.2);

           glVertex3f(-0.04, -19.0, 1.6);
           glVertex3f(-0.04, -22.0, 1.6);
           glVertex3f(-0.04, -22.0, 2.9);
           glVertex3f(-0.04, -19.0, 2.9);

        glEnd();

     glPopMatrix();
    glEndList();

}

void cobertura(int a)
{
    glNewList(COBERTURA, GL_COMPILE);
     glPushMatrix();

        glBegin(GL_QUADS);

        glColor3f(0.6,0.6,0.6);

           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);

        glColor3fv(color[a]);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 3.0);
           glVertex3f(35.0, 25.0, 3.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 3.0);
           glVertex3f(35.0, -25.0, 3.0);

           glNormal3f(1.0, 1.0, 0.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(35.0, 25.0, 3.0);
           glVertex3f(38.5, 21.5, 3.35);
           glVertex3f(38.5, 21.5, 0.0);

           glNormal3f(1.0, -1.0, 0.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(35.0, -25.0, 3.0);
           glVertex3f(38.5, -21.5, 3.35);
           glVertex3f(38.5, -21.5, 0.0);

           glNormal3f(0.0, 0.0, -1.0);
           glVertex3f(35.0, 25.0, 0.0);
           glVertex3f(35.0, 21.5, 0.0);
           glVertex3f(38.5, 21.5, 0.0);
           glVertex3f(35.0, 25.0, 0.0);

           glNormal3f(0.0, 0.0, -1.0);
           glVertex3f(35.0, -25.0, 0.0);
           glVertex3f(35.0, -21.5, 0.0);
           glVertex3f(38.5, -21.5, 0.0);
           glVertex3f(35.0, -25.0, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.5, 21.5, 0.0);
           glVertex3f(38.5, 21.5, 3.35);
           glVertex3f(38.5, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.5, -21.5, 0.0);
           glVertex3f(38.5, -21.5, 3.35);
           glVertex3f(38.5, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(35.0, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);
           glVertex3f(35.0, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 0.0);

           glNormal3f(0.0, 0.2, 1.0);
           glVertex3f(35.0, 25.0, 3.0);
           glVertex3f(38.5, 21.5, 3.35);
           glVertex3f(0.0, 21.5, 3.35);
           glVertex3f(0.0, 25.0, 3.0);

           glNormal3f(0.0, -0.2, 1.0);
           glVertex3f(35.0, -25.0, 3.0);
           glVertex3f(38.5, -21.5, 3.35);
           glVertex3f(0.0, -21.5, 3.35);
           glVertex3f(0.0, -25.0, 3.0);

           glNormal3f(0.0, 0.2, 1.0);
           glVertex3f(0.0, 21.5, 3.35);
           glVertex3f(0.0, 15.0, 4.0);
           glVertex3f(38.5, 15.0, 4.0);
           glVertex3f(38.5, 21.5, 3.35);

           glNormal3f(0.0, -0.2, 1.0);
           glVertex3f(0.0, -21.5, 3.35);
           glVertex3f(0.0, -15.0, 4.0);
           glVertex3f(38.5, -15.0, 4.0);
           glVertex3f(38.5, -21.5, 3.35);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 25.0, 0.0);
           glVertex3f(0.0, 25.0, 3.0);
           glVertex3f(0.0, 15.0, 4.0);
           glVertex3f(0.0, 15.0, 0.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, -25.0, 0.0);
           glVertex3f(0.0, -25.0, 3.0);
           glVertex3f(0.0, -15.0, 4.0);
           glVertex3f(0.0, -15.0, 0.0);

           glEnd();


           glColor3f(0.9, 0.9, 0.2);
           for (k=0.0; k<3.0; k++) {

           glBegin(GL_QUADS);

           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(35.0, -15.0, k);
           glVertex3f(38.0, -15.0, k);
           glVertex3f(38.0, 15.0, k);
           glVertex3f(35.0, 15.0, k);


           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(35.0, -15.0, k+0.2);
           glVertex3f(38.0, -15.0, k+0.2);
           glVertex3f(38.0, 15.0, k+0.2);
           glVertex3f(35.0, 15.0, k+0.2);


           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(38.0, -15.0, k);
           glVertex3f(38.0, -15.0, k+0.2);
           glVertex3f(38.0, 15.0, k+0.2);
           glVertex3f(38.0, 15.0, k);

           glEnd();
           }

           glBegin(GL_QUADS);

           glColor3f(0.3,0.3,0.3);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(35.0, 15.0, 2.2);
           glVertex3f(35.0, -15.0, 2.2);
           glVertex3f(35.0, -15.0, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(35.01, 15.0, 0.0);
           glVertex3f(35.01, 15.0, 2.2);
           glVertex3f(35.01, -15.0, 2.2);
           glVertex3f(35.01, -15.0, 0.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(35.0, 15.0, 0.0);
           glVertex3f(35.0, 15.0, 4.0);
           glVertex3f(0.0, 15.0, 4.0);
           glVertex3f(0.0, 15.0, 0.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(35.0, -15.0, 0.0);
           glVertex3f(35.0, -15.0, 4.0);
           glVertex3f(0.0, -15.0, 4.0);
           glVertex3f(0.0, -15.0, 0.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 15.0, 0.0);
           glVertex3f(0.0, 15.0, 4.0);
           glVertex3f(0.0, 5.7, 4.0);
           glVertex3f(0.0, 5.7, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(0.01, 15.0, 0.0);
           glVertex3f(0.01, 15.0, 4.0);
           glVertex3f(0.01, 5.7, 4.0);
           glVertex3f(0.01, 5.7, 0.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, -15.0, 0.0);
           glVertex3f(0.0, -15.0, 4.0);
           glVertex3f(0.0, -5.7, 4.0);
           glVertex3f(0.0, -5.7, 0.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(0.01, -15.0, 0.0);
           glVertex3f(0.01, -15.0, 4.0);
           glVertex3f(0.01, -5.7, 4.0);
           glVertex3f(0.01, -5.7, 0.0);

           glColor3f(0.9,0.9,0.9);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(0.0, 5.7, 0.0);
           glVertex3f(0.0, -5.7, 0.0);
           glVertex3f(0.0, -5.7, 10.0);
           glVertex3f(0.0, 5.7, 10.0);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(15.0, 5.7, 0.0);
           glVertex3f(15.0, -5.7, 0.0);
           glVertex3f(15.0, -5.7, 10.0);
           glVertex3f(15.0, 5.7, 10.0);

           glNormal3f(0.0, 1.0, 0.0);
           glVertex3f(15.0, 5.7, 0.0);
           glVertex3f(0.0, 5.7, 0.0);
           glVertex3f(0.0, 5.7, 10.0);
           glVertex3f(15.0, 5.7, 10.0);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(15.0, -5.7, 0.0);
           glVertex3f(0.0, -5.7, 0.0);
           glVertex3f(0.0, -5.7, 10.0);
           glVertex3f(15.0, -5.7, 10.0);

           glNormal3f(0.0, 0.0, 1.0);
           glVertex3f(15.0, -5.7, 10.0);
           glVertex3f(0.0, -5.7, 10.0);
           glVertex3f(0.0, 5.7, 10.0);
           glVertex3f(15.0, 5.7, 10.0);

           glColor3f(0.0,0.0,0.0);

           glNormal3f(-1.0, 0.0, 0.0);
           glVertex3f(-0.04, -0.8, 2.0);
           glVertex3f(-0.04, 0.8, 2.0);
           glVertex3f(-0.04, 0.8, 2.8);
           glVertex3f(-0.04, -0.8, 2.8);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(15.04, 0.0, 0.0);
           glVertex3f(15.04, -1.5, 0.0);
           glVertex3f(15.04, -1.5, 2.9);
           glVertex3f(15.04, 0.0, 2.9);
           glVertex3f(15.04, -1.6, 0.0);
           glVertex3f(15.04, -3.1, 0.0);
           glVertex3f(15.04, -3.1, 2.9);
           glVertex3f(15.04, -1.6, 2.9);

           glNormal3f(1.0, 0.0, 0.0);
           glVertex3f(7.5, 0.05, 10.0);
           glVertex3f(7.5, 0.05, 14.0);
           glVertex3f(7.5, -0.05, 14.0);
           glVertex3f(7.5, -0.05, 10.0);

        glEnd();

        glBegin(GL_QUAD_STRIP);

        glColor3f(0.0,0.0,0.0);

           glVertex3f(-0.03, 5.73, 4.0);
           glVertex3f(-0.03, 5.73, 4.1);

           glVertex3f(-0.03, -5.73, 4.0);
           glVertex3f(-0.03, -5.73, 4.1);

           glVertex3f(15.03, -5.73, 4.0);
           glVertex3f(15.03, -5.73, 4.1);

           glVertex3f(15.03, 5.73, 4.0);
           glVertex3f(15.03, 5.73, 4.1);

           glVertex3f(-0.03, 5.73, 4.0);
           glVertex3f(-0.03, 5.73, 4.1);

        glEnd();

        glBegin(GL_QUAD_STRIP);

           glVertex3f(-0.03, 5.73, 8.0);
           glVertex3f(-0.03, 5.73, 8.1);

           glVertex3f(-0.03, -5.73, 8.0);
           glVertex3f(-0.03, -5.73, 8.1);

           glVertex3f(15.03, -5.73, 8.0);
           glVertex3f(15.03, -5.73, 8.1);

           glVertex3f(15.03, 5.73, 8.0);
           glVertex3f(15.03, 5.73, 8.1);

           glVertex3f(-0.03, 5.73, 8.0);
           glVertex3f(-0.03, 5.73, 8.1);

        glEnd();

        luz_red();
        glColor3f(0.0,0.0,0.0);
        glTranslatef(7.5, 0.0, 14.0);
        glutSolidSphere ( 0.3 , 10 , 10 );
        normal();

     glPopMatrix();
    glEndList();
}


void fechar (int value)
{
   if (door < 1.0) {
   door = door + 0.015625;
   glutTimerFunc(10, fechar, 1);
   glutPostRedisplay();
   }
}

void abrir(int value)
{
   if (door > 0.0625) {
   door = door - 0.015625;
   glutPostRedisplay();
   glutTimerFunc (10, abrir, 1);
   }   
}
