/*  portVideo, a cross platform camera framework
    Copyright (C) 2005 Martin Kaltenbrunner <mkalten@iua.upf.es>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "portVideoQt.h"
#include "FrameInverter.h"

int main(int argc, char* argv[]) {

	bool colour = false;
	
	if (argc==2) {
		if (strcmp( argv[1], "-h")==0) {
			printf("usage: portVideoDemo [-c]\n");
                	return 0;
		}
		if (strcmp( argv[1], "-c")==0) colour=true;
	}

	portVideoQt *engine = new portVideoQt("portVideoDemo",colour,colour);
	FrameProcessor *inverter = new FrameInverter();
	
	engine->addFrameProcessor(inverter);
	engine->start();
	engine->removeFrameProcessor(inverter);

	delete inverter;
	delete engine;

	return 0;
}
