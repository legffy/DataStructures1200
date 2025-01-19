#ifndef __DRIVER_H
#define __DRIVER_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

class Driver{
    public:
        Driver();
        Driver(std::string aFirstName, std::string aLastName, std::string aGender, int aAge, std::string aPhoneNumber, double aRating,
                double aLatitude, double aLongitude, std::string aVechicleType, std::string aState, std::string aRiderFirstName,
                std::string aRiderLastName, std::string aRiderPhoneNumber);
    //ACCESSORS
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getGender() const;
        int getAge() const;
        std::string getPhoneNumber() const;
        double getRating() const;
        double getLatitude() const;
        double getLongitude() const;
        std::string getVehicleType() const;
        std::string getState() const;
        std::string getRiderFirstName() const;
        std::string getRiderLastName() const;
        std::string getRiderPhoneNumber() const;

    //MODIFIERS
        void setFirstName(std::string aFirstName);
        void setLastName(std::string aLastName);
        void setGender(std::string aGender);
        void setAge(int aAge);
        void setPhoneNumber(std::string aPhoneNumber);
        void setRating(double aRating);
        void setLatitude(double aLatitude);
        void setLongitude(double aLongtitude);
        void setVehicleType(std::string aVehicleType);
        void setState(std::string aState);
        void setRiderFirstName(std::string aRiderFirstName);
        void setRiderLastName(std::string aRiderLastName);
        void setRiderPhoneNumber(std::string aRiderPhoneNumber);
    
    //OTHER MEMBER FUNCTIONS
    
    private: //MEMBER VARIABLES
        std::string firstName;
        std::string lastName;
        std::string gender;
        int age;
        std::string phoneNumber;
        double rating;
        double latitude;
        double longitude;
        std::string vehicleType;
        std::string state;
        std::string riderFirstName;
        std::string riderLastName;
        std::string riderPhoneNumber;
};
//NON-MEMBER FUNCTIONS
bool numberExists(std::string);
#endif