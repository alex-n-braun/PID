# PID
PID controller to keep a car on a track. Project of the Udacity Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Reflection

### Effect of P, I, and D components
Input to the controller is the cross track error cte, which is the deviation of the car from the set position. Output of the controller is the steering angle (value range -1 .. 1). If the car is right (left) to the set position, cte is positive (negative). In case of positive (negative) cte, the car should steer in direction of the set position, which then means negative (positive) value for the steering angle. A non-zero steering angle changes the yaw angle of the car (the yaw angle integrates the steering angle, if the car is moving). This means that 

- P contribution should be negative in order to counteract the cte
- there is need to counteract an increasing yaw angle; as long as the sign of cte does not change, yaw angle will increase as long as there is only a non-zero P contribution. This means that cte will be reduced with increasing speed and eventually overshoot. Therefore we need a negative D contribution, which counteracts an increasingly fast reduction of cte.
- I contribution is not needed. In principle, an I part is only needed if the P part only will systematically lead to a non-vanishing control deviation. This is not the case here, as argued before. On a straight path, a negative P contribution will _always_ lead to overshooting due to the integrating nature of the yaw angle.

### Tuning of control parameters P, I, and D
The control parameters where chosen by trial and error, while it was clear, that the values needed to be negative; compare the discussion above.


