/**
 * SystemSdlClass
 * $Id$
 * \file gdemu_system_sdl.h
 * \brief SystemSdlClass
 * \date 2012-06-27 11:28GMT
 * \author Jan Boon (Kaetemi)
 */

/*
 * Copyright (C) 2011  Jan Boon (Kaetemi)
 *
 * This file is part of GAMEDUINO EMULATOR.
 * GAMEDUINO EMULATOR is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 2 of the
 * License, or (at your option) any later version.
 *
 * GAMEDUINO EMULATOR is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GAMEDUINO EMULATOR; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifdef GDEMU_SDL
#ifndef GDEMU_SYSTEM_SDL_H
#define GDEMU_SYSTEM_SDL_H
// #include <...>

// Sdl Headers
#include <SDL.h>
/*#include <sdl.h>
#include <avrt.h>*/

// GDI+
/*#include <gdiplus.h>*/

// WASAPI
/*#include <objbase.h>
#include <mmreg.h>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <audiopolicy.h>*/

// C Headers
#include <cstdlib>

// STL Headers
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

namespace GDEMU {

/**
 * SystemSdlClass
 * \brief SystemSdlClass
 * \date 2012-06-27 11:28GMT
 * \author Jan Boon (Kaetemi)
 */
class SystemSdlClass
{
public:
	SystemSdlClass() { }

	static void ErrorSdl();

private:
	SystemSdlClass(const SystemSdlClass &);
	SystemSdlClass &operator=(const SystemSdlClass &);

}; /* class SystemSdlClass */

extern SystemSdlClass SystemSdl;

} /* namespace GDEMU */

#endif /* #ifndef GDEMU_SYSTEM_SDL_H */
#endif /* #ifdef GDEMU_SDL */

/* end of file */
