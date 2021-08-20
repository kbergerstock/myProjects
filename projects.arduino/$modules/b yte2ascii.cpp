
void __n2a(byte nb, char* const tbuf)
{
  const char* nibbles = "0123456789ABCDEF";
  *tbuf = nibbles[nb & 0x0f];
}

const char* byte2ascii(byte nb, char* const tbuf)
{
  __n2a(nb >> 4,tbuf);
  __n2a(nb , tbuf+1);
  *(tbuf+2) = 0;
  return tbuf;
}
