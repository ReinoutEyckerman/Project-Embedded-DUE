/*
 * echo.cpp
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
#include "echo.h"
#include "Convolution.h"
/*
 * Verzwakt of versterkt de sample en steekt deze in de echo array.
 */
float Echo::pushSample(int sample){
    float value = sample * AMP;

    // 'index' bevat de echo van ECHO_DELAY sec geleden,
    // dus index - 1 is de plaats voor de recentste.
    if(index == 0)
        _echo[ECHO_SIZE - 1] = value;
    else _echo[_index - 1] = value;
    return value;
}

/*
 * Krijg de echo van ECHO_DELAY seconden geleden.
 */
void Echo::emitEcho(){
    float value = _echo[_index];

    _index++;
    if(_index == ECHO_SIZE)
        _index = 0;
    analogWrite(DAC0, value );
}
