/*
 * echo.h
 *
 * Copyright 2015 Oliver Hofkens <oli.hofkens@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef Echo_h
#define Echo_h

#define SAMPLERATE 16000
#define ECHO_DELAY 0.5

#define ECHO_SIZE (int) ( SAMPLERATE * ECHO_DELAY )

#include "Arduino.h"
class Echo{
  public:
    float pushSample(int sample);
    void emitEcho();
  private:
  // = {0} sets the first and all undefined elements to 0.
    float _echo[ECHO_SIZE] = {0};
    int _index = 0;
    float _amp;
};


#endif
