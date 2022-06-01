/**
 * @file SignalHandler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include "LOG.h"
#include "ThreadFunctions.h"
#include <signal.h>

void set_signal(struct sigaction &sa);


#endif
