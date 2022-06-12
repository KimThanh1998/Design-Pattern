#include <iostream>
#include <string>

using namespace std;

class IObserver{
	public:
		virtual void update(string operation, string record) = 0;	
};

class ISubject{
	public:
		virtual void registerObserver(IObserver* obs) = 0;
		virtual void unregisterObserver(IObserver* obs) = 0;
		virtual void notifyObserver() = 0;
};

