#include <iostream>
#include<string>
#include<string.h>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <fstream>
#include<time.h>
#include<ctime>
#include<iomanip>
#pragma warning(disable : 4996)
using namespace std;

struct flight
{
	int number;
	string destination;
	string pilot_name;
	double price;
	bool flight_class;
	string date;
	string passenger_name;
};


void addFlight(flight arr[], int& current, int length)
{
	if (current <= length)
	{
		cout << endl;
		flight temp;
		while (true)
		{
			cout << "Enter flight number: ";
			cin >> temp.number;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Wrong input!" << endl;
				continue;
			}
			if (temp.number < 0)
			{
				cout << "Incorrect flight number!" << endl;
				continue;
			}
			else
			{
				break;
			}

		}
		cout << "Enter destination: ";
		cin >> temp.destination;
		cout << "Enter pilot name: ";
		cin >> temp.pilot_name;
		cout << "Enter price(lv.): ";
		cin >> temp.price;
		while (true)
		{
			cout << "Enter flight class(1-first/0-second): ";
			cin >> temp.flight_class;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Incorrect input!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "Enter a date (dd.mm.yy): ";
		cin >> temp.date;
		cout << "Enter passenger name: ";
		cin >> temp.passenger_name;
		cout << endl;
		arr[current] = temp;
		current++;

	}
	else
	{
		cout << "No space left!" << endl;
	}
}
void addFlights(flight arr[], int& current, int length)
{
	int n;
	while (true)
	{
		cout << "Enter number of flights: ";
		cin >> n;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "You didn't input a number" << endl;
			continue;
		}

		if (n < 0)
		{
			cout << "Incorrect flight number!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	cout << endl;
	if (current + n <= length)
	{
		int k = current + n;
		for (int i = current; i < k; i++)
		{
			flight temp;
			while (true)
			{
				cout << "Enter flight number: ";
				cin >> temp.number;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (temp.number < 0)
				{
					cout << "Incorrect flight number!" << endl;
					continue;
				}
				else
				{
					break;
				}

			}
			cout << "Enter destination: ";
			cin >> temp.destination;
			cout << "Enter pilot name: ";
			cin >> temp.pilot_name;
			cout << "Enter price(lv.): ";
			cin >> temp.price;
			while (true)
			{
				cout << "Enter flight class(1-first/0-second): ";
				cin >> temp.flight_class;
				if (!cin)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Incorrect input!" << endl;
					continue;
				}
				else
				{
					break;
				}
			}
			cout << "Enter a date (dd.mm.yy):";
			cin >> temp.date;
			cout << "Enter passenger name: ";
			cin >> temp.passenger_name;
			cout << endl;

			arr[i] = temp;
			current++;

		}
	}
	else
	{
		cout << "Not enough space!" << endl;
	}
}
void output(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	else
	{
		cout << endl;
		cout << "All flights in the database:" << endl;
		cout << endl;

		for (int i = 0; i < current; i++)
		{
			cout << "Flight number: " << arr[i].number << endl;
			cout << "Destination: " << arr[i].destination << endl;
			cout << "Pilot name: " << arr[i].pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " <<setprecision(2) << arr[i].price << "lv." << endl;
			if (arr[i].flight_class == true)
			{
				cout << "Flight class: First class" << endl;
			}
			else
			{
				cout << "Flight class: Second class" << endl;
			}
			cout << "Date: " << arr[i].date << endl;
			cout << "Passenger name: " << arr[i].passenger_name << endl;
			cout << endl;

		}
	}
}
void cheapestPriceOutput(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	double minPrice = arr[0].price;
	for (int i = 1; i < current; i++)
	{
		if (arr[i].price < minPrice)
		{
			minPrice = arr[i].price;
		}
	}
	cout << "Cheapest flight(s)" << endl;
	cout << endl;
	for (int i = 0; i < current; i++)
	{
		if (arr[i].price == minPrice)
		{
			cout << "Flight number: " << arr[i].number << endl;
			cout << "Destination: " << arr[i].destination << endl;
			cout << "Pilot name: " << arr[i].pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " << setprecision(2) << arr[i].price << "lv." << endl;
			if (arr[i].flight_class == true)
			{
				cout << "Flight class: First class" << endl;
			}
			else
			{
				cout << "Flight class: Second class" << endl;
			}
			cout << "Date: " << arr[i].date << endl;
			cout << "Passenger name: " << arr[i].passenger_name << endl;
			cout << endl;
		}
	}

}
void outputByPilotName(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	string pilot_name;
	int flightsFound = 0;
	cout << "Enter the pilot you are seeking for" << endl;
	cin >> pilot_name;
	cout << "Flight(s) of " << pilot_name << ":" << endl;
	cout << endl;
	for (int i = 0; i < current; i++)
	{
		if (strcmp(arr[i].pilot_name.c_str(), pilot_name.c_str()) == 0)
		{
			cout << "Flight number: " << arr[i].number << endl;
			cout << "Destination: " << arr[i].destination << endl;
			cout << "Pilot name: " << arr[i].pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " << setprecision(2) << arr[i].price << "lv." << endl;
			if (arr[i].flight_class == true)
			{
				cout << "First class" << endl;
			}
			else
			{
				cout << "Second class" << endl;
			}
			cout << "Date: " << arr[i].date << endl;
			cout << "Passenger name: " << arr[i].passenger_name << endl;
			cout << endl;
			flightsFound++;
		}
	}
	if (flightsFound == 0)
	{
		cout << "No such pilot" << endl;
	}
}
void sortAlphabeticallyByDestination(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	string temp;
	for (int i = 0; i < current; ++i)
	{
		for (int j = i + 1; j < current; ++j)
		{
			if (arr[i].destination < arr[j].destination)
			{
				temp = arr[i].destination;
				arr[i].destination = arr[j].destination;
				arr[j].destination = temp;
			}
		}
	}
	cout << "In alphabetical order by destination name descending" << endl;
	cout << endl;
	for (int i = 0; i < current; i++)
	{
		cout << "Flight number: " << arr[i].number << endl;
		cout << "Destination: " << arr[i].destination << endl;
		cout << "Pilot name: " << arr[i].pilot_name << endl;
		cout.setf(ios::fixed);
		cout << "Price: " << setprecision(2) << arr[i].price << "lv." << endl;
		if (arr[i].flight_class == true)
		{
			cout << "First class" << endl;
		}
		else
		{
			cout << "Second class" << endl;
		}
		cout << "Date: " << arr[i].date << endl;
		cout << "Passenger name: " << arr[i].passenger_name << endl;
		cout << endl;
	}
}
void writeInBinaryFile(flight arr[], string& fileName, int& current)
{
	if (current < 1)
	{
		cout << "Nothing was written because there are no flights in the database" << endl;
		exit(1);
	}
	ofstream out(fileName, ios::out | ios::binary | ios::app);
	if (!out) {
		cout << "Cannot open file!" << endl;
	}
	for (int i = 0; i < current; i++)
	{
		flight temp = arr[i];
		char arrDest[25];//
		char arrPilotName[25];//
		char arrDate[9];
		char arrPassengerName[25];

		strcpy(arrDest,temp.destination.c_str());//
		strcpy(arrPilotName, temp.pilot_name.c_str());
		strcpy(arrDate, temp.date.c_str());
		strcpy(arrPassengerName, temp.passenger_name.c_str());//

		out.write((char*)&temp.number, sizeof(int));
		out.write((char*)&arrDest, sizeof(arrDest));//
		out.write((char*)&arrPilotName, sizeof(arrPilotName));
		out.write((char*)&temp.price, sizeof(double));
		out.write((char*)&temp.flight_class, sizeof(bool));
		out.write((char*)&arrDate, sizeof(arrDate));
		out.write((char*)&arrPassengerName, sizeof(arrPassengerName));

		//out.write((char*)&temp, sizeof(flight));
		out.flush();
	}
	out.close();
	if (!out.good()) {
		cout << "Error occurred at writing time!" << endl;
	}
	else
	{
		cout << "Successfully written to file!" << endl;
	}
	cout << endl;
}
void binaryFileUpdateAfterFlightCancel(flight arr[], string& fileName, int& current)
{
	if (current < 1)
	{
		cout << "Nothing was written because there are no flights in the database" << endl;
		exit(1);
	}
	ofstream out(fileName, ios::out | ios::binary);
	if (!out) {
		cout << "Cannot open file!" << endl;
	}
	for (int i = 0; i < current; i++)
	{
		flight temp = arr[i];
		char arrDest[25];
		char arrPilotName[25];
		char arrDate[9];
		char arrPassengerName[25];

		strcpy(arrDest, temp.destination.c_str());
		strcpy(arrPilotName, temp.pilot_name.c_str());
		strcpy(arrDate, temp.date.c_str());
		strcpy(arrPassengerName, temp.passenger_name.c_str());

		out.write((char*)&temp.number, sizeof(int));
		out.write((char*)&arrDest, sizeof(arrDest));
		out.write((char*)&arrPilotName, sizeof(arrPilotName));
		out.write((char*)&temp.price, sizeof(double));
		out.write((char*)&temp.flight_class, sizeof(bool));
		out.write((char*)&arrDate, sizeof(arrDate));
		out.write((char*)&arrPassengerName, sizeof(arrPassengerName));

		//out.write((char*)&temp, sizeof(flight));
		out.flush();
	}
	out.close();
	if (!out.good()) {
		cout << "Error occurred at updating the database!" << endl;
	}
	else
	{
		cout << "Successfully updated the database!" << endl;
	}
	cout << endl;
}

void readBinaryFile(flight arr[], string& fileName, int& current)
{
	ifstream in(fileName, ios::in | ios::binary); flight temp;
	in.seekg(0l, ios::end);
	int size = in.tellg();
	in.seekg(0, ios::beg);
	in.close();
	int n = size / 97;
	if (n == 0)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	in.open(fileName, ios::binary | ios::in);
	if (!in)
	{
		cout << "Cannot open file" << endl;
	}
	else
	{
		cout << endl;
		cout << "All flights in the database: " << endl;
	}
	for (int i = 0; i < n; i++)
	{
		//in.read((char*)&temp, sizeof(flight));

		char arrDest[25];
		char arrPilotName[25];
		char arrDate[9];
		char arrPassengerName[25];
		
		in.read((char*)&temp.number, sizeof(int));
		in.read((char*)&arrDest, sizeof(arrDest));
		in.read((char*)&arrPilotName, sizeof(arrPilotName));
		in.read((char*)&temp.price, sizeof(double));
		in.read((char*)&temp.flight_class, sizeof(bool));
		in.read((char*)&arrDate, sizeof(arrDate));
		in.read((char*)&arrPassengerName, sizeof(arrPassengerName));

		temp.destination = arrDest;
		temp.pilot_name = arrPilotName;
		temp.date = arrDate;
		temp.passenger_name = arrPassengerName;

		cout << endl;
		cout << "Flight number: " << temp.number << endl;
		cout << "Destination: " << temp.destination << endl;
		cout << "Pilot name: " << temp.pilot_name << endl;
		cout.setf(ios::fixed);
		cout << "Price: " << setprecision(2) << temp.price << "lv." << endl;
		if (temp.flight_class == 1)
		{
			cout << "Flight class: " << "First class" << endl;
		}
		else if (temp.flight_class == 0)
		{
			cout << "Flight class: " << "Second class" << endl;
		}
		cout << "Date: " << temp.date << endl;
		cout << "Passenger name: " << temp.passenger_name << endl;
		cout << endl;
	}
	in.close();
	if (!in.good())
	{
		cout << "Error occured at reading time!" << endl;
	}
}
void loadFromBinaryFile(flight arr[], string& fileName, int& current)
{
	ifstream in(fileName, ios::in | ios::binary); flight temp;
	in.seekg(0l, ios::end);
	int size = in.tellg();
	in.seekg(0, ios::beg);
	in.close();
	int n = size / 97;
	if (n == 0)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	in.open(fileName, ios::binary | ios::in);
	if (!in)
	{
		cout << "Cannot open file" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		
		char arrDest[25];
		char arrPilotName[25];
		char arrDate[9];
		char arrPassengerName[25];
		
		in.read((char*)&temp.number, sizeof(int));
		in.read((char*)&arrDest, sizeof(arrDest));
		in.read((char*)&arrPilotName, sizeof(arrPilotName));
		in.read((char*)&temp.price, sizeof(double));
		in.read((char*)&temp.flight_class, sizeof(bool));
		in.read((char*)&arrDate, sizeof(arrDate));
		in.read((char*)&arrPassengerName, sizeof(arrPassengerName));

		temp.destination = arrDest;
		temp.pilot_name = arrPilotName;
		temp.date = arrDate;
		temp.passenger_name = arrPassengerName;

		arr[i].number = temp.number;
		arr[i].destination = temp.destination;
		arr[i].pilot_name = temp.pilot_name;
		arr[i].price = temp.price;
		arr[i].flight_class = temp.flight_class;
		arr[i].date = temp.date;
		arr[i].passenger_name = temp.passenger_name;
		current++;
	}
	in.close();
	if (!in.good())
	{
		cout << "Error occured at reading time!" << endl;
	}
	else
	{
		cout<<"Database ready to use!"<<endl;
	}

}
void currentFlightPrice(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	string entered_date;
	cout << "Enter a date (dd.mm.yy): " << endl;
	cin >> entered_date;
	int entered_day = stoi(entered_date.substr(0, 2));
	int entered_month = stoi(entered_date.substr(4, 2));
	int entered_year = stoi(entered_date.substr(6));

	const int MaxLen = 80;
	char currentDate[MaxLen];
	time_t t = time(0);
	strftime(currentDate, MaxLen, "%d.%m.%y", localtime(&t));

	string currentDateString;
	currentDateString.append(currentDate);
	int currentDay = stoi(currentDateString.substr(0, 2));
	int currentMonth = stoi(currentDateString.substr(3, 2));
	int currentYear = stoi(currentDateString.substr(6));
	//int dateTotal = currentMonth * 30 + currentDay;
	int dateTotal = 0;
	cout << endl;
	for (int i = 0; i < current; i++)
	{
		int arr_day = stoi(arr[i].date.substr(0, 2));
		int arr_month = stoi(arr[i].date.substr(3, 2));
		int arr_year = stoi(arr[i].date.substr(6));
		int arr_date_total = arr_month * 30 + arr_day;
		//Check for matches in the array
		if (entered_day == arr_day && entered_month == arr_month && entered_year == arr_year)
		{
			//Check if the flights are in the same year
			if (arr_year > currentYear)
			{
				//Check if there is more than 1 year until the flight
				if (arr_year - currentYear > 1)
				{
					cout << "Flight number: " << arr[i].number << endl;
					cout.setf(ios::fixed);
					cout << "Main price: " <<setprecision(2) << arr[i].price << "lv." << endl;
					cout.setf(ios::fixed);
					cout << "Current price: " <<setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
					cout << endl;
				}
				else if (arr_year - currentYear == 1)
				{
					if (12 - currentMonth > 0)
					{

						if (arr_month > 1)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else
						{
							if (currentDay == 30)
							{
								dateTotal = (12 - currentMonth) * 30 + arr_day;
							}
							else
							{
								dateTotal = (12 - currentMonth) * 30 + (30 - currentDay) + arr_day;
							}

							if (dateTotal >= 20)
							{
								cout << "Flight number: " << arr[i].number << endl;
								cout.setf(ios::fixed);
								cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
								cout.setf(ios::fixed);
								cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
								cout << endl;
							}
							else if (dateTotal < 20 && dateTotal >= 5)
							{
								cout << "Flight number: " << arr[i].number << endl;
								cout.setf(ios::fixed);
								cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
								cout.setf(ios::fixed);
								cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
								cout << endl;
							}
							else if (dateTotal < 5)
							{
								cout << "Flight number: " << arr[i].number << endl;
								cout.setf(ios::fixed);
								cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
								cout.setf(ios::fixed);
								cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
								cout << endl;
							}
						}
					}
					else if (12 - currentMonth == 0)
					{
						if (arr_month > 1)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (arr_month == 1)
						{
							dateTotal = (30 - currentDay) + arr_day;
						}
						if (dateTotal >= 20)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (dateTotal < 20 && dateTotal >= 5)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (dateTotal < 5)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
					}
				}
			}
			else if (arr_year == currentYear)
			{
				if (arr_month - currentMonth > 1)
				{
					dateTotal = (arr_month - currentMonth - 1) * 30 + arr_day + (30 - currentDay);
					if (dateTotal >= 20)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
					else if (dateTotal < 20 && dateTotal >= 5)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
					else if (dateTotal < 5)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
				}
				else if (arr_month - currentMonth == 1)
				{
					if (currentDay == 30)
					{
						dateTotal = 1 + arr_day;
						if (dateTotal >= 20)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (dateTotal < 20 && dateTotal >= 5)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (dateTotal < 5)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
					}
					else
					{
						dateTotal = (30 - current) + arr_day;
						if (dateTotal >= 20)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (dateTotal < 20 && dateTotal >= 5)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
						else if (dateTotal < 5)
						{
							cout << "Flight number: " << arr[i].number << endl;
							cout.setf(ios::fixed);
							cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
							cout.setf(ios::fixed);
							cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
							cout << endl;
						}
					}
				}
				else if (arr_month - currentMonth == 0)
				{
					dateTotal = arr_day - currentDay;
					if (dateTotal >= 20)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
					else if (dateTotal < 20 && dateTotal >= 5)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
					else if (dateTotal < 5 && dateTotal > 0)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
					else if (dateTotal == 0)
					{
						cout << "Flight number: " << arr[i].number << endl;
						cout.setf(ios::fixed);
						cout << "Main price: " << setprecision(2) << arr[i].price << "lv." << endl;
						cout.setf(ios::fixed);
						cout << "Current price: " << setprecision(2) << arr[i].price * 0.5 << "lv." << endl;
						cout << endl;
					}
				}
			}
		}
	}
}
void searchByDateAndDestination(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	string entered_date;
	cout << "Enter a date (dd.mm.yy): ";
	cin >> entered_date;
	string enteredDestination;
	cout << "Enter a destination: ";
	cin >> enteredDestination;
	int flightsFound = 0;
	for (int i = 0; i < current; i++)
	{
		if (strcmp(arr[i].destination.c_str(), enteredDestination.c_str()) == 0)
		{
			if (strcmp(arr[i].date.c_str(), entered_date.c_str()) == 0)
			{
				cout << "Flight number: " << arr[i].number << endl;
				cout << "Destination: " << arr[i].destination << endl;
				cout << "Pilot name: " << arr[i].pilot_name << endl;
				cout.setf(ios::fixed);
				cout << "Price: " <<setprecision(2) << arr[i].price << "lv." << endl;
				if (arr[i].flight_class == true)
				{
					cout << "First class" << endl;
				}
				else
				{
					cout << "Second class" << endl;
				}
				cout << "Date: " << arr[i].date << endl;
				cout << "Passenger name: " << arr[i].passenger_name << endl;
				flightsFound++;
			}
		}
	}
	if (flightsFound == 0)
	{
		cout << "No flights found" << endl;
	}
}
void ascendingOrderByPriceAndFlighClass(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	flight copyArr[50];
	for (int i = 0; i < current; i++)
	{
		copyArr[i] = arr[i];
	}
	int copyLength = current;

	for (int i = 0; i < copyLength - 1; i++)
	{
		for (int j = 0; j < copyLength - i - 1; j++)
		{
			if (copyArr[j].flight_class > copyArr[j + 1].flight_class)
			{
				flight temp = copyArr[j];
				copyArr[j] = copyArr[j + 1];
				copyArr[j] = temp;
			}
		}
	}
	for (int i = 0; i < copyLength - 1; i++)
	{
		for (int j = 0; j < copyLength - i - 1; j++)
		{
			if (copyArr[j].price > copyArr[j + 1].price)
			{
				flight temp = copyArr[j];
				copyArr[j] = copyArr[j + 1];
				copyArr[j] = temp;
			}
		}
	}
	for (int i = 0; i < copyLength; i++)
	{
		cout << "Flight number: " << copyArr[i].number << endl;
		cout << "Destination: " << copyArr[i].destination << endl;
		cout << "Pilot name: " << copyArr[i].pilot_name << endl;
		cout.setf(ios::fixed);
		cout << "Price: " <<setprecision(2) << copyArr[i].price << "lv." << endl;
		if (copyArr[i].flight_class == true)
		{
			cout << "First class" << endl;
		}
		else
		{
			cout << "Second class" << endl;
		}
		cout << "Date: " << copyArr[i].date << endl;
		cout << "Passenger name: " << copyArr[i].passenger_name << endl;
	}
}
void flightClassSwap(flight arr[], int current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	int flightNum;
	string passengerName;
	cout << "Enter the number of the flight and the passenger name" << endl;
	cin >> flightNum;
	cin >> passengerName;
	int flightsFound = 0;
	for (int i = 0; i < current; i++)
	{
		if (flightNum == arr[i].number && strcmp(passengerName.c_str(), arr[i].passenger_name.c_str()) == 0)
		{
			if (arr[i].flight_class == 0)
			{
				arr[i].flight_class = 1;
				cout << "You successfully swapped your ticket!" << endl;
				flightsFound++;
			}
			else
			{
				cout << "Your flight is already a first class one!" << endl;
			}

		}
	}
	if (flightsFound == 0)
	{
		cout << "No such flight" << endl;
	}
}
void cancelFlight(flight arr[], int& current)
{
	if (current < 1)
	{
		cout << "No flights in the database" << endl;
		exit(1);
	}
	int flightNum;
	string passengerName;
	cout << "Enter the number of the flight you want to cancel" << endl;
	cin >> flightNum;
	cout << "Enter the passenger name" << endl;
	cin >> passengerName;
	int indexOfCanceling;
	int flightsFound = 0;
	for (int i = 0; i < current; i++)
	{
		if (flightNum == arr[i].number && strcmp(passengerName.c_str(), arr[i].passenger_name.c_str()) == 0)
		{
			//Date of the flight
			int arr_day = stoi(arr[i].date.substr(0, 2));
			int arr_month = stoi(arr[i].date.substr(3, 2));
			int arr_year = stoi(arr[i].date.substr(6));
			int dateTotal = 0;
			//Current date
			const int MaxLen = 80;
			char currentDate[MaxLen];
			time_t t = time(0);
			strftime(currentDate, MaxLen, "%d.%m.%y", localtime(&t));
			string currentDateString;
			currentDateString.append(currentDate);
			int currentDay = stoi(currentDateString.substr(0, 2));
			int currentMonth = stoi(currentDateString.substr(3, 2));
			int currentYear = stoi(currentDateString.substr(6));
			double refundMoney = 0;
			//Check if the flights are in the same year
			if (arr_year > currentYear)
			{
				//Check if there is more than 1 year until the flight
				if (arr_year - currentYear > 1)
				{
					refundMoney = arr[i].price;
				}
				else if (arr_year - currentYear == 1)
				{
					if (12 - currentMonth > 0)
					{

						if (arr_month > 1)
						{
							refundMoney = arr[i].price;
						}
						else if (arr_month == 1)
						{
							if (currentDay == 30)
							{
								dateTotal = (12 - currentMonth) * 30 + arr_day;
							}
							else
							{
								dateTotal = (12 - currentMonth) * 30 + (30 - currentDay) + arr_day;
							}
							if (dateTotal >= 20)
							{
								refundMoney = arr[i].price;
							}
							else if (dateTotal < 20 && dateTotal >= 5)
							{
								refundMoney = arr[i].price * 0.75;
							}
							else if (dateTotal < 5)
							{
								refundMoney = arr[i].price * 0.5;
							}
						}
					}
					else if (12 - currentMonth == 0)
					{
						if (arr_month > 1)
						{
							refundMoney = arr[i].price;
						}
						else if (arr_month == 1)
						{
							dateTotal = (30 - currentDay) + arr_day;
						}
						if (dateTotal >= 20)
						{
							refundMoney = arr[i].price;
						}
						else if (dateTotal < 20 && dateTotal >= 5)
						{
							refundMoney = arr[i].price * 0.75;
						}
						else if (dateTotal < 5)
						{
							refundMoney = arr[i].price * 0.5;
						}
					}
				}
			}
			else if (arr_year == currentYear)
			{
				if (arr_month - currentMonth > 1)
				{
					dateTotal = (arr_month - currentMonth - 1) * 30 + arr_day + (30 - currentDay);
					if (dateTotal >= 20)
					{
						refundMoney = arr[i].price;
					}
					else if (dateTotal < 20 && dateTotal >= 5)
					{
						refundMoney = arr[i].price * 0.75;
					}
					else if (dateTotal < 5)
					{
						refundMoney = arr[i].price * 0.5;
					}
				}
				else if (arr_month - currentMonth == 1)
				{
					if (currentDay == 30)
					{
						dateTotal = arr_day;
						if (dateTotal >= 20)
						{
							refundMoney = arr[i].price;
						}
						else if (dateTotal < 20 && dateTotal >= 5)
						{
							refundMoney = arr[i].price * 0.75;
						}
						else if (dateTotal < 5)
						{
							refundMoney = arr[i].price * 0.5;
						}
					}
					else
					{
						dateTotal = (30 - currentDay) + arr_day;
						if (dateTotal >= 20)
						{
							refundMoney = arr[i].price;
						}
						else if (dateTotal < 20 && dateTotal >= 5)
						{
							refundMoney = arr[i].price * 0.75;
						}
						else if (dateTotal < 5)
						{
							refundMoney = arr[i].price * 0.5;
						}
					}
				}
				else if (arr_month - currentMonth == 0)
				{
					dateTotal = arr_day - currentDay;
					if (dateTotal >= 20)
					{
						refundMoney = arr[i].price;
					}
					else if (dateTotal < 20 && dateTotal >= 5)
					{
						refundMoney = arr[i].price * 0.75;
					}
					else if (dateTotal < 5 && dateTotal > 0)
					{
						refundMoney = arr[i].price * 0.5;
					}
				}
			}
			indexOfCanceling = i;
			for (int i = indexOfCanceling; i <= current - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			current--;
			flightsFound++;
			cout << "Your flight has been successfully cancelled!" << endl;
			cout.setf(ios::fixed);
			cout << "Your refund is: " <<setprecision(2) << refundMoney << "lv." << endl;
		}
	}
	if (flightsFound == 0)
	{
		cout << "No such flight found!" << endl;
	}
}
int main()
{
	const int length = 50;
	flight arr_flights[length];
	int current = 0; // counter of the initialized elements
	int command = 0;
	string fileName = "flights.bin";

	loadFromBinaryFile(arr_flights, fileName, current);

	while (true)
	{
		cout << "1. Add a flight" << endl;
		cout << "2. Add n flights" << endl;
		cout << "3. Flights output" << endl;
		cout << "4. Cheapest flights" << endl;
		cout << "5. Flights of certain pilot" << endl;
		cout << "6. Arrange the flights in alphabetical order" << endl;
		cout << "7. Output in file" << endl;
		cout << "8. Input from file" << endl;
		cout << "9. Price at the moment" << endl;
		cout << "10. Flight class swap" << endl;
		cout << "11. Cancel a flight" << endl;
		cout << "12. More options" << endl;
		cout << "13. Exit" << endl;



		while (true)
		{
			cout << "Enter a command between 1 and 13: ";
			cin >> command;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "You didn't input a number" << endl;
				continue;
			}

			if (command <= 0 || command > 13)
			{
				cout << "Incorrect command input!" << endl;
				continue;
			}
			else
			{
				break;
			}

		}
		switch (command)
		{
		case 1:
			addFlight(arr_flights, current, length);
			break;
		case 2:
			addFlights(arr_flights, current, length);
			break;
		case 3:
			output(arr_flights, current);
			break;
		case 4:
			cheapestPriceOutput(arr_flights, current);
			break;
		case 5:
			outputByPilotName(arr_flights, current);
			break;
		case 6:
			sortAlphabeticallyByDestination(arr_flights, current);
			break;
		case 7:
		{
			writeInBinaryFile(arr_flights, fileName, current);
		}
		break;
		case 8:
		{
			readBinaryFile(arr_flights, fileName, current);
		}
		break;
		case 9:
			currentFlightPrice(arr_flights, current);
			break;
		case 10:
			flightClassSwap(arr_flights, current);
			break;
		case 11:
			cancelFlight(arr_flights, current);
			binaryFileUpdateAfterFlightCancel(arr_flights, fileName, current);
			break;
		case 12:
		{
			int smallCommand = 0;

			while (true)
			{
				cout << "1. Ascending order by price and flight class" << endl;
				cout << "2. Search by date and destination" << endl;
				cout << "3. Back to main menu" << endl;
				cin >> smallCommand;
				switch (smallCommand)
				{
				case 1:
					ascendingOrderByPriceAndFlighClass(arr_flights, current);
					break;
				case 2:
					searchByDateAndDestination(arr_flights, current);
					break;
				case 3:
					break;
				default:
					break;
				}
				if (smallCommand == 3)
				{
					break;
				}

			}
			break;
		}
		case 13:
			writeInBinaryFile(arr_flights, fileName, current);
			cout << "You exited the program" << endl;
			break;
		default:
			break;
		}
		if (command == 13)
		{
			break;
		}
	}
	return 0;
}