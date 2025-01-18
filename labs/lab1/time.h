class Time {
public:
  Time();
  Time(int aHour, int aMinute, int aSecond);

  // ACCESSORS
  int getHour() const;
  int getMinute() const;
  int getSecond() const;

  // MODIFIERS
  void setHour(int aHour);
  void setMinute(int aMinute);
  void setSecond(int aSecond);
  //OTHER Member functions
  void PrintAMPM();
private:  // REPRESENTATION (member variables)
  int hour;
  int minute;
  int second;
};

// prototypes for other functions that operate on class objects are often
// included in the header file, but outside of the class declaration
