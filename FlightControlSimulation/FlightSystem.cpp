#include "FlightSystem.h"

FlightSystem::FlightSystem() {

}

//Member functions
void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading) {
	bool AircraftCheck{ 0 };
	
	for (unsigned int i = 0; i < aircraftList_.size(); i++){
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			std::cout << "Flight " << flightNumber << "already exists in the system" << std::endl;
			AircraftCheck = { 0 };
		}
		if (AircraftCheck = { 1 }) {
			aircraftList_.push_back(Aircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading));
			if (aircraftList_[i].GetGridReference() == gridReference) {
				if (aircraftList_[i].GetAltitude() == altitude) {
					if (altitude - aircraftList_[i].GetAltitude() <= 3000) {
						std::cout << "Warning – Aircraft collision possible between " << flightNumber << " and " << flightNumber << std::endl;
					}
				}
			}
		}
	}
}

std::vector<Aircraft> FlightSystem::ListAllAircraft() {

	return aircraftList_;
}

std::vector<Aircraft> FlightSystem::ListAllCrusingAircraft()
{
	std::vector<Aircraft> CrusingAircrafts;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetAltitude() >= 30000) {
			CrusingAircrafts.push_back(aircraftList_[i]);
		}
	}
	return CrusingAircrafts;
}

void FlightSystem::RemoveAircraft(std::string flightNumber) {
	bool AircraftCheck{ 0 };

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			std::cout << "Flight " << flightNumber << "is not in the system”" << std::endl;
			AircraftCheck = { 0 };
		}
		else if (AircraftCheck = { 1 }) {
			aircraftList_.erase(aircraftList_.begin()+i, aircraftList_.end()-i);
		}
	}
}

void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {
	bool AircraftCheck{ 0 };

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = { 1 };
			std::cout << "This flight exists! Its heading will now change!" << std::endl;
			return aircraftList_[i].SetHeading(heading);
			}
		else if (AircraftCheck = { 0 }) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

int FlightSystem::GetHeading(std::string flightNumber) const {
	bool AircraftCheck{ 0 };

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = { 1 };
			std::cout << "The heading is : " << aircraftList_[i].GetHeading() << std::endl;
		}
		else if (AircraftCheck = { 0 }) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return 0;
}

void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {
	bool AircraftCheck{ 0 };
	int CollisionDistance = 3000;

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = { 1 };
			std::cout << "This flight exists! Its altitude will now change!" << std::endl;
			if (aircraftList_[i].GetGridReference() == flightNumber) {
				if (aircraftList_[i].GetAltitude() - altitude <= CollisionDistance) {
					std::cout << "Warning – Aircraft collision possible between " << flightNumber << " and " << flightNumber << std::endl;
				}
			}
			return aircraftList_[i].SetAltitude(altitude);
		}
		else if (AircraftCheck = { 0 } ) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

int FlightSystem::GetAltitude(std::string flightNumber) const {
	bool AircraftCheck{ 0 };

	for (unsigned int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			AircraftCheck = { 1 };
			std::cout << "The altitude is : " << aircraftList_[i].GetHeading() << std::endl;
		}
		else if (AircraftCheck = { 0 }) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return 0;
}

int FlightSystem::NumAircaftinSector() {
	
	return aircraftList_.size();
}
