/*
 * Button.h
 *
 *  Created on: 19.06.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "Drawable.h"

class Button: public Drawable {
public:
	Button(int x = 0, int y = 0);
		virtual bool isClicked(int x, int y);
	virtual ~Button();
};

#endif /* BUTTON_H_ */
