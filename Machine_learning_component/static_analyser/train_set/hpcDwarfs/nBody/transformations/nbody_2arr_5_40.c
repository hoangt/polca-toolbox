
// Obtained from: https://github.com/harrism/mini-nbody

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "params.h"


void bodyForce(float *pos,float *vel, float dt, int n) {
  for (int i = 0; i < n*DIM; i+=3) {
    float Fx = 0.0f; float Fy = 0.0f; float Fz = 0.0f;

    for (int j = 0; j < n*DIM; j+=3) {
      float dx = pos[j]   - pos[i];
      float dy = pos[j+1] - pos[i];
      float dz = pos[j+2] - pos[i];
      float distSqr = dx*dx + dy*dy + dz*dz + SOFTENING;
      float invDist = 1.0f / sqrtf(distSqr);
      float invDist3 = invDist * invDist * invDist;

      Fx += dx * invDist3; Fy += dy * invDist3; Fz += dz * invDist3;
    }
    /* printf("%d: %f %f %f %f\n",n,dt,Fx,vx[i],vx[i] + dt*Fx); */
    vel[i] += dt*Fx; vel[i+1] += dt*Fy; vel[i+2] += dt*Fz;
    /* printf("%d: %f\n",n,vx[i]); */
    /* printf("%d:\n",i); */
  }
}

int main(const int argc, const char** argv) {
  
  int nBodies,nElems;
  int dataType;
  /* if (argc > 1) nBodies = atoi(argv[1]); */

  const float dt   = DT;    // time step
  const int nIters = ITERS; // simulation iterations

  /* int bytes = nBodies*sizeof(Body); */
  /* float *buf = (float*)malloc(bytes); */
  /* Body *p = (Body*)buf; */
  
  float *pos,*vel;

  input_arr_arg("../../data/pos_input.dat",  &pos,&nElems,&dataType);
  input_arr_arg("../../data/vel_input.dat",  &vel,&nElems,&dataType);

  nBodies = nElems / DIM;

#if PROFILING == 1
 for(int sample=0;sample<SAMPLES;sample++){
    StartTimer();
#endif
  for (int iter = 1; iter <= nIters; iter++) {
    /* printf("%d: %f\n",nBodies,x[0]); */
    /* bodyForce(pos,vel,dt, nBodies); // compute interbody forces */

    float Fx;
    float Fy;
    float Fz;

    float dx;
    float dy;
    float dz;
    float distSqr;
    float invDist;
    float invDist3;
    float F[3];

    for (int ijk = 0; ijk < nBodies*nBodies*3; ijk++) {
      int i  = ijk / (nBodies*3);
      int jk = ijk % (nBodies*3);
      int j  = jk / 3;
      int k  = jk % 3;

      dx = k==0 ? pos[j*3]   - pos[i*3]   : dx;
      dy = k==0 ? pos[j*3+1] - pos[i*3+1] : dy;
      dz = k==0 ? pos[j*3+2] - pos[i*3+2] : dz;

      distSqr = k==0 ? dx*dx + dy*dy + dz*dz + SOFTENING : distSqr;
      invDist = k==0 ? 1.0f / sqrtf(distSqr) : invDist;
      invDist3 = k==0 ? invDist * invDist * invDist : invDist3;

      F[0] = (k==0 ? dx * invDist3 : 0.0f) + (k==0 && j==0 ? 0.0f : F[0]); 
      F[1] = (k==0 ? dy * invDist3 : 0.0f) + (k==0 && j==0 ? 0.0f : F[1]); 
      F[2] = (k==0 ? dz * invDist3 : 0.0f) + (k==0 && j==0 ? 0.0f : F[2]);

      vel[i*3+k] = j==nBodies-1 ? vel[i*3+k] + dt*F[k] : vel[i*3+k];
    }

    for (int i = 0 ; i < nBodies*DIM; i+=DIM) { // integrate position
      pos[i]   += vel[i]*dt;
      pos[i+1] += vel[i+1]*dt; 
      pos[i+2] += vel[i+2]*dt;
    }
    /* printf("%d: %f\n",nBodies,vx[0]); */
    /* printf("%d: %f\n",nBodies,x[0]); */
  }
#if PROFILING == 1
  GetTimer();
 } // End of loop for time samples
#endif

  output_arr_arg("../../data/pos_out.dat",   pos, nBodies*DIM, dataType);
  output_arr_arg("../../data/vel_out.dat",   vel, nBodies*DIM, dataType);

  free(pos);
  free(vel);
}
