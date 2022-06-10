#include <stdio.h>

#include "arn.h"

int main(int argc, char** argv){
   
   // A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
   // F P R T U

   ARN* A = ARN_Criar();

   ARN_Inserir(&A, (int)'U', 0);
   ARN_Imprimir(A, 0, 'r');
   ARN_Inserir(&A, (int)'T', 0);
   ARN_Imprimir(A, 0, 'r');
   ARN_Inserir(&A, (int)'F', 0);
   ARN_Imprimir(A, 0, 'r');
   ARN_Inserir(&A, (int)'P', 0);
   ARN_Imprimir(A, 0, 'r');
   ARN_Inserir(&A, (int)'R', 0);

   ARN_Imprimir(A, 0, 'r');


}