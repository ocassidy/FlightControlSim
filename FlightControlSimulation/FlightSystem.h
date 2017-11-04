#pragma once
#include "Aircraft.h"

class FlightSystem {
private:
	 std::vector<Aircraft> aircraftList_;

public:

	FlightSystem::FlightSystem();

	//Member functions
	void AddAircraft(std::string flightNumber, std::string  airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading);

	std::vector<Aircraft> ListAllAircraft();

	std::vector<Aircraft> ListAllCrusingAircraft();

	void RemoveAircraft(std::string flightNumber);

	void ChangeHeading(std::string flightNumber, int heading);

	int GetHeading(std::string flightNumber) const;

	void ChangeAltitude(std::string flightNumber, int altitude);

	int GetAltitude(std::string flightNumber) const;

	int NumAircaftinSector();
};