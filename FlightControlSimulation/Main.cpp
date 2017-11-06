#include "FlightSystem.h"

//Main : Will be used for UI navigation
int main()
{
	//FlightSystem Object instantiated
	FlightSystem flightSystem = FlightSystem();

	//Declaration of Navigate
	int Navigate;

	//Declaration of flight number
	std::string flightNumber;
	std::regex rFlightNumber{ R"(\w?\w?\w?\w?[a-zA-Z](\s)?\d?\d?\d?\d?[0-9]{2,8})" };
	bool flightMatch{ 0 };

	//Declaration of for airline
	std::string airline;
	std::regex rAirline{ R"(\D\w?\s?[A-Z]{4,20})" };
	bool airlineMatch{ 0 };

	//Declaration of aircraft type
	std::string aircraftType;
	std::regex rAircraftype{ R"(\w?(\s)?[A-Z]{3,10})" };
	bool aircraftMatch{ 0 };

	//Declaration of groundspeed
	int groundspeed;

	//Declaration of altitude
	int altitude;

	//Declaration of grid reference
	std::string gridReference;
	std::regex rGridReference{ R"(\D\w?[A-J]?\d?[0-9]{1,3})" };
	bool gridReferenceMatch{ 0 };

	//Declaration of heading
	int heading;


	//Menu print
	std::cout << "Welcome to the flight system." << std::endl;
	std::cout << "You can navigate by using the number keys." << std::endl;
	std::cout << "[1] will be used for adding aircraft." << std::endl;
	std::cout << "[2] will be used for listing all aircraft." << std::endl;
	std::cout << "[3] will be used for listing all crusing aircraft." << std::endl;
	std::cout << "[4] will be used for removing an aircraft." << std::endl;
	std::cout << "[5] will be used for changing the heading of an aircraft." << std::endl;
	std::cout << "[6] will be used to get the heading of an aircraft." << std::endl;
	std::cout << "[7] will be used to change the altitude of an aircraft." << std::endl;
	std::cout << "[8] will be used for get the altitude of an aircraft." << std::endl;
	std::cout << "[9] will list all the aircraft in a sector." << std::endl;
	std::cout << "[10] can be used to exit the program." << std::endl;

	//Menu naviagte
	std::cin >> (Navigate);
	switch (Navigate)
	{
		//AddAircraft variables entered and passed to flightSystem.AddAircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);
	case 1:
		//Verifications for each entered variable
		std::cout << "Enter Flight Number: " << std::endl;
		std::cin >> flightNumber;
		while (!flightMatch) {
			if (regex_match(flightNumber, rFlightNumber)) {
				std::cout << "Flight number accepted! The Flight Number is : " << flightNumber << std::endl;
				flightMatch = { 1 };
			}

			std::cout << "Enter Airline: " << std::endl;
			while (!aircraftMatch) {
				std::cin >> airline;
				if (regex_match(airline, rAirline)) {
					std::cout << "The Airline is is : " << airline << std::endl;
					aircraftMatch = { 1 };
				}
			}

			std::cout << "Enter Aircraft Type: " << std::endl;
			while (!aircraftMatch) {
				std::cin >> aircraftType;
				if (regex_match(aircraftType, rAircraftype)) {
					std::cout << "The Aircraft Type is : " << aircraftType << std::endl;
					aircraftMatch = { 1 };
				}
			}

			std::cout << "Enter Groundspeed: " << std::endl;
			std::cin >> (groundspeed);
			while (groundspeed <= 0 || groundspeed > 800) {
				std::cout << "The Groundspeed is invalid! Must be between 0-800mph: " << groundspeed << std::endl;
				std::cout << "Please re-enter Groundspeed: " << std::endl;
				std::cin >> (groundspeed);
			}

			std::cout << "Enter Altitude: " << std::endl;
			std::cin >> (altitude);
			while (altitude < 0 || altitude > 60000) {
				std::cout << "This Altitude is invalid! Must be between 0-60000ft: " << altitude << std::endl;
				std::cout << "Please re-enter altitude: " << std::endl;
				std::cin >> (altitude);
			}

			std::cout << "Enter Grid Reference: " << std::endl;
			while (!gridReferenceMatch) {
				std::cin >> gridReference;
				if (regex_match(gridReference, rGridReference)) {
					std::cout << "This Grid Reference is valid!" << std::endl;
					gridReference = { 1 };
				}
				else {
					std::cout << "This Grid Reference is invalid! Please Re-enter" << std::endl;
					std::cin >> gridReference;
				}
			}

			std::cout << "Enter Heading: " << std::endl;
			std::cin >> (heading);
			while (heading < 0 || heading > 360) {
				std::cout << "The Heading is is invalid! Must be between 0-360°: " << heading << std::endl;
				std::cout << "Please re-enter heading: " << std::endl;
				std::cin >> (heading);
			}

			flightSystem.AddAircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);
			break;
		}

	case 2:
		//Returns and lists all aircraft in the system
		std::cout << "All the aircraft will be listed below." << std::endl;
		flightSystem.ListAllAircraft();
		break;

	case 3:
		//Returns and lists all aircraft in the system above 30000ft
		std::cout << "All the aircraft above 30000ft will be listed below." << std::endl;
		flightSystem.ListAllCrusingAircraft();
		break;

	case 4:
		//Removes flights from the system
		std::getline(std::cin, flightNumber);
		std::cout << "This flight will now be deleted!" << std::endl;
		flightSystem.RemoveAircraft(flightNumber);

		break;
	case 5:
		//Changes heading of an aircraft
		std::cout << "Enter flight number to change heading: " << std::endl;
		std::getline(std::cin, flightNumber);
		std::cout << "Enter the heading you wish to change it to : " << std::endl;
		std::cin >> heading;

		flightSystem.ChangeHeading(flightNumber, heading);
		break;
	case 6:
		//Gets the heading of an aircraft
		std::cout << "Enter flight number to get heading: " << std::endl;
		std::cin >> flightNumber;
		std::cout << "Enter flight number to get heading:" << flightSystem.GetHeading(flightNumber) << std::endl;
		break;

	case 7:
		//Changes the altitude of an aircraft
		std::cout << "Enter flight number to change altitude: " << std::endl;
		std::cin >> flightNumber;
		std::cout << "Enter the altitude you wish to change it to: " << std::endl;
		std::cin >> (altitude);
		flightSystem.ChangeAltitude(flightNumber, altitude);
		break;
	case 8:
		//Gets the altitude of an aircraft
		std::cout << "Enter flight number you wish to get the altitude of. " << std::endl;
		std::cin >> flightNumber;
		std::cout << "This flights altitude is " << flightSystem.GetAltitude(flightNumber) << std::endl;
		break;
	case 9:
		//Prints the number of aircraft in the sector
		std::cout << "There are " << flightSystem.NumAircaftinSector() << " in the sector." << std::endl;
		break;
	case 10:
		//Exits the program
		std::cout << "You have chosen to exit the program. " << std::endl;
		break;
	default:
		std::cout << "Invalid input!" << std::endl;
		std::cout << "Please re-try!" << std::endl;
		std::cin.operator>> (Navigate);
	}
	return 0;
}