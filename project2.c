/* iaed-23 - ist196191 - project2 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"

#define BUFFER_SIZE 256
#define MEM_ERR_MSG printf("No memory.\n");

int main(){
	int /*i,*/ car_size = 0, par_size = 0, ret = 0;
	char mode, *temp = NULL, *s = NULL;
	car **carreiras_all = NULL;
	par **paragens_all = NULL;

	s = malloc(sizeof(char)*(MAX_INPUT+1));
	if(s==NULL){
		MEM_ERR_MSG
		return 0;
	}

	if(Init_Glob_Arr(&carreiras_all,&paragens_all)){
		free(s);
		MEM_ERR_MSG;
		return 0;
	}
	
	s = fgets(s,MAX_INPUT,stdin);
	
	while(s != NULL){
		if(sscanf(s,"%c",&mode)!=1)
			exit(-1);
		switch (mode){
			case 'a':
				Free_All(carreiras_all,car_size,paragens_all,par_size);
				free(carreiras_all);
				free(paragens_all);
				paragens_all = NULL;
				carreiras_all = NULL;
				ret = Init_Glob_Arr(&carreiras_all,&paragens_all);
				par_size = 0;
				car_size = 0;
				break;

			case 'c':
				ret = Modo_C(s,&carreiras_all, &car_size);
				break;
			
			case 'p':
				ret = Modo_P(s,&paragens_all, &par_size);
				break;

			case 'l':
				ret = Modo_L(s,carreiras_all, car_size, paragens_all, par_size);
				break;
			
			case 'i':
				Modo_I(paragens_all, par_size);
				break;
			
			case 'r':
				ret = Modo_R(s,carreiras_all,&car_size);
				break;
			
			case 'e':
				ret = Modo_E(s,paragens_all,&par_size);
				break;
			
			case 'q':
			default:
				Free_All(carreiras_all,car_size,paragens_all,par_size);
				free(s);
				s=NULL;
				break;
		}
		if(ret){
			MEM_ERR_MSG
			break;
		}
		if(s != NULL)
			s = fgets(s,MAX_INPUT,stdin);
	}

	free(carreiras_all);
	free(paragens_all);
	free(temp);
	free(s);
	return 0;
}
