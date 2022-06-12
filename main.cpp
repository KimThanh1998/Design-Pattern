#include <iostream>
#include <vector>
#include "observer.h"

using namespace std;

class Database : public ISubject
{
	private:
		vector<IObserver*> _Observers;
		string _operation;
		string _record;
	public:
		Database () {};
		~Database () {};
		
		void registerObserver(IObserver* obs)
		{
			_Observers.push_back(obs);
		}
		void unregisterObserver(IObserver* obs)
		{
			for(int i = 0; i < _Observers.size(); i++)
			{
				if(_Observers[i] == obs)
				{
					_Observers.erase(_Observers.begin() + i);
				}	
			}
		}
		void notifyObserver()
		{
			for(auto& obs : _Observers)
			{
				obs->update(_operation, _record);
			}
		}
		void editRecord(string operation, string record)
		{
			_operation = operation;
			_record = record;
			notifyObserver();
		}
};	

class client : public IObserver
{
	public:
		client() {};
		void update(string operation, string record)
		{
			cout << "Client " << operation << " operation was performed on " << record << endl;
		}
};

class developer : public IObserver
{
	public: 
		developer() {};
		void update(string operation, string record)
		{
			cout << "Developer " << operation << " operation was performed by developer on " << record << endl;
		}
};

class boss : public IObserver
{
	public: 
		boss() {};
		void update(string operation, string record)
		{
			cout << "Boss " << operation << " operation was performed on " << record << endl;
		}
};

int main(){
	Database db;
	client myClient1;
	developer myDeveloper1;
	boss myBoss1;
	db.registerObserver(&myClient1);
	db.registerObserver(&myDeveloper1);
	db.registerObserver(&myBoss1);
	db.editRecord("delete", "record1");

	db.unregisterObserver(&myBoss1);
	db.editRecord("modify", "record2");
	return 0;
}
