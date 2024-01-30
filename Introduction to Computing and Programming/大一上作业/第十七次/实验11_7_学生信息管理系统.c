#include<stdio.h>

struct student{
	char id[11];
	char name[11];
	int math;
	int eng;
	int cs;
};
struct student n[130];
int n_cnt = 0;
int find(char *s);

int main(){
	
	int cnt;
	scanf("%d",&cnt);
	int i;
	for( i = 0; i < cnt; i++ ){
		int cmd;
		scanf("%d",&cmd);
		
		if(cmd == 1){
			struct student m;
			scanf("%s%s%d%d%d",m.id,m.name,&m.math,&m.eng,&m.cs);
			if(find(m.id) != -1){
				printf("Students already exist");
			}else{
				n[n_cnt] = m;
				n_cnt++;
				printf("Add success");
			}
		}else if(cmd == 2){
			char id[11];
			scanf("%s",id);
			if(find(id) == -1){
				printf("Students do not exist");
			}else{
				int t = find(id);
				int i = t;
				for( i = t; i < n_cnt-1; i++){
					n[i] = n[i+1]; 
				}
				printf("Delete success");
				n_cnt--;
			}
		}else if(cmd == 3){
			struct student m;
			scanf("%s%d%d%d",m.id,&m.math,&m.eng,&m.cs);
			if(find(m.id) == -1){
				printf("Students do not exist");
			}else{
				int t = find(m.id);
				n[t].cs = m.cs;
				n[t].eng = m.eng;
				n[t].math = m.math;
				printf("Update success");
			}
		}else if(cmd == 4){
			char id[11];
			scanf("%s",id);
			if(find(id) == -1){
				printf("Students do not exist");
			}else{
				int t = find(id);
				double average;
				average = (n[t].cs+n[t].eng+n[t].math)*1.0/3;
				printf("Student ID:%s",n[t].id);
				printf("\nName:%s",n[t].name);
				printf("\nAverage Score:%.1lf",average);
			}
		}
	}
}

int find(char *s){
	int i = 0;
	while(i<n_cnt){
		if(strcmp(n[i].id,s) == 0){
			return i;
		}
		i++;
	}
	return -1;
}
