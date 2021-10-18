/**
 * @author Forrest Jablonski
 */

#include "Event.h"

std::atomic<ym::hsm::Event::Signal_T> ym::hsm::Event::s_signalCounter = 0;
