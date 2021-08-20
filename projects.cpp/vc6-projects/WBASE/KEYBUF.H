//  keyboard buffer handler
// simulates comm input for audit test
// K.R. BERGERSTOCK  @ 4/97

#define cbInMax    1024 				// size of transmit and
#define BufMax		160 				// size of line buffer

#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif

#ifndef __TQUE_H
#include "tque.h"
#endif

#ifndef __KEYBUF_H
#define __KEYBUF_H

class KeyBuffer
{
  private:
  TQUE<char> cbInBuf;

  protected:

  public:
   KeyBuffer();                         // constructor
   ~KeyBuffer();                    	// destructor

   int getError(void);					// fetch the last error on the comm port

   int	PutChar(char);					// ouputs a char to the comm device
   char GetChar(void);					// recieves a char from the comm device
   int	PutStr(LPSTR);					// outputs a string to the comm device
   int	NumInBuffer(void);				// obtains the number of characters in
										// the recieve buffer
   void Flush(void);
};

#endif
