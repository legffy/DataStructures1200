#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


#include "driver.h"
#include "rider.h"
/*
 * File: main.cpp
 * Description: A ride sharing program that processes driver and rider information
 *              to handle ride requests, cancellations, and status updates.
 * Author: Randy Taylor
 * Date: 1/23/25
 * Features:
 * - Reads driver and rider information from input files.
 * - Handles ride requests and finds the nearest available driver.
 * - Manages cancellations and reassigns drivers if needed.
 * - Outputs results and updates driver and rider data files.
 *

 *
 */





// Used to debug.
void check(){
    std::cout<< "check" << std::endl;
}
// Used to determine if a word needs a or an based on the vehicle given.
std::string isItAOrAn(std::string aOrAn){
    if(aOrAn == "Economy"){
        return "an ";
    }
    return  "a ";
}
// Makes sure that entered number is a number in typical phone format
// Checks first three, middle 4, and last three to see if it contains a number
// Checks in between numbers to make sure it's a dash
bool checkIfValidNumber(std::string number){
    for(int i = 0; i<3; i++){
         if (!(number[i] >= '0' && number[i] <= '9')) {
            return false;
        }
    }
    if(number.find("-")!=3){
        return false;
    }
    for(int i = 4; i<7; i++){
        if (!(number[i] >= '0' && number[i] <= '9')) {
            return false;
        }
    }
    if(number.substr(7).find("-")!=0){
        return false;
    }
     for(int i = 8; i<12; i++){
        if (!(number[i] >= '0' && number[i] <= '9')) {
            return false;
        }
    }
    return true;
}
// calculate the distance between two coordinates using Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double radiusOfEarth = 6371.0; // Earth's radius in kilometers

    // convert latitude and longitude from degrees to radians
    lat1 *= M_PI / 180.0;
    lon1 *= M_PI / 180.0;
    lat2 *= M_PI / 180.0;
    lon2 *= M_PI / 180.0;

    // Haversine formula
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + cos(lat1) * cos(lat2) * sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    // distance in kilometers
    double distanceKM = radiusOfEarth * c;
    // convert it to distance in miles
    double distanceMiles = distanceKM * 0.621371;

    return distanceMiles;
}
//finds a drivers index based on a given number
int findDriverIndex(std::vector<Driver> drivers, std::string number){
    for(int d = 0; d<drivers.size(); d++){
        if(number == drivers[d].getPhoneNumber()){
            return d;
        }
    }
    return -1;
}
//finds rider index based on a given number
int findRiderIndex(std::vector<Rider> riders, std::string number){
    for(int r= 0; r<riders.size(); r++){
        if(number == riders[r].getPhoneNumber()){
            return r;
        }
    }
    return -1;
}
//finds the driver index closest to the current driver
int findClosestDriverIndex(Rider rider, std::vector<Driver> drivers){
    double rLat = rider.getLatitudePickUp();
    double rLong = rider.getLongitudePickUp();
    double minDist = calculateDistance(rLat,rLong, drivers[0].getLatitude(),drivers[0].getLongitude());
    int minIndex = -1;
    for(int i = 0; i < drivers.size(); i++){
        double currDist = calculateDistance(rLat,rLong, drivers[i].getLatitude(),drivers[i].getLongitude());
        if(currDist<=minDist && drivers[i].getVehicleType() == rider.getVehiclePreference() && drivers[i].getState() == "Available"){
            minIndex = i;
            minDist = currDist;
        }
    }
    return minIndex;
}
//converts a double with more than one decimal point to its string counter part with only one decimal point
std::string oneDecimalPlaceStr(double num){
    num = static_cast<int>(num*10)/10.0;
    std::string strNum = std::to_string(num);
    strNum = strNum.substr(0,strNum.find_last_not_of("0")+1);
    if(strNum.back() == '.'){
        strNum.substr(0,strNum.find("."));
    }
    return strNum;
}
//if the request is good from a given rider returns the message intended to placed in the output text
std::string goodRequest(Driver currDriver, Rider currRider){
    std::string aOrAn = isItAOrAn(currRider.getVehiclePreference());
    double distance = calculateDistance(currDriver.getLatitude(), currDriver.getLongitude(), currRider.getLatitudePickUp(), 
    currRider.getLongitudePickUp());
    std::string distanceAsStr = oneDecimalPlaceStr(distance);
    std::string message = "Ride requested for rider " + currRider.getFirstName() +
            ", looking for " + aOrAn + currRider.getVehiclePreference() + " vehicle.\n" +
             "Pick Up Location: " + currRider.getPickUpLocation() + ", Drop Off Location: " + 
             currRider.getDropOffLocation() + ".\nWe have found the closest driver " + currDriver.getFirstName() +
            "(" + oneDecimalPlaceStr(currDriver.getRating()) + ")" + " for you.\n" + 
            currDriver.getFirstName() + " is now " + distanceAsStr + " miles away from you."; 
    return message;
}
// If the request is bad from a given driver returns the message intended to be placed in the output text
std::string badRequest(Rider currRider){
    std::string aOrAn = isItAOrAn(currRider.getVehiclePreference());
    std::string message = "Ride requested for rider " + currRider.getFirstName() +
            ", looking for "+ aOrAn + currRider.getVehiclePreference() + " vehicle.\n" +
             "Pick Up Location: " + currRider.getPickUpLocation() + ", Drop Off Location: " + 
             currRider.getDropOffLocation() + ".\nSorry we can not find a driver for you at this moment.";
    return message;
}
// If the request got canceled by a driver then returns sthe message intended to be placed in the output text
std::string canceledRequest(Driver currDriver,std::string oldName, Rider currRider){
    std::string aOrAn = isItAOrAn(currRider.getVehiclePreference());
    double distance = calculateDistance(currDriver.getLatitude(), currDriver.getLongitude(), currRider.getLatitudePickUp(), 
    currRider.getLongitudePickUp());
    std::string distanceAsStr = oneDecimalPlaceStr(distance);
    std::string message = "Your driver " + oldName+" has canceled the ride request. We will now find a new driver for you.\n"+
            "Ride requested for rider " + currRider.getFirstName() +", looking for " + aOrAn + 
            currRider.getVehiclePreference() + " vehicle.\n" + "Pick Up Location: " + currRider.getPickUpLocation() +
            ", Drop Off Location: " + currRider.getDropOffLocation() + ".\nWe have found the closest driver " + 
            currDriver.getFirstName() +"(" + oneDecimalPlaceStr(currDriver.getRating()) + ")" + " for you.\n" + 
            currDriver.getFirstName() + " is now " + distanceAsStr + " miles away from you."; 
    return message;
}
/*
Main function that gets the information about different drivers and riders from different text files 
In the command line for the arguments you'r'e  intended to take the go like this
drivers.txt riders.txt, output0, output1, output2, number, action
The drivers text is a list of drivers with a bunch of information regarding a driver
The riders text is a list of riders with a bunch of information
The number is either drivers or riders phone number
based on this number the program looks for the number in the drivers or riders files and does a certain action based on that
the output0 file lets the user know what happened
the output 1 and 2 file are updated versions of the drivers and riders files
*/
int main(int argc, char* argv[]){
    // Opens files to read
    std::ifstream driversFile(argv[1]);
    std::ifstream ridersFile(argv[2]);
    // Creates files to import text into 
    std::ofstream output0(argv[3]);
    std::ofstream output1(argv[4]);
    std::ofstream output2(argv[5]);
    // Intializes a collection of drivers and riders
    std::vector<Driver> drivers;
    std::vector<Rider> riders;
    // Info about drivers
    std::string firstName, lastName, gender, phoneNumber, vehicleType, state, riderFirstName, riderLastName, riderPhoneNumber;
    int age;
    double rating, latitude, longitude;
    // Creates driver objects based off driver.txt file and adds them to drivers vector
    while(driversFile >> firstName >> lastName >> gender >> age >> phoneNumber >> rating >> latitude >> longitude >> vehicleType >>
          state >> riderFirstName >> riderLastName >> riderPhoneNumber){
            drivers.push_back(Driver(firstName,lastName,gender,age,phoneNumber,rating,latitude, longitude, vehicleType, state, 
            riderFirstName, riderLastName, riderPhoneNumber ));
    }
    // Info riders also have
    std::string pickUpLocation, dropOffLocation, driverFirstName, vehiclePreference ,driverLastName, driverPhoneNumber;
    double latitudePickUp, longitudePickUp, latitudeDropOff, longitudeDropOff;
    // Creates rider objects and adds them to riders vector
    while(ridersFile >> firstName >> lastName >> gender >> age >> phoneNumber >> rating >> pickUpLocation >> latitudePickUp >> 
          longitudePickUp >> dropOffLocation >>latitudeDropOff >> longitudeDropOff >> vehiclePreference >>
          state >> driverFirstName >> driverLastName >> driverPhoneNumber){
            riders.push_back(Rider(firstName, lastName, gender, age, phoneNumber, rating, pickUpLocation, 
            latitudePickUp, longitudePickUp, dropOffLocation, latitudeDropOff, longitudeDropOff, vehiclePreference, 
            state, driverFirstName, driverLastName, driverPhoneNumber ));
    }
    // Begins the process of processing the user input
    // First checks if the number inputted is in valid phone number format
    if(checkIfValidNumber(std::string(argv[6]))){
        // If its a request then the system will respond in 4 ways
        if(std::string(argv[7]) == "request" ){
            // Current Rider Index
            int cRI  =  findRiderIndex(riders, argv[6]);
            // Output if the rider doesn't exist
            if(cRI == -1){
                output0 << "Account does not exist." << std::endl;
            // Output if the driver is on the way
            }else if(riders[cRI].getState() == "Driver_on_the_way"){
                output0 << "You have already requested a ride and your driver is on the way to the pickup location." << std::endl;
            // Output if rider is already on a trip
            }else if(riders[cRI].getState() == "During_the_trip"){
                output0 << "You can not request a ride at this moment as you are already on a trip." << std::endl;
            }else{
                //current Driver Index
                // If the request is valid from the rider it will look for a driver
                int cDI  = findClosestDriverIndex(riders[cRI], drivers);
                // Output if no driver can be found
                if(cDI == -1){
                    output0 << badRequest(riders[cRI]);
                // Output if a driver is found
                // Makes changes to rider and driver objects so they can be used in the the two output files
                }else{
                    output0 << goodRequest(drivers[cDI], riders[cRI]);
                    riders[cRI].setState("Driver_on_the_way");
                    riders[cRI].setDriverFirstName(drivers[cDI].getFirstName());
                    riders[cRI].setDriverLastName(drivers[cDI].getLastName());
                    riders[cRI].setDriverPhoneNumber(drivers[cDI].getPhoneNumber());
                    drivers[cDI].setState("On_the_way_to_pickup");
                    drivers[cDI].setRiderFirstName(riders[cRI].getFirstName());
                    drivers[cDI].setRiderLastName(riders[cRI].getLastName());
                    drivers[cDI].setRiderPhoneNumber(riders[cRI].getPhoneNumber());
                }
            }
        // Action if rider or driver attempts to cancel
        }else if(std::string(argv[7]) == "cancel"){
            std::cout <<"You are canceling your ride" << std::endl;
            int cRI,cDI;
            if(findRiderIndex(riders,argv[6])>-1){
                cRI = findRiderIndex(riders,argv[6]);
                // Output if there's no driver on the way
                if(riders[cRI].getState()!="Driver_on_the_way"){
                    output0 << "You can only cancel a ride request if your driver is currently on the way to the pickup location." << std::endl;
                }else{
                // Changes the current rider and drivers information
                // Output if there's a driver on the way and the driver cancels.
                    cDI = findDriverIndex(drivers,riders[cRI].getDriverPhoneNumber());
                    output0 << "Ride request for rider " <<riders[cRI].getFirstName() <<" is now canceled by the rider." << std::endl;
                    drivers[cDI].setState("Available");
                    drivers[cDI].setRiderFirstName("null");
                    drivers[cDI].setRiderLastName("null");
                    drivers[cDI].setRiderPhoneNumber("null");
                    riders[cRI].setState("Ready_to_request");
                    riders[cRI].setDriverFirstName("null");
                    riders[cRI].setDriverLastName("null");
                    riders[cRI].setDriverPhoneNumber("null");
                }
            }else if(findDriverIndex(drivers,argv[6])>-1){
                cDI = findDriverIndex(drivers,argv[6]);
                cRI = findRiderIndex(riders,drivers[cDI].getRiderPhoneNumber());
                // Output if the driver attempts to cancel and they aren't on the way to pick up
                if(drivers[cDI].getState()!="On_the_way_to_pickup"){
                    output0 << "You can only cancel a ride request if you are currently on the way to the pickup location." << std::endl;   
                }else{
                    // Changes info if the cancel being attempted is valid
                    // Outputs the result if the driver attempts a valid cancel 
                    drivers[cDI].setState("Available");
                    drivers[cDI].setRiderFirstName("null");
                    drivers[cDI].setRiderLastName("null");
                    drivers[cDI].setRiderPhoneNumber("null");
                    riders[cRI].setState("Ready_to_request");
                    riders[cRI].setDriverFirstName("null");
                    riders[cRI].setDriverLastName("null");
                    riders[cRI].setDriverPhoneNumber("null");
                    std::string oldName = drivers[cDI].getFirstName();
                    cDI = findClosestDriverIndex(riders[cRI],drivers);
                    riders[cRI].setState("Driver_on_the_way");
                    riders[cRI].setDriverFirstName(drivers[cDI].getFirstName());
                    riders[cRI].setDriverLastName(drivers[cDI].getLastName());
                    riders[cRI].setDriverPhoneNumber(drivers[cDI].getPhoneNumber());
                    drivers[cDI].setState("On_the_way_to_pickup");
                    drivers[cDI].setRiderFirstName(riders[cRI].getFirstName());
                    drivers[cDI].setRiderLastName(riders[cRI].getLastName());
                    drivers[cDI].setRiderPhoneNumber(riders[cRI].getPhoneNumber());
                    output0 << canceledRequest(drivers[cDI],oldName,riders[cRI]) << std::endl;
                }
            // If the phone number can't be used to identify a rider or driver outputs that the account doesn't exist
            }else{
                output0 << "Account does not exist." << std::endl;
            }
        }
    // Outputs the number entered was in a incorrect format
    }else{
        output0 << "Phone number is invalid." << std::endl;
    }
    // Outputs updated drivers information to output1.txt file
    for(int i = 0; i<drivers.size(); i++){
        output1 << drivers[i].getFirstName() << " " << drivers[i].getLastName() << " " << drivers[i].getGender() << " " << 
        drivers[i].getAge() <<" " << drivers[i].getPhoneNumber() << " " << drivers[i].getRating() << " " << drivers[i].getLatitude() << " " << 
        drivers[i].getLongitude() <<" " << drivers[i].getVehicleType() << " " << drivers[i].getState() << " " << drivers[i].getRiderFirstName()<< 
        " " << drivers[i].getRiderLastName() <<" " << drivers[i].getRiderPhoneNumber() << std::endl;
    }
    // Outputs updated riders information to output2.txt file
    for(int i = 0; i<riders.size();i++){
        output2 <<riders[i].getFirstName() << " " << riders[i].getLastName() << " " << riders[i].getGender() << " " << riders[i].getAge() <<
        " " << riders[i].getPhoneNumber() << " " << riders[i].getRating() << " " << riders[i].getPickUpLocation() <<
        " " << riders[i].getLatitudePickUp() << " " << riders[i].getLongitudePickUp() << " " << riders[i].getDropOffLocation() <<
        " " << riders[i].getLatitudeDropOff() << " " << riders[i].getLongitudeDropOff() << " " << riders[i].getVehiclePreference() <<
        " " << riders[i].getState() << " " << riders[i].getDriverFirstName() << " " << riders[i].getDriverLastName() << " " << 
        riders[i].getDriverPhoneNumber() <<std::endl;

    }
    //Closes all
    driversFile.close();
    ridersFile.close();
    output0.close();
    output1.close();
    output2.close();
}