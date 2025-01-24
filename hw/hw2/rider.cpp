#include "rider.h"
// CONSTRUCTORS
Rider::Rider(): firstName(""), lastName(""), gender(""), age(0),phoneNumber(""), rating(0),pickUpLocation(""),latitudePickUp(0), 
                longitudePickUp(0), dropOffLocation(""), latitudeDropOff(0), longitudeDropOff(0), vehiclePreference (""), state ("Available"), 
                driverFirstName(""), driverLastName(""), driverPhoneNumber("") {}
Rider::Rider(std::string aFirstName, std::string aLastName, std::string aGender, int aAge, std::string aPhoneNumber, double aRating, 
                std::string aPickUpLocation, double aLatitudePickUp, double aLongitudePickUp, std::string aDropOffLocation,
                double aLatitudeDropOff, double aLongitudeDropOff,std::string aVechiclePrefermce, std::string aState, 
                std::string aDriverFirstName,std::string aDriverLastName, std::string aDriverPhoneNumber):
                firstName(aFirstName), lastName(aLastName), gender(aGender),age(aAge), phoneNumber(aPhoneNumber), rating(aRating),
                pickUpLocation(aPickUpLocation), latitudePickUp(aLatitudePickUp), longitudePickUp(aLongitudePickUp), 
                dropOffLocation(aDropOffLocation), latitudeDropOff(aLatitudeDropOff), longitudeDropOff(aLongitudeDropOff), 
                vehiclePreference(aVechiclePrefermce), state(aState), driverFirstName(aDriverFirstName), driverLastName(aDriverLastName), 
                driverPhoneNumber(aDriverPhoneNumber) {}
Rider::Rider(std::string aNotFoundNumber): firstName(""), lastName(""), gender(""), age(0),phoneNumber("invalid"), 
                rating(0), pickUpLocation(""),latitudePickUp(0), longitudePickUp(0), dropOffLocation(""), latitudeDropOff(0), longitudeDropOff(0), vehiclePreference (""), state ("Available"), 
                driverFirstName(""), driverLastName(""), driverPhoneNumber("") {}
// ACCESSORS
std::string Rider::getFirstName() const{
    return firstName;
}
std::string Rider::getLastName() const{
    return lastName;
}
std::string Rider::getGender() const{
    return gender;
}
int Rider::getAge() const{
    return age;
}
std::string Rider::getPhoneNumber() const{
    return phoneNumber;
}
double Rider::getRating() const{
    return rating;
}
std::string Rider::getPickUpLocation() const{
    return pickUpLocation;
}
double Rider::getLatitudePickUp() const{
    return latitudePickUp;
}
double Rider::getLongitudePickUp() const{
    return longitudePickUp;
}
std::string Rider::getDropOffLocation() const{
    return dropOffLocation;
}
double Rider::getLatitudeDropOff() const{
    return latitudeDropOff;
}
double Rider::getLongitudeDropOff() const{
    return longitudeDropOff;
}
std::string Rider::getVehiclePreference() const{
    return vehiclePreference;
}
std::string Rider::getState() const{
    return state;
}
std::string Rider::getDriverFirstName() const{
    return driverFirstName;
}
std::string Rider::getDriverLastName() const{
    return driverLastName;
}
std::string Rider::getDriverPhoneNumber() const{
    return driverPhoneNumber;
}
// MODIFIERS
void Rider::setFirstName(std::string aFirstName){
    firstName = aFirstName;
}
void Rider::setLastName(std::string aLastName){
    lastName = aLastName;
}
void Rider::setGender(std::string aGender){
    gender = aGender;
}
void Rider::setAge(int aAge){
    age = aAge;
}
void Rider::setPhoneNumber(std::string aPhoneNumber){
    phoneNumber = aPhoneNumber;
}
void Rider::setRating(double aRating){
    rating = aRating;
}
void Rider::setPickUpLocation(std::string aPickUpLocation){
    pickUpLocation = aPickUpLocation;
}
void Rider::setLatitudePickUp(double aLatitudePickUp){
    latitudePickUp= aLatitudePickUp;
}
void Rider::setLongitudePickUp(double aLongitudePickUp){
    longitudePickUp = aLongitudePickUp;
}
void Rider::setDropOffLocation(std::string aDropOffLocation){
    dropOffLocation = aDropOffLocation;
}
void Rider::setLatitudeDropOff(double aLatitudeDropOff){
    latitudeDropOff= aLatitudeDropOff;
}
void Rider::setLongitudeDropOff(double aLongitudeDropOff){
    longitudeDropOff = aLongitudeDropOff;
}
void Rider::setVehiclePreference(std::string aVechiclePreference){
    vehiclePreference = aVechiclePreference;
}
void Rider::setState(std::string aState){
    state = aState;
}
void Rider::setDriverFirstName(std::string aDriverFirstName){
    driverFirstName = aDriverFirstName;
}
void Rider::setDriverLastName(std::string aDriverLastName){
    driverLastName = aDriverLastName;
}
void Rider::setDriverPhoneNumber(std::string aDriverPhoneNumber){
    driverPhoneNumber = aDriverPhoneNumber;
}
// NON-MEMBER FUNCTIONS

//returns info about a given object created by this class
std::ostream& operator<<(std::ostream& os, const Rider& rider){
    os << "Rider* " << "Name: " << rider.getFirstName() << " " << rider.getLastName() << std::endl <<
    "Gender: "  << rider.getGender() << std::endl << "Age: " << rider.getAge() << std::endl <<
    "Phone Number: " << rider.getPhoneNumber() << std::endl << "Rating: " << rider.getRating() << std::endl <<
    "Pick up Location: " << rider.getPickUpLocation() << std::endl <<
    "Pick up Latitude and Longitude: " << rider.getLatitudePickUp() << ", " << rider.getLongitudePickUp() << std::endl <<
    "Drop off Location: " << rider.getDropOffLocation() << std:: endl << 
    "Drop off Latitude and Longitude: " << rider.getLatitudeDropOff() << ", " << rider.getLongitudeDropOff() << std::endl << 
    "Vehichle Preference: " << rider.getVehiclePreference() << std::endl << "State: " << rider.getState() << std::endl << 
    std::endl << "Driver* " << "Name: " << rider.getDriverFirstName() << " " << rider.getDriverLastName() << std::endl <<
    "Phone Number: " << rider.getDriverPhoneNumber() << std::endl;
    return os;
} 
