
#define String(x...)  @#x                      //! Stringify the content.
#define Escape        String(\u0027)           //! ' U+0027 APOSTROPHE
#define Literal(x...) Escape String(x) Escape  //! Specify a non-pattern part.
#define Pattern(x)    String(x)                //! Specify a pattern.
#define Localized(locale, pattern...)  [NSDateFormatter dateFormatFromTemplate: (pattern) options:0 locale:locale]
#define Space         Literal(\u0020)          //!   U+0020 SPACE
#define Dash          Literal(\u002d)          //! - U+002D HYPHEN-MINUS
#define Colon         Literal(\u003a)          //! : U+003A COLON
#define Dot           Literal(\u002e)          //! . U+002E FULL STOP
#define Slash         Literal(\u002f)          //! / U+002F SOLIDUS
#define Apostrophe    Escape Escape            //! ' U+002F APOSTROPHE


#define DateTime_ISO            Date_ISO Time_ISO Zone_ISO      //! 2016-02-13T15:07:24+00:00
#define DateTime_ISO_Z          Date_ISO Time_ISO Zone_ISO_Z    //! 2016-02-13T15:07:24Z
#define DateTime_ISO_Compact    Date_ISO_Compact Time_ISO_Compact Zone_ISO_Compact  //! 20160213T150724+0000
#define DateTime_ISO_Z_Compact  Date_ISO_Compact Time_ISO_Compact Zone_ISO_Z_Compact    //! 20160213T150724Z
#define DateTime_HTTP           Date_HTTP Space Time_HTTP Space Literal(Z)  //! Sat, 13 Feb 2016 17:36:23 Z


#pragmamark - Time

#define Time_12             Time_12_Base Space Period               //! 03:07 PM
#define Time_12_Second      Time_12_Base Colon Second Space Period  //! 03:07:24 PM
#define Time_12_Base        Hour_12_Padded Colon Minute_Padded      //! 03:07
#define Time_24             Hour_24_Padded Colon Minute_Padded      //! 15:07
#define Time_24_Second      Time_24 Colon Second                    //! 15:07:24
#define Time_ISO            Literal(T) Hour_ISO Colon Minute_ISO Colon Second_ISO   //! T15:07:24
#define Time_ISO_Compact    Literal(T) Hour_ISO Minute_ISO Second_ISO               //! T150724
#define Time_HTTP           Time_24_Padded                          //! 15:07:24

#define Hour_12             Pattern( h )       //! 1…12
#define Hour_12_Padded      Pattern( hh )      //! 01…12
#define Hour_24             Pattern( H )       //! 0…23
#define Hour_24_Padded      Pattern( HH )      //! 00…23
#define Hour_ISO            Hour_24_Padded     //! 00…23

#define Minute              Pattern( m )       //! 0…59
#define Minute_Padded       Pattern( mm )      //! 00…59
#define Minute_ISO          Minute_Padded      //! 00…59

#define Second              Pattern( s )       //! 0…59
#define Second_Padded       Pattern( ss )      //! 00…59
#define Second_Fraction_1   Pattern( S )       //! 0…9 as deciseconds
#define Second_Fraction_2   Pattern( SS )      //! 00…99 as centiseconds
#define Second_Fraction_3   Pattern( SSS )     //! 000…999 as miliseconds
#define Second_ISO          Second_Padded      //! 00…59

#define Period              Pattern( a )       //! AM / PM


#pragma mark - Date

#define Date_ISO            Year_ISO Dash Month_ISO Dash Day_ISO    //! 2016-02-13
#define Date_ISO_Month      Year_ISO Dash Month_ISO                 //! 2016-02
#define Date_ISO_Compact    Year_ISO Month_ISO Day_ISO              //! 20160213
#define Date_ISO_DayOfYear  Year_ISO Dash DayOfYear_ISO             //! 2016-02-13
#define Date_HTTP           Weekday_Abbrev Comma Space Day_Padded Space Month_Abbrev Space Year //! Sat, 13 Feb 2016

#define Day                 Pattern( d )       //! 1…31
#define Day_Padded          Pattern( dd )      //! 01…31
#define Day_ISO             Date_ISO           //! 01…31

#define DayOfYear           Pattern( D )       //! 1…366
#define DayOfYear_Padded    Pattern( DDD )     //! 001…366
#define DayOfYear_ISO       DayOfYear_Padded   //! 001…366

#define Month               Pattern( M )       //! 1…12
#define Month_Padded        Pattern( MM )      //! 01…12
#define Month_Standalone    Pattern( LLLL )    //! January…December
#define Month_Name          Pattern( MMMM )    //! (of) January…December
#define Month_Abbrev        Pattern( MMM )     //! Jan…Dec
#define Month_Letter        Pattern( MMMMM )   //! J…D

#define Quarter             Pattern( Q )       //! 1…4
#define Quarter_Padded      Pattern( QQ )      //! 01…04
#define Quarter_Prefixed    Pattern( QQQ )     //! Q1…Q4
#define Quarter_Standalone  Pattern( qqqq )    //! 1st…4th quarter
#define Quarter_Name        Pattern( QQQQ )    //! (of) 1st…4th quarter

#define Year                Pattern( yyyy )    //! 0000…9999
#define Year_Short          Pattern( yy )      //! 00…99

#define Era                 Pattern( G )       //! BC / AD
#define Era_Name            Pattern( GGGG )    //! Before Christ / Anno Domini


#pragma mark - Weeks

#define Week_ISO            YearOfWeek_ISO Dash Literal(W) WeekOfYear_ISO                    //! 2016-W06
#define Week_ISO_Compact    YearOfWeek_ISO Literal(W) WeekOfYear_ISO                         //! 2016W06
#define Week_ISO_Weekday    YearOfWeek_ISO Dash Literal(W) WeekOfYear_ISO Dash Weekday_ISO   //! 2016-W06-5

#define Weekday             Pattern( e )       //! 1…7
#define Weekday.Standalone  Pattern( cccc )    //! Monday…Sunday
#define Weekday_Name        Pattern( eeee )    //! (of) Monday…Sunday
#define Weekday_Abbrev      Pattern( eee )     //! Mon…Sun
#define Weekday_2Letters    Pattern( eeeeee )  //! Mo…Su
#define Weekday_Letter      Pattern( eeeee )   //! M…S
#define Weekday_ISO         Weekday            //! 1…7

#define WeekOfMonth         Pattern( W )       //! 1…6 (ordinal of week in month)
#define WeekdayOfMonth      Pattern( F )       //! 1…6 (ordinal of weekday in month)

#define WeekOfYear          Pattern( w )       //! 1…53
#define WeekOfYear_Padded   Pattern( ww )      //! 01…53
#define WeekOfYear_ISO      WeekOfYear_Padded  //! 01…53

#define YearOfWeek          Pattern( YYYY )    //! 0000…9999
#define YearOfWeek_Short    Pattern( YY )      //! 00…99
#define YearOfWeek_ISO      YearOfWeek         //! 0000…9999


#pragma mark - Zones

#define Zone_Abbrev         Pattern( v )       //! PT
#define Zone_Abbrev_DST     Pattern( z )       //! PDT
#define Zone_Name           Pattern( vvvv )    //! Pacific Time
#define Zone_Name_DST       Pattern( zzzz )    //! Pacific Daylight Time
#define Zone_GMT            Pattern( O )       //! GMT+1
#define Zone_GMT_Long       Pattern( OOOO )    //! GMT+01:00
#define Zone_ID             Pattern( VV )      //! America/Los_Angeles
#define Zone_City           Pattern( VVV )     //! Los Angeles
#define Zone_ISO            Pattern( xxxx )    //! +01:00 / +00:00
#define Zone_ISO_Compact    Pattern( xxxx )    //! +0100 / +0000
#define Zone_ISO_Hours      Pattern( x )       //! +01 / +00
#define Zone_ISO_Z          Pattern( xxxx )    //! +01:00 / Z
#define Zone_ISO_Z_Compact  Pattern( XXXX )    //! +0100 / Z
#define Zone_ISO_Z_Hours    Pattern( X )       //! +01 / Z

