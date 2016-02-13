jDateFormat
===========

Never again write format strings by hand. Is it `yyyy` or `YYYY`? Which one is 24-hour, `HH` or `hh`? Month is `M` or `m`?

This project provides macros for (almost) every date format pattern available. They are named intuitively and their results are documented.

- Use `jYear` and avoid _Week Of Year_ bug. Use `jYearOfWeek` to have that bug anyway.
- Use `jHour_12_Padded` and `jHour_24_Padded` instead of `hh` or `HH`.
- Use `jMonth` and `jMinute` instead of `M` or `m`.

These macros produce `NSString` literals, so it’s easy to chain them:

```objc
dateFormatter.dateFormat = jHour_12 @":" jMinute_Padded jPeriod;
```

List of Patterns
----------

- `jHour` – 12-hour and 24-hour formats with optional padding.
- `jMinute` – Minute with opzional padding.
- `jSecond` – Seconds with optional padding and fractions.
- `jPeriod` – AM vs. PM for 12-hour clock.
- `jDay` and `jDayOfYear` – Day of month and year with optional padding.
- `jMonth` – Month number, name, abbreviations, and standalone name.
- `jQuarter` – Quarter number with optional padding and prefix, and quarter name.
- `jYear` – Year in 4 or 2 digits.
- `jEra` – AD vs. BC with optional full name.
- `jWeekday` – Weekday number, name, several abbreviations and standalone name.
- `jWeekOfMonth` and `jWeekdayOfMonth` – Ordinal numbers within month.
- `jWeekOfYear` – Number of week with optional padding
- `jYearOfWeek` – Year using week calendar 2 or 4 digit. Common bug.
- `jZone` – Zone ID, name, abbreviation, GMT offset or several ISO formats.

---

Source: [Unicode Date Format Patterns](http://www.unicode.org/reports/tr35/tr35-31/tr35-dates.html#Date_Format_Patterns)
