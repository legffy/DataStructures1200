

#include "driver.h"

Driver::Driver(): firstName(""), lastName(""), gender(""), age(0),phoneNumber(""), rating(0),latitude(0), longitude (0), 
                vehicleType (""), state ("Available"), riderFirstName(NULL), riderLastName(NULL), riderPhoneNumber(NULL) {}
Driver::Driver(std::string aFirstName, std::string aLastName, std::string aGender, int aAge, std::string aPhoneNumber, double aRating,
                double aLatitude, double aLongitude, std::string aVechicleType, std::string aState, std::string aRiderFirstName,
                std::string aRiderLastName, std::string aRiderPhoneNumber):
                firstName(aFirstName), lastName(aLastName), gender(aGender),age(aAge), phoneNumber(aPhoneNumber), rating(aRating),
                latitude(aLatitude), longitude(aLongitude), vehicleType(aVechicleType), state(aState), riderFirstName(aRiderFirstName),
                riderLastName(aRiderLastName), riderPhoneNumber(aRiderPhoneNumber) {}

std::string Driver::getFirstName() const{
    return firstName;
}
std::string Driver::getLastName() const{
    return lastName;
}
std::string Driver::getGender() const{
    return gender;
}
int Driver::getAge() const{
    return age;
}
std::string Driver::getPhoneNumber() const{
    return phoneNumber;
}
double Driver::getRating() const{
    return rating;
}
double Driver::getLatitude() const{
    return latitude;
}
double Driver::getLongitude() const{
    return longitude;
}
std::string Driver::getVehicleType() const{
    return vehicleType;
}
std::string Driver::getState() const{
    return state;
}
std::string Driver::getRiderFirstName() const{
    return riderFirstName;
}
std::string Driver::getRiderLastName() const{
    return riderLastName;
}
std::string Driver::getRiderPhoneNumber() const{
    return riderPhoneNumber;
}

void Driver::setFirstName(std::string aFirstName){
    firstName = aFirstName;
}
void Driver::setLastName(std::string aLastName){
    lastName = aLastName;
}
void Driver::setGender(std::string aGender){
    gender = aGender;
}
void Driver::setAge(int aAge){
    age = aAge;
}
void Driver::setPhoneNumber(std::string aPhoneNumber){
    phoneNumber = aPhoneNumber;
}
void Driver::setRating(double aRating){
    rating = aRating;
}
void Driver::setLatitude(double aLatitude){
    latitude= aLatitude;
}
void Driver::setLongitude(double aLongitude){
    longitude = aLongitude;
}
void Driver::setVehicleType(std::string aVechicleType){
    vehicleType = aVechicleType;
}
void Driver::setState(std::string aState){
    state = aState;
}
void Driver::setRiderFirstName(std::string aRiderFirstName){
    riderFirstName = aRiderFirstName;
}
void Driver::setRiderLastName(std::string aRiderLastName){
    riderLastName = aRiderLastName;
}
void Driver::setPhoneNumber(std::string aRiderPhoneNumber){
    riderPhoneNumber = aRiderPhoneNumber;
}


