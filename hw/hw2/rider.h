#ifndef __MYCLASS_H
#define __MYCLASS_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

/*
Header of Rider Class

Responsible for creating the individual data when it comes to identifying different riders in taxi situation.
Randy Taylor
1/23/25
*/
class Rider{
    public:
    // CONSTRUCTORS
        Rider();
        Rider(std::string aFirstName, std::string aLastName, std::string aGender, int aAge, std::string aPhoneNumber, double aRating, 
                std::string aPickUpLocation, double aLatitudePickUp, double aLongitudePickUp, std::string aDropOffLocation,
                double aLatitudeDropOff, double aLongitudeDropOff,std::string aVechiclePrefermce, std::string aState, 
                std::string aDriverFirstName,std::string aDriverLastName, std::string aDriverPhoneNumber);
        Rider(std::string aNotFoundNumber);
    // ACCESSORS
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getGender() const;
        int getAge() const;
        std::string getPhoneNumber() const;
        double getRating() const;
        std::string getPickUpLocation() const;
        double getLatitudePickUp() const;
        double getLongitudePickUp() const;
        std::string getDropOffLocation() const;
        double getLatitudeDropOff() const;
        double getLongitudeDropOff() const;
        std::string getVehiclePreference() const;
        std::string getState() const;
        std::string getDriverFirstName() const;
        std::string getDriverLastName() const;
        std::string getDriverPhoneNumber() const;

    //MODIFIERS
        void setFirstName(std::string aFirstName);
        void setLastName(std::string aLastName);
        void setGender(std::string aGender);
        void setAge(int aAge);
        void setPhoneNumber(std::string aPhoneNumber);
        void setRating(double aRating);
        void setPickUpLocation(std::string aPickUpLocation); 
        void setLatitudePickUp(double aLatitudePickUp);
        void setLongitudePickUp(double aLongtitudePickUp);
        void setDropOffLocation(std::string aDropOffLocation); 
        void setLatitudeDropOff(double aLatitudeDropOff);
        void setLongitudeDropOff(double aLongtitudeDropOff);
        void setVehiclePreference(std::string aVehicleType);
        void setState(std::string aState);
        void setDriverFirstName(std::string aDriverFirstName);
        void setDriverLastName(std::string aDriverLastName);
        void setDriverPhoneNumber(std::string aDriverPhoneNumber);
    private:
        std::string firstName;
        std::string lastName;
        std::string gender;
        int age;
        std::string phoneNumber;
        double rating;
        std::string pickUpLocation;
        double latitudePickUp;
        double longitudePickUp;
        std::string dropOffLocation;
        double latitudeDropOff;
        double longitudeDropOff;
        std::string vehiclePreference;
        std::string state;
        std::string driverFirstName;
        std::string driverLastName;
        std::string driverPhoneNumber;
};
//NON-MEMBER FUNCTIONS
std::ostream& operator<<(std::ostream& os, const Rider& rider);
#endif