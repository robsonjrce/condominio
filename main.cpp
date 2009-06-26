     /*      Computação Gráfica I                   *
     *                                              *
     *   Marcelo de Brito Soares Almeida - 0262417  *
     *   Ivan Kenji Maruyama Laite       - 0262448  *
     *     Feito e Testado no Dev-C++ 4.0           *
     */
     
#include <iostream>
#include <stdlib.h>
#include "codigo.h"
#include <GL/glut.h>


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Condominio");
    glutReshapeFunc(AlteraTamanhoJanela);      
	glutDisplayFunc(Desenha);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(setas);  
    Iluminacao();
	Inicializa();
    glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
