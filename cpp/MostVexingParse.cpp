/// @file
/// @brief Illustrates C++ behavior to interpret anything that looks like a function
/// as a function

struct Clock { };

struct Alarm
{
    Alarm(const Clock& clock) { };
    void GetTimeRemaining() { };
    
};

/// @brief Run the tests
void MostVexingParse()
{
    Alarm alarm1( Clock() );
    //alarm1.GetTimeRemaining(); // compile error on this line!
    // error: request for member ‘GetTimeRemaining’ in ‘alarm1’,
    //        which is of non-class type ‘Alarm(Clock (*)())
    
    // Multiple ways to fix:
    
    Alarm alarm2( (Clock()) );
    alarm2.GetTimeRemaining();
    
    Alarm alarm3{ Clock() };
    alarm3.GetTimeRemaining();

    Alarm alarm4( Clock{} );
    alarm4.GetTimeRemaining();

    Alarm alarm5{ Clock{} };
    alarm5.GetTimeRemaining();
}
