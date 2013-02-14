#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "./a.out contact_file day month year"

int get_month_number(char *month_name);
void split_string(char *city, char *country, char *place, int n_chars);
int compute_n_days(int day_i, int month_i, int year_i, int day_f, int month_f, int year_f);
void print_message(char *name, int day, char *month, int year, int totaldays, char *city, char * country, char * message, char * signature);
int main(int argc, char **argv){
  FILE *in;
  char smonth_file[256];
  char smonth_input[256];
  char filein[256];
  char name[256];
  char place[256];
  char city[256];
  char country[256];
  char message[256];
  int ndays;

  int day_input, month_input, year_input;
  int day_file, month_file, year_file;
  
  if(argc!=5){
    fprintf(stderr, "USAGE: %s\n", USAGE);
    exit(1);
  }
  
  /*parse the command line input*/
  strcpy(filein, argv[1]);
  day_input = atoi(argv[2]);
  strcpy(smonth_input, argv[3]);
  year_input = atoi(argv[4]);

  /*read the file and get the important information*/
  if(!(in=fopen(filein, "r"))){
    fprintf(stderr, "Problem opening file %s\n", filein);
    exit(1);
  }
  fgets(name, 256, in); //reads name
  fscanf(in, "%d %s %d\n", &day_file, smonth_file, &year_file);
  fgets(place, 256, in); //reads name
  fgets(message, 256, in);
  fclose(in);

  /*Converts month name into number*/
  month_input = get_month_number(smonth_input);
  month_file = get_month_number(smonth_file);

  /*splits place into two strings, city and country*/
  split_string(city, country, place, 256);

  /*counts the total number of days*/
  ndays = compute_n_days(day_file, month_file, year_file, day_input, month_input, year_input);
  
  /*write message*/
  print_message(name, day_input, smonth_input, year_input, ndays, city, country, message, "Jaime Forero");
  return 0;
}

void print_message(char *name, int day, char *month, int year, int totaldays, char *city, char * country, char * message, char * signature){
  fprintf(stdout, "Bogota %d %s %d\n", day, month, year);
  fprintf(stdout, "Hola %s", name);
  fprintf(stdout, "Hace unos %d dias que no te escribo, por eso quisiera aprovechar\n", totaldays);
  fprintf(stdout, "este momento para decirte algo que siempre pense en decir:\n\n%s\n", message);
  fprintf(stdout, "Espero que nos podamos ver pronto en %s, siempre he\nquerido visitar %s\n\n", city, country);
  fprintf(stdout, "Saludos,\n%s\n", signature);
}

int compute_n_days(int day_i, int month_i, int year_i, int day_f, int month_f, int year_f){
  int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  char months[12][256];
  int month_days_i=0;
  int month_days_f=0;
  int i;
  int total_i, total_f;
  int diff_days;
  /*Initialization of the array months, with the name of each month in spanish*/
  strcpy(months[0], "Enero");
  strcpy(months[1], "Febrero");
  strcpy(months[2], "Marzo");
  strcpy(months[3], "Abril");
  strcpy(months[4], "Mayo");
  strcpy(months[5], "Junio");
  strcpy(months[6], "Julio");
  strcpy(months[7], "Agosto");
  strcpy(months[8], "Septiembre");
  strcpy(months[9], "Octubre");
  strcpy(months[10], "Noviembre");
  strcpy(months[11], "Diciembre");

  /*check day and month*/
  if(day_i> days[month_i] || day_f > days[month_f]){
    fprintf(stderr, "Error. Either %s doesn't have %d days or %s doesn't have %d days\n", 
	    months[month_i], day_i, months[month_f], day_f);
    exit(1);
  }
  
  month_days_i = 0;
  for(i=0;i<12;i++){
    if(i<month_i){
    month_days_i += days[i];
    }
  }
  month_days_f = 0;
  for(i=0;i<12;i++){
    if(i<month_f){
      month_days_f += days[i];
    }
  }

  /*the number of days since the first day*/
  total_i = month_days_i + (365*year_i) + day_i;
  total_f = month_days_f + (365*year_f) + day_f;
  
  diff_days = total_f - total_i;
  return diff_days;
}


void split_string(char *city, char *country, char *place, int n_chars){
  /*looks for the comma*/
  int i;
  int comma=-1;
  do{
    comma++;
  }while(comma<n_chars && place[comma]!=',');

  for(i=0;i<comma;i++){
    city[i] = place[i];
  }
  city[i] = '\0'; //closes the string
  for(i=comma+1;i<n_chars;i++){
    if(place[i]!='\n'){//take out that from the last item in the line
      country[i-comma-1] = place[i];
    }else{
      country[i-comma-1] = '\0';
    }
  }


}

int get_month_number(char *month_name){
  int i;
  char months[12][256];
  /*Initialization of the array months, with the name of each month in spanish*/
  strcpy(months[0], "Enero");
  strcpy(months[1], "Febrero");
  strcpy(months[2], "Marzo");
  strcpy(months[3], "Abril");
  strcpy(months[4], "Mayo");
  strcpy(months[5], "Junio");
  strcpy(months[6], "Julio");
  strcpy(months[7], "Agosto");
  strcpy(months[8], "Septiembre");
  strcpy(months[9], "Octubre");
  strcpy(months[10], "Noviembre");
  strcpy(months[11], "Diciembre");
  
  i=-1;
  do{    
    i++;
  }while((strcmp(months[i],month_name)!=0) && i<12);

  if(i==-1||i==12){
    fprintf(stderr, "We cannot find this month in the list: %s. Sorry!\n", month_name);
    exit(1);
  }
  return i;
}
