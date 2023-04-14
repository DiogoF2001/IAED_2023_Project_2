#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"

int Modo_C(char* s, car*** c_ori, int* c_size){
	int args=0, i, err = 0;
	char *nome = NULL, *inv = NULL;
	char useless;
	car **temp = NULL, **c = *c_ori;

	nome=malloc(sizeof(char)*(MAX_INPUT+1));
	if(nome == NULL)
		return 1;

	inv=malloc(sizeof(char)*(strlen("inverso")+1));
	if(inv == NULL){
		free(inv);
		return 1;
	}

	args = Count_Args(s);
	switch (args)
	{
	case 1:
		Print_Car(c,NULL,0,(*c_size));
		break;
	
	case 2:
		sscanf(s,"%c %s", &useless, nome);
		i = Find_Car(c,nome,*c_size);
		if(i == -1){
			i = (*c_size);
			temp = Res_Car(c,(*c_size)+1);
			if(temp == NULL){
				err = 1;
				break;
			}
			(*c_size)++;
			c = temp;
			c[i] = Init_Car();
			if(c[i] == NULL){
				err = 1;
				break;
			}
			c[i]->nome = malloc(sizeof(char)*(strlen(nome)+1));
			if(c[i]->nome == NULL){
				err = 1;
				break;
			}
			strcpy(c[i]->nome,nome);
		}
		else
			Print_Car(NULL,c[i],0,*c_size);
		break;
	
	case 3:
		sscanf(s,"%c %s %s", &useless, nome, inv);
		i = Find_Car(c,nome,*c_size);
		if(i == -1){
			i = (*c_size);
			temp = Res_Car(c,(*c_size)+1);
			if(temp == NULL){
				err = 1;
				break;
			}
			(*c_size)++;
			c = temp;
			c[i] = Init_Car();
			if(c[i] == NULL){
				err = 1;
				break;
			}
			c[i]->nome = malloc(sizeof(char)*(strlen(nome)+1));
			if(c[i]->nome == NULL){
				err = 1;
				break;
			}
			strcpy(c[i]->nome,nome);
		}
		else{
			if(strncmp(inv,"inverso",strlen(inv)) == 0 && strlen(inv)>=3)
				Print_Car(NULL,c[i],1,*c_size);
			else
				SORT_ERR_MSG
		}
		break;
	
	default:
		break;
	}
	*c_ori = c;
	free(nome);
	free(inv);

	return err;
}

int Modo_P(char *s, par*** p_ori, int *p_size){
	int args=0, i, err = 0;
	double lat = 0, lon = 0;
	char *nome = NULL, *temp = NULL, **ret = NULL;
	par** aux, **p = *p_ori;

	args = Count_Args(s);

	switch (args)
	{
	case 1:
		Print_Par(p,NULL,*p_size);
		break;
	
	case 2:
		ret = Get_Name(MAX_INPUT,s);
		if(ret == NULL){
			err = 1;
			break;
		}
		nome = ret[0];
		i = Find_Par(p,nome,*p_size);
		if(i==-1){
			printf(NO_STOP_ERR_MSG, nome);
			break;
		}
		Print_Par(NULL,p[i],*p_size);
		break;
	
	case 4:
		ret = Get_Name(MAX_INPUT,s);
		if(ret == NULL){
			err = 1;
			break;
		}
		nome = ret[0];
		temp = ret[1];
		i = Find_Par(p,nome,*p_size);
		if(i!=-1){
			printf(DUP_STOP_ERR_MSG, nome);
		}
		else{
			i = (*p_size);
			aux = Res_Par(p,(*p_size)+1);
			if(aux == NULL){
				err = 1;
				break;
			}
			(*p_size)++;
			p = aux;
			p[i] = Init_Par();
			if(p[i] == NULL){
				err = 1;
				break;
			}
			sscanf(temp,"%lf %lf", &lat, &lon);
			p[i]->nome = malloc(sizeof(char)*(strlen(nome)+1));
			if(p[i]->nome == NULL){
				err = 1;
				break;
			}
			strcpy(p[i]->nome,nome);
			p[i]->lat = lat;
			p[i]->lon = lon;
		}
		break;

	default:
		break;
	}

	*p_ori = p;
	if(nome != NULL)
		free(nome);
	if(ret != NULL)
		free(ret);
	
	return err;
}


int Modo_L(char* s, car **c, int c_size, par **p, int p_size){
	int i_c = 0, i_p_ori = 0, i_p_des = 0;
	char **ret = NULL, *temp = NULL;
	double cost = -1, dur = -1;
	lis_par *l_p_temp = NULL;

	ret = Get_Name(MAX_INPUT,s);
	if(ret == NULL){
		return 1;
	}
	i_c = Find_Car(c,ret[0],c_size);

	if(i_c == -1){
		printf(NO_LINE_ERR_MSG, ret[0]);
		if(ret[0]!=NULL)
			free(ret[0]);
		free(ret);
		return 0;
	}

	temp = ret[1]-1;

	if(ret[0]!=NULL)
		free(ret[0]);
	free(ret);

	ret = Get_Name(MAX_INPUT,temp);
	if(ret == NULL){
		return 1;
	}
	i_p_ori = Find_Par(p,ret[0],p_size);

	if(i_p_ori == -1){
		printf(NO_STOP_ERR_MSG, ret[0]);
		if(ret[0]!=NULL)
			free(ret[0]);
		free(ret);
		return 0;
	}

	temp = ret[1]-1;

	if(ret[0]!=NULL)
		free(ret[0]);
	free(ret);

	ret = Get_Name(MAX_INPUT,temp);
	if(ret == NULL){
		return 1;
	}
	i_p_des = Find_Par(p,ret[0],p_size);

	if(i_p_des == -1){
		printf(NO_STOP_ERR_MSG, ret[0]);
		if(ret[0]!=NULL)
			free(ret[0]);
		free(ret);
		return 0;
	}

	sscanf(ret[1], "%lf %lf", &cost, &dur);
	
	if(ret[0]!=NULL)
		free(ret[0]);
	free(ret);

	if(cost < 0 || dur < 0){
		VAL_ERR_MSG
		return 0;
	}
	
	if(c[i_c]->ori == NULL){
		c[i_c]->ori = Init_lis_par_cell();
		if(c[i_c]->ori == NULL)
			return 1;

		c[i_c]->ori->this = p[i_p_ori];

		c[i_c]->dest = Init_lis_par_cell();
		if(c[i_c]->ori == NULL)
			return 1;

		c[i_c]->dest->this = p[i_p_des];

		c[i_c]->dest->prev = c[i_c]->ori;
		c[i_c]->ori->next = c[i_c]->dest;

		c[i_c]->ori->cost = cost;
		c[i_c]->ori->dur = dur;

		c[i_c]->cost += cost;
		c[i_c]->dur += dur;

		c[i_c]->num_par = 2;
	}
	else{
		if(!Check_Lig(c[i_c],p[i_p_ori],p[i_p_des])){
			LINK_ERR_MSG
			return 0;
		}

		if(p[i_p_ori] == c[i_c]->dest->this && p[i_p_des]==c[i_c]->ori->this){
			l_p_temp = Init_lis_par_cell();
			if(l_p_temp == NULL)
				return 1;
			
			l_p_temp->this = p[i_p_des];

			l_p_temp->prev = c[i_c]->dest;
			c[i_c]->dest->next = l_p_temp;
			c[i_c]->dest = l_p_temp;

			l_p_temp->prev->cost = cost;
			l_p_temp->prev->dur = dur;
			
			c[i_c]->cost += cost;
			c[i_c]->dur += dur;

			c[i_c]->num_par ++;
		}
		else if(p[i_p_ori] == c[i_c]->dest->this){
			l_p_temp = Init_lis_par_cell();
			if(l_p_temp == NULL)
				return 1;
			
			c[i_c]->num_par++;

			l_p_temp->this = p[i_p_des];

			l_p_temp->prev = c[i_c]->dest;
			c[i_c]->dest->next = l_p_temp;
			c[i_c]->dest = l_p_temp;
			
			l_p_temp->prev->cost = cost;
			l_p_temp->prev->dur = dur;

			c[i_c]->cost += cost;
			c[i_c]->dur += dur;
		}
		else if(p[i_p_des] == c[i_c]->ori->this){
			l_p_temp = Init_lis_par_cell();
			if(l_p_temp == NULL)
				return 1;

			c[i_c]->num_par++;

			l_p_temp->this = p[i_p_ori];

			l_p_temp->next = c[i_c]->ori;
			c[i_c]->ori->prev = l_p_temp;
			c[i_c]->ori = l_p_temp;

			l_p_temp->cost = cost;
			l_p_temp->dur = dur;
			
			c[i_c]->cost += cost;
			c[i_c]->dur += dur;
		}
	}

	if(Find_Car_in_Lis(c[i_c],p[i_p_ori]->cars) == NULL){
		p[i_p_ori]->num_car ++;
		if(Add_to_Car_lis(c[i_c],p[i_p_ori]))
			return 1;
	}
	if(Find_Car_in_Lis(c[i_c],p[i_p_des]->cars) == NULL){
		p[i_p_des]->num_car ++;
		if(Add_to_Car_lis(c[i_c],p[i_p_des]))
			return 1;
	}
	
	return 0;
}

void Modo_I(par** p, int p_size){
	int i;
	lis_car *temp=NULL;
	for(i=0;i<p_size && p[i] != NULL;i++){
		if(p[i]->num_car>1){
			printf("%s %d:", p[i]->nome, p[i]->num_car);
			temp = p[i]->cars;
			while(temp != NULL){
				printf(" %s", temp->this->nome);
				temp = temp->next;
			}
			printf("\n");
		}
	}

}

int Modo_R(char *s, car** c,int *size){
	int i;
	char *nome = NULL, useless;
	lis_car *temp_c = NULL, *aux = NULL;
	lis_par *temp_p = NULL;

	nome = malloc(sizeof(char)*MAX_INPUT);
	if(nome == NULL)
		return 1;

	sscanf(s,"%c %s", &useless, nome);

	i = Find_Car(c,nome,(*size));
	if(i == -1){
		printf(NO_LINE_ERR_MSG, nome);
		free(nome);
		return 0;
	}
	free(nome);

	/*This removes the line from every stop it contains*/
	for(temp_p = c[i]->ori; temp_p != NULL; temp_p = temp_p->next){
		for(temp_c = temp_p->this->cars, aux = NULL; 
		temp_c != NULL && temp_c->this != c[i]; 
		aux = temp_c, temp_c = temp_c->next);

		if (temp_c == NULL)
			continue;
		else if(aux == NULL)
			temp_p->this->cars = temp_c->next;
		else
			aux->next = temp_c->next;
		
		free(temp_c);

		temp_p->this->num_car--;

	}


	Free_Car(c[i]);
	--(*size);
	for(; i < (*size); i++){
		c[i] = c[i+1];
	}
	return 0;
}

int Modo_E(char *s, par **p, int *size){
	int i;
	char *nome = NULL, **ret = NULL;
	lis_car *temp_c = NULL;
	lis_par *temp_p = NULL, *aux = NULL;

	ret = Get_Name(MAX_INPUT,s);
	if(ret == NULL || ret[0] == NULL)
		return 1;

	nome = ret[0];

	i = Find_Par(p,nome,(*size));
	if(i == -1){
		printf(NO_LINE_ERR_MSG, nome);
		free(nome);
		free(ret);
		return 0;
	}
	free(nome);
	free(ret);

	for(temp_c = p[i]->cars; temp_c != NULL; temp_c = temp_c->next){
		/*There's only 2 stops in the line so we remove both*/
		if(temp_c->this->num_par == 2){
			if(temp_c->this->dest->this != p[i])
				Free_Car_in_Par(temp_c->this,temp_c->this->dest->this);
			else if(temp_c->this->ori->this != p[i])
				Free_Car_in_Par(temp_c->this,temp_c->this->ori->this);
			free(temp_c->this->ori);
			free(temp_c->this->dest);
			temp_c->this->ori = NULL;
			temp_c->this->dest = NULL;
			temp_c->this->cost = 0;
			temp_c->this->dur = 0;
			temp_c->this->num_par = 0;
		}
		else{
			for(temp_p = temp_c->this->dest; temp_p != NULL; temp_p = aux){
				if(temp_p->this == p[i]){
					/*If there is only a single stop left*/
					if(temp_p->prev == temp_p->next){
						temp_c->this->ori = NULL;
						temp_c->this->dest = NULL;
					}
					else if(temp_p->next == NULL){
						/*It's the last stop but there are more than 2*/
						temp_c->this->cost -= temp_p->prev->cost;
						temp_c->this->dur -= temp_p->prev->dur;
						temp_p->prev->cost = 0;
						temp_p->prev->dur = 0;

						temp_p->prev->next = NULL;
						temp_c->this->dest = temp_p->prev;

					}
					else if(temp_p->prev == NULL){
						/*It's the first stop but there are more than 2*/
						temp_c->this->cost -= temp_p->cost;
						temp_c->this->dur -= temp_p->dur;
						temp_c->this->ori = temp_p->next;
						temp_p->next->prev = NULL;
					}
					else{
						temp_p->prev->cost += temp_p->cost;
						temp_p->prev->dur += temp_p->dur;
						temp_p->prev->next = temp_p->next;
						temp_p->next->prev = temp_p->prev;
					}
					aux = temp_p->prev;
					free(temp_p);
					temp_c->this->num_par--;
				}
				else
					aux = temp_p->prev;
			}
		}
	}

	Free_Par(p[i]);
	--(*size);

	/*Moves every stop in the array after the one we free'd one
	position to the left*/
	for(; i < (*size); i++){
		p[i] = p[i+1];
	}
	return 0;
}