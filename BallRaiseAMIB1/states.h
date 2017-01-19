#pragma once

#include <Manager.h>

namespace IDLE {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}

namespace BALLRAISE {
extern Value<uint32_t> stepperPosition;

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();

namespace tablet {

namespace events {
void finishedAction();

}
}

namespace events {
void demo();
void liftLeftWall();
void liftRightWall();
void lowerLeftWall();
void lowerRightWall();
void leftWall();
void rightWall();
}
}

namespace OFF {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}



enum State {
  STATE_IDLE,
  STATE_BALLRAISE,
  STATE_OFF
};

extern MasterManager<State, 3, 1> manager;
