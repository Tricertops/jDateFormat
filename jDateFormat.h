//
//  jDateFormat.h
//  The MIT License
//  © Martin Kiss
//
//  Never again write date formats by hand. Is it yyyy or YYYY? Is 24-hour clock HH or hh? Month is M or m?
//  - Use jYear and avoid Year Of Week bug. Use jYearOfWeek to have that bug anyway.
//  - Use jHour_12_Padded and jHour_24_Padded instead of hh or HH.
//  - Use jMonth and jMinute instead of M or m.
//
//  These macros produce NSString literals, so it’s easy to chain them:
//    dateFormatter.dateFormat = jHour_12 @":" jMinute_Padded jPeriod;
//
//  Source: http://www.unicode.org/reports/tr35/tr35-31/tr35-dates.html#Date_Format_Patterns
//


#define jLiteral(x...) jEscape jString(x) jEscape //! Specify a non-pattern part.
#define jPattern(x)    jString(x)
#define jString(x...)  @#x
#define jSpace         @" "
#define jEscape        @"'"
#define jApostrophe    Escape Escape
#define jDash          jString(-)
#define jColon         jString(:)
#define jDot           jString(.)
#define jSlash         jString(/)


#define jDateTime_ISO           jDate_ISO jTime_ISO jZone_ISO    //! 2016-02-13T15:07:24+00:00
#define jDateTime_ISO_Z         jDate_ISO jTime_ISO jZone_ISO_Z  //! 2016-02-13T15:07:24Z
#define jDateTime_ISO_Compact   jDate_ISO_Compact jTime_ISO_Compact jZone_ISO_Compact    //! 20160213T150724+0000
#define jDateTime_ISO_Z_Compact jDate_ISO_Compact jTime_ISO_Compact jZone_ISO_Z_Compact  //! 20160213T150724Z
#define jDateTime_HTTP          jDate_HTTP jSpace jTime_HTTP jSpace jLiteral(Z)  //! Sat, 13 Feb 2016 17:36:23 Z


#pragma mark - Time

#define jTime_12           jTime_12_Base jSpace jPeriod                 //! 03:07 PM
#define jTime_12_Second    jTime_12_Base jColon jSecond jSpace jPeriod  //! 03:07:24 PM
#define jTime_12_Base      jHour_12_Padded jColon jMinute_Padded        //! 03:07
#define jTime_24           jHour_24_Padded jColon jMinute_Padded        //! 15:07
#define jTime_24_Second    jTime_24 Colon jSecond                       //! 15:07:24
#define jTime_ISO          jLiteral(T) jHour_ISO jColon jMinute_ISO jColon jSecond_ISO  //! T15:07:24
#define jTime_ISO_Compact  jLiteral(T) jHour_ISO jMinute_ISO jSecond_ISO                //! T150724
#define jTime_HTTP         jTime_24_Padded  //! 15:07:24

#define jHour_12         jPattern( h )    //! 1…12
#define jHour_12_Padded  jPattern( hh )   //! 01…12
#define jHour_24         jPattern( H )    //! 0…23
#define jHour_24_Padded  jPattern( HH )   //! 00…23
#define jHour_ISO        jHour_24_Padded  //! 00…23

#define jMinute         jPattern( m )   //! 0…59
#define jMinute_Padded  jPattern( mm )  //! 00…59
#define jMinute_ISO     jMinute_Padded  //! 00…59

#define jSecond             jPattern( s )    //! 0…59
#define jSecond_Padded      jPattern( ss )   //! 00…59
#define jSecond_Fraction_1  jPattern( S )    //! 0…9 as deciseconds
#define jSecond_Fraction_2  jPattern( SS )   //! 00…99 as centiseconds
#define jSecond_Fraction_3  jPattern( SSS )  //! 000…999 as miliseconds
#define jSecond_ISO         jSecond_Padded   //! 00…59

#define jPeriod  jPattern( a )  //! AM / PM


#pragma mark - Date

#define jDate_ISO            jYear_ISO jDash jMonth_ISO jDash jDay_ISO  //! 2016-02-13
#define jDate_ISO_Month      jYear_ISO jDash jMonth_ISO                 //! 2016-02
#define jDate_ISO_Compact    jYear_ISO jMonth_ISO jDay_ISO              //! 20160213
#define jDate_ISO_DayOfYear  jYear_ISO jDash jDayOfYear_ISO             //! 2016-02-13
#define jDate_HTTP  jWeekday_Abbrev jComma jSpace jDay_Padded jSpace jMonth_Abbrev jSpace jYear  //! Sat, 13 Feb 2016

#define jDay         jPattern( d )   //! 1…31
#define jDay_Padded  jPattern( dd )  //! 01…31
#define jDay_ISO     jDate_ISO       //! 01…31

#define jDayOfYear         jPattern( D )      //! 1…366
#define jDayOfYear_Padded  jPattern( DDD )    //! 001…366
#define jDayOfYear_ISO     jDayOfYear_Padded  //! 001…366

#define jMonth             jPattern( M )      //! 1…12
#define jMonth_Padded      jPattern( MM )     //! 01…12
#define jMonth_Standalone  jPattern( LLLL )   //! January…December
#define jMonth_Name        jPattern( MMMM )   //! (of) January…December
#define jMonth_Abbrev      jPattern( MMM )    //! Jan…Dec
#define jMonth_Letter      jPattern( MMMMM )  //! J…D

#define jQuarter             jPattern( Q )     //! 1…4
#define jQuarter_Padded      jPattern( QQ )    //! 01…04
#define jQuarter_Prefixed    jPattern( QQQ )   //! Q1…Q4
#define jQuarter_Standalone  jPattern( qqqq )  //! 1st…4th quarter
#define jQuarter_Name        jPattern( QQQQ )  //! (of) 1st…4th quarter

#define jYear        jPattern( yyyy )  //! 0000…9999
#define jYear_Short  jPattern( yy )    //! 00…99

#define jEra       jPattern( G )     //! BC / AD
#define jEra_Name  jPattern( GGGG )  //! Before Christ / Anno Domini


#pragma mark - Weeks

#define jWeek_ISO          jYearOfWeek_ISO jDash jLiteral(W) jWeekOfYear_ISO  //! 2016-W06
#define jWeek_ISO_Compact  jYearOfWeek_ISO jLiteral(W) jWeekOfYear_ISO        //! 2016W06
#define jWeek_ISO_Weekday  jYearOfWeek_ISO jDash jLiteral(W) jWeekOfYear_ISO jDash jWeekday_ISO  //! 2016-W06-5

#define jWeekday             jPattern( e )       //! 1…7
#define jWeekday_Standalone  jPattern( cccc )    //! Monday…Sunday
#define jWeekday_Name        jPattern( eeee )    //! (of) Monday…Sunday
#define jWeekday_Abbrev      jPattern( eee )     //! Mon…Sun
#define jWeekday_2Letters    jPattern( eeeeee )  //! Mo…Su
#define jWeekday_Letter      jPattern( eeeee )   //! M…S
#define jWeekday_ISO         jWeekday            //! 1…7

#define jWeekOfMonth     jPattern( W )  //! 1…6
#define jWeekdayOfMonth  jPattern( F )  //! 1…6

#define jWeekOfYear         jPattern( w )       //! 1…53
#define jWeekOfYear_Padded  jPattern( ww )      //! 01…53
#define jWeekOfYear_ISO     jWeekOfYear_Padded  //! 01…53

#define jYearOfWeek        jPattern( YYYY )  //! 0000…9999
#define jYearOfWeek_Short  jPattern( YY )    //! 00…99
#define jYearOfWeek_ISO    jYearOfWeek       //! 0000…9999


#pragma mark - Zones

#define jZone_Abbrev         jPattern( v )     //! PT
#define jZone_Abbrev_DST     jPattern( z )     //! PDT
#define jZone_Name           jPattern( vvvv )  //! Pacific Time
#define jZone_Name_DST       jPattern( zzzz )  //! Pacific Daylight Time
#define jZone_GMT            jPattern( O )     //! GMT+1
#define jZone_GMT_Long       jPattern( OOOO )  //! GMT+01:00
#define jZone_ID             jPattern( VV )    //! America/Los_Angeles
#define jZone_City           jPattern( VVV )   //! Los Angeles
#define jZone_ISO            jPattern( xxxx )  //! +01:00 / +00:00
#define jZone_ISO_Compact    jPattern( xxxx )  //! +0100 / +0000
#define jZone_ISO_Hours      jPattern( x )     //! +01 / +00
#define jZone_ISO_Z          jPattern( xxxx )  //! +01:00 / Z
#define jZone_ISO_Z_Compact  jPattern( XXXX )  //! +0100 / Z
#define jZone_ISO_Z_Hours    jPattern( X )     //! +01 / Z

