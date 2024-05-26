def is_prime(number):
  for element in range(2,round(number/2)):
    if number % element == 0:
      print(f"{number} is not a prime number.")
      return 0
  else:
    print(f"{number} is prime number.")
if __name__ == "__main__":
  number = int(input("Enter a number: "))
  is_prime(number)
      
