#define WINVER 0x0500
#include <Windows.h>
#include <iostream>
#include <time.h>
#include "Leap.h"

clock_t time1;
clock_t time2;
bool waiting;

bool preferStart;

void simulateStartKey()
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// Press the Windows key
	ip.ki.wVk = VK_LWIN; // virtual-key code for the Windows key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the Windows key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
}

void simulateShowDesktop()
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	INPUT ipd;
	ipd.type = INPUT_KEYBOARD;
	ipd.ki.wScan = 0; // hardware scan code for key
	ipd.ki.time = 0;
	ipd.ki.dwExtraInfo = 0;

	// Press the Windows key
	ip.ki.wVk = VK_LWIN; // virtual-key code for the Windows key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Press the D key
	ipd.ki.wVk = 0x44; // virtual-key code for the Windows key
	ipd.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ipd, sizeof(INPUT));

	// Release the D key
	ipd.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ipd, sizeof(INPUT));

	// Release the Windows key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
}

class DefListener : public Leap::Listener
{
	public:
    virtual void onInit( const Leap::Controller& );
    virtual void onConnect( const Leap::Controller& );
    virtual void onDisconnect( const Leap::Controller& );
    virtual void onExit( const Leap::Controller& );
    virtual void onFrame( const Leap::Controller& );
};

void DefListener::onInit( const Leap::Controller& controller )
{
	time1 = clock();
	waiting = false;
	std::cout << "Initialized" << std::endl;
}

void DefListener::onConnect( const Leap::Controller& controller )
{
	std::cout << "Connected" << std::endl;
}

void DefListener::onDisconnect( const Leap::Controller& controller )
{
	std::cout << "Disconnected" << std::endl;
}

void DefListener::onExit( const Leap::Controller& controller )
{
	std::cout << "Exited" << std::endl;
}

void DefListener::onFrame( const Leap::Controller& controller )
{
	// Get the most recent frame and report some basic information
	const Leap::Frame frame = controller.frame();

	time2 = clock() - time1;
	if( (float)time2/CLOCKS_PER_SEC >= 0.2 ) waiting = false;
	if( frame.hands()[0].fingers().count() != 5 ) waiting = false;

	if( !frame.hands().empty() && !waiting )
	{
		if( frame.hands()[0].fingers().count() >= 5 )
		{
			if( preferStart ) simulateStartKey();
			else simulateShowDesktop();
			waiting = true;
			time1 = clock();
		}
		else waiting = false;
	}
}

int main() {
	//Set whether to show the desktop or the start screen
	preferStart = false; //show desktop
	//preferStart = true; //show start

	//hide console window (note: you will have to use task manager to close it)
	//ShowWindow( GetConsoleWindow(), SW_HIDE );

	// Create a sample listener and controller
	DefListener callibrateListener;
	Leap::Controller controller;

	// Have the sample listener receive events from the controller
	controller.addListener(callibrateListener);

	// Keep this process running until Enter is pressed
	std::cin.get();

	//remove the listener
	controller.removeListener(callibrateListener);

	return 0;
}