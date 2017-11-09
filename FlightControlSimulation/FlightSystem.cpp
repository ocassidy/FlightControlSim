#include "FlightSystem.h"

FlightSystem::FlightSystem() {

}

//Member functions
void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading) {
	bool AircraftCheck = 0;
	int CollisionDistance = 3000;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			std::cout << "Flight " << flightNumber << "already exists in the system" << std::endl;
			AircraftCheck == 0;
		}
		if (AircraftCheck == 1) {
			aircraftList_.push_back(Aircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading));
			CheckForCollision(flightNumber, altitude, gridReference);

			/*for (unsigned int j = 1; j < aircraftList_.size(); j++) {
				if ((aircraftList_[i].GetGridReference()) == (aircraftList_[j].GetGridReference())) {
					if (aircraftList_[i].GetAltitude() == altitude) {
						if ((aircraftList_[i].GetAltitude() >= CollisionDistance) == (aircraftList_[j].GetAltitude()  <= CollisionDistance)) {
							std::cout << "Warning – Aircraft collision possible between " << aircraftList_[i].GetFlightNumber() << " and " << aircraftList_[j].GetFlightNumber() << std::endl;
						}
					}
				}
			}*/
		}
	}
}

std::vector<Aircraft> FlightSystem::ListAllAircraft() {

	return aircraftList_;
}

std::vector<Aircraft> FlightSystem::ListAllCrusingAircraft() {
	std::vector<Aircraft> CrusingAircraft;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetAltitude() >= 30000) {
			CrusingAircraft.push_back(aircraftList_[i]);
		}
	}
	return CrusingAircraft;
}

void FlightSystem::RemoveAircraft(std::string flightNumber) {
	bool AircraftCheck = 0;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			std::cout << "Flight " << flightNumber << "is not in the system”" << std::endl;
			AircraftCheck = 0;
		}
		else if (AircraftCheck == 1) {
			aircraftList_.erase(aircraftList_.begin() + i, aircraftList_.end() - i);
		}
	}
}

void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {
	bool AircraftCheck = 0;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = 1;
			std::cout << "Heading of flight " << flightNumber << " changed to " << heading << std::endl;
			return aircraftList_[i].SetHeading(heading);
		}
		else if (AircraftCheck == 0) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

int FlightSystem::GetHeading(std::string flightNumber) const {
	bool AircraftCheck = 0;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = { 1 };
			std::cout << "The heading is : " << aircraftList_[i].GetHeading() << std::endl;
		}
		else if (AircraftCheck = 0) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return 0;
}

void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {
	bool AircraftCheck = 0;
	int CollisionDistance = 3000;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = { 1 };
			std::cout << "Alititude of flight " << flightNumber << " changed to " << altitude << std::endl;
			CheckForCollision(flightNumber, altitude, gridReference);

			/*for (unsigned int j = 1; j < aircraftList_.size(); j++){
				if ((aircraftList_[i].GetGridReference()) == (aircraftList_[j].GetGridReference())) {
					if (aircraftList_[i].GetAltitude() == altitude) {
						if ((aircraftList_[i].GetAltitude() >= CollisionDistance) == (aircraftList_[j].GetAltitude() <= CollisionDistance)) {
							std::cout << "Warning – Aircraft collision possible between " << aircraftList_[i].GetFlightNumber() << " and " << aircraftList_[j].GetFlightNumber() << std::endl;
						}
					}
				}
			}*/
			return aircraftList_[i].SetAltitude(altitude);
		}
		else if (AircraftCheck = 0) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

int FlightSystem::GetAltitude(std::string flightNumber) const {
	bool AircraftCheck{ 0 };

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = 1;
			std::cout << "The altitude is : " << aircraftList_[i].GetAltitude() << std::endl;
		}
		else if (AircraftCheck = 0) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return 0;
}

void FlightSystem::CheckForCollision(std::string, int altitude, std::string gridReference) {
	int CollisionDistance = 3000;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		for (unsigned int j = 1; j < aircraftList_.size(); j++) {
			if ((aircraftList_[i].GetGridReference()) == (aircraftList_[j].GetGridReference())) {
				if (aircraftList_[i].GetAltitude() == altitude) {
					if ((aircraftList_[i].GetAltitude() >= CollisionDistance) == (aircraftList_[j].GetAltitude() <= CollisionDistance)) {
						std::cout << "Warning – Aircraft collision possible between " << aircraftList_[i].GetFlightNumber() << " and " << aircraftList_[j].GetFlightNumber() << std::endl;
					}
				}
			}
		}
	}
}

int FlightSystem::NumAircaftinSector() {

	return aircraftList_.size();
}