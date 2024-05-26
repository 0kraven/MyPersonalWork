print("Welcome to the secret auction program.")
answer = True
bidders = [
  {"name":"","bid":0}
]
bidders_count = 0;
while True:
  name = input("Enter your name: ")
  bid = int(input("Enter your bid: "))
  bidders.append({"name":name,"bid":bid}) 
  answer = input("Are there any other bidders? Type 'yes' or 'no': ")
  if answer == "no":
    break
  bidders_count += 1

heighst = 0
name = ""
for index in bidders:
  if index["bid"] > heighst:
    heighst = index["bid"]
    name = index["name"]
print(f"The winner is {name} with a bid of ${heighst}")
