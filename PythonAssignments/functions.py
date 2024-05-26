def calc(height, width, cover):
  area = height * width
  num_of_cans = area / cover
  print(f"You'll need {num_of_cans} cans of paint.")
if __name__ == "__main__":
  wall_height = int(input("Enter the height of the wall: ")) 
  wall_width = int(input("Enter the width of the wall: "))
  coverage = 5
  calc(wall_height, wall_width, coverage)
