# City Tourism Management System

## Description

The City Tourism Management System is a C-based program designed to manage and analyze information about various cities, including their tourist numbers and key attractions. This program provides a comprehensive menu for performing various operations such as viewing file content, loading city data into an array, ranking cities based on tourist numbers, updating tourist information, and more. This system is useful for tourism departments, travel agencies, and researchers who need to manage and analyze city tourism data efficiently.

## Features

1. **View File Content:** Display the contents of the input file containing city data.
2. **Load File Data to an Array:** Load the city data from the input file into an array for further processing.
3. **Get Ranking of a City:** Retrieve the ranking of a specific city based on the number of tourists.
4. **Get Information about a City:** Get detailed information about a specific city, including its tourist attractions.
5. **Update the Number of Yearly Tourists of a City:** Update the number of yearly tourists for a specific city.
6. **Find the Most Visited Cities in a Country:** Identify and list the most visited cities within a specific country.
7. **Remove a City from the Ranking:** Remove a city from the ranking list.
8. **Quit:** Exit the program.

## Usage

### Compilation

To compile the program, use a C compiler like `gcc`:

```sh
gcc -o city_tourism_management Project1.c
```

### Execution

Run the compiled program:

```sh
./city_tourism_management
```

### Menu Options

Upon execution, the program will display a menu with the following options:

1. **View File Content:** Choose this option to display the content of the input file.
2. **Load File Data to an Array:** This option loads the city data into an array for processing.
3. **Get Ranking of a City:** Enter the name of the city to get its ranking based on tourist numbers.
4. **Get Information about a City:** Enter the name of the city to get detailed information.
5. **Update the Number of Yearly Tourists of a City:** Enter the name of the city and the new number of tourists to update the record.
6. **Find the Most Visited Cities in a Country:** Enter the name of the country to find its most visited cities.
7. **Remove a City from the Ranking:** Enter the name of the city to remove it from the ranking list.
8. **Quit:** Exit the program.

### Input File Format

The input file should contain city data in the following format:

```
CityName1
CountryName1
NumberOfTourists1
Hotspot1
CityName2
CountryName2
NumberOfTourists2
Hotspot2
...
```

## Example

An example input file (`city_data.txt`):

```
Paris
France
8924000
Eiffel Tower
Tokyo
Japan
15290000
Tokyo Tower
New York
USA
13350000
Statue of Liberty
```

Load the file data into the array and perform various operations as per the menu options.

