#include "FlightSystem.h"

//Main : Will be used for UI navigation
int main()
{
	//FlightSystem Object instantiated
	FlightSystem flightSystem;

	//Declaration of Navigate
	int Navigate;

	//Declaration of flight number
	std::string flightNumber;
	std::regex rFlightNumber{ R"(\w?\w?\w?\w?[a-zA-Z]{1,4}(\s)?\d?\d?\d?\d?[0-9]{1,4}$)" };
	bool flightMatch = 0;

	//Declaration of for airline
	std::string airline;
	bool airlineMatch = 0;

	//Declaration of aircraft type
	std::string aircraftType;
	bool aircraftMatch = 0;

	//Declaration of groundspeed
	int groundspeed;
	bool groundspeedMatch = 1;

	//Declaration of altitude
	int altitude;
	bool altitudeMatch = 0;

	//Declaration of grid reference
	std::string gridReference;
	std::regex rGridReference{ R"(\w?[a-jA-J]\d{1,1})" };
	bool gridReferenceMatch = 0;

	//Declaration of heading
	int heading;
	bool headingMatch = 0;

	//while (Navigate != 10) {
		//Menu print

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
		//std::cin >> (Navigate);

	//	switch (Navigate)
	//	{
	//		//AddAircraft variables entered and passed to flightSystem.AddAircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);
	//	case 1:
	//		//Verifications for each entered variable
	//		std::cout << "Enter Flight Number: " << std::endl;
	//		std::getline(std::cin, flightNumber);
	//		while (flightMatch != 1) {
	//			if (regex_match(flightNumber, rFlightNumber)) {
	//				std::cout << "Flight number accepted! The Flight Number is : " << flightNumber << std::endl;
	//				flightMatch = 1;
	//			}
	//			else {
	//				std::cout << "Flight number invalid please enter again" << std::endl;
	//				std::getline(std::cin, flightNumber);
	//			}
	//		}

	//		while (aircraftMatch != 1) {
	//			std::cout << "Enter Airline: " << std::endl;
	//			std::getline(std::cin, airline);
	//			if (airline.length() >= 4 || airline.length() <= 20) {
	//				std::cout << "The Airline is : " << airline << std::endl;
	//				aircraftMatch = 1;
	//			}
	//			else {
	//				std::cout << "Airline is invalid please enter again" << std::endl;
	//				std::getline(std::cin, airline);
	//			}
	//		}

	//		while (aircraftMatch != 1) {
	//			std::cout << "Enter Aircraft Type: " << std::endl;
	//			std::getline(std::cin, aircraftType);
	//			if (aircraftType.length() <= 4 || aircraftType.length() >= 20) {
	//				std::cout << "The Aircraft Type is : " << aircraftType << std::endl;
	//				aircraftMatch = 1;
	//			}
	//			else {
	//				std::cout << "Enter Aircraft Type: " << std::endl;
	//				std::cin >> aircraftType;
	//			}

	//		}

	//		std::cout << "Enter Groundspeed: " << std::endl;
	//		std::cin >> (groundspeed);
	//		while (groundspeedMatch != 1) {
	//			if (groundspeed <= 0 || groundspeed > 800) {
	//				std::cout << "The Groundspeed is invalid! Must be between 0-800mph: " << groundspeed << std::endl;
	//				std::cout << "Please re-enter Groundspeed: " << std::endl;
	//				std::cin >> (groundspeed);
	//			}
	//			else if (groundspeed >= 0 || groundspeed < 800) {
	//				std::cout << "Groundspeed is " << groundspeed << std::endl;
	//				groundspeedMatch = 1;
	//			}
	//		}

	//		std::cout << "Enter Altitude: " << std::endl;
	//		std::cin >> (altitude);
	//		while (altitudeMatch != 1) {
	//			if (altitude < 0 || altitude > 60000) {
	//				std::cout << "This Altitude is invalid! Must be between 0-60000ft: " << altitude << std::endl;
	//				std::cout << "Please re-enter altitude: " << std::endl;
	//				std::cin >> (altitude);
	//			}
	//			else if (altitude > 0 || altitude < 60000) {
	//				std::cout << "Altitude is " << altitude << std::endl;
	//				altitudeMatch = 1;
	//			}
	//		}

	//		std::cout << "Enter Grid Reference: " << std::endl;
	//		std::getline(std::cin, gridReference);
	//		while (gridReferenceMatch != 1) {
	//			if (regex_match(gridReference, rGridReference)) {
	//				std::cout << "This Grid Reference is valid!" << std::endl;
	//				gridReferenceMatch = 1;
	//			}
	//			else {
	//				std::cout << "This Grid Reference is invalid! Please Re-enter" << std::endl;
	//				std::getline(std::cin, gridReference);
	//			}
	//		}

	//		std::cout << "Enter Heading: " << std::endl;
	//		std::cin >> (heading);
	//		while (headingMatch != 1) {
	//			if (heading < 0 || heading > 360) {
	//				std::cout << "The Heading is invalid! Must be between 0-360°: " << heading << std::endl;
	//				std::cout << "Please re-enter heading: " << std::endl;
	//				std::cin >> (heading);
	//			}
	//			else if (heading > 0 || heading < 360) {
	//				std::cout << "Heading Accepted!" << std::endl;
	//				headingMatch = 1;
	//			}
	//		}
	//		flightSystem.AddAircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);
	//		break;

	//	case 2:
	//		//Returns and lists all aircraft in the system
	//		std::cout << "All the aircraft will be listed below." << std::endl;
	//		flightSystem.ListAllAircraft();
	//		break;

	//	case 3:
	//		//Returns and lists all aircraft in the system above 30000ft
	//		std::cout << "All the aircraft above 30000ft will be listed below." << std::endl;
	//		flightSystem.ListAllCrusingAircraft();
	//		break;

	//	case 4:
	//		//Removes flights from the system
	//		std::cout << "Enter flightnumber of flight you wish to delete" << std::endl;
	//		std::cin >> flightNumber;
	//		std::cout << "This flight will now be deleted!" << std::endl;
	//		flightSystem.RemoveAircraft(flightNumber);
	//		break;
	//	case 5:
	//		//Changes heading of an aircraft
	//		std::cout << "Enter flight number to change heading: " << std::endl;
	//		std::cin >> flightNumber;
	//		std::cout << "Enter the heading you wish to change it to : " << std::endl;
	//		std::cin >> heading;

	//		flightSystem.ChangeHeading(flightNumber, heading);
	//		break;
	//	case 6:
	//		//Gets the heading of an aircraft
	//		std::cout << "Enter flight number to get heading: " << std::endl;
	//		std::cin >> flightNumber;
	//		std::cout << "Enter flight number to get heading:" << flightSystem.GetHeading(flightNumber) << std::endl;
	//		break;

	//	case 7:
	//		//Changes the altitude of an aircraft
	//		std::cout << "Enter flight number to change altitude: " << std::endl;
	//		std::cin >> flightNumber;
	//		std::cout << "Enter the altitude you wish to change it to: " << std::endl;
	//		std::cin >> (altitude);
	//		flightSystem.ChangeAltitude(flightNumber, altitude);
	//		break;
	//	case 8:
	//		//Gets the altitude of an aircraft
	//		std::cout << "Enter flight number you wish to get the altitude of. " << std::endl;
	//		std::cin >> flightNumber;
	//		std::cout << "This flights altitude is " << flightSystem.GetAltitude(flightNumber) << std::endl;
	//		break;
	//	case 9:
	//		//Prints the number of aircraft in the sector
	//		std::cout << "There are " << flightSystem.NumAircaftinSector() << " in the sector." << std::endl;
	//		break;
	//	case 10:
	//		//Exits the program
	//		std::cout << "You have chosen to exit the program. " << std::endl;
	//		break;
	//	default:
	//		std::cout << "Invalid input!" << std::endl;
	//		std::cout << "Please re-try!" << std::endl;
	//		std::cin >> (Navigate);
	//	}
	//}

		flightSystem.AddAircraft("KYGH43", "British Airlines", "Boeing747", 345, 34675, "A3", 247);
		flightSystem.AddAircraft("NDFG33", "Irish Air", "Boeing747", 434, 33000, "A3", 354);
		flightSystem.AddAircraft("QKE322", "German Lufthansa", "Boeing747", 763, 37622, "A5", 134);
		flightSystem.AddAircraft("MLAU792", "Sweedish Plones", "Boeing747", 236, 12346, "A8", 168);
		return 0;
}