#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(){
	int gate = 1;
	while(gate){
		cout << "Enter the task number: ";
		cin >> gate;
		if(gate == 1){
			regex dataRule("([\\d]{1,2})"
						   "(\\.)"
						   "([\\d]{1,2})"
						   "(\\.)"
						   "([\\d]{4})");
			string dataCheck;
			cout << "Enter on data format dd.mm.yyyy: ";
			cin >> dataCheck;
			if(regex_match(dataCheck.c_str(), dataRule)){
				cout << "Data format is correct!" << endl;
			} else {
				cout << "Data format is incorrect!" << endl;
			}
		}
		else if(gate == 2){
			regex expRule("[\\d](?=\\+)");
			cmatch result;
			string expCheck;
			cout << "Enter arifmetic expression: ";
			cin >> expCheck;
			cout << "Expression is: ";
			size_t i = 0;
			while(regex_search(expCheck.c_str(), result, expRule)){
				cout << result.str(0);
				i++;
				expCheck = result.suffix().str();
			} 
			cout << endl;
		}
		else if(gate == 3){
			regex expRule("^a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*A*B*C*D*E*F*G*H*I*J*K*L*M*N*O*P*Q*R*S*T*U*V*W*X*Y*Z*$");
			cmatch result;
			string expCheck;
			cout << "Enter expression: ";
			cin >> expCheck;
			cout << expCheck;
			if(regex_search(expCheck.c_str(), result, expRule)){
				cout << "True" << endl;
			} else { 
				cout << "False" << endl; 
			}
		}
		else if(gate == 4){
			regex dataRule("^(?:[0-9]{1,3}\\.){3}[0-9]{1,3}$");
			string dataCheck;
			cout << "Enter on IPv4 format : ";
			cin >> dataCheck;
			if(regex_match(dataCheck.c_str(), dataRule)){
				cout << "IPv4 format is correct!" << endl;
			} else {
				cout << "IPv4 format is incorrect!" << endl;
			}
		}
		else if(gate == 5){
			regex expRule("https:\\/\\/(?!\\-)(?:[a-zA-Z\\d\\-]{0,62}[a-zA-Z\\d]\\.){1,126}(?!\\d+)[a-zA-Z\\d]{1,63}");
			cmatch result;
			string expCheck;
			cout << "Enter domen expression: ";
			cin >> expCheck;
			cout << "Expression is: ";
			size_t i = 0;
			while(regex_search(expCheck.c_str(), result, expRule)){
				cout << result.str(0) << " | ";
				i++;
				expCheck = result.suffix().str();
			} 
			cout << endl;
		}
		else if(gate == 0){
			cout << "Closing app..." << endl;
			break;
		} else {
			cout << "Incorrect input!" << endl;
		}
	}
	return 0;
}