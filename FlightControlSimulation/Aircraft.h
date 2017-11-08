#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>

class Aircraft {
private:
	std::string flightNumber_;
	std::string airline_;
	std::string aircraftType_;
	int groundSpeed_;
	int altitude_;
	std::string gridReference_;
	int heading_;

public:

	//Default constructor
	Aircraft::Aircraft();

	//Non-default constructor
	Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading);

	//Member functions
	void SetFlightNumber(std::string flightNumber);

	std::string GetFlightNumber() const;

	void SetAirline(std::string airline);

	std::string GetAirline() const;

	void SetAircraftType(std::string aircraftType);

	std::string GetAircraftType() const;

	void SetGroundSpeed(int groundSpeed);

	int GetGroundSpeed() const;

	void SetAltitude(int altitude);

	int GetAltitude() const;

	void SetGridReference(std::string gridReference);

	std::string GetGridReference() const;

	void SetHeading(int heading);

	int GetHeading() const;

};