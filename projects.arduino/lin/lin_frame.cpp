/*
lin_frame impelentatoin;

k.r.bergerstock 6/2016

*/

#include "lin_frame.h"

byte calcParity(byte cmd)
{
	if ((bitRead(cmd, 0) ^ bitRead(cmd, 1) ^ bitRead(cmd, 2) ^ bitRead(cmd, 4)) == 1)
	{
		cmd |= 0x40;
	}

	if ((bitRead(cmd, 1) ^ bitRead(cmd, 3) ^ bitRead(cmd, 4) ^ bitRead(cmd, 5)) == 0)
	{
		cmd |= 0x80;
	}

	return cmd;
}

byte calcCksum(byte* data, byte len)
{
	word sum = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		sum += data[i];
		if (sum & 0x0100)
		{
			sum++;
			sum &= 0xff;
		}
	}

	sum = (~sum) & 0xff;

	return byte(sum);
}

/* cFrame implemntation */

cFrame::cFrame() { header = len = 0; }

void cFrame::initialize(byte hdr, HEADER_TYPE ft, int fd, byte fl)
{
	header = hdr;
	type = ft;
	frame_delay = fd;
	len = fl;
}

void cFrame::parity()
{
	outBuf[0] = 0x55;
	outBuf[1] = calcParity(header);
}

byte cFrame::cksum()
{
	return calcCksum( &outBuf[1] , (len + 1) );
}

void cFrame::formPacket()
{
	int i;
	switch (type)
	{
	case CMD:
		parity();						// set the parity corrected cmd byte in place
		for (i = 0; i < len; i++)		// copy in the data
			outBuf[i + 2] = data[i];
		outBuf[len + 2] = cksum();		// create the cksum and add to packet
		break;
	case RSP:
		parity();
		break;
	default:
		break;
	}
}

void cFrame::resetInputBuffer()
{
	for (int i = 0; i < 12; i++)
		input_buffer[i] = 0x00;
}

void cFrame::setData(const byte* d, byte Len)
{
	// limit the data buffer to 8
	len = Len % 8;
	// fill in the data buffer
	for (int i = 0; i < len; i++)
		data[i] = d[i];
}