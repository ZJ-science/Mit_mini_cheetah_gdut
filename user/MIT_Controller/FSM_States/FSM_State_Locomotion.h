#ifndef FSM_STATE_LOCOMOTION_H
#define FSM_STATE_LOCOMOTION_H

#include <Controllers/convexMPC/ConvexMPCLocomotion.h>
#include "FSM_State.h"
#include <gui_main_control_settings_t.hpp>

/**
 *
 */
template <typename T>
class FSM_State_Locomotion : public FSM_State<T> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  FSM_State_Locomotion(ControlFSMData<T>* _controlFSMData);

  // Behavior to be carried out when entering a state
  void onEnter();

  // Run the normal behavior for the state
  void run();

  // Checks for any transition triggers
  FSM_StateName checkTransition();

  // Manages state specific transitions
  TransitionData<T> transition();

  // Behavior to be carried out when exiting a state
  void onExit();
  
  gui_main_control_settings_t main_control_settings;  ///增加

 private:
  // Keep track of the control iterations
  int iter = 0;
  ConvexMPCLocomotion cMPCOld;

  // Parses contact specific controls to the leg controller
  void LocomotionControlStep();

  // Impedance control for the stance legs during locomotion
  void StanceLegImpedanceControl(int leg);
};

#endif  // FSM_STATE_LOCOMOTION_H
