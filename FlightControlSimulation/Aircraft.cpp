#include "Aircraft.h"

Aircraft::Aircraft() {

}

Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading) 
: flightNumber_{ flightNumber }, airline_{ airline }, aircraftType_{ aircraftType }, groundSpeed_{ groundspeed }, altitude_{ altitude }, gridReference_{ gridReference }, heading_{heading} {
	
}

void Aircraft::SetFlightNumber(std::string flightNumber) {
	flightNumber = flightNumber_;
}

std::string Aircraft::GetFlightNumber() const {
	return flightNumber_;
}

void Aircraft::SetAirline(std::string airline) {
	airline = airline_;
}

std::string Aircraft::GetAirline() const {
	return airline_;
}

void Aircraft::SetAircraftType(std::string aircraftType) {
	aircraftType = aircraftType_;
}

std::string Aircraft::GetAircraftType() const {
	return aircraftType_;;
}

void Aircraft::SetGroundSpeed(int groundSpeed) {
	groundSpeed = groundSpeed_;
}

int Aircraft::GetGroundSpeed() const {
	return groundSpeed_;
}

void Aircraft::SetAltitude(int altitude) {
	altitude_ = altitude;
}

int Aircraft::GetAltitude() const {
	return altitude_;
}

void Aircraft::SetGridReference(std::string gridReference) {
	gridReference = gridReference_;
}

std::string Aircraft::GetGridReference() const {
	return gridReference_;
}

void Aircraft::SetHeading(int heading) {
	heading = heading_;
}

int Aircraft::GetHeading() const {
	return heading_;
}
