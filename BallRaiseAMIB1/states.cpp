#include "states.h"

static const StateInfo state_infos[3] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {BALLRAISE::setup, BALLRAISE::enter, BALLRAISE::exit, BALLRAISE::loop, BALLRAISE::event},
  {OFF::setup, OFF::enter, OFF::exit, OFF::loop, OFF::event}
};

static const WireValue wire_values[1] = {
  {1, 0, sizeof(uint32_t), (Value<void*>*) &BALLRAISE::stepperPosition}
};

MasterManager<State, 3, 1> manager(0x5602f9df, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace BALLRAISE {
Value<uint32_t> stepperPosition;

void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::demo();
    break;
  case 1:
    events::liftLeftWall();
    break;
  case 2:
    events::liftRightWall();
    break;
  case 3:
    events::lowerLeftWall();
    break;
  case 4:
    events::lowerRightWall();
    break;
  case 5:
    events::leftWall();
    break;
  case 6:
    events::rightWall();
    break;
  default:
    break;
  }
}

namespace tablet {

namespace events {
void finishedAction() { manager.sendTabletEvent(0); }
}
}
}
namespace OFF {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}

