//  keyboard buffer handler
// simulates comm input for audit test
// K.R. BERGERSTOCK  @ 4/97

#include "keybuf.h"

KeyBuffer::KeyBuffer()
{
 cbInBuf.Create(cbInMax);
}

KeyBuffer::~KeyBuffer()
{
  cbInBuf.Destroy();
}

int KeyBuffer::PutChar(char cbout)
{
  cbInBuf.Put(cbout);
  return cbInBuf.GetOverFlow();
}

int KeyBuffer::PutStr(LPSTR szStr)
{
  while(*szStr)
    { PutChar(*szStr++); }

 return cbInBuf.GetOverFlow();
}

char KeyBuffer::GetChar(void)
{
  return cbInBuf.Get();
}

int  KeyBuffer::NumInBuffer(void)
{
   return cbInBuf.GetCount();
}

void KeyBuffer::Flush(void)
{
  cbInBuf.Reset();
}
