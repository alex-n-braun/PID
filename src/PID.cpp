#include <iostream>

#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() : p_error(0.0), i_error(0.0), d_error(0.0), cte_old(0.0) {
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  cte_old = 0.0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  p_error = Kp*cte;
  i_error = i_error + Ki*cte;
  d_error = Kd*(cte - cte_old);
  cte_old = cte;
  std::cout<<"-- P = "<<p_error<<", I = "<<i_error<<", D = "<<d_error<<std::endl;
}

double PID::TotalError() {
  return p_error + i_error + d_error;
}

