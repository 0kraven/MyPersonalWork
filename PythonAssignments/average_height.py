# you can manually change the list or use a for loop to take inputs
students_hieght = [156, 178, 165, 171, 187]
average_height = 0
size = 0
for element in students_hieght:
  average_height += element
  size += 1
average_height /= size
print("Average height of the students is: ", round(average_height))
