#include <iostream>
#include "Prescrib_sign.h"
#include "Prohib_sign.h"
#include "Warning_sign.h"
#include "Sign.h"
#include "funcs.h"
#include <cstdlib>
#include <ctime>

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

using namespace std;

int main() {
	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);

	setlocale(LC_ALL, "rus");

	srand(static_cast<unsigned int>(time(0)));

	int n{ 53 };

	Sign** signs = new Sign*[n] { 
		new Prescrib_sign("Intersection with a roundabout", 500),
		new Prescrib_sign("Traffic light control", 1000),
		new Prescrib_sign("Steep descent", 1000),
		new Prescrib_sign("Slippery road", 500),
		new Prescrib_sign("Intersection with a roundabout", 500),
		new Prescrib_sign("Traffic light control", 1000),
		new Prescrib_sign("Steep descent", 1000),
		new Prescrib_sign("Slippery road", 500),
		new Prescrib_sign("Intersection with a roundabout", 500),
		new Prescrib_sign("Traffic light control", 1000),
		new Prescrib_sign("Steep descent", 1000),
		new Prescrib_sign("Slippery road", 500),
		new Prescrib_sign("Intersection with a roundabout", 500),
		new Prescrib_sign("Traffic light control", 1000),
		new Prescrib_sign("Steep descent", 1000),
		new Prescrib_sign("Slippery road", 500),
		new Prescrib_sign("Intersection with a roundabout", 500),
		new Prescrib_sign("Traffic light control", 1000),
		new Prescrib_sign("Steep descent", 1000),
		new Prescrib_sign("Slippery road", 500),
		
		new Prohib_sign("No entry"),
		new Prohib_sign("Customs"),
		new Prohib_sign("No overtaking for trucks"),
		new Prohib_sign("No entry"),
		new Prohib_sign("Customs"),
		new Prohib_sign("No overtaking for trucks"),
		new Prohib_sign("No entry"),
		new Prohib_sign("Customs"),
		new Prohib_sign("No overtaking for trucks"),
		new Prohib_sign("No entry"),
		new Prohib_sign("Customs"),
		new Prohib_sign("No overtaking for trucks"),
		new Prohib_sign("No entry"),
		new Prohib_sign("Customs"),
		new Prohib_sign("No overtaking for trucks"),
		new Prohib_sign("No entry"),
		new Prohib_sign("Customs"),
		new Prohib_sign("No overtaking for trucks"),

		new Warning_sign("Bicycle path"),
		new Warning_sign("Roundabout"),
		new Warning_sign("Direction of movement of vehicles carrying dangerous goods"),
		new Warning_sign("Bicycle path"),
		new Warning_sign("Roundabout"),
		new Warning_sign("Direction of movement of vehicles carrying dangerous goods"),
		new Warning_sign("Bicycle path"),
		new Warning_sign("Roundabout"),
		new Warning_sign("Direction of movement of vehicles carrying dangerous goods"),
		new Warning_sign("Bicycle path"),
		new Warning_sign("Roundabout"),
		new Warning_sign("Direction of movement of vehicles carrying dangerous goods"),
		new Warning_sign("Bicycle path"),
		new Warning_sign("Roundabout"),
		new Warning_sign("Direction of movement of vehicles carrying dangerous goods"),
	};
	
	
	double salary{ 11053.*2 }; // 2 subsistence minimums of the Rostov Oblast
	double original_salary{ salary };
	
	int prohib{ 0 };
	int road_accident{ 0 };

	cout << "Your balance: " << salary << endl << endl;

	for (int i = 0; i < n; ++i) {
		
		if (signs[i]->is_violated()) {
			cout << type_to_string(signs[i]->get_type()) << endl;
			cout << signs[i]->mess() << endl;
		}
		/*else {
			cout << "The sign was run.";
		}*/

		if (signs[i]->get_type() == type_sign::prescribing && signs[i]->is_violated()) {
			double r{ rand_double() };
			if (r < 0.15) {
				cout << "Your violation was detected. \nYou have to pay a fine.\n";
				//salary -= ((Prescrib_sign*)signs[i])->get_fine();
				salary -= dynamic_cast<Prescrib_sign*>(signs[i])->get_fine();
				cout << "Your balance: " << salary;
			}
			else {
				cout << "Your violation was not detected." << endl;
			}
		}
		else if (signs[i]->get_type() == type_sign::prohibition && signs[i]->is_violated()) {
			prohib++;
			double r{ rand_double() };
			if (r < 0.15) {
				cout << "Your violation was recorded by a police officer.\n";
				cout << "You must hand in your driving license" << endl;
			}
			else if (r < 0.3) {
				cout << "Your violation was recorded by a police officer.\nYou gave a bribe";
				salary -= 2000;
				cout << "Your balance: " << salary;
			}
			else if (r < 0.35) {
				cout << "Your violation was recorded by a surveillance camera.\nYour license will be revoked.\n";
			}
			else {
				cout << "Your violation was not recorded.\n";
			}
		}
		else if (signs[i]->get_type() == type_sign::warning && signs[i]->is_violated()) {
			road_accident++;
			double r{ rand_double() };
			if (r < 0.15) {
				cout << "You were in a serious accident.\nPay for the repair of your car and the other car";
				salary -= 5000;
				cout << "Your balance: " << salary;
			}else if (r < 0.4) {
				cout << "You were in a minor accident.\nPay for the repair of the other car" << endl;
				salary -= 1000;
				cout << "Your balance: " << salary << endl;
			}else{
				cout << "Everything is fine" << endl;
			}
		}

		cout << endl;
	}

	cout << "You have arrived!" << endl << endl;

	cout << "Your balance: " << salary << endl << endl;


	for (int i = 0; i < n; ++i) {
		delete signs[i];
	}

	delete[] signs;

	_CrtMemDumpAllObjectsSince(&_ms);
	return 0;
}