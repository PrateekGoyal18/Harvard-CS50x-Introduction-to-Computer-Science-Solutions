from cs50 import get_int

while True:
    height = get_int("Enter the height: ")
    if int(height)>=1 and int(height)<=8:
        break

# Pattern
for i in range(1, height + 1):
    num_hashes = i
    num_spaces = height - num_hashes

    print(" " * num_spaces, end="")
    print("#" * num_hashes, end="")
    print("  ", end="")
    print("#" * num_hashes)