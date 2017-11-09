#include "FlightSystem.h"

FlightSystem::FlightSystem() {

}

//Member functions
void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading)
{
	int VectorSize = aircraftList_.size();
	bool AircraftCheck = 0;
	int CollisionDistance = 3000;

	for (unsigned int i = 0; i < VectorSize; i++){
		if (aircraftList_[i].GetFlightNumber() == flightNumber){
			AircraftCheck = 1;
			std::cout << "Flight " << flightNumber << " already exists in the system" << std::endl;
		}
	}

	if (AircraftCheck == 0) {
		aircraftList_.push_back(Aircraft(flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading));

		for (unsigned int i = 0; i < aircraftList_.size() - 1; i++) {
			if (aircraftList_[i].GetGridReference() == gridReference) {
				if (std::abs(aircraftList_[i].GetAltitude() - altitude) <= CollisionDistance) {
					std::cout << "Warning - Aircraft collision possible between " << flightNumber << " and " << aircraftList_[i].GetFlightNumber() << std::endl;
				}
			}
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
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
			AircraftCheck = 0;
		}
		else if (AircraftCheck == 1) {
			aircraftList_.erase(aircraftList_.begin() + i);
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

void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude){
	int AircraftCheck = -1;
	int CollisionDistance = 3000;

	for (unsigned int i = 0; i < aircraftList_.size(); i++){
		if (aircraftList_[i].GetFlightNumber() == flightNumber){
			AircraftCheck = i;
			std::cout << "Alititude of flight " << flightNumber << " changed to " << altitude << std::endl;
			aircraftList_[i].SetAltitude(altitude);
		}
	}

	if (AircraftCheck == -1){
		std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
	}
	else{
		for (unsigned int i = 0; i < aircraftList_.size(); i++){
			if (i != AircraftCheck){
				if (aircraftList_[i].GetGridReference() == aircraftList_[AircraftCheck].GetGridReference()){
					if ((aircraftList_[i].GetAltitude() - altitude) <= CollisionDistance){
						std::cout << "Warning - Aircraft collision possible between " << aircraftList_[AircraftCheck].GetFlightNumber() << " and " << aircraftList_[i].GetFlightNumber() << std::endl;
					}
				}
			}
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

int FlightSystem::NumAircaftinSector() {

	return aircraftList_.size();
}