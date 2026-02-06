def is_leap_year(year):
    return (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0))

def is_date_valid(day, month, year):
    days_in_month = [31, 29 if is_leap_year(year) else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    if month < 1 or month > 12:
        print("Invalid month!")
        return False
    if day < 1 or day > days_in_month[month - 1]:
        print("Invalid day for this month!")
        return False
    return True

def print_next_date(day, month, year):
    days_in_month = [31, 29 if is_leap_year(year) else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    day += 1
    if day > days_in_month[month - 1]:
        day = 1
        month += 1
        if month > 12:
            month = 1
            year += 1
    
    print(f"The next date: {day}/{month}/{year}")

def get_valid_int(prompt):
    while True:
        try:
            value = int(input(prompt))
            return value
        except ValueError:
            print("Error! Please enter a valid integer.")


restart = 1
while restart == 1:
    year = get_valid_int("Enter a year: ")

    # Input month and validate
    while True:
        month = get_valid_int("Enter a month: ")
        if is_date_valid(day, month, year):
            break
        
    # Input day and validate
    while True:
        day = get_valid_int("Enter a day: ")
        if is_date_valid(day, month, year):
            break

    print(f"Date you entered: {day}/{month}/{year} - ", end="")
    if is_leap_year(year):
        print("This is a leap year!")
    else:
        print("This is an ordinary year!")

    print_next_date(day, month, year)

    # Ask if the user wants to restart
    while True:
        try:
            restart = int(input("Do you want to restart (1) or end (0) the program? "))
            if restart in [0, 1]:
                break
            else:
                print("You need to input 1 to restart or 0 to end the program!")
        except ValueError:
            print("You need to input 1 to restart or 0 to end the program!")


