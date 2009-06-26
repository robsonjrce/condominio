//    MARCELO DE BRITO SOARES ALMEIDA - 0262417
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "predio.h"
#include "codigo.h"
#define PI        3.141592
#define PISCINA   1
#define ANDAR     2
#define COBERTURA 3
#define ENTRADA   4
#define PISO      5
#define MURO      6
#define QUADRA    7
#define CUBO      8
#define PORTA     9
#define POSTE    10

int i;
int aux, luz = 0;
float j, ex2, var;
GLfloat angle, ang, fAspect, eyex, eyey, eyez, atx, aty, atz, upx, upy, upz;

   GLfloat emi_normal[] = {0.0, 0.0, 0.0, 1.0};
   GLfloat amb_normal1[] = {0.0, 0.0, 0.0, 0.0};    
   GLfloat dif_normal1[] = {0.7, 0.7, 0.7, 1.0};
   GLfloat spc_normal1[] = {0.5, 0.5, 0.5, 1.0};
   GLfloat shi_normal[] = {60.0};

   GLfloat amb_normal2[] = {0.0, 0.0, 0.0, 0.0}; 
   GLfloat dif_normal2[] = {0.0, 0.0, 0.0, 0.0};
   GLfloat spc_normal2[] = {0.0, 0.0, 0.0, 1.0};

   GLfloat emi_sol[] = {0.9, 0.9, 0.2, 0.0};
   
 
float ex = atx - eyex;
float ey = aty - eyey;

void sol(void)
{
   glMaterialfv(GL_FRONT, GL_EMISSION, emi_sol);
}

void poste(void)
{
    glNewList(POSTE, GL_COMPILE);
      glPushMatrix();
      
        glColor3f(0.4, 0.4, 0.4);      
        glTranslatef(0.0, 0.0, 3.5);
        glRotatef(180, 0.0, 1.0, 0.0);
        glutSolidCone(0.1, 40, 10, 10);
    
      glPopMatrix();      
      glPushMatrix();
        if(luz==0)
            normal();
        else
            luz_branca();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef( 0.0, 0.0, 3.5);        
        glutSolidSphere(0.45, 20, 20);
        if(luz==1)
            normal();
      glPopMatrix();
    glEndList();
}

void visao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(angle, fAspect, 0.4, 1000);
    gluLookAt(eyex,eyey,eyez, atx,aty,atz, upx,upy,upz);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	visao();
}

void Iluminacao(void)
{

	GLfloat posicaoLuz1[4]   = {110.0, 80.0, 300.0, 0.0};
    GLfloat posicaoLuz2[4]   = {50.0, 66.0, 3.8, 1.0};
    GLfloat posicaoLuz3[4]   = {150.0, 66.0, 3.8, 1.0};


	if (luz==0) {
        glClearColor(0.6f, 0.6f, 1.0f, 1.0f);
        emi_sol[0] = 0.9;    amb_normal1[0] =  0.30;       amb_normal2[0] = 0.0;     dif_normal2[0] = 0.0;
        emi_sol[1] = 0.9;    amb_normal1[1] =  0.30;       amb_normal2[1] = 0.0;     dif_normal2[1] = 0.0;
        emi_sol[2] = 0.2;    amb_normal1[2] =  0.30;       amb_normal2[2] = 0.0;     dif_normal2[2] = 0.0;
        emi_sol[3] = 0.0;    amb_normal1[3] =  1.00;       amb_normal2[3] = 1.0;     dif_normal2[3] = 1.0;
        }
    else {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        emi_sol[0] = 0.45;   amb_normal1[0] =  0.1;       amb_normal2[0] = 0.15;     dif_normal2[0] = 0.3;
        emi_sol[1] = 0.45;   amb_normal1[1] =  0.1;       amb_normal2[1] = 0.15;     dif_normal2[1] = 0.3;
        emi_sol[2] = 0.45;   amb_normal1[2] =  0.1;       amb_normal2[2] = 0.15;     dif_normal2[2] = 0.3;
        emi_sol[3] = 0.0;    amb_normal1[3] =  1.0;       amb_normal2[3] = 1.0;      dif_normal2[3] = 0.3;
        }
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT, GL_SPECULAR, spc_normal1);
	// Define a concentração do brilho
	glMaterialfv(GL_FRONT,GL_SHININESS,shi_normal);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_normal1);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb_normal1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif_normal1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spc_normal1);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz1);

    glLightfv(GL_LIGHT1, GL_AMBIENT, amb_normal2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif_normal2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spc_normal2);
	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz2);

    glLightfv(GL_LIGHT2, GL_AMBIENT, amb_normal2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, dif_normal2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spc_normal2);
	glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz3);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  

	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

}

// Função callback chamada para fazer o desenho
void Desenha(void)
{   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    visao();

    glCallList(PISO);
    glCallList(MURO);

    glTranslatef(50.0,95.0,0.1);
    glRotatef(-90.0,0.0,0.0,1.0);

    entrada(1);
    glCallList(ENTRADA);
    glTranslatef(0.0,0.0,4.0);
    
    andar(1,2);
    for (i = 1; i<20; i++) {
    if (i==17)
    andar(1,1);
    glCallList(ANDAR);
    glTranslatef(0.0,0.0,3.0);
    }
    cobertura(1);
    glCallList(COBERTURA);
    glLoadIdentity();

    glTranslatef(150.0,95.0,0.1);
    glRotatef(-90.0,0.0,0.0,1.0);
    
    entrada(0);
    glCallList(ENTRADA);
    glTranslatef(0.0,0.0,4.0);

    andar(0,2);
    for (i = 1; i<20; i++) {
    if(i==17)
    andar(0,0);
    glCallList(ANDAR);
    glTranslatef(0.0,0.0,3.0);
    }
    cobertura(0);
    glCallList(COBERTURA);
    glLoadIdentity();

    glTranslatef(40.0,20.0,0.1);
    glCallList(PISCINA);
    glLoadIdentity();

    glTranslatef(120.0,10.0,0.1);
    glCallList(QUADRA);
    glLoadIdentity();
    
    poste();
    glTranslatef(85.0,55.0,0.0);
    glCallList(POSTE);
    glTranslatef(30.0,0.0,0.0);
    glCallList(POSTE);
    glLoadIdentity();

    sol();
    glColor3f(0.6, 0.6, 0.6);
    glTranslatef(250.0, 80.0, 800.0);
    glutSolidSphere ( 20, 25, 25);
    
    normal();
    
    glLoadIdentity();
            
    glutSwapBuffers();

}

void Inicializa (void)
{
    printf("                      Controls\n\n                   Up Arrow    -> Move Forward\n                   Down Arrow  -> Move Backward\n                   Left Arrow  -> Turn Left\n                   Right Arrow -> Turn Right\n                   Page Up     -> Look Up\n                   Page Down   -> Look Down\n                   End         -> Center View\n                   N           -> Turn Day/Night\n                   O           -> Fly\n                   L           -> Back to the floor\n");
    angle = 60;
    ang = PI/2.0;

    eyex  = 100.0;
    eyey  = 5.0;
    eyez  = 1.75;

    atx = eyex;
    aty = eyey + 5;
    atz = eyez;

    upx = 0.0;
    upy = 0.0;
    upz = 1.0;

    glNewList(MURO, GL_COMPILE);
    glPushMatrix();

    glColor3f(0.8, 0.0, 0.0);

       glTranslatef(0.0,0.0,0.0);
       glScalef(90.0,0.3,50.0);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(110.0,0.0,0.0);
       glScalef(90.0,0.3,50.0);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(199.7,0.0,0.0);
       glScalef(0.3,120.0,50.0);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(0.0,119.7,0.0);
       glScalef(199.7,0.3,50.0);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(0.0,0.0,0.0);
       glScalef(0.3,120.0,50.0);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();

        glColor3f(0.0,0.0,0.8);

        glTranslatef(100.0,0.0,0.0);
        glRotatef(90,1.0,0.0,0.0);

        glutSolidTorus(0.7,10,50,50);

        glColor3f(0.9,0.9,0.2);
        glutSolidTorus(0.3,8.5,50,50);

        glColor3f(0.9,0.9,0.9);
        glTranslatef(0.0,-3.0,0.0);
        glutSolidTorus(0.3,8.0,50,50);

     glPopMatrix();

     glPushMatrix();

     glTranslatef(94.0,0.0,0.0);
     glutSolidCone(0.1,2.5,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,3.5,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,4.2,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,4.7,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,5.0,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,5.2,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,5.3,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,5.2,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,5.0,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,4.7,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,4.2,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,3.5,10,10);

     glTranslatef(1.0,0.0,0.0);
     glutSolidCone(0.1,2.5,10,10);


     glPopMatrix();
    glEndList();

    glNewList(PISO, GL_COMPILE);
    glPushMatrix();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);

        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(200.0,0.0,0.0);
        glVertex3f(200.0,120.0,0.0);
        glVertex3f(0.0,120.0,0.0);

        glColor3f(0.2, 0.2, 0.2);

        glVertex3f(-2000.0,-2000.0,-0.03);
        glVertex3f(2000.0,-2000.0,-0.03);
        glVertex3f(2000.0,2000.0,-0.03);
        glVertex3f(-2000.0,2000.0,-0.03);

    glEnd();

    glPopMatrix();
    glEndList();

    glNewList(PISCINA, GL_COMPILE);

    glColor3f(0.8,0.7,0.1);

     glPushMatrix();
       glTranslatef(-26.0,10.0,0.0);
       glScalef(51.0,1.0,1.5);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(-26.0,-11.0,0.0);
       glScalef(51.0,1.0,1.5);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(-26.0,-10.0,0.0);
       glScalef(1.0,20.0,1.5);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glTranslatef(25.0,-11.0,0.0);
       glScalef(1.0,22.0,1.5);
       glCallList(CUBO);
     glPopMatrix();

     glPushMatrix();
       glColor3f(0.5,0.5,1.0);
       glBegin(GL_QUADS);

          glNormal3f(0.0, 0.0, 1.0);
          glVertex3f(-25.0, -10.0, 0.0);
          glVertex3f(25.0, -10.0, 0.0);
          glVertex3f(25.0, 10.0, 0.0);
          glVertex3f(-25.0, 10.0, 0.0);
          
       glEnd();
     glPopMatrix();

    glEndList();


    glNewList(CUBO, GL_COMPILE);
     glPushMatrix();

          glTranslatef(0.5,0.5,0.0);
          glScalef(10.0,10.0,1.0);
          glutSolidCube(0.1);

     glPopMatrix();
    glEndList();

    glNewList(QUADRA, GL_COMPILE);
     glPushMatrix();

       glBegin(GL_QUADS);

          glColor3f(0.3,0.6,0.3);

          glNormal3f(0.0, 0.0, 1.0);
          glVertex3f(0.0, 0.0, 0.03);
          glVertex3f(50.0, 0.0, 0.03);
          glVertex3f(50.0, 20.0, 0.03);
          glVertex3f(0.0, 20.0, 0.03);

          glColor3f(1.0, 1.0, 1.0);

          glNormal3f(0.0, 0.0, 1.0);
          glVertex3f(25.0, 0.0, 0.06);
          glVertex3f(25.0, 20.0, 0.06);
          glVertex3f(25.1, 20.0, 0.06);
          glVertex3f(25.1, 0.0, 0.06);

       glEnd();

     glPopMatrix();
    glEndList();
    
}    

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla) {
    case 27:
        exit(0);
    break;    
    case 'O':
    case 'o':
        eyez  = 74;
        atz   = 74;
    break;   
    case 'L':
    case 'l':
        if (eyez == 74) {
            eyex  = 100.0;
            eyey  = 5.0;
            eyez  = 1.75;
            atx   = eyex;
            aty   = eyey + 5;
            atz   = eyez;
            ang   = PI/2.0;
            }        
    break;          
    case 'N':
    case 'n':
      if(luz==0)
        luz = 1;
      else
        luz = 0;
      Iluminacao();
    break;    
    }
    visao();
    glutPostRedisplay();
}

void setas(int key, int x, int y)
{   
    float auxeyex, auxeyey, auxatx, auxaty;
    auxeyex = eyex;
    auxeyey = eyey;
    auxatx = atx;
    auxaty = aty;
    
    //printf("eyex = %f - eyey = %f - atx = %f - aty = %f \n",eyex,eyey,atx,aty);
    
    switch (key) {
    case GLUT_KEY_LEFT:
        
    ang = ang + PI/50.0;

    ex  = 5*cos(ang);
    ey  = 5*sin(ang);
    
    atx =  eyex + ex;
    aty =  eyey + ey;
    

    break;
    case GLUT_KEY_RIGHT:
    
    ang = ang - PI/50.0;

    ex  = 5*cos(ang);
    ey  = 5*sin(ang);
    
    atx =  eyex + ex;
    aty =  eyey + ey;   

    break;
    case GLUT_KEY_DOWN:
    ex = atx - eyex;
    ey = aty - eyey;
        
        
        eyey = eyey - ey/20.0;        
        eyex = eyex - ex/20.0;
                    
        if ((eyex>1.5) && (eyex<198.5))
            atx = atx - ex/20.0;
        if ((eyey>1.5) && (eyey<118.5))
            aty = aty - ey/20.0;

            
        if (eyex < 1.5)
            eyex = 1.5;
        if (eyex > 198.5)
            eyex = 198.5;
        
        if (eyey < 1.5)
            eyey = 1.5;
        if (eyey > 118.5)
            eyey = 118.5;
            
        if (eyez < 4) {        
            
                 // Predio 1
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 24) && (eyex < 25)) {            
                eyex = 24;
                atx = atx + ex/20.0;
                }
            if ((eyex > 35) && (eyex < 36)) {
                eyex = 36;                               //Lateral Esquerda
                atx = atx + ex/20.0;
                }
            }
            
        if ((eyex > 24) && (eyex < 36)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty + ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty + ey/20.0;
                }
            }
            
        
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 64) && (eyex < 65.5)) {            
                eyex = 64;
                atx = atx + ex/20.0;
                }                                      //Lateral direita
            if ((eyex > 75) && (eyex < 76)) {
                eyex = 76;
                atx = atx + ex/20.0;
                }
            }
            
        if ((eyex > 65.5) && (eyex < 76)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty + ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty + ey/20.0;
                }
            }
            
        
        if ((eyex > 34.5) && (eyex < 49.2)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty + ey/20.0;               //Parede Porta 1
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty + ey/20.0;
               }
        }
        
        if ((eyex > 50.8) && (eyex < 65.5)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty + ey/20.0;             //Parede Porta 2
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty + ey/20.0;
               }
        }
        
        
        if ((eyex > 34.5) && (eyex < 65.5)) {
           if ((eyey > 92) && (eyey < 93)) {            
               eyey = 92;
               aty = aty + ey/20.0;             //Parede externa
               }
           if ((eyey > 95) && (eyey < 96)) {
               eyey = 96;
               aty = aty + ey/20.0;
               }
        }
        
                     // Predio 2
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 124) && (eyex < 125)) {            
                eyex = 124;
                atx = atx + ex/20.0;
                }
            if ((eyex > 135) && (eyex < 136)) {
                eyex = 136;                               //Lateral Esquerda
                atx = atx + ex/20.0;
                }
            }
            
        if ((eyex > 124) && (eyex < 136)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty + ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty + ey/20.0;
                }
            }
            
        
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 164) && (eyex < 165.5)) {            
                eyex = 164;
                atx = atx + ex/20.0;
                }                                      //Lateral direita
            if ((eyex > 175) && (eyex < 176)) {
                eyex = 176;
                atx = atx + ex/20.0;
                }
            }
            
        if ((eyex > 165.5) && (eyex < 176)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty + ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty + ey/20.0;
                }
            }
            
        
        if ((eyex > 134.5) && (eyex < 149.2)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty + ey/20.0;               //Parede Porta 1
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty + ey/20.0;
               }
        }
        
        if ((eyex > 150.8) && (eyex < 165.5)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty + ey/20.0;             //Parede Porta 2
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty + ey/20.0;
               }
        }
        
        
        if ((eyex > 134.5) && (eyex < 165.5)) {
           if ((eyey > 92) && (eyey < 93)) {            
               eyey = 92;
               aty = aty + ey/20.0;             //Parede externa
               }
           if ((eyey > 95) && (eyey < 96)) {
               eyey = 96;
               aty = aty + ey/20.0;
               }
        }                       
                            
        //Area da Porta para abrir
        if (aux==0 && (((eyex > 47) && (eyex < 52)) && ((eyey > 65) && ( eyey < 85)) || (((eyex > 147) && (eyex < 152)) && ((eyey > 65) && ( eyey < 85))))) {
            abrir(1);
            aux = 1;
            }
            
        // Area da Porta para fechar
        if (aux==1 && ((((eyex < 45) || (eyex > 54)) || ((eyey < 63) || (eyey > 87))) && ((eyex < 145) || (eyex > 154)) || ((eyey < 63) || (eyey > 87)))) {
            fechar(1);
            aux = 0;
            }
            
        if ((eyey > 9.2) && (eyey < 30.3)) {
            if ((eyex > 14.3) && (eyex < 15.3)) {            
                eyex = 14.3;
                atx = atx + ex/20.0;
                }
            if ((eyex > 64.5) && (eyex < 65.5)) {
                eyex = 65.5;                               //Piscina
                atx = atx + ex/20.0;
                }
            }
            
        if ((eyex > 14.3) && (eyex < 65.5)) {
            if ((eyey > 9.2) && (eyey < 10.2)) {            
                eyey = 9.2;
                aty = aty + ey/20.0;
                }
            if ((eyey > 29.3) && (eyey < 30.3)) {
                eyey = 30.3;
                aty = aty + ey/20.0;
                }
            }

            
        } //fim do IF (eyez <4)
        
        
    break;
    case GLUT_KEY_UP:    
    ex = atx - eyex;
    ey = aty - eyey;
    
        eyey = eyey + ey/20.0;        
        eyex = eyex + ex/20.0;
                    
        if ((eyex>1.5) && (eyex<198.5))
            atx = atx + ex/20.0;
        if ((eyey>1.5) && (eyey<118.5))
            aty = aty + ey/20.0;
        
        if (eyex < 1.5)
            eyex = 1.5;          //Muros
        if (eyex > 198.5)
            eyex = 198.5;
        
        if (eyey < 1.5)
            eyey = 1.5;
        if (eyey > 118.5)
            eyey = 118.5;
            
        if (eyez < 4) {

        
                 // Predio 1
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 24) && (eyex < 25)) {            
                eyex = 24;
                atx = atx - ex/20.0;
                }
            if ((eyex > 35) && (eyex < 36)) {
                eyex = 36;                               //Lateral Esquerda
                atx = atx - ex/20.0;
                }
            }
            
        if ((eyex > 24) && (eyex < 36)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty - ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty - ey/20.0;
                }
            }
            
        
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 64) && (eyex < 65.5)) {            
                eyex = 64;
                atx = atx - ex/20.0;
                }                                      //Lateral direita
            if ((eyex > 75) && (eyex < 76)) {
                eyex = 76;
                atx = atx - ex/20.0;
                }
            }
            
        if ((eyex > 65.5) && (eyex < 76)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty - ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty - ey/20.0;
                }
            }
            
        
        if ((eyex > 34.5) && (eyex < 49.2)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty - ey/20.0;               //Parede Porta 1
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty - ey/20.0;
               }
        }
        
        if ((eyex > 50.8) && (eyex < 65.5)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty - ey/20.0;             //Parede Porta 2
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty - ey/20.0;
               }
        }
        
        
        if ((eyex > 34.5) && (eyex < 65.5)) {
           if ((eyey > 92) && (eyey < 93)) {            
               eyey = 92;
               aty = aty - ey/20.0;             //Parede externa
               }
           if ((eyey > 95) && (eyey < 96)) {
               eyey = 96;
               aty = aty - ey/20.0;
               }
        }
                                
                     // Predio 2
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 124) && (eyex < 125)) {            
                eyex = 124;
                atx = atx - ex/20.0;
                }
            if ((eyex > 135) && (eyex < 136)) {
                eyex = 136;                               //Lateral Esquerda
                atx = atx - ex/20.0;
                }
            }
            
        if ((eyex > 124) && (eyex < 136)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty - ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty - ey/20.0;
                }
            }
            
        
        if ((eyey > 55.5) && (eyey < 96)) {
            if ((eyex > 164) && (eyex < 165.5)) {            
                eyex = 164;
                atx = atx - ex/20.0;
                }                                      //Lateral direita
            if ((eyex > 175) && (eyex < 176)) {
                eyex = 176;
                atx = atx - ex/20.0;
                }
            }
            
        if ((eyex > 165.5) && (eyex < 176)) {
            if ((eyey > 55.5) && (eyey < 56.5)) {            
                eyey = 55.5;
                aty = aty - ey/20.0;
                }
            if ((eyey > 95) && (eyey < 96)) {
                eyey = 96;
                aty = aty - ey/20.0;
                }
            }
            
        
        if ((eyex > 134.5) && (eyex < 149.2)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty - ey/20.0;               //Parede Porta 1
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty - ey/20.0;
               }
        }
        
        if ((eyex > 150.8) && (eyex < 165.5)) {
           if ((eyey > 74) && (eyey < 75.15)) {            
               eyey = 74;
               aty = aty - ey/20.0;             //Parede Porta 2
               }
           if ((eyey >= 75.15) && (eyey < 76.5)) {
               eyey = 76.5;
               aty = aty - ey/20.0;
               }
        }
        
        
        if ((eyex > 134.5) && (eyex < 165.5)) {
           if ((eyey > 92) && (eyey < 93)) {            
               eyey = 92;
               aty = aty - ey/20.0;             //Parede externa
               }
           if ((eyey > 95) && (eyey < 96)) {
               eyey = 96;
               aty = aty - ey/20.0;
               }
        }
           
            
        if ((eyey > 9.2) && (eyey < 30.3)) {
            if ((eyex > 14.3) && (eyex < 15.3)) {            
                eyex = 14.3;
                atx = atx - ex/20.0;
                }
            if ((eyex > 64.5) && (eyex < 65.5)) {
                eyex = 65.5;                               //Piscina
                atx = atx - ex/20.0;
                }
            }
            
        if ((eyex > 14.3) && (eyex < 65.5)) {
            if ((eyey > 9.2) && (eyey < 10.2)) {            
                eyey = 9.2;
                aty = aty - ey/20.0;
                }
            if ((eyey > 29.3) && (eyey < 30.3)) {
                eyey = 30.3;
                aty = aty - ey/20.0;
                }
            }
            
        //Area da Porta para abrir
        if (aux==0 && (((eyex > 47) && (eyex < 52)) && ((eyey > 65) && ( eyey < 85)) || (((eyex > 147) && (eyex < 152)) && ((eyey > 65) && ( eyey < 85))))) {
            abrir(1);
            aux = 1;
            }
 
        // Area da Porta para fechar
        if (aux==1 && ((((eyex < 45) || (eyex > 54)) || ((eyey < 63) || (eyey > 87))) && ((eyex < 145) || (eyex > 154)) || ((eyey < 63) || (eyey > 87)))) {
            fechar(1);
            aux = 0;
            } 
            
            
        } //Fim do IF (eyez < 4)
        
    break;
    case GLUT_KEY_PAGE_UP:
        atz += 0.2;
    break;
    case GLUT_KEY_PAGE_DOWN:
        atz -= 0.2;
    break;
    case GLUT_KEY_END:
        atz = eyez;
    }
    
    if (((((eyex > 84.5) && (eyex < 85.5)) && ((eyey > 54.5) && (eyey < 55.5)))) ||
        ((((eyex > 114.5) && (eyex < 115.5)) && ((eyey > 54.5) && (eyey < 55.5))))) {
        eyex = auxeyex;
        eyey = auxeyey;        
        atx  = auxatx;
        aty  = auxaty;
    }          
    
    visao();
    glutPostRedisplay();
}



