#include<stdio.h>
#include<string.h>

typedef struct{
    char city_name[50];
    char country_name[50];
    double tourist_n;
    char hotspot_name[50];
}city_info;

void menu(void){
    printf("\n\t\t-------------------- Menu To Use--------------------\n"); 
    printf("\n\t\t1. View File Content\n");
    printf("\n\t\t2. Load File Data to an Array\n");
    printf("\n\t\t3. Get ranking of a city X\n");
    printf("\n\t\t4. Get Information about a city X \n");
    printf("\n\t\t5. Update the number of yearly tourists of a city X\n");
    printf("\n\t\t6. Find the most visited cities in a country X\n");
    printf("\n\t\t7. Remove a city from the ranking\n"); 
    printf("\n\t\t8. Quit\n"); 
    printf("\n\t\t----------------------------------------------------\n");
    printf("\n\t\tYour Choice:");
}

int display_file_content(FILE* infp){

    int i, cnt = 0;
    char answer;
    char Line[100];

    do{

         for(i = 0; i < 25; i++){
            if (!feof(infp))
            {
                cnt++;
                fgets(Line, 100, infp);
                printf("\t\t%s", Line);
            }
            else
                break;

        }

        scanf("%c", &answer);

    }while(answer == '\n' && !feof(infp));

    return cnt/5;

}

void load_data_arr(city_info* arr, FILE* infp){ // when theres a choice diff

    int i = 0;
    char Line[50];

    fseek(infp, 0, 0);

    while(!feof(infp)){

        fgets(arr[i].city_name, 50, infp);
        arr[i].city_name[strlen(arr[i].city_name)-1] = '\0';

        fgets(arr[i].country_name, 50, infp);
        arr[i].country_name[strlen(arr[i].country_name)-1] = '\0'; 

        fscanf(infp, "%lf", &arr[i].tourist_n);

        fgetc(infp);

        fgets(arr[i].hotspot_name, 50, infp);
        arr[i].hotspot_name[strlen(arr[i].hotspot_name)-1] = '\0'; 

        fgets(Line, 50, infp);
        i++;

    }

}

int display_ranking(city_info* arr, char* city, int N){ //N = cities number

    int rank = -1;

    for(int i = 0; i < N; i++){

        if(strcmp(arr[i].city_name, city) == 0){
            rank = i;
            break;
        }

    }

    return rank;
}

void get_all_info(city_info* arr, char* city, int N, city_info* data, int rank){
    
    *data = arr[rank];
}

void update_tourist_number(city_info* arr, char* city, double new_tourist_number, int N){
    
    for(int i = 0; i < N; i++){
        if(strcmp(arr[i].city_name, city) == 0){
            arr[i].tourist_n = new_tourist_number;
        }
    }

    city_sort(arr, N); 
    
}

void city_sort(city_info* arr, int N){

  for(int i = 0; i < N - 1; i++){
    int min_idx = i;

    for(int j = i + 1; j < N; j++){
      if(arr[min_idx].tourist_n < arr[j].tourist_n){
        min_idx = j;
      }
    }

    if(min_idx != i)
      swap(&arr[min_idx], &arr[i]);

  }

}

void swap(city_info *a, city_info *b){
    city_info tmp = *a;
    *a = *b;
    *b = tmp;
 }

int find_cities_of_country(city_info* arr, int N, char* country){

    int flag = 0;
    FILE* outpf;

    for(int i = 0; i < N; i++){

        if(strcmp(arr[i].country_name, country) == 0){
            if(flag == 0){
                outpf = fopen("city.txt","w");
                flag = 1;
            }
            fprintf(outpf,"%s\n",arr[i].city_name);
        }

    }

    if(flag == 1){
        fclose(outpf);
        return 1;
    }

    return 0;

}

void delete_city(city_info* arr, int *N, char* city){

    for(int i = 0; i < *N; i++){

        if(strcmp(arr[i].city_name, city) == 0){

            for(int j = i; j < *N; j++)
                arr[j] = arr[j+1];

            (*N)--;
            break;  
        }

    }

}

int main(){

    FILE* infp = fopen("data.txt", "r");
    city_info arr[100];
    city_info data;
    int choice, cities_number, arr_loaded = 0, file_displayed = 0;
    char city[50], country[50];

    if(infp==NULL)
        printf("\n\t\tThe cannot be opened!\n");
    else{

        do{
            
            choice = 0;
            menu();
            scanf("%d", &choice);
            getchar();

            if((choice > 2 && choice < 8) && (arr_loaded == 0 || file_displayed == 0))
                printf("\n\t\tYou need to display the file then load it to the array first in order to use that choice");
            else{

                switch (choice){

                    case 1: 
            
                        printf("\n\t\t----------------------------------------------------\n");
                        cities_number = display_file_content(infp);
                        printf("\n\t\tThe number of cities is: %d.\n", cities_number);
                        file_displayed = 1;

                        break;

                    case 2:

                        if(arr_loaded == 1){
                            printf("\n\t\tYou already filled the array.");
                            break;
                        }
                        else if(file_displayed == 0){
                            printf("\n\t\tYou should display the file first.");
                            break;
                        }

                        load_data_arr(arr, infp); 
                        printf("\n\t\tThe file is loaded into the array!");
                        arr_loaded = 1;
                        fclose(infp);

                        break;

                    case 3: 

                        printf("\n\t\tEnter the name of the city to see its ranking: "); // can i use a fct to avoid writing thhe same lines
                        gets(city);

                        int rank = display_ranking(arr, city, cities_number);

                        if(rank==-1)
                            printf("\n\t\t'%s' does not exist.\n", city);
                        else{
                            rank++;
                            printf("\n\t\tThe rank of '%s' is: %d.\n", arr[rank-1].city_name, rank);                     
                        }

                        break;

                    case 4: 

                        printf("\n\t\tEnter the name of the city to see its information: ");
                        gets(city);

                        int rank1 = display_ranking(arr, city, cities_number);

                        if(rank1==-1)
                            printf("\n\t\t'%s' does not exist.\n", city);
                        else{
                            get_all_info(arr, city, cities_number, &data, rank1);
                            rank1++;
                            printf("\n\t\t%s is ranked#%d located in %s receiving %.3lf tourists yearly and the most visited place is %s.\n", arr[rank1-1].city_name,  rank1, arr[rank1-1].country_name, arr[rank1-1].tourist_n, arr[rank1-1].hotspot_name);
                        }

                        break;

                    case 5:

                        printf("\n\t\tEnter the name of the city to update its number of tourists: "); // the first element does not exist
                        gets(city);

                        int flag = display_ranking(arr, city, cities_number);

                        if(flag != -1){ 
                            
                            double new_tourist_number;
                            printf("\n\t\tEnter the new number of tourists: ");
                            scanf("%lf", &new_tourist_number);

                            update_tourist_number(arr, city, new_tourist_number, cities_number);

                            printf("\n\t\tThe number of tourists is updated successfully.");
                        }
                        else
                            printf("\n\t\t'%s' does not exist.\n", city);

                        break; 

                    case 6: 
                            

                            printf("\n\t\tEnter the name of the country: ");
                            gets(country);

                            int flag1 = find_cities_of_country(arr, cities_number, country);

                            if(flag1)
                                printf("\n\t\tPlease check your folder!'city.txt' was created!\n\n\t\t");                     
                            else
                                printf("\n\t\t'%s' does not exist.\n", country);

                        break;

                    case 7: 
                            printf("\n\t\tEnter the name of the city to delete: ");
                            gets(city);

                            int flag2 = display_ranking(arr, city, cities_number);

                            if(flag2 != -1){ 
                                delete_city(arr, &cities_number, city);
                                printf("\n\t\t%s has successfully been deleted.", city); // return smth
                            }
                            else
                                printf("\n\t\t'%s' does not exist.\n", city);

                        break;

                    case 8: 
                        printf("\n\t\tYou Quited The Program!\n\t\tCIAO!!\n\n\t\t");
                        break;
                    
                    default:printf("\n\t\tThat was a wrong choice!\n");
        
                }

            }            

        }while(choice != 8);

    }
    
    return 0;
}