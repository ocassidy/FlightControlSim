#include "Aircraft.h"
#include "FlightSystem.h"

//Main : Will be used for UI navigation
int main()
{
	//FlightSystem Object instantiated
	FlightSystem flightSystem = FlightSystem();

	int Navigate;
	char YesNo = 'A';

	//
	std::string flightNumber;
	std::regex rFlightNumber{ R"(\w\w[a-z]\d\d?\d?\d?\d?[a-z]?)" };
	
	//
	std::string airline;
	std::regex rAirline{ R"([a-z][0-9]{4,20}$)" };

	//
	std::string aircraftType; 
	std::regex rAircraftype{ R"([a-z](\s)?[0-9]{4,20}$)" };

	//
	int groundspeed;
	
	//
	int altitude;

	//
	std::string gridReference;
	std::regex rGridReference{ R"([a-z]?[1-9])" };

	//
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

	std::cin>> (Navigate);

	switch (Navigate)
	{
	case 1: 
		std::cout << "Do you want to add a flight to the system?" << std::endl;
		std::cin>> YesNo;
		YesNo = toupper(YesNo);
		
		if (YesNo == 'Y') {
			std::cout << "Enter Flight Number: " << std::endl;
			std::cin>> flightNumber;
			if (regex_match(flightNumber, rFlightNumber)) {
				std::cout << "Flight number accepted! The Flight Number is : " << flightNumber << std::endl;
			}

			std::cout << "Enter Airline: " << std::endl;
			std::cin >> airline;
			if (regex_match(airline, rAirline)) {
				std::cout << "The Airline is is : " << airline << std::endl;
			}

			std::cout << "Enter Aircraft Type: " << std::endl;
			std::cin >> aircraftType;
			if (regex_match(aircraftType, rAircraftype)) {
				std::cout << "The Aircraft Type is : " << aircraftType << std::endl;
			}

			std::cout << "Enter Groundspeed: " << std::endl;
			std::cin >> (groundspeed);
			if (groundspeed < 0 || groundspeed > 800 ) {
				std::cout << "The Groundspeed is invalid! Must be between 0-800mph: " << groundspeed << std::endl;
				std::cout << "Please re-enter Groundspeed: " << std::endl;
				std::cin >> (groundspeed);
			}

			std::cout << "Enter Altitude: " << std::endl;
			std::cin >> (altitude);
			if (altitude < 0 || altitude > 60000) {
				std::cout << "The Altitude is invalid! Must be between 0-60000ft: " << altitude << std::endl;
				std::cout << "Please re-enter altitude: " << std::endl;
				std::cin >> (altitude);
			}

			std::cout << "Enter Grid Reference: " << std::endl;
			std::cin >> gridReference;
			if (regex_match(gridReference, rGridReference)) {
				std::cout << "The Grid Reference is : " << gridReference << std::endl;
			}

			std::cout << "Enter Heading: " << std::endl;
			std::cin >> (heading);
			if (heading < 0 || heading > 360) {
				std::cout << "The Heading is is invalid! Must be between 0-360°: " << heading << std::endl;
				std::cout << "Please re-enter heading: " << std::endl;
				std::cin >> (heading);
			}

			flightSystem.AddAircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);
			break;
		}
		else if (YesNo == 'N') {
			std::cout << "You have chosen to not remove any aircraft." << std::endl;
			break;
		}
		else {
			std::cout << "Error invalid input please try again " << std::endl;
			std::cout << "Please enter [Y/N]: ";
			std::cin >> YesNo;
			YesNo = toupper(YesNo);
		}
		
	case 2: 
		std::cout << "All the aircraft will be listed below." << std::endl;
		flightSystem.ListAllAircraft();
		break;
	case 3: 
		std::cout << "All the aircraft above 30000ft will be listed below." << std::endl;
		flightSystem.ListAllCrusingAircraft();
		break;
	case 4: 
		
		std::cout << "Do you want to remove any flights from the system?" << std::endl;
		std::cin>> YesNo;
		YesNo = toupper(YesNo);
		if (YesNo == 'Y') {
			std::cout << "Do you want to remove any flights from the system?" << std::endl;
			std::getline(std::cin, flightNumber);
			std::cout << "This flight will now be deleted!" << std::endl;
			flightSystem.RemoveAircraft(flightNumber);
		}
		else if (YesNo == 'N') {
			std::cout << "You have chosen to not remove any aircraft." << std::endl;
		}
		else {
			std::cout << "Error invalid input please try again " << std::endl;
			std::cout << "Please enter [Y/N]: ";
			std::cin >> YesNo;
			YesNo = toupper(YesNo);
		}
		break;
	case 5:
		std::cout << "Do you want to change a flight's heading?" << std::endl;
		std::cin>> YesNo;
		YesNo = toupper(YesNo);
		
		if (YesNo == 'Y') {
			std::cout << "Enter flight number to change heading: " << std::endl;
			std::getline(std::cin, flightNumber);
			std::cout << "Enter the heading you wish to change it to : " << std::endl;
			std::cin>> heading;

			flightSystem.ChangeHeading(flightNumber, heading);
		}
		else if (YesNo == 'N') {
			std::cout << "You have chosen to not change any aircraft headings." << std::endl;
		}
		else {
			std::cout << "Error invalid input please try again " << std::endl;
			std::cout << "Please enter [Y/N]: ";
			std::cin >> YesNo;
			YesNo = toupper(YesNo);
		}
		break;
	case 6:
		std::cout << "Enter flight number to get heading: " << std::endl;
		std::getline(std::cin, flightNumber);
		flightSystem.GetHeading(flightNumber);
		break;
		
	case 7:
		std::cout << "Do you want to change a flight's altitude?" << std::endl;
		std::cin>> YesNo;
		YesNo = toupper(YesNo);

		if (YesNo == 'Y') {
			std::cout << "Enter flight number to change altitude: " << std::endl;
			std::getline(std::cin, flightNumber);
			std::cout << "Enter the altitude you wish to change it to: " << std::endl;
			std::cin>> (altitude);
			flightSystem.ChangeAltitude(flightNumber, altitude);
		}
		else if (YesNo == 'N') {
			std::cout << "You have chosen to change an altitude" << std::endl;
		}
		else {
			std::cout << "Error invalid input please try again " << std::endl;
			std::cout << "Please enter [Y/N]: ";
			std::cin >> YesNo;
			YesNo = toupper(YesNo);
		}
		break;
	case 8:
		std::cout << "Enter flight number you wish to get the altitude of. " << std::endl;
		std::getline(std::cin, flightNumber);
		std::cout << "This flights altitude is " << flightSystem.GetAltitude(flightNumber) << std::endl;
		break;
	case 9:
		std::cout << "There are " << flightSystem.NumAircaftinSector() << " in the sector." << std::endl;
		break;
	case 10:
		std::cout << "You have chosen to exit the program. " << std::endl;
		break;
	default:
		std::cout << "Invalid input!" << std::endl;
		std::cin.operator>> (Navigate);
	}
    return 0;
}