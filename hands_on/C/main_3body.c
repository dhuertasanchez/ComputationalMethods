#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FLOAT float
#define PI 3.141592653589793
#define G_GRAV 39.486 //units of ua+3 msun-1 yr-1

FLOAT * get_memory(int n_points);
void initialize_pos(FLOAT *x, FLOAT *y, FLOAT *z, int n_points, FLOAT radius);
void initialize_vel(FLOAT *vx, FLOAT *vy, FLOAT *vz, int n_points, FLOAT vel, FLOAT radius);
void initialize_mass(FLOAT *mass, int n_points, FLOAT unit_mass);
void print_status(FLOAT *x, FLOAT *y, FLOAT *z, FLOAT *vx, FLOAT *vy, FLOAT *vz, FLOAT *ax, FLOAT *ay, FLOAT *az, int n_points);
void get_acceleration(FLOAT *ax, FLOAT *ay, FLOAT *az, FLOAT *x, FLOAT *y, FLOAT *z, FLOAT *mass, int n_points);

int main(int argc, char **argv){
  
  /*positions of all particles*/
  FLOAT *x;
  FLOAT *y;
  FLOAT *z;
  
  /*velocities of all particles*/
  FLOAT *v_x;
  FLOAT *v_y;
  FLOAT *v_z;

  /*accelerations of all particles*/
  FLOAT *a_x;
  FLOAT *a_y;
  FLOAT *a_z;

  /*masses*/
  FLOAT *mass;

  /*timestep variables*/
  FLOAT delta_t= 0.001;
  int n_steps = (int)(100.0/delta_t);
  int n_points = 3;
  FLOAT radius = 100.0;
  FLOAT unit_mass = 1.0; 
  FLOAT vel_initial = sqrt((11.0/3.0) * G_GRAV * unit_mass / (sqrt(3.0)*radius));
  int i,j;
  
  /*memory allocation*/
  x = get_memory(n_points);
  y = get_memory(n_points);
  z = get_memory(n_points);
  v_x = get_memory(n_points);
  v_y = get_memory(n_points);
  v_z = get_memory(n_points);
  a_x = get_memory(n_points);
  a_y = get_memory(n_points);
  a_z = get_memory(n_points);
  mass = get_memory(n_points);

  initialize_pos(x,y,z, n_points, radius);
  initialize_vel(v_x,v_y,v_z, n_points, vel_initial, radius);
  initialize_mass(mass, n_points, unit_mass);

  /*implementation of a simple Euler integration*/
  for(i=0;i<n_steps;i++){
    get_acceleration(a_x, a_y, a_z, x, y, z, mass, n_points);
    for(j=0;j<n_points;j++){    
      x[j] = x[j] + delta_t * v_x[j];
      y[j] = y[j] + delta_t * v_y[j];
      z[j] = z[j] + delta_t * v_z[j];

      v_x[j] = v_x[j] + delta_t * a_x[j];
      v_y[j] = v_y[j] + delta_t * a_y[j];
      v_z[j] = v_z[j] + delta_t * a_z[j];
    }
    print_status(x,y,z,v_x,v_y,v_z, a_x, a_y, a_z, n_points);
  }  
}

void get_acceleration(FLOAT *ax, FLOAT *ay, FLOAT *az, FLOAT *x, FLOAT *y, FLOAT *z, FLOAT *mass, int n_points){
  int i,j;
  FLOAT r_ij;
  for(i=0;i<n_points;i++){
    ax[i]=0.0;
    ay[i]=0.0;
    az[i]=0.0;
    
    for(j=0;j<n_points;j++){
      if(j!=i){
	r_ij = (pow((x[i] - x[j]),2.0) +
		pow((y[i] - y[j]),2.0) +
		pow((z[i] - z[j]),2.0));
	r_ij = sqrt(r_ij);
	ax[i] += -G_GRAV *mass[j]/ pow(r_ij,1.5) * (x[i] - x[j]);
	ay[i] += -G_GRAV *mass[j]/ pow(r_ij,1.5) * (y[i] - y[j]);
	az[i] += -G_GRAV *mass[j] / pow(r_ij,1.5) * (z[i] - z[j]);
      }
    }    
  }  
}

void initialize_pos(FLOAT *x, FLOAT *y, FLOAT *z, int n_points, FLOAT radius){
  int i; 
  FLOAT delta_theta;
  delta_theta = 2.0*PI/n_points;
  
  for(i=0;i<3;i++){
    x[i] = cos(delta_theta * i) * radius;
    y[i] = sin(delta_theta * i) * radius;
    z[i] = 0.0;
  }
}

void initialize_vel(FLOAT *vx, FLOAT *vy, FLOAT *vz, int n_points, FLOAT vel, FLOAT radius){
  int i; 
  FLOAT delta_theta;
  delta_theta = 2.0*PI/n_points;
  
  for(i=0;i<3;i++){
    vx[i] = -sin(delta_theta * i) * vel;
    vy[i] = cos(delta_theta * i) * vel;
    vz[i] = 0.0;
  }  

}

void initialize_mass(FLOAT *mass, int n_points, FLOAT unit_mass){
  int i;
  for (i=0;i<n_points;i++){
    mass[i] = (i+1) * unit_mass;
  }
}

FLOAT * get_memory(int n_points){
  FLOAT * x; 
  if(!(x = malloc(sizeof(FLOAT) * n_points))){
    printf("problem with memory allocation");
    exit(1);
  }
  return x;
}

void print_status(FLOAT *x, FLOAT *y, FLOAT *z, FLOAT *vx, FLOAT *vy, FLOAT *vz, FLOAT *ax, FLOAT *ay, FLOAT *az, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    printf("%f %f %f ",
	   x[i], y[i], z[i]);
  }
  printf("\n");
}


