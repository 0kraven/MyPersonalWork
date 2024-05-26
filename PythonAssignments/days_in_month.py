def days_in_month(year = 1900, month = 1):
  month_days = [31, leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
  if month > 12 or month < 1:
      return "Invalid month"
  return month_days[month - 1]
def leap_year(year = 1900):
  return 29 if ((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)) else 28
def main():
  print(days_in_month(2024, 2))
if __name__ == "__main__":
  main()
