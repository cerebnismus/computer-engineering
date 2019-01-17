#ifndef ERROR_H
#define ERROR_H
#include <helper.hpp>
using namespace std;
class Error
{
private:
	int error;
public:
	Error(int error):error(error){}
	void Message()
	{
		switch (error)
		{
		case 1:cout<<"doesn't exist"<<endl;break;
		case 2:cout<<"out of"<<endl;break;
		case 3:cout<<"empty"<<endl;break;
		case 4:cout<<"full"<<endl;break;
		default:cout<<"other"<<endl;
			break;
		}
	}

};


#endif //ERROR_H